// Post-Order Traversal of BT



/*// Code-Problem-Link->
// https://www.naukri.com/code360/problems/postorder-traversal_2035933?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

void solve(TreeNode* root, vector<int>& arr) {
    if(root == NULL) return;

    solve(root->left, arr);
    solve(root->right, arr);
    arr.push_back(root->data);
}

vector<int> postorderTraversal(TreeNode *root){
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
    solve(root->right, arr);
    arr.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> arr;

    solve(root, arr);
    return arr;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
