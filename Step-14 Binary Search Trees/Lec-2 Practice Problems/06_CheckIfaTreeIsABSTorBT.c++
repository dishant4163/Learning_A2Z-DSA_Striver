// Check if a tree is a Binary Search Tree or Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/check-bst_5975?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool solve(TreeNode* node, int minVal, int maxVal){
    if(node == NULL) return true;

    if(node->data <= minVal || node->data >= maxVal) return false;
    return solve(node->left, minVal, node->data) && solve(node->right, node->data, maxVal);
}

bool isBST(TreeNode* root) {
    return solve(root, INT_MIN, INT_MAX);
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};



bool solve(TreeNode* node, int minVal, int maxVal){
    if(node == NULL) return true;

    if(node->data <= minVal || node->data >= maxVal) return false;
    return solve(node->left, minVal, node->data) && solve(node->right, node->data, maxVal);
}

bool isValid(TreeNode* root) {
    return solve(root, INT_MIN, INT_MAX);
}


void printInOrder(TreeNode* root) {
    if(root == NULL) return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    cout << "Inorder Traversal of Tree:" << endl;
    printInOrder(root);
    cout << endl;

    // Checking if the created tree is a valid BST
    bool isValidBST = isValid(root);

    if (isValidBST) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    return 0;
}
