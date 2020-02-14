#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <vector>
#include "ReadyQueue.h"

/*
 * Use  "-g"  compilation flag for g++ when debugging your program
 * and "-O2" or "-O3" to generate optimized code for timing in test2
 */

void getRandomPCBs(ReadyQueue *q, PCBTable *table);

int main(int argc, char* argv[]) {
    //Print basic information about the program
    std::cout << "CS 433 Programming assignment 1" << std::endl;
    std::cout << "Author: Mario Rodriguez and Nikki" << std::endl;
    std::cout << "Date: 02/13/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
    std::cout << "=================================" << std::endl;

    //These Process IDs are the ones to be loaded into the Priority Queue
    int pcbIDs[] = {15, 6, 23, 29, 8, 3, 17, 22, 12, 19};
    ReadyQueue *q1 = new ReadyQueue();
    ReadyQueue *q2 = new ReadyQueue();
    PCBTable *pcbTable1 = new PCBTable();
    PCBTable *pcbTable2 = new PCBTable();
    pcbTable1->initializeSeq();
    pcbTable2->initializeRand();

    // TODO: Add your code for Test 1
    std::cout << "Performing Test 1" << std::endl;


    for (int i = 0; i < 5; ++i) {
        // Grab PCB element from PCBtable Object at index pcbID[i])+1 and add to queue
        q1->add(pcbTable1->getPCB_Element(pcbIDs[i]));
    }
    q1->display();

    std::cout << "End of Test 1" << std::endl;

    // TODO: Add your code for Test 2
    std::cout << "Performing Test 2" << std::endl;
    //Initialize the test with 30 using getRandomPCBs
    getRandomPCBs(q2, pcbTable2);
    std::cout << "Queue 2 before test 2 starts" << std::endl;
    q2->display();


    std::cout << "End of Test 2" << std::endl;
    return 0;
}

void getRandomPCBs(ReadyQueue *q, PCBTable *table) {
    srand(time(0));
    std::vector<int> processIDs(30);
    int index;
    PCB *pcb;

    for (int i = 0; i < 30; ++i) {
        processIDs.push_back(i);
    }
    for (int j = 0; j < 15; ++j) {
        index = rand()%processIDs.size();
        pcb = table->getPCB_Element(index);
        pcb->setState(ProcState::READY);
        q->add(pcb);
        processIDs.erase(processIDs.begin() + index);
    }
}