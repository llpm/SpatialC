package simple;


module Fifo(
    int Size,
    type Type
) {
    mem Type [Size] buffer;
    reg uint start;
    reg uint end;

    input Type din;
    output Type dout;
    internal void flushLoop;

    init {
        start <- 0;
        end <- 0;
        flushLoop <- void;
    }

    event "din" (din -> data) atomic {
        wait_until ( (end != 0 && start != (end - 1)) ||
                     (end == 0 && start != (Size - 1)) );

        var start = start;
        var startNext = start + 1;
        if (startNext >= Size) {
            startNext = 0;
        }

        xact {
            buffer[start] <- data;
        }
        start <- startNext;
    }

    event "flush" (flushLoop -> *) atomic xact {
        var end = end;
        if (end != start) {
            dout <- buffer[end];
            var endVal = end + 1;
            if (endVal >= Size) {
                endVal = 0;
            }
            end <- endVal;
        }

        flushLoop <- void;
    }
}

module Simple {
    input int din;
    output int dout;

    mod Fifo!(Type=type int, Size=16) fifo;

    connect din -> fifo.din;
    connect fifo.dout -> dout;
}
