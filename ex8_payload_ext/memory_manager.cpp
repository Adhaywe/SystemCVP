#include <iostream>

#include "memory_manager.h"

using namespace std;

MemoryManager::MemoryManager(): numberOfAllocations(0), numberOfFrees(0)
{
}

MemoryManager::~MemoryManager()
{
    for (gp* payload: freePayloads) {
        delete payload;
        numberOfFrees++;
    }
}

gp* MemoryManager::allocate()
{
    if (freePayloads.empty()) {
        numberOfAllocations++;
        return new gp(this);
    } else {
        gp* result = freePayloads.back();
        freePayloads.pop_back();
        return result;
    }
}

void MemoryManager::free(gp* payload)
{
    payload->reset(); //clears all extensions
    freePayloads.push_back(payload);
}