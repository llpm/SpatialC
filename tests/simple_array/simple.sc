package simple;

struct Write {
    int idx;
    int val;
}

module Simple {
    input Write wreq;

    input int rreq;
    output int rresp;

    int[25] array;

    event (wreq -> r) {
        array[r.idx] <- r.val;
    }

    event (rreq -> r) {
        rresp <- array[r];
    }
}
