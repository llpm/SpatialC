package simple;

module Simple {
    input int intIn;
    output int intOut;

    event "relay" (intIn-> msg) {
        intOut <- msg;
    }
}
