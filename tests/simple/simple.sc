package simple;

module Simple {
    input int intIn;
    output int intOut;
    output int33 incrOut;
    output int1  cmpOut;

    event "relay" (intIn-> msg) {
        intOut <- msg;
    }

    event "incr" (intIn-> msg) {
        incrOut <- msg + 4;
    }

    event "cmp" (intIn-> msg) {
        cmpOut <- (msg == 1) && true;
    }
}
