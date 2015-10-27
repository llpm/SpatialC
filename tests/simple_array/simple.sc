package simple;

struct Write {
    int idx;
    int val;
}

struct sumPartial {
    int idx;
    int sum;
}

module Simple {
    input Write wreq;

    input int rreq;
    output int rresp;

    input void sumReq;
    internal sumPartial sumP;
    output int sum;

    int[25] array;

    event (wreq -> r) {
        array[r.idx] <- r.val;
    }

    event (rreq -> r) {
        rresp <- array[r];
    }

    event "sumStart" (sumReq -> r) {
        sumP <- sumPartial {idx: 0, sum: 0};
    }

    event "sum" (sumP -> r) {
        if (r.idx >= 25) {
            sum <- r.sum;
        } else {
            sumP <- sumPartial {
                idx: r.idx + 1,
                sum: r.sum + array[r.idx]
            };
        }
    }
}
