#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "ReadyQueue.h"

int main(int argc, char* argv[]) {
    //Print basic information about the program
    std::cout << "CS 433 Programming assignment 1" << std::endl;
    std::cout << "Author: Mario Rodriguez and Nikki" << std::endl;
    std::cout << "Date: 02/13/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : Program to implement a priority ready queue of processes" << std::endl;
    std::cout << "=================================" << std::endl;

    //These Process IDs are the ones to be loaded into the Priority Queue
    int pcbID[] = {15, 6, 23, 29, 8, 3, 17, 22, 12, 19};

    // TODO: Add your code for Test 1
    std::cout << "Performing Test 1" << std::endl;
    ReadyQueue *q1 = new ReadyQueue();
    PCBTable *pcbTable = new PCBTable();

    for (int i = 0; i < 5; ++i) {
        // Grab PCB element from PCBtable Object at index pcbID[i])+1 and add to queue
        q1->add(pcbTable->getPCB_Element(pcbID[i]));
    }

    std::cout << "End of Test 2" << std::endl;

    // TODO: Add your code for Test 2
    std::cout << "Performing Test 2" << std::endl;

    std::cout << "End of Test 2" << std::endl;
    return 0;
}