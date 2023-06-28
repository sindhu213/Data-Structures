#include <iostream>

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
        Node* insertNode(Node *node, int data);
        Node* deleteNode(Node *node, int data);

        Node* leftRotate(Node *node);
        Node* rightRotate(Node *node);

        int balanceFactor(Node *node);

        void inorder(Node *root);

        Node* getMinimum(Node *node);
        int max(int a, int b);

        Node* updateHeight(Node *node);
        int getHeight(Node *node);
};


//INSERTION OPERATION
Node* AVL::insertNode(Node *node, int data){
    //BST insertion
    if(node == nullptr){
        node = new Node(data);
        return node;
    }else{
        if(node->data > data){
            node->left = insertNode(node->left, data);
        }else{
            node->right = insertNode(node->right, data);
        }
    }

    node = updateHeight(node);
    int bf = balanceFactor(node);

    //Left Rotation
    if(bf < -1 && data > node->right->data){
        return leftRotate(node);
    }

    //Right Rotation
    if(bf > 1 && data < node->left->data){
        return rightRotate(node);
    }

    //Left-Right Rotation
    if(bf > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //Right-Left Rotation
    if(bf < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}


//DELETION OPERATION
Node* AVL::deleteNode(Node *node, int data){
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

    node = updateHeight(node);
    int bf = balanceFactor(node);

    // Left Rotation
    if (bf > 1 && balanceFactor(node->left) >= 0){
        return rightRotate(node);
    }

    // Right Rotation
    if (bf < -1 && balanceFactor(node->right) <= 0){
        return leftRotate(node);
    }

    // Left Right Rotation
    if (bf > 1 && balanceFactor(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Rotation
    if (bf < -1 && balanceFactor(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}


//ROTATIONS
Node* AVL::leftRotate(Node *node){
    Node *root = node->right;
    Node *buffer = root->left;

    root->left = node;
    node->right = buffer;

    node = updateHeight(node);
    root = updateHeight(root);
    return root;
}

Node* AVL::rightRotate(Node *node){
    Node *root = node->left;
    Node *buffer = root->right;  

    root->right = node;
    node->left = buffer;

    node = updateHeight(node);
    root = updateHeight(root);
    return root;
}


//UTILITY METHODS
int AVL::balanceFactor(Node *node){
    if(node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
} 

int AVL::getHeight(Node *node){
    if (node == nullptr) return -1;
    return node->height;
};

Node* AVL::updateHeight(Node *node){
    node->height = max(getHeight(node->left), 
                       getHeight(node->right)) + 1;
    return node;
}

Node* AVL::getMinimum(Node *node){
    if(node == nullptr || node->left == nullptr){
        return node;
    }
    return getMinimum(node->left);
}

int AVL::max(int a, int b){
    return (a>b)?a:b;
}


//TRAVERSAL OPERATION
void AVL::inorder(Node *root){
    if(root != nullptr){
        inorder(root->left);
        std::cout<<root->data<<" ";
        inorder(root->right);
    }
}

