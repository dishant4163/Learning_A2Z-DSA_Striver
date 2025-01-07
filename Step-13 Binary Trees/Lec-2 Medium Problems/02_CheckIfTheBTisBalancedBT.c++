// Check if the Binary Tree is Balanced Binary Tree


/* // Problem-Link->
// https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_975497?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int dfsHeight(TreeNode<int>* root) {
    if(!root) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}


bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return dfsHeight(root) != -1;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



// Soln-1 BRUTE Force
// function to find height
int getHeight(Node* root) {
    if(root == NULL) return 0;

    int lH = getHeight(root->left);
    int rH = getHeight(root->right);
    return 1 + max(lH, rH);
}

// main function 
bool checkIsBalanced(Node* root) {
    if(root == NULL) return true;

    int lH = getHeight(root->left);
    int rH = getHeight(root->right);

    if (abs(lH - rH) <= 1 && checkIsBalanced(root->left) && checkIsBalanced(root->right)) {
        return true;
    }

    return false;
}






// Soln-2 OPtimal SOln
int dfsHeight(Node* root) {
    if(root == NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) < 1) return -1;
    return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
    return dfsHeight (root) != -1;
}






int main() {

// Soln-1 Brute Force
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    if (checkIsBalanced(root)) 
        cout << "The tree is balanced." << endl;
    else 
        cout << "The tree is not balanced." << endl;


cout << endl << endl;


// Soln-2 OPTIMAL
    Node* Root = new Node(1);
    Root->left = new Node(2);
    Root->right = new Node(3);
    Root->left->left = new Node(4);
    Root->left->right = new Node(5);
    Root->left->right->right = new Node(6);
    Root->left->right->right->right = new Node(7);

    // Checking if the tree is balanced
    if (isBalanced(Root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }




    return 0;
}
