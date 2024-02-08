//
// Created by adam on 24.12.23.
//

#include <iostream>
#include <systemc.h>
#include <queue>
#include <tlm.h>


using namespace std;
using namespace tlm;

class INITIATOR: sc_module, tlm::tlm_bw_transport_if<> {
public:
    tlm::tlm_initiator_socket<> iSocket;

};

int sc_main(int __attribute__((unused)) argc,
            char __attribute__((unused)) *argv[])
{

    sc_start();
    return 0;
}