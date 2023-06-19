#include <iostream>

class Node{
    private:
        int data;
        Node *next;
        friend class CircularLinkedList;

    public: 
        Node(int nodeVal){
            this->data = nodeVal;
            this->next = nullptr;
        }
        Node(): Node(0){}
};

class CircularLinkedList{
    private:
        Node *tail;
        int nNodes = 0;

    public: 
        CircularLinkedList(Node **root): tail{*root}{}

        void insertAtBeginning(int data);
        void insertAtEnd(int data);
        void insertAtIndex(int data, int idx);

        void deleteAtBeginning();
        void deleteAtEnd();
        void deleteAtIndex(int idx);

        int size() const {return nNodes;}

        void traverse();

        bool search(int key); 

        ~CircularLinkedList();
};

//INSERTION OPERATION
void CircularLinkedList::insertAtBeginning(int data){
    Node *buffer = new Node(data);
    if(tail == nullptr){
        tail = buffer;
        tail->next = tail;
    }else{
        buffer->next = tail->next;
        tail->next = buffer;
    }
    nNodes++;
}

void CircularLinkedList::insertAtEnd(int data){
    Node *buffer = new Node(data);
    if(tail == nullptr){
        tail = buffer;
        tail->next = tail;
    }else{
        buffer->next = tail->next;
        tail->next = buffer;
        tail = buffer;
    }
    nNodes++;
}

void CircularLinkedList::insertAtIndex(int data, int idx){
    if(idx == nNodes) insertAtEnd(data);
    else if(idx == 0) insertAtBeginning(data);
    else if(idx > nNodes || idx < 0){
        std::cout<<"Insertion failed: index is out of bounds!\n";
    }else{
        int cnt = 0;
        Node *ptr = tail->next;
        Node *buffer = new Node(data);
        while(cnt != idx-1){
            ptr = ptr->next;
            cnt++;
        }
        buffer->next = ptr->next;
        ptr->next = buffer;
        nNodes++;
    }
}

//DELETION OPERATION
void CircularLinkedList::deleteAtBeginning(){
    if(tail == nullptr){
        std::cout<<"Deletion failed: linked list is empty!\n";
    }else{
        Node *ptr = tail->next;
        tail->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        nNodes--;
    }
}

void CircularLinkedList::deleteAtEnd(){
    if(tail == nullptr){
        std::cout<<"Deletion failed: linked list is empty!\n";
    }else{
        Node *ptr = tail;
        while(tail->next != ptr){
            tail = tail->next;
        }
        tail->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        nNodes--;
    }
}

void CircularLinkedList::deleteAtIndex(int idx){
    if(idx == 0) deleteAtBeginning();
    else if(idx == nNodes-1) deleteAtEnd();
    else if(idx < 0 || idx >= nNodes){
        std::cout<<"Deletion failed: index is out of bounds!\n";
    }else{
        int cnt = 0;
        Node *ptr = tail->next, *preptr = nullptr;
        while(cnt != idx){
            preptr = ptr;
            ptr = ptr->next;
            cnt++;
        }
        preptr->next = ptr->next;
        ptr->next = nullptr;
        delete ptr;
        nNodes--;
    }
}

//SEARCH OPERATION 
bool CircularLinkedList::search(int key){
    Node *temp = tail->next;
    while(temp != tail){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

//DESTRUCTOR
CircularLinkedList::~CircularLinkedList(){
    if(tail != nullptr){ 
        Node *curr = tail->next;
        while(curr != tail){
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        delete tail;
        tail = nullptr;
    }
}

//TRAVERSAL OPERATION
void CircularLinkedList::traverse(){
    Node *temp = tail->next;
    while(temp != tail){
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<temp->data<<"\n";
}