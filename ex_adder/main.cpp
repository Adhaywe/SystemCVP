//
// Created by adam on 22.02.24.
//
// simple 2 bit full-adder

#include <systemc.h>
#include <iostream>

SC_MODULE(adder) {
    sc_in<bool> a;
    sc_in<bool> b;
    sc_in<bool> cin;
    sc_out<bool> sum;
    sc_out<bool> co;

    SC_CTOR(adder) {
        SC_METHOD(process);
        sensitive << a << b << cin;
    }

    void process() {
        sum.write ( a.read() xor b.read() xor cin.read());
        co.write ((a.read() && b.read()) || ((a.read() xor b.read()) and cin.read()));

    }
};

SC_MODULE(toplevel) {
    sc_signal<bool> A;
    sc_signal<bool> B;
    sc_signal<bool> CIN;
    sc_signal<bool> S;
    sc_signal<bool> CO;

    adder fa;

    SC_CTOR(toplevel): fa("fa") {
        SC_THREAD(stimuli);

        //do binding
        fa.a.bind(A);
        fa.b.bind(B);
        fa.cin.bind(CIN);
        fa.sum.bind(S);
        fa.co.bind(CO);

    }

    void stimuli() {

        //instantiate values
        A.write(1);
        B.write(1);
        CIN.write(1);

        wait(10, SC_NS);

        std::cout << "sum : " << S.read() << "   cout : "  << CO.read() << std::endl;


        A.write(1);
        B.write(0);
        CIN.write(0);

        wait(10, SC_NS);

        std::cout << "sum : " << S.read() << "   cout : "  << CO.read() << std::endl;

    }



};

int sc_main (int, char **) {


    toplevel tp ("tp");

    sc_start();



    return 0;
}
