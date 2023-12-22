#include <iostream> 

//define Node structure 
struct Node {
    int data; 
    Node *prev; 
    Node *next; 
};

// construct global struct for head node 
struct Node* head = nullptr; 

void insertFront(Node *node) {
   
    Node *new_node = new Node; 

    new_node = node; 
    new_node->next = head; 
    head = new_node; 
    head->prev = new_node; 

};


void insertAfter(int data, Node *prev) {
    
    // error check 
    if (prev == nullptr) {
        std::cerr << "Error: Previous node cannot be null." << std::endl;
        return;
    }

    Node *new_node = new Node;

    new_node->data = data;
    new_node->next = prev->next;

    if (prev->next != nullptr) {
        (prev->next)->prev = new_node;
    }

    new_node->prev = prev;
    prev->next = new_node;
}

void printList() {
    Node *curr = head; 

    // iterate and print out data until last node reached 
    while(curr != nullptr) {
        std::cout << curr->data << " "; 
        curr = curr->next; 
    }

    std::cout <<std::endl; 
}

int main() {

    Node* n1 = new Node; 
    Node* n2 = new Node; 
    Node* n3 = new Node; 

    n1->data = 1; 
    n2->data = 2; 
    n3->data = 3; 

    // Test insertFront
    insertFront(n1);
    insertFront(n2);
    insertFront(n3);

    printList();  

    //test insertAfter
    insertAfter(4, head); 
    printList(); 

    return 0;
}


