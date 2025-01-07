// Inorder Traversal of Binary Tree  


/* // Code-Problem-Link->
// https://www.naukri.com/code360/problems/inorder-traversal_3839605?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

void solve(TreeNode* root, vector<int>& arr) {
    if(root == nullptr) return;

    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);
}

vector<int> getInOrderTraversal(TreeNode *root) {
    // Write your code here.
    vector<int> arr;

    solve(root, arr);
    return arr;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


void solve(Node* root, vector<int>& arr) {
    if(root == nullptr) return;

    solve(root->left, arr);
    arr.push_back(root->data);
    solve(root->right, arr);
}

vector<int> inOrder(Node* root) {
    vector<int> arr;

    solve(root, arr);
    return arr;
}



int main() {

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
