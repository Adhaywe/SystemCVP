//
// Created by adam on 27.12.23.
//

#ifndef EXOR_H
#define EXOR_H

#include "nand.h"

SC_MODULE(exor) {
    //call the defined nand module
    nand na, nb, nc ,nd;
    //define helping signals
    sc_signal<bool> h1, h2, h3;
    sc_in <bool> a, b;
    sc_out <bool> f;


    SC_CTOR(exor) : na("na"), nb("nb"), nc("nc"), nd("nd"), a("a"), b("b"), f("f"),
                   h1("h1"), h2("h2"), h3("h3")
    {
       // SC_METHOD(process);
        na.A.bind(a);
        na.B.bind(b);
        na.Z.bind(h1);

        nb.A(h1);
        nb.B(b);
        nb.Z(h3);

        nc.A(a);
        nc.B(h1);
        nc.Z(h2);

        nd.A(h2);
        nd.B(h3);
        nd.Z(f);
        sensitive << a << b << h1 << h2 << h3 ;
    }

};


#endif //EXOR_H