
#include <iostream>

#include "state_machine.h"

void stateMachine::process() {
    char currentSymbol = input.read();

    switch(currentState) {
        case Start:
            if (currentSymbol == 'G') {
                currentState = G_s;
            }
            else if (currentState == 'A' || currentState == 'C' || currentState == 'T' ) {
                currentState = Start;
            }

            break;


        case G_s:

            if (currentSymbol == 'A') {
                currentState = GA;
            } else if (currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            } else if (currentSymbol == 'G') {
                currentState = G_s;
            }
            break;

        case GA:
            if (currentSymbol == 'A') {
                currentState = GAA;
            } else if (currentSymbol == 'G') {
                currentState = G_s;
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
                currentState = G_s;
            } else if (currentSymbol == 'A' || currentSymbol == 'C' || currentSymbol == 'T') {
                currentState = Start;
            }
            break;

        default:
            break;
    }

}
