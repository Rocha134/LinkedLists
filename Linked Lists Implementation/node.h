#include <iostream>

class Node {

    private:
        int number;
        Node* after;
      
    public:
        Node();
        Node(int n, Node* a);
        void SetAfter(Node* a);
        Node* GetAfter();
        int GetNum();
};

Node::Node(){
    number = 0;
    after = NULL;
}

Node::Node(int n, Node* a){
    number = n;
    after = a;
}

Node* Node::GetAfter(){
    return after;
}


void Node::SetAfter(Node* a){
    after = a;
}


int Node::GetNum(){
    return number;
}