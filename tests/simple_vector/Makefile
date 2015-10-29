OPTS=--control_regions 1
CFLAGS=-O0
CXXFLAGS=${CFLAGS}

CLANGXX=../../bin/llvm/bin/clang++
CLANG=../../bin/llvm/bin/clang
CXX=$(CLANGXX)
DIS=../../bin/llvm/bin/llvm-dis
OPT=../../bin/llvm/bin/opt

NAME=simple
ROOT=Simple

default: ${NAME}_test ${ROOT}.pdf ${ROOT}_simple.pdf



obj/${ROOT}.hpp: ${NAME}.sc ../../bin/spatialc
	../../bin/spatialc -I. -m ${NAME}.${ROOT} ${OPTS}

${ROOT}.hpp: obj/${ROOT}.hpp
	cp obj/${ROOT}.hpp .

${NAME}_test: ${NAME}_test.cpp ${ROOT}.hpp
	${CXX} -c -emit-llvm ${CXXFLAGS} ${NAME}_test.cpp -o ${NAME}_test.cpp.bc
	${CXX} -o ${NAME}_test ${NAME}_test.cpp.bc obj/${ROOT}_sw.bc

%.bc: %.cpp
	${CLANGXX} -c -emit-llvm ${CFLAGS} $< -o $@
	${DIS} $@

%.pdf: obj/%.gv
	dot -Tpdf -o $@ $< || true

clean:
	rm -rf ${NAME}_test ${NAME}.hpp *.bc obj *.ll
