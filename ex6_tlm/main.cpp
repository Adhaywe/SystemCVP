//
// Created by adam on 23.02.24.
//


#include <iostream>
#include <iomanip>
#include <systemc.h>

#include "memory.h"
#include "processor.h"
#include "bus.h"


int sc_main (int, char **)
{

    // Task1 - one cpu - one memory
    processor * cpu0 = new processor("cpu0", "/home/adam/syc/SystemCVP/ex66/stimuli1.txt", sc_time(1, SC_NS));

    memory<1024> * memory0 = new memory<1024>("memory0");

    //Task2
    processor * cpu1 = new processor("cpu1", "/home/adam/syc/SystemCVP/ex66/stimuli2.txt", sc_time(1, SC_NS));

    memory<1024> * memory1 = new memory<1024>("memory1");

    bus * b = new bus("b");



    //binding
    //cpu0->iSocket.bind(memory0->tSocket); //task1

    //task 2 - 2 cpu - bus - 2 memory blocks
    cpu0->iSocket.bind(b->tSocket[0]);
    cpu1->iSocket.bind(b->tSocket[1]);

    b->iSocket[0].bind(memory0->tSocket);
    b->iSocket[1].bind(memory1->tSocket);






    std::cout << std::endl << "Name "
              << std::setfill(' ') << std::setw(10)
              << "Time" << " "
              << std::setfill(' ') << std::setw(5)
              << "CMD" << "   "
              << std::setfill(' ') << std::setw(8)
              << "Address"
              << "   " << std::hex
              << std::setfill(' ') << std::setw(8)
              << "Data"
              << " " << std::endl
              << "-------------------------------------------"
              << std::endl;

    sc_start();

    std::cout << std::endl;
    return 0;
}
