#include "LinkedList.h"
#include <limits>
#include <iostream>
using namespace std;

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::LinkedList(int *arr, int size){
    //construct the first node
    addFront(arr[0]);
    Node *tmp = head;

    for(int i = 1; i < size; i++){
        Node *node = new Node();
        node->setData(arr[i]);
        node->setNext(NULL);
        tmp->setNext(node);
        tmp = node;
    }
}

LinkedList::~LinkedList(){
    Node *tmp = head, *preTmp = head;
    while(tmp){
        preTmp = tmp;
        tmp = tmp->getNext();
        delete(preTmp);
    }
    delete(tmp);
}

// insert a new node, containing the newItem, at the beginning of the list
void LinkedList::addFront(int newItem){
    Node *newNode = new Node();
    newNode->setData(newItem);
    newNode->setNext(head);
    head = newNode;
}

// insert a new node, containing the newItem, at the end of the list
void LinkedList::addEnd(int newItem){
    Node *newNode = new Node();
    newNode->setData(newItem);
    newNode->setNext(NULL);

    Node *tmp = head;
    // find the last node
    while(tmp->getNext())
        tmp = tmp->getNext();
    tmp->setNext(newNode);
}

// insert a new node, containing the newItem, such that it is the posi!on-th member of the list
void LinkedList::addAtPosition(int position, int newItem){
    if(position <= 1)
        addFront(newItem);
    else{
        int size = 0;
        Node *tmp = head, *preTmp = head;
        while(tmp){
            size += 1;

            if(size == position){
                Node *newNode = new Node();
                newNode->setData(newItem);
                newNode->setNext(tmp);
                preTmp->setNext(newNode);
            }
            preTmp = tmp;
            tmp = tmp->getNext();
        }

        if(position > size)
            addEnd(newItem);
    }
}

// search the list for the first instance of the item
int LinkedList::search(int item){
    int pos = 0, size = 0;
    Node *tmp = head;
    // search
    while(tmp){
        size += 1;

        if(tmp->getData() == item){
            cout << size << " ";
            pos = size;
        }
        
        tmp = tmp->getNext();
    }
    // not found
    if(pos == 0){
        cout << 0 << " ";
    }
    return pos;
}

// delete the first element of the list
void LinkedList::deleteFront(){
    Node *tmp = head;
    head = head->getNext();
    delete tmp;
}

// delete the last element of the list
void LinkedList::deleteEnd(){
    Node *tmp = head, *preTmp = head;
    // find the last two nodes
    while(tmp->getNext()){
        preTmp = tmp;
        tmp = tmp->getNext();
    }
    preTmp->setNext(NULL);
    delete tmp;
}

// delete the element at the given posi!on of the list.
void LinkedList::deletePosition(int position){
    if(position < 1)
        cout << "outside range" << endl;
    else{
        int size = 0;
        Node *tmp = head, *preTmp = head;
        while(tmp){
            size += 1;

            // delete
            if(size == position)
                preTmp->setNext(tmp->getNext());
            
            preTmp = tmp;
            tmp = tmp->getNext();
        }

        if(position > size)
            cout << "outside range" << endl;
    }
}

// print the value of the item (followed by a space) and returns the value of the item at the given posi!on of the list
int LinkedList::getItem(int position){
    int result = 0;
    if(position < 1){
        cout << std::numeric_limits < int >::max() << " ";
        result = std::numeric_limits < int >::max();
    }
    else{
        int size = 0;
        Node *tmp = head;
        // search
        while(tmp){
            size += 1;

            if(size == position){
                cout << tmp->getData() << " ";
                result = tmp->getData();
            }
            
            tmp = tmp->getNext();
        }
        // beyond the size of the array
        if(position > size){
            cout << std::numeric_limits < int >::max() << " ";
            result = std::numeric_limits < int >::max();
        }
    }
    return result;
}

// print the value of the items of the list from head to tail
void LinkedList::printItems(){
    Node *tmp = head;
    while(tmp){
        cout << tmp->getData() << ' ';
        tmp = tmp->getNext();
    }
}