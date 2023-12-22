#include <iostream> 

struct Node {
    int val; 
    Node *left; 
    Node *right; 
}; 

 struct Node* newNode(int val)
{
    Node* new_node = new Node;
    new_node->val = val;

    new_node->left = new_node->right = nullptr;
    return new_node;
};

// void insert(Node* &node, int val) {

//     Node *new_node = new Node; 

//     new_node->val = val; 

//     new_node->right = new_node->left = nullptr;
// }

void inorder(Node* root) {
    if (root == nullptr) return; 

    // recursion on left subtree first 
    inorder(root->left); 

    std::cout << root->val << " "; 

    // recursion on right subtree after 
    inorder(root->right); 
};

void preorder(Node* root) {
    if (root == nullptr) return; 

    // print data 
    std::cout << root->val << " "; 

    // recursion on left subtree first 
    preorder(root->left);

    // then recur on right subtree 
    preorder(root->right); 
}

void postorder(Node* root) {
    if (root == nullptr) return; 

    postorder(root->left); 

    postorder(root->right);

    std::cout << root->val << " "; 
}

int main() {
    Node* root = new Node;
    root->val = 1;
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4); 
    root->left->right = newNode(5); 


 /* example tree 
        1
       / \
      2   3
     / \ 
    4   5
*/

    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}

