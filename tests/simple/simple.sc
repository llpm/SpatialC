package simple;

module Simple {
    input void rst;

    input int intIn;
    input int dummy;
    output int intOut;
    output int33 incrOut;
    output int1  cmpOut;

    int counter;

    event "reset" (rst -> msg) {
        counter <- 0;
    }

    event "relay" (intIn-> msg) {
        intOut <- msg;
        counter <- 1;
    }

    event "incr" (intIn-> msg) {
        incrOut <- msg + 4;
    }

    event "cmp" ((dummy | intIn) -> msg) {
        cmpOut <- (msg == 1) && true;
    }
}
