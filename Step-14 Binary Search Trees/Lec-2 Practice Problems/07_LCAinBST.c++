// Lowest Common Ancestor/LCA for two given Nodes in BST


/* // Problem-Link->
// https://www.naukri.com/code360/problems/lca-in-a-bst_981280


TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q){
    // Write your code here.
    if(!root) return nullptr;
    int curr = root->data; // curr is meant to be a pointer
    if(curr < P->data && curr < Q->data) {
        return LCAinaBST(root->right, P, Q);
    }
    if(curr > P->data && curr > Q->data) {
        return LCAinaBST(root->left, P, Q);
    }
    return root;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) {
        data = x;
        left = right = nullptr;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;

    int curr = root->data; // curr is meant to be a pointer
    if(curr < p->data && curr < q->data) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p->data && curr > q->data) {
        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}




int main() {

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Nodes for which we want to find the LCA
    TreeNode* p = root->left->left;  // Node with value 5
    TreeNode* q = root->left->right; // Node with value 15

    // Call the function to find the LCA
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Print the result
    if (lca != nullptr)
        cout << "LCA of " << p->data << " and " << q->data << " is " << lca->data << endl;
    else
        cout << "LCA not found" << endl;


    return 0;
}
