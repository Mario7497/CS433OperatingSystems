//
// Created by User on 2/5/2020.
//

#include <cstdlib>
#include<time.h>
#include "PCB.h"

PCB::PCB(unsigned int id, unsigned int priority, ProcState state)
: id(id), priority(priority), state(state){

}

PCB::~PCB() {
}

unsigned int PCB::getId() const {
    return id;
}

void PCB::setId(unsigned int id) {
    PCB::id = id;
}

unsigned int PCB::getPriority() const {
    return priority;
}

void PCB::setPriority(unsigned int priority) {
    PCB::priority = priority;
}

ProcState PCB::getState() const {
    return state;
}

void PCB::setState(ProcState state) {
    PCB::state = state;
}


PCBTable::PCBTable(){
    srand(time(0));

    for (int i = 0; i < 30; ++i) {
        //populate PCB table with 30 new PCBs with random priority values
        //and all ProcState initialized to NEW
        table[i] = new PCB(i,rand()%50+1,ProcState::NEW);
    }
}

PCB *PCBTable::getPCB_Element(int index) {
    return table[index];
}
