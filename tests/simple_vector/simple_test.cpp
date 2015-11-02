#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    s->resetVec();
    s->run(5);
    printf("Finished reset\n");

    uint32_t csum = 0;
    for (int32_t i=0; i<4; i++) {
        s->write(i, i*5);
        csum += i*5;
        printf("Sent write %d\n", i);
        uint32_t tmp;
        s->writeDone(&tmp);
        printf("Finished write with %u\n", tmp);
        s->run(2);
    }
    
    s->run(20);
    printf("Finished writes\n");

    uint32_t sum = 0;
    s->reqSum();
    s->sum(&sum);

    printf("correct sum: %u, calcSum: %u\n", csum, sum);

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
