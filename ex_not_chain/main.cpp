//
// Created by adam on 22.02.24.
//

#include <systemc.h>
#include <iostream>

SC_MODULE(not_gate) {
    sc_in<bool> in;
    sc_out<bool> out;

    SC_CTOR(not_gate) : in("in"), out("out")
    {
        SC_METHOD(process);
        sensitive << in << out ;
    }

    void process() {
        out.write(!(in.read()));
    }
};

SC_MODULE(not_chain) {
    sc_in<bool> IN;
    sc_out<bool> OUT;
    sc_signal<bool> h1;
    sc_signal<bool> h2;

    not_gate n1, n2, n3;


    SC_CTOR(not_chain) : n1("n1"), n2("n2"), n3("n3")
    {
        //binding
        n1.in.bind(IN);
        n1.out.bind(h1);

        n2.in.bind(h1);
        n2.out.bind(h2);

        n3.in.bind(h2);
        n3.out.bind(OUT);
    }

};

SC_MODULE(toplevel) {
    sc_signal<bool> foo;
    sc_signal<bool> bar;

    not_chain nc;

    SC_CTOR(toplevel): nc("nc")
    {
        SC_THREAD(stimulus);
        nc.IN.bind(foo);
        nc.OUT.bind(bar);
    }
    void stimulus() {

        foo.write(1);

        wait(10, SC_NS);

        std::cout << "output : " << bar.read() << std::endl;

        foo.write(0);

        wait(10, SC_NS);

        std::cout << "output : " << bar.read() << std::endl;
    }
};

int sc_main(int, char **) {

    toplevel tp("tp");

    sc_start();
    return 0;
}
