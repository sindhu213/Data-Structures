#include <iostream>

class Node{
    private:
        char data;
        int priority;
        Node *next;
        friend class PriorityQueue;

    public:
        Node(char nodeVal, int weight){
            this->data = nodeVal;
            this->priority = weight;
            this->next = nullptr;
        }
        Node(): Node(' ',0){}
};

class PriorityQueue{
    private:
        int sz = 0;
        Node *front;
    
    public: 
        PriorityQueue(Node **head): front{*head}{}
        void enqueue(char data, int weight);
        void dequeue();
        bool isEmpty();
        int size() const {return sz;}
        Node* peek() const {return front;}
        void traverse();
        ~PriorityQueue();
};

//INSERTION OPERATION
void PriorityQueue::enqueue(char data, int weight){
    Node *buffer = new Node(data,weight);
    int idx = 0;
    if(buffer == nullptr){
        std::cout<<"Insertion failed: unable to allocate memory!\n";
        return;
    }
    if(front == nullptr){
        front = buffer;
        return;
    }

    //find the ideal position for insertion
    Node *ptr = front, *preptr;
    while(ptr != nullptr){
        if(ptr->priority < weight) break;
        preptr = ptr;
        ptr = ptr->next;
        idx++;
    }

    //reassign the pointers
    if(idx == 0){
        buffer->next = front;
        front = buffer;
    }else{
        buffer->next = preptr->next;
        preptr->next = buffer;
    }
}

//DELETION OPERATION
void PriorityQueue::dequeue(){
    if(isEmpty()){
        std::cout<<"Deletion failed: queue is empty!\n";
    }else{
        Node *ptr = front;
        front = front->next;
        ptr->next = nullptr;
        delete ptr;
    }
}

//CHECK IF THE QUEUE IS EMPTY
bool PriorityQueue::isEmpty(){
    if(front == nullptr) return true;
    return false;
}

//TRAVERSAL OPERATION
void PriorityQueue::traverse(){
    Node *ptr = front;
    while(ptr != nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<"\n";
}


//DESTRUCTOR 
PriorityQueue::~PriorityQueue(){
    while(front != nullptr){
        Node *ptr = front;
        front = front->next;
        ptr->next = nullptr;
        delete ptr;
    }
}