package simple;

struct Foo {
    int a;
    int b;
}

module Simple {
    input Foo fooIn;
    output int sumOut;

    event "adder" (fooIn -> msg) {
        sumOut <- msg.a + msg.b;
    }
}
