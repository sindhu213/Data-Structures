#include <iostream>

class Node{
    private:
        int data;
        Node *next;
        friend class SinglyLinkedList;
    public:
        Node(int nodeVal){this->data = nodeVal; this->next = nullptr;}
        Node(): Node(0){}
};

class SinglyLinkedList{ 
    private:
        Node *head, *tail;
    public:
        SinglyLinkedList(Node **root): head{*root}{}

        void insertAtEnd(int data);
        void insertAtBeginning(int data);

        void deleteAtEnd();
        void deleteAtBeginning();

        bool search(int key);

        void traverse();
        
        ~SinglyLinkedList();
};

//INSERTION OPEARTION
void SinglyLinkedList::insertAtEnd(int data){
    Node *buffer = new Node(data);
    if(head == nullptr){
        tail = head = buffer;
    }else{
        tail->next = buffer;
        tail = buffer;
    }
}

void SinglyLinkedList::insertAtBeginning(int data){
    Node *buffer = new Node(data);
    buffer->next = head;
    if(head == nullptr) tail = buffer;
    head = buffer;
}

//DELETION OPERATION
void SinglyLinkedList::deleteAtEnd(){
    if(head == nullptr){
        std::cout<<"Linked list is empty!\n";
        return; 
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return; 
    }
    Node *ptr = head, *preptr;
    while(ptr->next != nullptr){
        preptr = ptr;
        ptr = ptr->next;
    }
    delete ptr;
    preptr->next = nullptr;
}

void SinglyLinkedList::deleteAtBeginning(){
    if(head == nullptr){
        std::cout<<"Linked list is empty!\n";
    }

    Node *ptr = head;
    head = head->next;
    delete ptr;
}

//SEARCH OPERATION
bool SinglyLinkedList::search(int key){
    Node *ptr = head;
    while(ptr != nullptr){
        if(ptr->data == key) return true;
        ptr = ptr->next;
    }
    return false;
}

//TRAVERSAL OPERATION
void SinglyLinkedList::traverse(){
    Node *temp = head;
    while(temp != nullptr){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<"\n";
}

//DESTRUCTOR
SinglyLinkedList::~SinglyLinkedList(){
    if(head != nullptr){
        Node *ptr, *preptr = head;
        while(preptr != nullptr){
            ptr = preptr->next;
            delete preptr;
            preptr = ptr;
        }
        head = nullptr;
    }
}