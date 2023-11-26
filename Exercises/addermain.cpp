/*
 * 1-bit adder design in systemc
 * 24.11.2023 RPTU
 */

#include <systemc.h>

SC_MODULE(Adder) {

    sc_in<sc_logic> a, b, cin;
    sc_out<sc_logic> cout, sum;

    void compute() {
        sc_logic tempc, tempd, tempe;
        tempc = a.read() & b.read();
        tempd = a.read() ^ b.read();
        tempe = tempd & cin.read();
        sum.write(tempd ^ cin);
        cout.write(tempc | tempe);
    }

    SC_CTOR(Adder){

        SC_METHOD(compute);
        sensitive << a << b << cin;
    }
};

//this is a module that binds the variables of out testbench to the design
SC_MODULE(test) {
    sc_signal<sc_logic> a_sig, b_sig, cin_sig;
    sc_signal<sc_logic> cout_sig, sum_sig;
    Adder tb;

    SC_CTOR(test) : tb("tb") {
        SC_THREAD(process);
        tb.a(a_sig);
        tb.b(b_sig);
        tb.cin(cin_sig);
        tb.cout(cout_sig);
        tb.sum(sum_sig);
    }


    //Here we test our design
    void process() {


        a_sig.write(SC_LOGIC_0);
        b_sig.write(SC_LOGIC_0);
        cin_sig.write(SC_LOGIC_0);
        wait(100, SC_NS);
        std::cout << "----------" << std::endl;
        std::cout << "Sum: " << sum_sig.read() << std::endl;
        std::cout << "Cout:" << cout_sig.read() << std::endl;
        std::cout << "----------" << std::endl;



        a_sig.write(SC_LOGIC_1);
        b_sig.write(SC_LOGIC_1);
        cin_sig.write(SC_LOGIC_1);
        wait(100, SC_NS);

        std::cout << "Sum: " << sum_sig.read() << std::endl;
        std::cout << "Cout:" << cout_sig.read() << std::endl;
        std::cout << "----------" << std::endl;



        a_sig.write(SC_LOGIC_0);
        b_sig.write(SC_LOGIC_1);
        cin_sig.write(SC_LOGIC_1);
        wait(100, SC_NS);
        std::cout << "Sum: " << sum_sig.read() << std::endl;
        std::cout << "Cout:" << cout_sig.read() << std::endl;
        std::cout << "----------" <<  std::endl;


    }
};


int sc_main(int argc, char *argv[]) {

    test t("t");
    sc_start();
    return 0;
}