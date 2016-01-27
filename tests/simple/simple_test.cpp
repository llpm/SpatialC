#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>

int main() {
    Simple* s = new Simple();
    s->trace("debug.vcd");
    s->reset();
    uint64_t start = s->cycles();

    int32_t i=0;
    int32_t j=0;
    while (i < 25 || j < 25) {
        if (((rand() & 0x0F) == 0) && i < 25 && s->intIn_size() == 0) {
            Simple::intIn_type t;
            t.arg0 = i;
            s->intIn_nonblock(t);
            printf("in: %u\n", i);
            i++;
        } 
        if (s->intOut_size() > 0 && ((rand() & 0xFF) == 0)) {
            int32_t k;
            s->intOut((uint32_t*)&k);
            if (k != j)
                printf("out: %u <-- ERROR\n", k);
            else
                printf("out: %u\n", k);
            j++;
        } 
        s->run(1);
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
