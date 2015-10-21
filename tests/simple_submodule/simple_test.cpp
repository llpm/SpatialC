#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    s->rst();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<100; i++) {
        s->valIn(i);
        s->run(2);
        uint32_t j, k;
        s->byTwo(&j);
        s->total(&k);
        printf("i: %d, byTwo: %u, total: %u\n",
               i, j, k);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
