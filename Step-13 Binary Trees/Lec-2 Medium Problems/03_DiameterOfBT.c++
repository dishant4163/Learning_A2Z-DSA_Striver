// Calculate the Diameter of a Binary Tree


/* // Problem-Link->
// https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_920552?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    

int getHeight(TreeNode<int>* root, int& diamter) {
    if(!root) return 0;

    int l = getHeight(root->left, diamter);
    int r = getHeight(root->right, diamter);

    diamter = max(diamter, (l + r));

    return 1 + max(l, r);
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int diameter = 0;
    getHeight(root, diameter);

    return diameter;
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


// Global Variable to store the maxi daimeter
int Diameter = 0;


// Soln-1 BRUTE FORCE
int calculateHeight(Node* root) {
    if(root == NULL) return 0;

    int lh = calculateHeight(root->left);
    int rh = calculateHeight(root->right);

    Diameter = max(Diameter, (lh + rh));

    return 1 + max(lh, rh);
}

// Main Function 
int diameterOfBinaryTree(Node* root) {
    calculateHeight(root);
    return Diameter;
}






// Soln-2 OPtimal Soln
int getHeight(Node* root, int& diameter) {
    if (root == NULL) return 0;

    int l = getHeight(root->left, diameter);
    int r = getHeight(root->right, diameter);

    diameter = max(diameter, (l + r));

    return 1 + max(l, r);
}

int diameterOfBT(Node* root) {
    int diameter = 0;

    getHeight(root, diameter);

    return diameter;
}




int main() {

// Soln-1 BRUTE FORCE
    Node* Root = new Node(1);
    Root->left = new Node(2);
    Root->right = new Node(3);
    Root->left->left = new Node(4);
    Root->left->right = new Node(5);
    Root->left->right->right = new Node(6);
    Root->left->right->right->right = new Node(7);

    // Calculate the diameter of the binary tree
    int res = diameterOfBinaryTree(Root);

    cout << "The diameter of the binary tree is: " << res << endl;



cout << endl << endl;



// Soln-2 OPtimal 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Calculate the diameter of the binary tree
    int ans = diameterOfBT(root);

    cout << "The diameter of the binary tree is: " << ans << endl;




    return 0;
}
