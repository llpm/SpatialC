#include "Simple.hpp"
#include "obj/verilator_extra.h"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main() {
    Simple* s = new Simple();
    // s->trace("debug.vcd");
    s->reset();

    // start_debug(fopen("debug.txt", "w"));

    for (unsigned i=0; i<10; i++) {
        s->cnfg(i, (i+1)*100);
    }
    s->run(50);

    unsigned NUM = 5000;

    map<unsigned, vector<unsigned>> parts;

    srand(time(NULL));
    unsigned outCounter = 0;

    uint64_t start = s->cycles();
    for (int32_t i=0; i<NUM; ) {
        Simple::dout_type dout;

        if (s->din_size() == 0) {
            Simple::din_type din;
            din.arg0 = rand() % 1000;
            s->din_nonblock(din);
            i++;
        } else if (s->dout_nonblock(&dout)) {
            parts[dout.arg0].push_back(dout.arg1);
            outCounter++;
        } else {
            s->run(1);
        }
    }

    while (outCounter < NUM) {
        Simple::dout_type dout;
        s->dout(&dout);
        parts[dout.arg0].push_back(dout.arg1);
        outCounter++;
    }

#if 0
    for (const auto&p: parts) {
        printf("%2u: ", p.first);
        for (auto v: p.second) {
            printf("%3u, ", v);
        }
        printf("\n");
    }
#endif

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    close_debug();

    delete s;
    return 0;
}
