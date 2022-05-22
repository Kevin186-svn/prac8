#include "Node.h"
#include <iostream>

Node::Node(){
    data = 0;
    next = NULL;
}

void Node::setData(int data){
    this->data = data;
}

void Node::setNext(Node *next){
    this->next = next;
}

int Node::getData(){
    return data;
}

Node* Node::getNext(){
    return next;
}