#include "event.hpp"
#include <frontend/exception.hpp>
#include <libraries/core/logic_intr.hpp>

using namespace std;

namespace spatialc {

Event::Event(llpm::Design& design, std::string name, SpatialCModule* mod) :
    llpm::ContainerModule(design, name),
    _mod(mod) {
}

Context Event::buildInitial(ListEventParam* list) {
    Context ctxt;
    for (auto evParamI: *list) {
        auto evParam = dynamic_cast<EventParam1*>(evParamI);
        assert(evParam != nullptr);

        string paramName = evParam->id_;
        vector<string> inpNames;
        
        auto simpleEvOr = dynamic_cast<SimpleEvOr*>(evParam->eventorcond_);
        if (simpleEvOr != nullptr) {
            // No or condition -- just a simple input
            inpNames.push_back(simpleEvOr->id_);
        }

        auto orList = dynamic_cast<ListEvOr*>(evParam->eventorcond_);
        if (orList != nullptr) {
            for (EventOrList* orEv: *orList->listeventorlist_) {
                inpNames.push_back(((EventOrListId*)orEv)->id_);
            }
        }

        assert(inpNames.size() > 0);

        vector<Type> types;
        vector<InputPort*> ports;
        for (auto inpName: inpNames) {
            auto tyF = _mod->nameTypes()->find(inpName);
            if (tyF == _mod->nameTypes()->end()) {
                throw SemanticError(
                    "Could not locate input '" + inpName + "'!");
            }
            auto inpF = _mod->namedInputs()->find(inpName);
            assert(inpF != _mod->namedInputs()->end());

            if (types.size() > 0) {
                if (*types.begin() != tyF->second) {
                    throw SemanticError(
                        "Input types in OR list don't match!");
                }
            }

            types.push_back(tyF->second);
            ports.push_back(inpF->second); 
        }

        assert(types.size() == ports.size());
        assert(ports.size() == inpNames.size());
        auto inpSel = new Select(ports.size(), types.front().llvm());
        for (size_t i=0; i<inpNames.size(); i++) {
            _ioConnections[inpNames[i]] = 
                addInputPort(inpSel->din(i), inpNames[i]);
        }
        Variable var(types.front(), inpSel->dout(), paramName);
        ctxt.vars.push_back(var);
    }

    ctxt.createJoinSplit(conns());
    return ctxt;
}

void Event::scanForOutputs(::Block* blockD) {
    auto block = dynamic_cast<Block1*>(blockD);
    assert(block != nullptr);

    for (auto stmt: *block->liststatement_) {
        auto blockStmt = dynamic_cast<BlockStmt*>(stmt);
        if (blockStmt != nullptr) {
            ::Block1 b(nullptr, blockStmt->liststatement_);
            scanForOutputs(&b);
            continue;
        }

        auto pushStmt = dynamic_cast<PushStmt*>(stmt);
        if (pushStmt != nullptr) {
            string outName = pushStmt->id_;
            auto f = _mod->namedOutputs()->find(outName);
            if (f == _mod->namedOutputs()->end()) {
                throw SemanticError(
                    "Cannot find output channel '" + outName + "'!");
            }
            auto op = createOutputPort(f->second->type());
            _ioConnections[outName] = op;

            // TODO: Remove this dummy driver
            auto never = new Never(op->type());
            conns()->connect(getSink(op), never->dout());
            continue;
        }
    }
}

Event* Event::create(llpm::Design& design,
                     DefEvent* eventAst,
                     SpatialCModule* mod) {
    // Get event name
    string evName = "";
    auto evNameObj = dynamic_cast<EvName*>(eventAst->eventname_);
    if (evNameObj != nullptr) {
        evName = evNameObj->id_;
    }

    Event* ev = new Event(design, evName, mod);

    // Convert the event list to something usable
    Context ctxt = ev->buildInitial(eventAst->listeventparam_);
    for (auto v: ctxt.vars) {
        auto ns = new NullSink(v.op->type());
        ev->connect(v.op, ns->din());
    }

    // Find all the outputs this event uses
    ev->scanForOutputs(eventAst->block_);


    return ev;
}

} // namespace spatialc
