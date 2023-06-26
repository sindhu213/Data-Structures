#include <iostream>
#include <algorithm>

class Node{
    public:
        int data, height;
        Node *left, *right;
        Node(int nodeVal){
            this->data = nodeVal;
            this->left = this->right = nullptr;
            this->height = 0;
        }
        Node():Node(0){}
};

class AVL{
    public:
        Node *insertNode(Node *node, int data);
        Node *leftRotate(Node *node);
        int balanceFactor(Node *node);
        void inorder(Node *root);
        int calcHeight(Node *node);
        int getHeight(Node *node);
};

Node* AVL::insertNode(Node *node, int data){
    if(node == nullptr){
        node = new Node(data);
        return node;
    }
    if(node->data > data){
        node->left = insertNode(node->left, data);
    }else{
        node->right = insertNode(node->right, data);
    }
    node->height = calcHeight(node);
    return node;
}

Node* AVL::leftRotate(Node *node){
    Node *root = node->right;
    Node *buffer = root->left;

    root->left = node;
    node->right = buffer;

    node->height = calcHeight(node);
    root->height = calcHeight(root);
    return root;
}

//bug: adding 1 even when node is a leaf
int AVL::calcHeight(Node *node){
    return std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

int AVL::balanceFactor(Node *node){
    if(node == nullptr) return 0;
    return node->left->height - node->right->height;
} 

int AVL::getHeight(Node *node){
    if(node == nullptr) return 0;
    return node->height;
}

void AVL::inorder(Node *root){
    if(root != nullptr){
        inorder(root->left);
        std::cout<<root->data<<" "<<root->height<<"\n";
        inorder(root->right);
    }
}

//cross check balancefactor
int main(){
    Node *root = nullptr;
    AVL a;
    root = a.insertNode(root,30);
    root = a.insertNode(root,56);
    root = a.insertNode(root,88);
    a.inorder(root);

    std::cout<<"\n";

    root = a.leftRotate(root);
    a.inorder(root);
    return 0;
}


