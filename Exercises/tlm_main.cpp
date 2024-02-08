//
// Created by adam on 18.12.23.
//
#include <iostream>
#include <systemc.h>
#include <queue>

using namespace std;

enum cmd {READ, WRITE};

struct transaction {
    unsigned int data;
    unsigned int addr;
    cmd command;
};

class transactionIntercace : public sc_interface {
public:
    virtual void transport (transaction &trans) = 0; //this is the fucntion that the cpu will call when trying to access memory
};

SC_MODULE(PRODUCER) { //CPU
  sc_port< transactionIntercace > master;

    SC_CTOR(PRODUCER)
    {
        SC_THREAD(process);
    }

    void process() {
        //Write process
        for (unsigned int i=0; i < 4; i++) {
            wait(1, SC_NS);
            transaction trans;
            trans.addr = i;
            trans.data = i;
            trans.command = WRITE;
            master->transport(trans);
        }

        //Read process
        for (unsigned int i=0; i < 4; i++) {
            wait(1, SC_NS);
            transaction trans;
            //trans.data = i;
            trans.addr = i;
            trans.command = READ;
            master->transport(trans);
            //cout << trans.data << endl;
        }
    }
};

class CONSUMER : public sc_module, public transactionIntercace {
private:
    unsigned int memory[1024];

public:
    SC_CTOR(CONSUMER) {
        for (unsigned int i=0; i < 1024; i++){
            memory[i] = 0; // initialize memory
        }
    }

    void transport(transaction &trans) {
        if (trans.command == WRITE) {
            memory[trans.addr] = trans.data;
        } else {
            trans.data = memory[trans.addr];
        }
        cout << "@" << sc_time_stamp() << " " << ((trans.command == WRITE) ? "WRITE" : "READ") << endl;
    }
};

int sc_main(int __attribute__((unused)) argc,
            char __attribute__((unused)) *argv[])
{
    PRODUCER cpu ("cpu");
    CONSUMER mem("mem");
    cpu.master.bind(mem);

    sc_start();
    return 0;
}