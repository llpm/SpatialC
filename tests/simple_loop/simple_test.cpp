#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();
    s->count(5);

    for (int32_t i=0; i<5; i++) {
        uint32_t j;
        s->nums(&j);
        printf("out: %u\n", j);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
