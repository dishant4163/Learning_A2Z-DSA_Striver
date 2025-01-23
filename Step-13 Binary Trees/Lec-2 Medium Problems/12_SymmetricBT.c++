// Symmetric Binary Tree


/* // Problem-link->
// https://www.codingninjas.com/studio/problems/symmetric-tree_981177?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    

bool isSymmetricHelp(TreeNode<int>* l, TreeNode<int>* r) {
    if (l == NULL || r == NULL) return l == r;

    if(l->data != r->data) return false;

    return isSymmetricHelp(l->left, r->right) && isSymmetricHelp(l->right, r->left);
}

bool isSymmetric(TreeNode<int> *root) {
    // Write your code here
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};


bool isSymmetricHelp(Node* root1, Node* root2) {
    if(root1 == NULL || root2 == NULL) return true;

    if(root1->data != root2->data) return false;

    return isSymmetricHelp(root1->left, root2->right) && 
    isSymmetricHelp(root1->right, root2->left);
}


bool isSymmetric(Node* root) {
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

// Function to print the Inorder
// Traversal of the Binary Tree
void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res = isSymmetric(root);

    if(res) {
        cout << "This Tree is Symmetrical" << endl;
    } else {
        cout << "This Tree is NOT Symmetrical" << endl;
    }

    return 0;
}
