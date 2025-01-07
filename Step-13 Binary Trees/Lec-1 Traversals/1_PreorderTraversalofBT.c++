// Preorder Traversal of Binary Tree


/*// Code-Problem-Link->
// https://www.naukri.com/code360/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf       

void solve(TreeNode<int>* root, vector<int>& arr) {
    if(root == NULL) return;

    arr.push_back(root->data);
    solve(root->left, arr);
    solve(root->right, arr);
}
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> arr;

    solve(root, arr);

    return arr;
}

*/

#include<iostream>
#include<vector>
using namespace std; 

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void preorder(Node* root, vector<int>& arr) {
    if(root == nullptr) return;

    arr.push_back(root->data);

    preorder(root->left, arr);
    preorder(root->right, arr);
}


vector<int> preOrder(Node* root) {
    vector<int> arr;

    preorder(root, arr);

    return arr;
}




int main() {

    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
