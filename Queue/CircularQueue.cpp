#include <iostream>
#define MAX_SIZE 5

class CircularQueue{
    private:
        int queue[MAX_SIZE] = {0};
        int front, rear, sz=0;

    public:
        CircularQueue(): front{-1},rear{-1}{}
        void enqueue(int data);
        void dequeue();
        int size() const {return sz;}
        void traverse();
        bool isEmpty();
};

//INSERTION OPERATION
void CircularQueue::enqueue(int data){
    if(((front == 0) && (rear == MAX_SIZE-1)) || (front == rear + 1)){
        std::cout<<"Insertion failed: queue is full!\n";
        return;
    }

    if(rear == -1){
        front = rear = 0;
    }else if(rear == MAX_SIZE-1){
        rear = 0;
    }else{
        rear++;
    }
    queue[rear] = data;
    sz++;
}

//DELETION OPERATION
void CircularQueue::dequeue(){
    if(isEmpty()){
        std::cout<<"Deletion failed: queue is empty!\n";
        return;
    }

    queue[front] = 0;
    if(front == rear){
        front = rear = -1;
    }else if(front == MAX_SIZE-1){
        front = 0;
    }else{
        front++;
    }
    sz--;
}

//CHECK IF THE QUEUE IS EMPTY
bool CircularQueue::isEmpty(){
    if(front == -1) return true;
    return false;
}

//TRAVERSAL OPERATION
void CircularQueue::traverse(){
    for(int i=0;i<MAX_SIZE;i++){
        if(queue[i] != 0){
            std::cout<<queue[i]<<" ";
        }
    }
    std::cout<<"\n";
}