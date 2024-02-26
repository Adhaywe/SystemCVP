//
// Created by adam on 27.12.23.
//

#include "nand.h"

//a module to test the nand gate
SC_MODULE(toplevel) {
private:
    nand n1;
    unsigned int cnt;
    sc_signal<bool> A_sig;
    sc_signal<bool> B_sig;
    sc_signal<bool> Z_sig;

public:
    //initialize the toplevel module
    SC_CTOR(toplevel) : n1("n1"), cnt(0)
    {
        //do binding;
        n1.A.bind(A_sig);
        n1.B.bind(B_sig);
        n1.Z.bind(Z_sig);

        SC_METHOD(process);
        sensitive << A_sig << B_sig << Z_sig;
        //I can add this line so that I can change them in the process fun from the first line
        //A_sig.write(true);
        //B_sig.write(true);
    }

    //give the test numbers
    void process() {
        //counter tells us how many times this process is called
        cnt++;

        // Question:
        //  - Does this action make any difference? Why?
        // No it does not matter because the process is only called when there is a change
        // in the values of the signals, therefore this first line is usually ignored

        A_sig.write(false);
        B_sig.write(false);


       std::cout << "SC_METHOD process() trigger counter " << cnt << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << (A_sig.read() ? "'1'" : "'0'") << " B " << (B_sig.read() ? "'1'" : "'0'") << " Z " << (Z_sig.read() ? "'1'" : "'0'") << std::endl;
       // std::cout << "SC_METHOD process() trigger counter " << cnt << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << A_sig.read()  << " B " << B_sig.read()  << " Z " << Z_sig.read()  << std::endl;



        A_sig.write(true);
        B_sig.write(false);

        std::cout << "SC_METHOD process() trigger counter " << cnt << " simulation time " << sc_time_stamp().to_default_time_units() << " ps Δ cycle " << sc_delta_count() << ":\tA " << (A_sig.read() ? "'1'" : "'0'") << " B " << (B_sig.read() ? "'1'" : "'0'") << " Z " << (Z_sig.read() ? "'1'" : "'0'") << std::endl;


        //A_sig.write(false);
        //B_sig.write(true);
        //A_sig.write(true);
        //B_sig.write(false);
        //A_sig.write(false);
        //B_sig.write(true);


        //These lines are setting the values of A_sig and B_sig multiple times without
        // giving the simulation time to propagate changes.
        // You can leave only the initial values you set during the construction of the toplevel module.

        // REMEMBER, a process runs once during the initialization phase
        // (unless the function dont_initialize() is used to avoid it). Later
        // it will be triggered by events in the sensitivity list.
        //This is why the output is repeated for each test input

        // Questions:
        //  - How these write to A and B affect Z?
        // whenever there is a change in the value of A or B then the output Z will be computed.
        //  - Is the process triggered when Z changes?
        // yes because the signal z is in our sensitivity list
        //  - Are some of the writes to A and B ignored?
        // yes because we are not giving the signals enough time to propagate, there will be no change
        // in the output for the last lines
    }
};

//int sc_main(int argc, char* argv[]) {
//    toplevel tb("test");
//
//    sc_start();
//    return 0;
//
//}
