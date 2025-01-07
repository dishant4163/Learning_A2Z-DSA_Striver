// Check if two trees are identical


/* // Problem-Link->
// https://www.naukri.com/code360/problems/identical-trees_799364

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 
    if (!root1 && !root2) return true;	 
    if (!root1 || !root2) return false;	 

    return ((root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right));
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



bool isIdentical(Node* node1, Node* node2) {
    if (node1 == NULL && node2 == NULL) return true;
    if (node1 == NULL || node2 == NULL) return false;

    return ((node1->data == node2->data) 
    && isIdentical(node1->left, node2->left) 
    && isIdentical(node1->right, node2->right));
}


int main() {

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    if (isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
