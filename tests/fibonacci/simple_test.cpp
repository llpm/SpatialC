#include "Simple.hpp"
#include "obj/verilator_extra.h"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    start_debug(fopen("debug.txt", "w"));
    s->reset();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<25; i++) {
        uint64_t j;
        s->fibSeq(&j);
        printf("fib: %lu\n", j);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    close_debug();
    delete s;
    return 0;
}
