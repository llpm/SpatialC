/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitPackage(Package *t) {} //abstract class
void Skeleton::visitDef(Def *t) {} //abstract class
void Skeleton::visitMetaParamDecl(MetaParamDecl *t) {} //abstract class
void Skeleton::visitOptionalEqExp(OptionalEqExp *t) {} //abstract class
void Skeleton::visitMetaParam(MetaParam *t) {} //abstract class
void Skeleton::visitModDef(ModDef *t) {} //abstract class
void Skeleton::visitChannelSpecifier(ChannelSpecifier *t) {} //abstract class
void Skeleton::visitEventName(EventName *t) {} //abstract class
void Skeleton::visitEventParam(EventParam *t) {} //abstract class
void Skeleton::visitEventOrCond(EventOrCond *t) {} //abstract class
void Skeleton::visitEventOrList(EventOrList *t) {} //abstract class
void Skeleton::visitStructDef(StructDef *t) {} //abstract class
void Skeleton::visitFuncParam(FuncParam *t) {} //abstract class
void Skeleton::visitOptionalType(OptionalType *t) {} //abstract class
void Skeleton::visitStatement(Statement *t) {} //abstract class
void Skeleton::visitPushSubDest(PushSubDest *t) {} //abstract class
void Skeleton::visitVarAssignment(VarAssignment *t) {} //abstract class
void Skeleton::visitBlock(Block *t) {} //abstract class
void Skeleton::visitBlockAttr(BlockAttr *t) {} //abstract class
void Skeleton::visitElseBlock(ElseBlock *t) {} //abstract class
void Skeleton::visitExp(Exp *t) {} //abstract class
void Skeleton::visitPackageName(PackageName *t) {} //abstract class
void Skeleton::visitStructLiteralField(StructLiteralField *t) {} //abstract class
void Skeleton::visitIntOrName(IntOrName *t) {} //abstract class
void Skeleton::visitType(Type *t) {} //abstract class
void Skeleton::visitTemplateExp(TemplateExp *t) {} //abstract class
void Skeleton::visitTemplateArg(TemplateArg *t) {} //abstract class

void Skeleton::visitPDefs(PDefs *pdefs)
{
  /* Code For PDefs Goes Here */

  pdefs->listdef_->accept(this);

}

void Skeleton::visitDefImport(DefImport *defimport)
{
  /* Code For DefImport Goes Here */

  defimport->listpackagename_->accept(this);

}

void Skeleton::visitDefPackage(DefPackage *defpackage)
{
  /* Code For DefPackage Goes Here */

  defpackage->listpackagename_->accept(this);

}

void Skeleton::visitDefModule(DefModule *defmodule)
{
  /* Code For DefModule Goes Here */

  visitId(defmodule->id_);
  defmodule->metaparamdecl_->accept(this);
  defmodule->listmoddef_->accept(this);

}

void Skeleton::visitDefStruct(DefStruct *defstruct)
{
  /* Code For DefStruct Goes Here */

  visitId(defstruct->id_);
  defstruct->metaparamdecl_->accept(this);
  defstruct->liststructdef_->accept(this);

}

void Skeleton::visitNoParams(NoParams *noparams)
{
  /* Code For NoParams Goes Here */


}

void Skeleton::visitSomeParams(SomeParams *someparams)
{
  /* Code For SomeParams Goes Here */

  someparams->listmetaparam_->accept(this);

}

void Skeleton::visitEqExp(EqExp *eqexp)
{
  /* Code For EqExp Goes Here */

  eqexp->exp_->accept(this);

}

void Skeleton::visitNoEqExp(NoEqExp *noeqexp)
{
  /* Code For NoEqExp Goes Here */


}

void Skeleton::visitMetaParam1(MetaParam1 *metaparam1)
{
  /* Code For MetaParam1 Goes Here */

  metaparam1->type_->accept(this);
  visitId(metaparam1->id_);
  metaparam1->optionaleqexp_->accept(this);

}

void Skeleton::visitDefConst(DefConst *defconst)
{
  /* Code For DefConst Goes Here */

  defconst->type_->accept(this);
  visitId(defconst->id_);
  defconst->optionaleqexp_->accept(this);

}

void Skeleton::visitDefReg(DefReg *defreg)
{
  /* Code For DefReg Goes Here */

  defreg->type_->accept(this);
  visitId(defreg->id_);

}

void Skeleton::visitDefMem(DefMem *defmem)
{
  /* Code For DefMem Goes Here */

  defmem->type_->accept(this);
  visitId(defmem->id_);

}

void Skeleton::visitDefSubmodule(DefSubmodule *defsubmodule)
{
  /* Code For DefSubmodule Goes Here */

  defsubmodule->type_->accept(this);
  visitId(defsubmodule->id_);

}

void Skeleton::visitDefInput(DefInput *definput)
{
  /* Code For DefInput Goes Here */

  definput->type_->accept(this);
  visitId(definput->id_);

}

void Skeleton::visitDefOutput(DefOutput *defoutput)
{
  /* Code For DefOutput Goes Here */

  defoutput->type_->accept(this);
  visitId(defoutput->id_);

}

void Skeleton::visitDefInternal(DefInternal *definternal)
{
  /* Code For DefInternal Goes Here */

  definternal->type_->accept(this);
  visitId(definternal->id_);

}

void Skeleton::visitDefEvent(DefEvent *defevent)
{
  /* Code For DefEvent Goes Here */

  defevent->eventname_->accept(this);
  defevent->listeventparam_->accept(this);
  defevent->block_->accept(this);

}

void Skeleton::visitDefInit(DefInit *definit)
{
  /* Code For DefInit Goes Here */

  definit->eventname_->accept(this);
  definit->block_->accept(this);

}

void Skeleton::visitDefConnect(DefConnect *defconnect)
{
  /* Code For DefConnect Goes Here */

  defconnect->channelspecifier_1->accept(this);
  defconnect->channelspecifier_2->accept(this);

}

void Skeleton::visitDefFor(DefFor *deffor)
{
  /* Code For DefFor Goes Here */

  visitId(deffor->id_);
  deffor->exp_1->accept(this);
  deffor->exp_2->accept(this);
  deffor->listmoddef_->accept(this);

}

void Skeleton::visitDefIf(DefIf *defif)
{
  /* Code For DefIf Goes Here */

  defif->exp_->accept(this);
  defif->listmoddef_->accept(this);

}

void Skeleton::visitSimpleCS(SimpleCS *simplecs)
{
  /* Code For SimpleCS Goes Here */

  visitId(simplecs->id_);

}

void Skeleton::visitDotCS(DotCS *dotcs)
{
  /* Code For DotCS Goes Here */

  visitId(dotcs->id_1);
  visitId(dotcs->id_2);

}

void Skeleton::visitArrayDotCS(ArrayDotCS *arraydotcs)
{
  /* Code For ArrayDotCS Goes Here */

  visitId(arraydotcs->id_1);
  arraydotcs->exp_->accept(this);
  visitId(arraydotcs->id_2);

}

void Skeleton::visitNoEvName(NoEvName *noevname)
{
  /* Code For NoEvName Goes Here */


}

void Skeleton::visitEvName(EvName *evname)
{
  /* Code For EvName Goes Here */

  visitId(evname->id_);

}

void Skeleton::visitEventParamWithName(EventParamWithName *eventparamwithname)
{
  /* Code For EventParamWithName Goes Here */

  eventparamwithname->eventorcond_->accept(this);
  visitId(eventparamwithname->id_);

}

void Skeleton::visitEventParamNoName(EventParamNoName *eventparamnoname)
{
  /* Code For EventParamNoName Goes Here */

  eventparamnoname->eventorcond_->accept(this);

}

void Skeleton::visitCSEventCond(CSEventCond *cseventcond)
{
  /* Code For CSEventCond Goes Here */

  cseventcond->channelspecifier_->accept(this);

}

void Skeleton::visitListEvOr(ListEvOr *listevor)
{
  /* Code For ListEvOr Goes Here */

  listevor->listeventorlist_->accept(this);

}

void Skeleton::visitEventOrListChannelSpecifier(EventOrListChannelSpecifier *eventorlistchannelspecifier)
{
  /* Code For EventOrListChannelSpecifier Goes Here */

  eventorlistchannelspecifier->channelspecifier_->accept(this);

}

void Skeleton::visitDefSubstor(DefSubstor *defsubstor)
{
  /* Code For DefSubstor Goes Here */

  defsubstor->type_->accept(this);
  visitId(defsubstor->id_);

}

void Skeleton::visitDefFunction(DefFunction *deffunction)
{
  /* Code For DefFunction Goes Here */

  deffunction->type_->accept(this);
  visitId(deffunction->id_);
  deffunction->listfuncparam_->accept(this);
  deffunction->liststatement_->accept(this);

}

void Skeleton::visitFuncParam1(FuncParam1 *funcparam1)
{
  /* Code For FuncParam1 Goes Here */

  funcparam1->type_->accept(this);
  visitId(funcparam1->id_);

}

void Skeleton::visitNoType(NoType *notype)
{
  /* Code For NoType Goes Here */


}

void Skeleton::visitTypeSpec(TypeSpec *typespec)
{
  /* Code For TypeSpec Goes Here */

  typespec->type_->accept(this);

}

void Skeleton::visitVarStmt(VarStmt *varstmt)
{
  /* Code For VarStmt Goes Here */

  varstmt->optionaltype_->accept(this);
  visitId(varstmt->id_);
  varstmt->varassignment_->accept(this);

}

void Skeleton::visitAssignStmt(AssignStmt *assignstmt)
{
  /* Code For AssignStmt Goes Here */

  visitId(assignstmt->id_);
  assignstmt->exp_->accept(this);

}

void Skeleton::visitAssignArrStmt(AssignArrStmt *assignarrstmt)
{
  /* Code For AssignArrStmt Goes Here */

  visitId(assignarrstmt->id_);
  assignarrstmt->exp_1->accept(this);
  assignarrstmt->exp_2->accept(this);

}

void Skeleton::visitIfStmt(IfStmt *ifstmt)
{
  /* Code For IfStmt Goes Here */

  ifstmt->exp_->accept(this);
  ifstmt->block_->accept(this);
  ifstmt->elseblock_->accept(this);

}

void Skeleton::visitBlockStmt(BlockStmt *blockstmt)
{
  /* Code For BlockStmt Goes Here */

  blockstmt->block_->accept(this);

}

void Skeleton::visitPushStmt(PushStmt *pushstmt)
{
  /* Code For PushStmt Goes Here */

  visitId(pushstmt->id_);
  pushstmt->pushsubdest_->accept(this);
  pushstmt->exp_->accept(this);

}

void Skeleton::visitStaticForStmt(StaticForStmt *staticforstmt)
{
  /* Code For StaticForStmt Goes Here */

  visitId(staticforstmt->id_);
  staticforstmt->exp_1->accept(this);
  staticforstmt->exp_2->accept(this);
  staticforstmt->block_->accept(this);

}

void Skeleton::visitStaticIfStmt(StaticIfStmt *staticifstmt)
{
  /* Code For StaticIfStmt Goes Here */

  staticifstmt->exp_->accept(this);
  staticifstmt->block_->accept(this);

}

void Skeleton::visitReturnStmt(ReturnStmt *returnstmt)
{
  /* Code For ReturnStmt Goes Here */

  returnstmt->exp_->accept(this);

}

void Skeleton::visitWaitUntilStmt(WaitUntilStmt *waituntilstmt)
{
  /* Code For WaitUntilStmt Goes Here */

  waituntilstmt->exp_->accept(this);

}

void Skeleton::visitPushSubreg(PushSubreg *pushsubreg)
{
  /* Code For PushSubreg Goes Here */

  visitId(pushsubreg->id_);

}

void Skeleton::visitPushArray(PushArray *pusharray)
{
  /* Code For PushArray Goes Here */

  pusharray->exp_->accept(this);

}

void Skeleton::visitPushArrayDot(PushArrayDot *pusharraydot)
{
  /* Code For PushArrayDot Goes Here */

  pusharraydot->exp_->accept(this);
  visitId(pusharraydot->id_);

}

void Skeleton::visitPushReg(PushReg *pushreg)
{
  /* Code For PushReg Goes Here */


}

void Skeleton::visitVarAssign(VarAssign *varassign)
{
  /* Code For VarAssign Goes Here */

  varassign->exp_->accept(this);

}

void Skeleton::visitNoVarAssign(NoVarAssign *novarassign)
{
  /* Code For NoVarAssign Goes Here */


}

void Skeleton::visitBlock1(Block1 *block1)
{
  /* Code For Block1 Goes Here */

  block1->listblockattr_->accept(this);
  block1->liststatement_->accept(this);

}

void Skeleton::visitBlockAttr_atomic(BlockAttr_atomic *blockattr_atomic)
{
  /* Code For BlockAttr_atomic Goes Here */


}

void Skeleton::visitBlockAttr_xact(BlockAttr_xact *blockattr_xact)
{
  /* Code For BlockAttr_xact Goes Here */


}

void Skeleton::visitElseIf(ElseIf *elseif)
{
  /* Code For ElseIf Goes Here */

  elseif->exp_->accept(this);
  elseif->block_->accept(this);
  elseif->elseblock_->accept(this);

}

void Skeleton::visitElse(Else *else)
{
  /* Code For Else Goes Here */

  else->block_->accept(this);

}

void Skeleton::visitNoElse(NoElse *noelse)
{
  /* Code For NoElse Goes Here */


}

void Skeleton::visitEVoid(EVoid *evoid)
{
  /* Code For EVoid Goes Here */


}

void Skeleton::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */


}

void Skeleton::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */


}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */

  visitInteger(eint->integer_);

}

void Skeleton::visitEDouble(EDouble *edouble)
{
  /* Code For EDouble Goes Here */

  visitDouble(edouble->double_);

}

void Skeleton::visitEString(EString *estring)
{
  /* Code For EString Goes Here */

  visitString(estring->string_);

}

void Skeleton::visitEStructLiteral(EStructLiteral *estructliteral)
{
  /* Code For EStructLiteral Goes Here */

  estructliteral->type_->accept(this);
  estructliteral->liststructliteralfield_->accept(this);

}

void Skeleton::visitEVectorLiteral(EVectorLiteral *evectorliteral)
{
  /* Code For EVectorLiteral Goes Here */

  evectorliteral->listexp_->accept(this);

}

void Skeleton::visitEId(EId *eid)
{
  /* Code For EId Goes Here */

  visitId(eid->id_);

}

void Skeleton::visitEArrAcc(EArrAcc *earracc)
{
  /* Code For EArrAcc Goes Here */

  earracc->exp_1->accept(this);
  earracc->exp_2->accept(this);

}

void Skeleton::visitESlice(ESlice *eslice)
{
  /* Code For ESlice Goes Here */

  eslice->exp_1->accept(this);
  eslice->exp_2->accept(this);
  eslice->exp_3->accept(this);

}

void Skeleton::visitEDot(EDot *edot)
{
  /* Code For EDot Goes Here */

  edot->exp_->accept(this);
  visitId(edot->id_);

}

void Skeleton::visitETimes(ETimes *etimes)
{
  /* Code For ETimes Goes Here */

  etimes->exp_1->accept(this);
  etimes->exp_2->accept(this);

}

void Skeleton::visitEDiv(EDiv *ediv)
{
  /* Code For EDiv Goes Here */

  ediv->exp_1->accept(this);
  ediv->exp_2->accept(this);

}

void Skeleton::visitEPlus(EPlus *eplus)
{
  /* Code For EPlus Goes Here */

  eplus->exp_1->accept(this);
  eplus->exp_2->accept(this);

}

void Skeleton::visitEMinus(EMinus *eminus)
{
  /* Code For EMinus Goes Here */

  eminus->exp_1->accept(this);
  eminus->exp_2->accept(this);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->exp_1->accept(this);
  elt->exp_2->accept(this);

}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->exp_1->accept(this);
  egt->exp_2->accept(this);

}

void Skeleton::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */

  elteq->exp_1->accept(this);
  elteq->exp_2->accept(this);

}

void Skeleton::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */

  egteq->exp_1->accept(this);
  egteq->exp_2->accept(this);

}

void Skeleton::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->exp_1->accept(this);
  eeq->exp_2->accept(this);

}

void Skeleton::visitENEq(ENEq *eneq)
{
  /* Code For ENEq Goes Here */

  eneq->exp_1->accept(this);
  eneq->exp_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->exp_1->accept(this);
  eand->exp_2->accept(this);

}

void Skeleton::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->exp_1->accept(this);
  eor->exp_2->accept(this);

}

void Skeleton::visitPackageNameId(PackageNameId *packagenameid)
{
  /* Code For PackageNameId Goes Here */

  visitId(packagenameid->id_);

}

void Skeleton::visitStructLiteralField1(StructLiteralField1 *structliteralfield1)
{
  /* Code For StructLiteralField1 Goes Here */

  visitId(structliteralfield1->id_);
  structliteralfield1->exp_->accept(this);

}

void Skeleton::visitConstName(ConstName *constname)
{
  /* Code For ConstName Goes Here */

  visitId(constname->id_);

}

void Skeleton::visitInt(Int *int)
{
  /* Code For Int Goes Here */

  visitInteger(int->integer_);

}

void Skeleton::visitTyName(TyName *tyname)
{
  /* Code For TyName Goes Here */

  visitId(tyname->id_);

}

void Skeleton::visitTyVoid(TyVoid *tyvoid)
{
  /* Code For TyVoid Goes Here */


}

void Skeleton::visitTyType(TyType *tytype)
{
  /* Code For TyType Goes Here */


}

void Skeleton::visitTyNameParams(TyNameParams *tynameparams)
{
  /* Code For TyNameParams Goes Here */

  visitId(tynameparams->id_);
  tynameparams->listtemplatearg_->accept(this);

}

void Skeleton::visitTyArray(TyArray *tyarray)
{
  /* Code For TyArray Goes Here */

  tyarray->type_->accept(this);
  tyarray->intorname_->accept(this);

}

void Skeleton::visitTyVector(TyVector *tyvector)
{
  /* Code For TyVector Goes Here */

  tyvector->type_->accept(this);
  tyvector->intorname_->accept(this);

}

void Skeleton::visitTEType(TEType *tetype)
{
  /* Code For TEType Goes Here */

  tetype->type_->accept(this);

}

void Skeleton::visitTEConstExp(TEConstExp *teconstexp)
{
  /* Code For TEConstExp Goes Here */

  teconstexp->exp_->accept(this);

}

void Skeleton::visitTemplateArg1(TemplateArg1 *templatearg1)
{
  /* Code For TemplateArg1 Goes Here */

  visitId(templatearg1->id_);
  templatearg1->templateexp_->accept(this);

}


void Skeleton::visitListDef(ListDef *listdef)
{
  for (ListDef::iterator i = listdef->begin() ; i != listdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListMetaParam(ListMetaParam *listmetaparam)
{
  for (ListMetaParam::iterator i = listmetaparam->begin() ; i != listmetaparam->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListModDef(ListModDef *listmoddef)
{
  for (ListModDef::iterator i = listmoddef->begin() ; i != listmoddef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListEventParam(ListEventParam *listeventparam)
{
  for (ListEventParam::iterator i = listeventparam->begin() ; i != listeventparam->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListEventOrList(ListEventOrList *listeventorlist)
{
  for (ListEventOrList::iterator i = listeventorlist->begin() ; i != listeventorlist->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStructDef(ListStructDef *liststructdef)
{
  for (ListStructDef::iterator i = liststructdef->begin() ; i != liststructdef->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListFuncParam(ListFuncParam *listfuncparam)
{
  for (ListFuncParam::iterator i = listfuncparam->begin() ; i != listfuncparam->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStatement(ListStatement *liststatement)
{
  for (ListStatement::iterator i = liststatement->begin() ; i != liststatement->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListBlockAttr(ListBlockAttr *listblockattr)
{
  for (ListBlockAttr::iterator i = listblockattr->begin() ; i != listblockattr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExp(ListExp *listexp)
{
  for (ListExp::iterator i = listexp->begin() ; i != listexp->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListPackageName(ListPackageName *listpackagename)
{
  for (ListPackageName::iterator i = listpackagename->begin() ; i != listpackagename->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListStructLiteralField(ListStructLiteralField *liststructliteralfield)
{
  for (ListStructLiteralField::iterator i = liststructliteralfield->begin() ; i != liststructliteralfield->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListTemplateArg(ListTemplateArg *listtemplatearg)
{
  for (ListTemplateArg::iterator i = listtemplatearg->begin() ; i != listtemplatearg->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitId(Id x)
{
  /* Code for Id Goes Here */
}

void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}



