# SpatialC
A low level programming language frontend for LLPM


# Build Instructions:
- Make sure LLPM is built and working. By default the build scripts look for
  ../llpm, though this can be overridden with --llpm.
- $ scons

# Building the grammar (unnecessary unless you change the grammar)
To make compilation easier, the autogenerated .C and .H files for lexing,
parsing and AST generation are included in the repo. If you want to change the
grammar, these files must be rebuilt. To rebuild, 'cd grammar; ./build.sh; cd
..;'. This script requires bnfc (a submodule in this repo) to be built and
working. Please see the build directions in its directory. It also requires
bison and flex.


# SpatialC Status
SpatialC is really, really, really unstable and in early development. There is
little documentation and many features that should work don't. Here's a list of
potential gotchas:

- Errors in your code don't necessarily produce good error messages, especially
for features which aren't fully implemented yet. 
- The master HEAD of this SpatialC repo likely also requires the master HEAD of
the LLPM repo. They are developing in parallel and very dependent on each
other. For example, SpatialC may require a new feature or bugfix in LLPM.
- I'm sure there's plenty of other issues. I'll start using the github issue
tracker soon.
