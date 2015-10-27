#!/bin/sh

../ext/bnfc/source/dist/build/bnfc/bnfc --cpp spatialc.cf -l -m
make 2>&1 | grep -v "Printer.C" | grep -v "ShowAbsyn" | grep -v "PrintAbsyn" \
    | grep -v "Absyn.C" | grep -v "::" \
    | grep -v "\\^" | grep -v "render"
