#include "Node.h"

class LinkedList{
    private:
        Node *head;

    public:
        LinkedList();
        LinkedList(int *arr, int size);
        ~LinkedList();
        void addFront(int newItem);
        void addEnd(int newItem);
        void addAtPosition(int position, int newItem);
        int search(int item);
        void deleteFront();
        void deleteEnd();
        void deletePosition(int position);
        int getItem(int position);
        void printItems();
};