#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>
#include <string.h>

SC_MODULE(stateMachine)
{
    sc_in <char> input;
    sc_in <bool> clk;
    //char G, A, C, T;

    enum base {Start, G_S, GA, GAA, GAAG};

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