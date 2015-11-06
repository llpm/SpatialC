package simple;

module Simple {
    input int v1;
    output int o;

    event (v1 -> a) {
	o <- a + a;
    }
}
