// Check for Children Sum Property in a Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/children-sum-property_8357239?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   





// PRoblem-Link 2->
// https://www.naukri.com/code360/problems/childrensumproperty_790723



*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



void changeTree(TreeNode* root) {
    if(!root) return;
    int child = 0;

    if(root->left) child += root->left->val;
    if(root->right) child += root->right->val;

    if(child >= root->val) root->val = child;
    else {
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left || root->right) root->val = total;
}


// Function to print the inorder
// traversal of the tree
void inorderTraversal(TreeNode* root) {
    if(root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Print the inorder traversal
    // of tree before modification
    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;


    // Call the changeTree function
    // to modify the binary tree
    changeTree(root);

    // Print the inorder traversal
    // after modification
    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;
}

