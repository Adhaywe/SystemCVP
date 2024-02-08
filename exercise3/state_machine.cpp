#include <iostream>

#include "state_machine.h"


void stateMachine::process() {

    char currentSymbol = input.read();


    switch (currentState) {
        case Start:
            //std::cout << "We are in state: " << currentState << std::endl;
            if (currentSymbol == 'G') {
                currentState = G_S;
            } else if (currentSymbol == 'A' || currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            }
            break;

        case G_S:

            if (currentSymbol == 'A') {
                currentState = GA;
            } else if (currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            } else if (currentSymbol == 'G') {
                currentState = G_S;
            }
            break;

        case GA:
            if (currentSymbol == 'A') {
                currentState = GAA;
            } else if (currentSymbol == 'G') {
                currentState = G_S;
            } else if (currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            }
            break;

        case GAA:

            if (currentSymbol == 'G') {
                currentState = GAAG;
            } else if (currentSymbol == 'A' || currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            }
            break;

        case GAAG:
            std::cout << "We are in state GAAG !" << std::endl;
            if (currentSymbol == 'G') {
                currentState = G_S;
            } else if (currentSymbol == 'A' || currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            }
            break;

        default:
            break;
    }
}
