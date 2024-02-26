//
// Created by adam on 24.02.24.
//

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>

#include <tlm.h>

typedef tlm::tlm_generic_payload gp;

class MemoryManager : public tlm::tlm_mm_interface
{
public:
    MemoryManager();
    virtual ~MemoryManager();
    virtual gp* allocate();
    virtual void free(gp* payload);

private:
    unsigned int numberOfAllocations;
    unsigned int numberOfFrees;
    std::vector<gp*> freePayloads;
};

#endif // MEMORY_MANAGER_H
