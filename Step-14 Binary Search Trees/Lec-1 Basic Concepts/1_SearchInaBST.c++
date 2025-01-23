// Search In a Binary Search Tree


/* // Problem-Link->
// https://www.codingninjas.com/studio/problems/search-in-bst_1402878?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    while(root != NULL && root->data != x) {
        root = x < root->data ? root->left : root->right; 
    }
    return root;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* searchBST(TreeNode* root, int target) {
    while(root != NULL && root->data != target) {
        root = target < root->data ? root->left : root->right;
    }

    return root;
}


void inorder(TreeNode* root) {
    if(!root) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    int target = 6;
    TreeNode* result = searchBST(root, target);

    cout << "Binary Search Tree: ";
    inorder(root);
    cout << endl;
    if (result != nullptr) {
        cout << "Value " << target << " found in the BST." << endl;
    } else {
        cout << "Value " << target << " not found in the BST." << endl;
    }


    return 0;
}
