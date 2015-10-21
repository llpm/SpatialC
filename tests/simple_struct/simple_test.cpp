#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (uint32_t i=0; i<20; i++) {
        s->fooIn(i, i * 20 + 4);
        uint32_t sum;
        s->sumOut(&sum);
        printf("i: %u, sum: %u, (correct: %u)\n",
               i, sum, i + (i * 20 + 4));
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
