//
// Created by User on 2/5/2020.
//

#include <iostream>
#include "ReadyQueue.h"

ReadyQueue::ReadyQueue() {
    size = 0;
}

void ReadyQueue::add(PCB *pcbPtr) {

    pcbPtr->setState(ProcState::READY);
    if (size == 0) {
        //if the size is zero, initialize the head with data and make it point to itself
        Node *tmp = new Node(pcbPtr, nullptr, nullptr);
        head = tmp;
        tail = tmp;

    } else {
        //If the size is not zero then make the tail point to this node and set this
        //node as the new tail
        Node *tmp = new Node(pcbPtr, nullptr, nullptr);
        if (tmp->data->getPriority() < tail->data->getPriority()) {
            // This case is when the new PCB is the least important and adds it
            // to the tail
            tail->next = tmp;
            tmp->previous = tail;
            tail = tmp;
        } else if (tmp->data->getPriority() > head->data->getPriority()) {
            // This case is when the new PCB is the most important and adds it
            // to the front of the linked list
            head->previous = tmp;
            tmp->next = head;
            head = tmp;
        } else {
            // If neither of the cases are true then we're going to have to insert somewhere
            // in the middle of the linked list
            Node *right = head;
            Node *left;
            while (tmp->data->getPriority() < right->data->getPriority()) {
                right = right->next;
            }
            left = right->previous;
            tmp->next = right;
            tmp->previous = left;
            left->next = tmp;
            right->previous = tmp;
        }
    }
    size++;
}

PCB *ReadyQueue::removeHighest() {
    if (size == 0) {
        std::cout << "Queue is empty, returning nullptr" << std::endl;
        return nullptr;
    }
    Node *tmp = head;
    head = head->next;
    head->previous = nullptr;
    size--;

    // Set state of process to running before returning the process pointer
    tmp->data->setState(ProcState::RUNNING);
    return tmp->data;
}

void ReadyQueue::display() {
    Node *tmp = head;
    while ( tmp != nullptr) {
        std::cout << "Process: "<< tmp->data->id;
        std::cout << " Priority: " << tmp->data->priority;
        std::cout << " State: " << tmp->data->getStateAsString() << std::endl;
        tmp = tmp->next;
    }
}

int ReadyQueue::getSize(){
    return size;
}

bool ReadyQueue::hasElement(PCB *pcbptr) {
    Node *tmp = head;

    return false;
}
