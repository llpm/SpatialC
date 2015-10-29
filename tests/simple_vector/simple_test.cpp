#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    uint32_t csum = 0;
    for (int32_t i=0; i<4; i++) {
        s->write(i, i*5);
        csum += i*5;
    }

    uint32_t sum = 0;
    s->reqSum();
    s->sum(&sum);

    printf("correct sum: %u, calcSum: %u\n", csum, sum);

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
