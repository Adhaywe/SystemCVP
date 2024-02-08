//
// Created by adam on 26.11.23.
//
// exercise2-nand gate

#ifndef NAND_H
#define NAND_H
#include <systemc.h>

//define the module's name and its terminals
SC_MODULE(nand) {
    sc_in<bool> A;
    sc_in<bool> B;
    sc_out<bool> Z;

    //define the process
    void do_nand() {

        Z.write(!( A.read() && B.read()));
    }

   //initialize the module
    SC_CTOR(nand){
        SC_METHOD(do_nand);
        sensitive << A << B ;
    }
};

#endif //NAND_H
