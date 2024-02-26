//
// Created by adam on 22.02.24.
//

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

SC_MODULE(stateMachine) {
    sc_in<char> input;
    sc_in<bool> clk;

    enum base {Start, G_s, GA, GAA, GAAG, GAAA, GAAAG, GAAAA, GAAAAG};

    base currentState = Start;

    SC_CTOR(stateMachine) : currentState(Start)
    {
        SC_METHOD(process);
        sensitive << clk.pos();
        dont_initialize();
    }

    void process();
};

#endif // STATE_MACHINE_H
