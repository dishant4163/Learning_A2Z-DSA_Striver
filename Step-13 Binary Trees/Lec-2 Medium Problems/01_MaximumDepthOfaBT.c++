// Maximum Depth of a Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/height-of-binary-tree_4609628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    

#include<queue>
int heightOfBinaryTree(TreeNode<int> *root) {
	// Write your code here.
    int depth = 0;
    if (root == NULL) return depth;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        int s = q.size();
        depth++;
        
        for(int i=0; i < s; i++) {
            TreeNode<int>* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    return depth;
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

// Solving using Recursive Way
int maxDepth(Node* root) {
    if (root == NULL) return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}



// Solving By Level-Order Traversal i.e, by Iterative Way
// int maxDepth(Node* root) {
//     int depth = 0;
//     if(root == NULL) return depth;

//     queue<Node* > q;
//     q.push(root);

//     while(!q.empty()) {
//         int s =  q.size();
//         depth++;
//         for(int i=0; i < s; i++) {
//             Node* temp = q.front();
//             q.pop();
//             if(temp->left != NULL) q.push(temp->left);
//             if(temp->right != NULL) q.push(temp->right);
//         }
//     }

//     return depth;
// }






int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int depth = maxDepth(root);
    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}
