#include "Simple.hpp"

#include <cstdio>
#include <stdint.h>
#include <cassert>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main() {
    Simple* s = new Simple();
    //s->trace("debug.vcd");
    s->reset();

    for (unsigned i=0; i<10; i++) {
        s->cnfg(i, (i+1)*100);
    }
    s->run(50);

    unsigned NUM = 500;

    map<unsigned, vector<unsigned>> parts;

    srand(time(NULL));
    unsigned outCounter = 0;

    uint64_t start = s->cycles();
    for (int32_t i=0; i<NUM; i++) {
        unsigned n = rand() % 1000;
        s->din(n);

        Simple::dout_type dout;
        if (s->dout_nonblock(&dout)) {
            parts[dout.arg0].push_back(dout.arg1);
            outCounter++;
        }
    }

    while (outCounter < NUM) {
        Simple::dout_type dout;
        s->dout(&dout);
        parts[dout.arg0].push_back(dout.arg1);
        outCounter++;
    }

    for (const auto&p: parts) {
        printf("%2u: ", p.first);
        for (auto v: p.second) {
            printf("%3u, ", v);
        }
        printf("\n");
    }

    uint64_t stop = s->cycles();
    printf("Took %lu cycles to run\n", stop - start);

    delete s;
    return 0;
}
