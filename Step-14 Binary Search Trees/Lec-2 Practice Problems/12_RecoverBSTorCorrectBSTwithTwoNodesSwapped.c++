// Recover BST | Correct BST with Two Nodes Swapped


/*// Problem link->
// https://www.codingninjas.com/studio/problems/fix-bst_873137?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


TreeNode *first, *preV, *middle, *last;

void inorder(TreeNode* root) {
    if(!root) return;

    inorder(root->left);

    if (preV != NULL && root->data < preV->data) {
        if (first == NULL) {
            first = preV;    // The first violation
            middle = root;   // The second node involved in the violation
        } else {
            last = root;     // The second violation node
        }
    }

    preV = root;  // Move prev to the current node
    inorder(root->right);
}

TreeNode * FixBST(TreeNode * root){
    // Write your code here.
    first = middle = last = NULL;
    preV = new TreeNode(INT_MIN);
    inorder(root);
    if(first && last) {
        swap(first->data, last->data);
    }
    else if(first && middle) {
        swap(first->data, middle->data);
    }

    return root;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};




// SOLN-1 BRUTE Force
void inoTraversal(TreeNode* root, vector<int>& ino) {
    if(!root) return;
    inoTraversal(root->left, ino);
    ino.push_back(root->val);
    inoTraversal(root->right, ino);
}

void fixBSTHelp(TreeNode* root, vector<int>& ino, int& ptr) {
    if(!root) return;
    fixBSTHelp(root->left, ino, ptr);
    root->val = ino[ptr];
    ptr++;
    fixBSTHelp(root->right, ino, ptr);
}



TreeNode * FixBST(TreeNode * root) {
    vector<int> ino;
    inoTraversal(root, ino);
    sort(ino.begin(), ino.end());
    int i = 0;
    fixBSTHelp(root, ino, i);

    return root;
}




// Soln-2 OPTIMAL Soln
class Solution {
private:
    // Store first node of the misplaced pair
    TreeNode* first;    
    // Store previous node during inorder traversal
    TreeNode* prev;     
    // Store second node of the misplaced pair
    TreeNode* middle; 
    // Store last node of the misplaced pair
    TreeNode* last; 

void inOrder(TreeNode *root) {
    if(!root) return;

    inOrder(root->left);

    //check 4 misplaced node
    if(prev != NULL && root->val < prev->val) {
        // If this is the first violation,
        // mark nodes as 'first' and 'middle'
        if (first == NULL) {
            first = prev;
            middle = root;
        } else {
            // If it's not the first violation, mark 'last'
            last = root;
        }
    }
    // Update 'prev' for the next iteration
    prev = root;
    inOrder(root->right);
}

public:
// Function to recover the binary search tree
void recoverTree(TreeNode *root) {
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inOrder(root);

    // Swap the values of misplaced nodes based on conditions
    if (first && last) swap(first->val, last->val);
    else if (first && middle) swap(first->val, middle->val);
}

};




// Utility function to insert nodes into the BST
TreeNode *insertNode(TreeNode *root, int val) {
    if(!root) return new TreeNode(val);

    if(val < root->val){
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }

    return root;
}


// Function to swap two tree nodes and their subtrees
void swapNodes(TreeNode *a, TreeNode *b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;

    // swap left subtrees of the nodes
    TreeNode *tempLeft = a->left;
    a->left = b->left;
    b->left = tempLeft;

    TreeNode *tempRight = a->right;
    a->right = b->right;
    b->right = tempRight;
}


// Utility function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}



int main() {
    Solution soln;

    TreeNode* root = nullptr;
    root = insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 4);
    insertNode(root, 2);

cout <<"BRUTE Force Soltuion" << endl << endl;

    cout << "Original BST: ";
    inorderTraversal(root);
    cout << endl;


    TreeNode* node4 = root->right;
    TreeNode* node2 = root->left->right;
    swapNodes(node4, node2);

    cout << "BST with swapped nodes: ";
    inorderTraversal(root);
    cout << endl;

    // Recover the BST
    FixBST(root);

    cout << "Recovered BST: ";
    inorderTraversal(root);
    cout << endl;


cout << endl << endl;

cout << "OPTIMAL Solution" << endl;

    cout << "Original BST: ";
    inorderTraversal(root);
    cout << endl;


    cout << "BST with swapped nodes: ";
    inorderTraversal(root);
    cout << endl;

    // Recover the BST
    soln.recoverTree(root);

    cout << "Recovered BST: ";
    inorderTraversal(root);
    cout << endl;



    return 0;
}
