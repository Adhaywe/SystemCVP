//
// Created by adam on 27.12.23.
//

#ifndef NAND_H
#define NAND_H

#include <systemc.h>
//the nand module is defined here

SC_MODULE(nand) {
    //define in and out ports
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    //initialize the module
    SC_CTOR(nand): A("A"), B("B"), Z("Z")
    {
        SC_METHOD(do_nand);
        sensitive << A <<  B;
    }
    //define what the module does
    void do_nand() {
        Z.write (!(A.read() && B.read()));
    }

};

#endif //NAND_H
