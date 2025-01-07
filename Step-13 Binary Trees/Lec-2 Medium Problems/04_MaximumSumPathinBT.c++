// Maximum Sum Path in Binary Tree


// Problem-Link->
// https://www.codingninjas.com/studio/problems/maximum-sum-path-of-a-binary-tree._1214968?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    



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


int maxPath(Node* root, int& maxi) {
    if(!root) return 0;

    int lsum = max(0, maxPath(root->left, maxi));
    int rsum = max(0, maxPath(root->right, maxi));

    maxi = max(maxi, lsum + rsum + root->data);

    return root->data + max(lsum, rsum);
}

int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    maxPath(root, maxi);

    return maxi;
}



int main() {

Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Finding and printing the maximum path sum
    int ans = maxPathSum(root);
    cout << "Maximum Path Sum: " << ans << endl;


    return 0;
}