package simple;


module Buffer (
    int Size,
    int Threshold=0,
    type Type
) {
    mem Type [Size] buffer;
    reg uint start;
    reg uint end;

    input Type din;
    output Type dout;
    input void flush;
    internal void intFlush;

    init {
        start <- 0;
        end <- 0;
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
            start <- startNext;
        }

        var end = end;
        var trueStart = startNext;
        if (end > startNext) {
            trueStart = trueStart + Size;
        }

        //if (trueStart - end >= Threshold) {
            intFlush <- void;
        //}
    }

    event "flush" ((flush | intFlush) -> *) xact atomic {
        var end = end;
        if (end != start) {
            dout <- buffer[end];
            var endVal = end + 1;
            if (endVal >= Size) {
                endVal = 0;
            }
            end <- endVal;
            //intFlush <- void;
        }
    }
}

module Simple {
    input int din;
    input void flush;
    output int dout;

    mod Buffer!(Type=type int, Size=8, Threshold=4) buffer;

    connect din -> buffer.din;
    connect buffer.dout -> dout;
    connect flush -> buffer.flush;
}
