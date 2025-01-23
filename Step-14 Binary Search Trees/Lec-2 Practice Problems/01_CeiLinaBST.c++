// Ceil in a BST


/* // Problem-Link->
// https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil = -1;
    while(node) {
        if(node->data == x) {
            ceil = node->data;
            return ceil;
        }

        if(x > node->data) {
            node = node->right;
        } else {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = right = nullptr;
    }
};


int findCeil(TreeNode* root, int key) {
    int ceil = -1;
    while(root) {
        if(root->data == key) {
            ceil = root->data;
            return ceil;
        }

        if(key > root->data) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}



int main() {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    int target = 8;
    int ciel = findCeil(root, target);

    if(ciel != -1){
        cout << "Ceiling of " << target << " is: " << ciel << endl;
    }
    else{
        cout << "No ceiling found!";
    }

    return 0;
}
