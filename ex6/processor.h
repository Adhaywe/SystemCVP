//
// Created by adam on 05.01.24.
//

#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
#include <random>

#include <systemc.h>
#include <tlm.h>
#include <tlm_utils/tlm_quantumkeeper.h>


class processor : public sc_module, tlm::tlm_bw_transport_if<>
{
private:
    std::ifstream file;
    sc_time cycleTime;

    //last task
#ifdef USEQK
    tlm_utils::tlm_quantumkeeper quantumKeeper;
#endif

    // Method:
    void processTrace();
    void processRandom();

public:
    tlm::tlm_initiator_socket<> iSocket;  //iSocket was empty

    processor(sc_module_name, std::string pathToTrace, sc_time cycleTime);

    SC_HAS_PROCESS(processor);


    //last task
#ifdef USEQK
    quantumKeeper.set_global_quantum(sc_time(100000,SC_NS)); // STATIC!
        quantumKeeper.reset();
#endif

    // Dummy method:
    void invalidate_direct_mem_ptr(sc_dt::uint64, sc_dt::uint64)
    {
        SC_REPORT_FATAL(this->name(), "invalidate_direct_mem_ptr not implement");
    }

    // Dummy method:
    tlm::tlm_sync_enum nb_transport_bw(tlm::tlm_generic_payload &,tlm::tlm_phase &, sc_time &)
    {
        SC_REPORT_FATAL(this->name(), "nb_transport_bw is not implemented");
        return tlm::TLM_ACCEPTED;
    }
};

processor::processor(sc_module_name, std::string pathToFile, sc_time cycleTime) :
        file(pathToFile), cycleTime(cycleTime)
{
    if (!file.is_open())
        SC_REPORT_FATAL(name(), "Could not open trace");

    SC_THREAD(processTrace);
    //SC_THREAD(processRandom); //commented for the last task

    iSocket.bind(*this); //no 0 before
    //iSocket[1].bind(*this); //added line

}

// Use the command below in a terminal to get your gcc version.
// $ gcc --version
// If it is less than 4.9 uncomment the definition that follows.
// #define GCC_LESS_THAN_4_9_DOES_NOT_SUPPORT_REGEX

void processor::processTrace()
{
#ifdef LONG_RUN
    for (int j = 0; j < 100000; j++)
#endif
    for (int i = 0; i < 1024; i++) {
        tlm::tlm_generic_payload trans;
        unsigned char data = rand();
        trans.set_address(i);
        trans.set_data_length(1);
        trans.set_streaming_width(1);
        trans.set_command(tlm::TLM_WRITE_COMMAND);
        trans.set_data_ptr(&data);
        trans.set_response_status( tlm::TLM_INCOMPLETE_RESPONSE );
#ifdef USEQK
        sc_time delay = quantumKeeper.get_local_time();
#else
        sc_time delay = SC_ZERO_TIME;
#endif

#ifdef PRINTING
        cout << this->name() << ": B_TRANSPORT @" << sc_time_stamp()
                 << " Local Time " << quantumKeeper.get_local_time() << endl;
#endif
        iSocket->b_transport(trans, delay);
        if ( trans.is_response_error() )
            SC_REPORT_FATAL(name(), "Response error from b_transport");

#ifdef USEQK
        quantumKeeper.set(delay); // Anotate the time of the target
            quantumKeeper.inc(sc_time(10,SC_NS)); // Consume computation time
#else
        wait(delay+sc_time(10,SC_NS));
#endif

#ifdef USEQK
        if(quantumKeeper.need_sync())
            {
#ifdef PRINTING
                cout << this->name() << ": Context Switch @"
                     << sc_time_stamp() << endl;
#endif
                quantumKeeper.sync();
            }
#endif
    }
}


    // End Simulation because there are no events.


void processor::processRandom()
{
    wait(SC_ZERO_TIME);

    tlm::tlm_generic_payload trans;

    uint64_t cycles;
    uint64_t address;
    unsigned char data[4];

    std::default_random_engine randGenerator;
    std::uniform_int_distribution<uint64_t> distrCycle(0, 99);
    std::uniform_int_distribution<uint64_t> distrAddr(0, 1023);

    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
    data[3] = 0;

    trans.set_data_length(4);
    trans.set_command(tlm::TLM_WRITE_COMMAND);
    trans.set_data_ptr(data);

    for (uint64_t transId = 0; transId < 100000000; transId++)
    {
        cycles = distrCycle(randGenerator);
        address = distrAddr(randGenerator);

        sc_time delay;

        if (sc_time_stamp() <= cycles * cycleTime)
        {
            delay = cycles * cycleTime - sc_time_stamp();
        }
        else
        {
            delay = SC_ZERO_TIME;
        }

        trans.set_address(address);
        iSocket->b_transport(trans, delay);
        //iSocket[0]->b_transport(trans, delay);
        //iSocket[1]->b_transport(trans, delay);

        wait(delay);
    }

    // End Simulation because there are no events.
}

#endif // PROCESSOR_H
