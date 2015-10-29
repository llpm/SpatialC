package simple;

struct Write {
    int idx;
    int value;
}

module Simple {

    int<4> vec;

    input Write write;
    
    input void reqSum;
    output int sum;

    event (write -> w) {
        int<4> tmp = vec;
        tmp[w.idx] = w.value;
        vec <- tmp;
    }

    event (reqSum -> r) {
        int<4> v = vec;
        sum <- v[0] + v[1] + v[2] + v[3];
    }
}
