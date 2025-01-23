// Construct a BST from a Preorder Traversal


/* // PRoblem-Link->
// https://www.naukri.com/code360/problems/construct-bst-from-preorder-traversal_2689307


TreeNode* build(vector<int> &pre, int& iptr, int uprBound) {
    if(iptr == pre.size() || pre[iptr] > uprBound) return nullptr;
    TreeNode* root = new TreeNode(pre[iptr++]);
    root->left = build(pre, iptr, root->data);
    root->right = build(pre, iptr, uprBound);
    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder) {
    // Write your code here.
    int i=0;
    return build(preOrder, i, INT_MAX);
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};


TreeNode* build(vector<int>& pre, int& iPtr, int uprBound) {
    if(iPtr == pre.size() || pre[iPtr] > uprBound) return NULL;
    TreeNode* root = new TreeNode(pre[iPtr++]);
    root->left = build(pre, iPtr, root->data);
    root->right = build(pre, iPtr, uprBound);
    return root;
}


TreeNode* bstFromPreorder(vector<int>& pre) {
    int i = 0;
    return build(pre, i, INT_MAX);
}


void inorderTraversal(TreeNode* root) {
    if(!root) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Construct the BST from the preorder traversal
    TreeNode* root = bstFromPreorder(preorder);

    // Print inorder traversal to verify the BST
    cout << "Inorder Traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
