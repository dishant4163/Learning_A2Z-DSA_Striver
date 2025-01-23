// Insert a Given Node in Binary Search Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/insert-into-a-binary-search-tree_1279913?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val){
    // Write your code here.
    if(root == NULL) return new TreeNode<int>(val);

    TreeNode<int> *curr = root;
    while(true) {
        if(curr->val <= val) {
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode<int>(val);
                break;
            }
        } else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode<int>(val);
                break;
            }
        }
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





TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    TreeNode* curr = root;
    while(true) {
        if(curr->data <= val) {
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                break;
            }
        } else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}






void printInOrder(TreeNode* root) {
    if(root == nullptr) return;

    printInOrder(root->left);
    cout << root->data <<" ";
    printInOrder(root->right);
}



int main() {

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);



    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    int keyToInsert = 5;
    TreeNode* updatedTree = insertIntoBST(root, keyToInsert);

    cout << "Tree After Insertion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;


    return 0;
}
