//
// Created by User on 2/5/2020.
//

#include <iostream>
#include "ReadyQueue.h"

ReadyQueue::ReadyQueue() {
    size = 0;
}

void ReadyQueue::add(PCB *pcbPtr) {
    if (size == 0) {
        //if the size is zero, create new node and pass itself to be the head and tail
        Node *tmp = new Node(pcbPtr,tmp,tmp);
    } else {
        //If the size is not zero then make the tail point to this node and set this
        //node as the new tail
        Node *tmp = new Node(pcbPtr, nullptr, tail);
        tail->next = tmp;
    }
    size++;
}

PCB *ReadyQueue::removeHighest() {
    return nullptr;
}

void ReadyQueue::display() {
    Node *tmp = head;
    while ( tmp != nullptr) {
        std::cout << tmp->data->id;
    }
}

int ReadyQueue::getSize(){
    return size;
}
