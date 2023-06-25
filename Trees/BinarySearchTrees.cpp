#include <iostream>

class Node{
    public: 
        int data;
        Node *left, *right;
        Node(int nodeVal){
            this->data = nodeVal;
            this->left = this->right = nullptr;
        }
        Node(): Node(0){}
};


class BST{
    public:
        Node* insertNode(Node *node, int data);
        Node* deleteNode(Node *node, int data);

        Node* search(Node *node, int key);     

        Node* getMaximum(Node *node);
        Node* getMinimum(Node *node);

        void preorder(Node *node);
        void inorder(Node *node);
        void postorder(Node *node);

        Node* successor(Node *root, Node *node);
        Node* predecessor(Node *root, Node *node);
};


//INSERTION OPERATION
Node* BST::insertNode(Node *node, int data){
    if(node == nullptr){
        node = new Node(data);
    }else{
        if(node->data > data){
            node->left = insertNode(node->left, data);
        }else{
            node->right = insertNode(node->right, data);
        }
    }
    return node;
}


//DELETION OPERATION
Node* BST::deleteNode(Node *node, int data){
    if(node == nullptr){
        std::cout<<"Deletion failed: root is NULL.\n";
        return node;
    }

    if(node->data > data){
        node->left = deleteNode(node->left,data);
    }else if(node->data < data){
        node->right = deleteNode(node->right,data);
    }else{
        if(node->left == nullptr){
            Node *buffer = node->right;
            delete node;
            return buffer;
        }else if(node->right == nullptr){
            Node *buffer = node->left;
            delete node;
            return buffer;
        }
        Node *buffer = getMinimum(node->right);
        node->data = buffer->data;
        node->right = deleteNode(node->right, buffer->data);
    }
    return node;
}   


// UTILITY METHODS
Node* BST::successor(Node *root, Node *node){
    if(node == nullptr) return node;
    if(node->right != nullptr){
        return getMinimum(node->right);
    }
    Node *succ = nullptr;
    while(root != node){
        if(root->data > node->data){
            succ = root;
            root = root->left;
        }else{
            root = root->right;
        }
    }    
    return succ;
}

Node* BST::predecessor(Node *root, Node *node){
    if(node == nullptr) return node;
    if(node->left != nullptr){
        return getMaximum(node->left);
    }

    Node *pred = nullptr;
    while(root != node){
        if(root-> data < node->data){
            pred = root;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return pred;
}

Node* BST::getMaximum(Node *node){
    if(node == nullptr || node->right == nullptr){
        return node;
    }
    return getMaximum(node->right);
}

Node* BST::getMinimum(Node *node){
    if(node == nullptr || node->left == nullptr){
        return node;
    }
    return getMinimum(node->left);
}


//SEARCH OPERATION
Node* BST::search(Node *node, int key){
    if(node->data == key || node == nullptr){
        return node;
    }else if(node->data > key){
        return search(node->left,key);
    }else{
        return search(node->right,key);
    }
}


//TRAVERSAL OPERATION
void BST::inorder(Node *node){
    if(node != nullptr){
        inorder(node->left);
        std::cout<<node->data<<" ";
        inorder(node->right);
    }
}

void BST::postorder(Node *node){
    if(node != nullptr){
        postorder(node->left);
        postorder(node->right);
        std::cout<<node->data<<" ";
    }
}

void BST::preorder(Node *node){
    if(node != nullptr){
        std::cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}