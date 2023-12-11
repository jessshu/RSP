#include <iostream>
// time complexity: 

// do i understand it 

// define node struct 
struct Node {
    int data;
    Node* next; 
};

struct Node *head = nullptr;

void insert(int val) { // for inserting as head
    struct Node *new_node = new Node; 

    new_node->data = val; 
    new_node->next = head; 
    head = new_node; 
}

void display_list() {
    struct Node *temp = head; 

    while (temp != NULL) {
        std::cout << temp->data << " "; 

        temp = temp->next;
    }
            std::cout << std::endl;
}

void reverse_list() {

    Node* current_head = head; 
    Node* next_node = NULL;
    Node* prev_node = NULL;

    while (current_head != NULL) {
        next_node = current_head->next; 

        current_head->next = prev_node; 

        prev_node = current_head; 

        current_head = next_node; 
         
    }
    
    head = prev_node; 

}

int count_nodes() {
    int counter = 0; 

    Node* temp = head; 

    while (temp != NULL) {
        counter++; 

        temp = temp->next; 
    }

    return counter; 
}

void delete_node(int n) {
    Node* current_node = head; 
    Node* previous_node = nullptr; 

    // traverse list while n is not found 
    while (current_node->data!=n && current_node!=nullptr) {
        previous_node = current_node; 
        current_node = current_node->next; 
    }

    // if node with n is found 
    if (current_node!=nullptr) {
        // if its the first node 
        if (previous_node == nullptr) {
            head = current_node->next; 
        } else {
            previous_node->next = current_node->next; 
        }

        delete current_node; 
    }

}

int main() {

    std::cout << "Singly linked list:" << std::endl; 

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    display_list(); 

    std::cout << "Reversed list:" << std::endl; 

    reverse_list(); 
    display_list(); 

    std::cout<< "Number of nodes in list is: " << count_nodes() << std::endl; 

    delete_node(1); 

    display_list(); 

    return 0; 
}