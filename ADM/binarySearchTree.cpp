#include <iostream>

struct Node {
    int data;
    Node* left; 
    Node* right; 
};

Node * newNode(int val) {
    Node *new_node = new Node; 
    new_node->data = val; 
    new_node->left = new_node->right = nullptr; 

    return new_node; 
};

void insert(Node* &travptr, int data) {
    if (travptr == nullptr) {
        travptr = newNode(data);
        return;
    } 

    if (data > travptr->data) {
        insert(travptr->right,data);
    } else {
        insert(travptr->left, data); 
    }
};

bool contains(Node* travptr, int data) {
    if (travptr == nullptr) {
        return false; 
    } 

    if (travptr->data == data) {
        return true; 
    }

    if ( data > travptr->data) {
        return contains(travptr->right,data);
    } else {
        return contains(travptr->left, data);
    }
}

void displayTree(Node* root, int level = 0) {
    if (root != nullptr) {
        displayTree(root->right, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << root->data << std::endl;
        displayTree(root->left, level + 1);
    }
}

int main()
{
    Node* root = nullptr;

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    //std::cout << contains(root, 3) << "\t" << contains(root, 10) << "\t" << contains(root, 5);

    displayTree(root); 
    
    return 0;
}