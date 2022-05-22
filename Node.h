class Node{
    private:
        int data;
        Node *next;

    public:
        Node();
        void setData(int data);
        void setNext(Node *next);
        int getData();
        Node* getNext();
};