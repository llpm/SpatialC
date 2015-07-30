package grammar.example;
import somthing.else5;

module _aMod1 {
    int32 i;
    int7 i7;
    TstObj o;

    input double inDouble;
    input float inFloat;
    input bool inBool;
    output bool outBool;

    event (inFloat -> msg) atomic {
        float msgCopy = msg;
        if (msgCopy > 0.0) {
            outBool <- true;
            i = i + 1;
        } else {
            //outBool <- msg.bits()[0];
            i = i - (1 * 2 / 2);
        }
    }

    event ((inDouble | inFloat) -> nMsg,
           inBool -> bMsg) {
    }
}

struct Coord {
    int x;
    int y;

    bool isZero() {
        return x == 0 && y == 0;
    }

    void set(int _x, int _y) {
        x = _x;
        y = _y;
    }
}

module _1Mod2 { 
}
