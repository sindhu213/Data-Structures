#include <iostream>

class Node{
    private:
        int data;
        Node *next;
        friend class Deque;

    public:
        Node(int nodeVal){
            this->data = nodeVal;
            this->next = nullptr;
        }
        Node() : Node(0) {}
};

class Deque{
    private:
        int sz = 0;
        Node *front, *rear;
        
    public:
        Deque(Node **root): front{*root}, rear{*root}{}
        void push_back(int data);
        void push_front(int data);
        void pop_back();
        void pop_front();
        int size() const {return sz;}
        bool isEmpty();
        void traverse();
        ~Deque();
};

//INSERTION OPERATION
void Deque::push_front(int data){
    Node *buffer = new Node(data);
    if(buffer == nullptr){
        std::cout<<"Insertion failed: unable to allocate memory!\n";
        return;
    }

    if(front == nullptr){
        front = rear = buffer;
    }else{
        buffer->next = front;
        front = buffer;
    }
    sz++;
}

void Deque::push_back(int data){
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
void Deque::pop_front(){
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

void Deque::pop_back(){
    if(isEmpty()){
        std::cout<<"Deletion failed: queue is empty!\n";
    }else if(front == rear){
        delete front;
        front = nullptr;
        rear = nullptr;
    }else{
        Node *ptr = front;
        while(ptr->next != rear){
            ptr = ptr->next;
        }
        delete rear;
        rear = ptr;
        rear->next = nullptr;   
    }
    sz--;
}

//CHECK IF THE QUEUE IS EMPTY
bool Deque::isEmpty(){
    if(rear == nullptr && front == nullptr) return true;
    return false;
}

//TRAVERSAL OPERATION
void Deque::traverse(){
    Node *ptr = front;
    while(ptr != nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<"\n";
}

//DESTRUCTOR
Deque::~Deque(){
    while(front != nullptr){
        Node *ptr = front; 
        front = front->next;
        ptr->next = nullptr;
        delete ptr;   
    }
}