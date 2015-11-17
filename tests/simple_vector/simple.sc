package simple;

struct Write {
    int idx;
    int value;
}

module Simple {

    reg int<4> vec;

    input Write write;
    output int writeDone;
    input void resetVec;
    
    input void reqSum;
    output int sum;

    event (resetVec -> msg) {
        vec <- [0, 0, 0, 0];
    }

    event (write -> w) atomic {
        var :int<4> tmp = vec;
        tmp[w.idx] = w.value;
        vec <- tmp;
        writeDone <- 1;
    }

    event (reqSum -> r) {
        var :int<4> v = vec;
        sum <- v[0] + v[1] + v[2] + v[3];
    }
}
