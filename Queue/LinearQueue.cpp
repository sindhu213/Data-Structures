#include <iostream>

class Node{
    private:
        int data;
        Node *next;
        friend class LinearQueue;

    public:
        Node(int nodeVal){
            this->data = nodeVal;
            this->next = nullptr;
        }
        Node(): Node(0){}
};

class LinearQueue{
    private:
        int sz = 0;
        Node *front, *rear;

    public:
        LinearQueue(Node **head): front{*head}, rear{*head}{}
        void enqueue(int data);
        void dequeue();
        bool isEmpty();
        int size() const {return sz;}
        Node* peek() const {return front;}
        Node* back() const {return rear;}
        void traverse();
       ~LinearQueue(); 
};

//INSERTION OPERATION
void LinearQueue::enqueue(int data){
    Node *buffer = new Node(data);
    if(buffer == nullptr){
        std::cout<<"Insertion failed: unable to allocate memory!\n";
        return;
    }

    if(rear == nullptr){
        front = rear = buffer;
    }else{
        rear->next = buffer;
        rear = buffer;
    }
    sz++;
}

//DELETION OPERATION
void LinearQueue::dequeue(){
    if(isEmpty()){
        std::cout<<"Deletion failed: queue is empty!\n";
    }else{
        Node *ptr = front;
        front = front->next;
        ptr->next = nullptr;
        delete ptr;
    }
    sz--;
}

//CHECK IF THE QUEUE IS EMPTY
bool LinearQueue::isEmpty(){
    if(front == nullptr) return true;
    return false;
}

//TRAVERSAL OPERATION
void LinearQueue::traverse(){
    Node *ptr = front;
    while(ptr != nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<"\n";
}

//DESTRUCTOR
LinearQueue::~LinearQueue(){
    while(front != nullptr){
        Node *ptr = front;
        front = front->next;
        ptr->next = nullptr;
        delete ptr;
    }
}