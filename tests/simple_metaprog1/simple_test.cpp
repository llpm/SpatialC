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
    uint32_t size;

    for (int32_t i=0; i<64; i++) {
        s->write(i, i);
    }

    for (int32_t i=0; i<64; i++) {
        s->read(i);
        uint32_t j;
        s->read_val(&j);
        printf("i: %d, out: %u\n",
               i, j);
    }

    s->resetAll();

    s->run(200);

    for (int32_t i=0; i<64; i++) {
        s->read(i);
        uint32_t j;
        s->read_val(&j);
        printf("i: %d, out: %u\n",
               i, j);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
