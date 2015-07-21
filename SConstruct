import os
import os.path
import sys
from lex_bison import *

AddOption('--cxx', action='store', type='string', dest='cxx', nargs=1, metavar='COMPILER',
		   help='Use argument as the C++ compiler.')

AddOption('--llpm', action='store', type='string', dest='llpm', nargs=1,
                   default='../llpm/',
		   help='Location of LLPM build tree')

LlpmPath = GetOption('llpm')
print "Using LLPM tree at:", LlpmPath

LibPaths = [".", "./bin/", LlpmPath + "bin/llvm/lib", LlpmPath + "bin/"]
CxxLdFlags = """
-g -pthread -fno-omit-frame-pointer
""".split()

env = Environment(
    CPPPATH=['.', LlpmPath + 'bin/llvm/include/', LlpmPath + 'lib/'],
    CXXFLAGS="""-O0 -mfpmath=sse -msse4 -march=native
            -Wall -Wextra -std=c++1y
            -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS
            -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS """.split()
            + CxxLdFlags,
    LIBS="""tinyxml2 boost_program_options LLVM-3.5 llpm""".split(),
    LIBPATH=LibPaths,
    LINKFLAGS=[]
              + CxxLdFlags
              + map(lambda x: "-Wl,-rpath=\$$ORIGIN/%s" % x,
              LibPaths),
    tools = ["default", "doxygen"],
    toolpath = '.'
)
add_lex(env)
add_bison(env)

if GetOption('cxx') != None:
   env.Replace(CXX = GetOption('cxx'))

libenv = env.Clone()
spatialc = libenv.SharedLibrary('bin/spatialc',
                               Glob("./frontend/*.cpp") +
                               ["grammar/Absyn.C", "grammar/Printer.C",
                                "grammar/Parser.C", "grammar/Lexer.C"])
Default(spatialc)
env.Prepend(LIBS=['spatialc'])

for d in Glob("./tools/*"):
    d = str(d).split("/")[-1]
    driver = env.Program("bin/" + d, Glob("./tools/%s/*.cpp" % d))
    Default(driver)

docs = env.Doxygen("Doxyfile")


