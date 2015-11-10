package simple;

module Simple {
    input void rst;

    input int valIn;
    output int byTwo;

    output int total;
    Accumulator acc;

    connect valIn -> acc.value;
    connect rst -> acc.rst;
    connect acc.total -> total;

    event (valIn -> msg) {
        byTwo <- msg * 2;
    }

}

module Accumulator {
    int acc;

    input int value;
    output int total;

    input void rst;

    event(rst -> msg) {
        acc <- 0;
    }

    event(value -> msg) atomic {
        acc <- acc + msg;
        total <- acc + msg;
    }
}
