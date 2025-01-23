// Count Total Nodes in a Complete BT


/* // PRoblem-Link->
// https://www.codingninjas.com/studio/problems/nodes-in-complete-binary-tree_1281151?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

int findLeftHeight(BinaryTreeNode<int>* node) {
    int ht = 0;
    while(node) {
        ht++;
        node = node->left;
    }
    return ht;
}

int findRightHeight(BinaryTreeNode<int>* node) {
    int ht = 0;
    while(node) {
        ht++;
        node = node->right;
    }
    return ht;
}


int countNodes(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(!root) return NULL;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh) return (1 << lh) - 1; // (1 << lh) means 2 ^ lh

    return 1 + countNodes(root->left) + countNodes(root->right);
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Brute Force
void inorder(TreeNode* node, int& cnt) {
    if(!node) return;
    cnt++;
    inorder(node->left, cnt);
    inorder(node->right, cnt);
}

int cntNodes(TreeNode* node) {
    if(!node) return 0;
    int cnt = 0;
    inorder(node, cnt);
    return cnt;
}





// OPtimal Soln
int findLeftHt(TreeNode* node) {
    int ht = 0;
    while(node) {
        ht++;
        node = node->left;
    }
    return ht;
}

int findRightHt(TreeNode* node) {
    int ht = 0;
    while(node) {
        ht++;
        node = node->right;
    }
    return ht;
}


int countNodes(TreeNode* root) {
    if(!root) return 0;

    int lh = findLeftHt(root);
    int rh = findRightHt(root);

    if(lh == rh) return (1 << lh) - 1; // (1<<n) means 2 ^ n

    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main() {

// Brute Force Soln
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->right->left = new TreeNode(6);

    cout << "Total number of nodes in the Complete Binary Tree: "<< cntNodes(node) << endl;




cout << endl << endl;

// OPtimal Soln 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Call the countNodes function
    int totalNodes = countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "<< totalNodes << endl;



    return 0;
}
