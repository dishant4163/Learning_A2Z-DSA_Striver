// Delete a Node in Binary Search Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/delete-node-in-bst_920381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    

BinaryTreeNode<int>* findLastRight(BinaryTreeNode<int>* root) {
    if(root->right == NULL) return root;
    findLastRight(root->right);
}

BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root) {
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;

    BinaryTreeNode<int>* rightChild = root->right;
    BinaryTreeNode<int>* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    if(root == NULL) return nullptr;
    if(root->data == key) return helper(root);
    BinaryTreeNode<int>* dummy = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
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


TreeNode *findLastRight(TreeNode *root) {
    if(root->right == NULL) return root;
    findLastRight(root->right);
}

TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;

    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->data == key) return helper(root);

    TreeNode *dummy = root;
    while(root != NULL) {
        if(root->data > key) {
            if(root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }

    return dummy;
}





void printInOrder(TreeNode *root) {
    if(!root) return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}



int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    int keyToDelete = 3;
    TreeNode* updatedTree = deleteNode(root, keyToDelete);
    cout << "Tree After Deletion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;


    return 0;
}
