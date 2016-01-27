package simple;

module Simple {

    input int intIn;
    output int intOut;

    reg int counter;

    event "relay" (intIn-> msg) {
        intOut <- msg;
        counter <- counter + 1;
    }
}
