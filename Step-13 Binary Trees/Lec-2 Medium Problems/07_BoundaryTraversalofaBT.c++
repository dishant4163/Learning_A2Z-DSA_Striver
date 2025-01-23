// Boundary Traversal of a Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

bool isLeaf(TreeNode<int>* root) {
    return !root->left && !root->right;
}

void addLeftBoundary(TreeNode<int>* root, vector<int>& res) {
    TreeNode<int>* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) {
            res.push_back(curr->data);
        }

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(TreeNode<int>* root, vector<int>& res) {
    vector<int> temp;
    TreeNode<int>* curr = root->right;

    while(curr) {
        if(!isLeaf(curr)) {
            temp.push_back(curr->data);
        }

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size() - 1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int>& res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}


vector<int> traverseBoundary(TreeNode<int> *root) {
	// Write your code here.
    vector<int> ans;
    if(!root) return ans;

    if(!isLeaf(root)) {
        ans.push_back(root->data);
    }

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr; 
        right = nullptr;
    }
};


// Function to check if a node is a leaf
bool isLeaf(Node* root) {
    return !root->left && !root->right;
}


// Function to add the left boundary of the tree
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while(curr) {
        if(!isLeaf(curr)) {
            res.push_back(curr->data);
        }

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}


// Function to add the right boundary of the tree
void addRightBoundary(Node* root, vector<int>& res) {
    vector<int> temp;
    Node* curr = root->right;
    while(curr) {
        if(!isLeaf(curr)) {
            temp.push_back(curr->data);
        }

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

// Reverse & add the values from the temp vector to the result
    for(int i = temp.size()-1; i >= 0; i--) {
        res.push_back(temp[i]);
    }
}


// Function to add the leaves of the tree
void addLeaves(Node* root, vector<int>& res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }

    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(Node* root) {
    vector<int> ans;
    if(!root) return ans;

    if(!isLeaf(root)) {
        ans.push_back(root->data);
    }

    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);

    return ans;
}




int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    for(int it : res) {
        cout << it << " ";
    }

    return 0;
}
