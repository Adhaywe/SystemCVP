//
// Created by adam on 26.11.23.
//
#include "nand.h"

SC_MODULE(test) {

private:
    nand n1;
    unsigned int cnt;

    sc_signal<bool>A_sig;
    sc_signal<bool>B_sig;
    sc_signal<bool>Z_sig;

public:
    SC_CTOR(test) : n1("n1"), cnt(0)
    {

        n1.A(A_sig);
        n1.B(B_sig);
        n1.Z(Z_sig);

        SC_METHOD(process);
        sensitive << A_sig << B_sig << Z_sig;
    }


    void process() {
        A_sig.write(true);
        B_sig.write(true);

        cnt++;

        std::cout << "----------" << std::endl;
        std::cout << "Z: " << Z_sig.read() << std::endl;
        std::cout << "SC_METHOD process() trigger counter = " << cnt <<  std::endl;
        std::cout << "----------" << std::endl;
    }
};


//int sc_main (int argc, char* argv[]) {
  //  test tb("test");
    //sc_start();
    //return 0;
//}