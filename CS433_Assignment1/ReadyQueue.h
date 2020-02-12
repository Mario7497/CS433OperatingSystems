//
// Created by User on 2/5/2020.
//

#ifndef CS433_ASSIGNMENT1_READYQUEUE_H
#define CS433_ASSIGNMENT1_READYQUEUE_H


#include "PCB.h"

/**
 * ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue here uch that the process with the highest priority
 * can be selected next.
 */
class ReadyQueue {
private:
public:
    int getSize() const;

    void setSize(int size);

private:
    int size; //Size of the queue

    class Node { // private inner class Node for the linked list
    public:
        PCB *data;
        Node *next, *previouse;

        Node(PCB *tempData, Node *nextNode, Node *previousNode){
            data = tempData;
            next = nextNode;
            previouse = previousNode;
        }
    };

    Node *head = nullptr, *tail= nullptr;

public:
    // Constructor
    ReadyQueue();

    // TODO: Implement the required functions. Add necessary member fields and functions
    // You may use different parameter signatures from the example below

    // add a PCB representing a process into the ready queue.
    void add(PCB* pcbPtr);

    // remove and return the PCB with the highest priority from the queue
    PCB* removeHighest();

    //Size of the queue
    int getSize();

    // Prints the queue contents to standard output.
    void display();

};


#endif //CS433_ASSIGNMENT1_READYQUEUE_H
