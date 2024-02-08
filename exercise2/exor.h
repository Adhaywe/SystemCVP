//
// Created by adam on 26.11.23.
//

#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>
#include "nand.h"

SC_MODULE(exor) {

    SC_CTOR(exor) : n("n")
    {
        n.A(a);
        n.B(b);
        n.Z(h1);
        SC_METHOD(proc);
        sensitive << a << b << h1 << h2 << h3 << f;

    }

    nand n;
    sc_in<bool>a;
    sc_in<bool>b;
    sc_out<bool>f;
    sc_signal<bool> h1;
    sc_signal<bool> h2;
    sc_signal<bool> h3;

    void proc() {
           // h1.write(!( a.read() && b.read()));
            h2.write(!( h1.read() && a.read()));
            h3.write(!( h1.read() && b.read()));
            f.write(!( h2.read() && h3.read()));
    }
};


#endif //_EXOR_H
