#include <cstdio>

#include <frontend/package_set.hpp>

#include <llpm/design.hpp>

using namespace spatialc;
using namespace llpm;
using namespace std;

int main(int argc, char** argv) {
    try {
        Design d;

        vector<string> includeDirs;
        string modName;

        po::options_description desc("SpatialC Options");
        desc.add_options()
            ("help", "Show this output")
            ("include,I", po::value< vector<string> >()->multitoken(),
                  "Include directories (package search roots)")
            ("module,m", po::value<string>(&modName)->required(),
                  "Fully qualified name of top module")
        ;
        po::positional_options_description pd;
        pd.add("module", 1);

        desc.add(d.optDesc());

        for (int i=1; i<argc; i++) {
            if (strcmp(argv[i], "--help") == 0) {
                cout << desc << "\n";
                return 1;
            }
        }

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv)
                      .options(desc).positional(pd).run(), vm);
        po::notify(vm);
        d.notify(vm);

        includeDirs = vm["include"].as<vector<string>>();

        PackageSet ps(d, includeDirs);
        llpm::Module* hwMod = ps.instantiateModule(modName);

        if (hwMod == nullptr) {
            fprintf(stderr, "Could not find module %s\n", modName.c_str());
            return 2;
        }

        d.addModule(hwMod);

        return d.go();

    } catch (Exception& e) {
        fprintf(stderr, "Caught exception!\n\t%s\n", e.msg.c_str());
        return 1;
    }

    return 0;
}
