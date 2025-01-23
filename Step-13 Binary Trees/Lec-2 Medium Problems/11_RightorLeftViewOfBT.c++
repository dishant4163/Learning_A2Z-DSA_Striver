// Right/Left View of Binary Tree


/*// Problem-Link_Left View of BT->
// https://www.naukri.com/code360/problems/left-view-of-binary-tree_625707?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

void solveLeft(BinaryTreeNode<int>* root, int level, vector<int>& res) {
    if(!root) return;
    if(res.size() == level) res.push_back(root->data);
    solveLeft(root->left, level+1, res);
    solveLeft(root->right, level+1, res);
}

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    solveLeft(root, 0, ans);

    return ans;
}


*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


// Recursive function to traverse the
// binary tree and populate the right-side view
void solveRight(Node* root, int level, vector<int>& res) {
    if(!root) return;
    if(res.size() == level) res.push_back(root->data);
    solveRight(root->right, level+1, res);
    solveRight(root->left, level+1, res);
}

// Recursive function to traverse the
// binary tree and populate the left-side view
void solveLeft(Node* root, int level, vector<int>& res) {
    if(!root) return;
    if(res.size() == level) res.push_back(root->data);
    solveLeft(root->left, level+1, res);
    solveLeft(root->right, level+1, res);
}


// Function to return the Right view of the binary tree
vector<int> rightsideView(Node* root) {
    vector<int> ans;
    solveRight(root, 0, ans);

    return ans;
}

// Function to return the Left view of the binary tree
vector<int> leftsideView(Node* root) {
    vector<int> ans;
    solveLeft(root, 0, ans);

    return ans;
}





int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int> rightView = rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

