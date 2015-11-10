#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    for (int32_t i=0; i<5; i++) {
        s->setReq(i);
        s->run(5);
        s->getReq();
        int32_t j;
        s->getResp((uint32_t*)&j);
        printf("in: %u, out: %u\n", i, j);
        assert( i == j );
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
