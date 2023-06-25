#include <iostream>

class Node{
    private:
        int data;
        Node *prev, *next;
        friend class DoublyLinkedList;
        
    public:
        Node(int nodeVal){
            this->data = nodeVal;
            this->prev = this->next = nullptr;
        }
        Node(): Node(0){};
};


class DoublyLinkedList{
    private:
        int nNodes = 0;
        Node *head, *tail;

    public:
        DoublyLinkedList(Node **front, Node **rear)
            :head(*front), tail(*rear){}

        void insertAtBeginning(int data);
        void insertAtEnd(int data);
        void insertAtIndex(int data, int idx);

        void deleteAtBeginning();
        void deleteAtEnd();
        void deleteAtIndex(int idx);

        int size() const {return nNodes;}

        void forwardTraversal();
        void backwardTraversal();

        bool search(int key);

        ~DoublyLinkedList();
};

//INSERTION OPERATION
void DoublyLinkedList::insertAtBeginning(int data){
    Node *buffer = new Node(data);
    if(head == nullptr){
        head = tail = buffer;
    }else{
        buffer->next = head;
        head->prev = buffer;
        head = buffer;
    }
    nNodes++;
}

void DoublyLinkedList::insertAtEnd(int data){
    Node *buffer = new Node(data);
    if(head == nullptr){
        head = tail = buffer;
    }else{
        tail->next = buffer;
        buffer->prev = tail;
        tail = buffer;
    }
    nNodes++;
}

void DoublyLinkedList::insertAtIndex(int data, int idx){
    if(idx == 0) insertAtBeginning(data);
    else if(idx == nNodes) insertAtEnd(data);
    else if(idx > nNodes || idx < 0) std::cout<<"Invalid insertion: index is out of bounds.\n";
    else{
        int cnt;
        Node *ptr, *buffer = new Node(data);
        if((nNodes - idx) > idx){
            ptr = head; cnt = 0;
            while(cnt != idx-1){
                ptr = ptr->next;
                cnt++;
            }
        }else{
            ptr = tail; cnt = nNodes-1;
            while(cnt != idx-1){
                ptr = ptr->prev;
                cnt--;
            }
        }
        buffer->next = ptr->next;
        buffer->prev = ptr;
        ptr->next->prev = buffer;
        ptr->next = buffer;
        nNodes++;
    }
}

//DELETION OPERATION
void DoublyLinkedList::deleteAtBeginning(){
    if(head == nullptr){
        std::cout<<"Linked list is empty!\n";
    }else{
        Node *ptr = head;
        head = head->next;
        head->prev = nullptr;
        delete ptr;
    }
}

void DoublyLinkedList::deleteAtEnd(){
    if(head == nullptr){
        std::cout<<"Linked list is empty!";
    }else{
        Node *ptr = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete ptr;
    }
}

void DoublyLinkedList::deleteAtIndex(int idx){
    if(idx == 0) deleteAtBeginning();
    else if(idx == nNodes-1)  deleteAtEnd();
    else if(idx >= nNodes || idx < 0) std::cout<<"Invalid deletion: index is out of bounds.\n";
    else{
        int cnt;
        Node *ptr;
        if (nNodes - idx > idx){
            ptr = head; cnt = 0;
            while(cnt != idx){
                ptr = ptr->next;
                cnt++;
            }
        }else{
            ptr = tail; cnt = nNodes-1;
            while(cnt != idx){
                ptr = ptr->prev;
                cnt--;
            }
        }
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        nNodes--;
        delete ptr;
    }
}

//DESTRUCTOR 
DoublyLinkedList::~DoublyLinkedList() { 
    if(head != nullptr){
        Node *ptr, *preptr = head;
        while (preptr != nullptr) {
            ptr = preptr->next;
            delete preptr;
            preptr = ptr;
        }
        head = nullptr;
        tail = nullptr;
    }
}

//TRAVERSAL OPERATION
void DoublyLinkedList::forwardTraversal(){
    Node *ptr = head;
    while(ptr != nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    std::cout<<"\n";
}

void DoublyLinkedList::backwardTraversal(){
    Node *ptr = tail;
    while(ptr != nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }
    std::cout<<"\n";
}

//SEARCH OPERATION
bool DoublyLinkedList::search(int key){
    Node *ptr = head;
    while(ptr != nullptr){
        if(ptr->data == key) return true;
        ptr = ptr->next;
    }
    return false;
}