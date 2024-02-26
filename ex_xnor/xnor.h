//
// Created by adam on 22.02.24.
//

#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor) {
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;
    sc_signal<bool> h1;
    sc_signal<bool> h2;
    sc_signal<bool> h3;
    sc_signal<bool> h4;

    nand n1, n2, n3, n4, n5;

    SC_CTOR(exor): n1("n1"), n2("n2"), n3("n3"), n4("n4"), n5("n5"), A("A"), B("B"), Z("Z"), h1("h1"), h2("h2"), h3("h3"), h4("h4")
    {
        n1.A.bind(A);
        n1.B.bind(B);
        n1.Z.bind(h1);

        n2.A.bind(A);
        n2.B.bind(h1);
        n2.Z.bind(h2);

        n3.A.bind(h1);
        n3.B.bind(B);
        n3.Z.bind(h3);

        n4.A.bind(h2);
        n4.B.bind(h3);
        n4.Z.bind(h4);

        n5.A.bind(h4);
        n5.B.bind(h4);
        n5.Z.bind(Z);

    }
};

#endif // EXOR_H