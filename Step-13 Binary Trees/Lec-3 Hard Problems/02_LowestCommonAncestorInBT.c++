// LCA in BT / Lowest Common Ancestor for two given Nodes


/* // Problem-Link->
// https://www.naukri.com/code360/problems/lca-of-binary-tree_920541

int lowestCommonAncestor(TreeNode<int> *root, int x, int y){
	//    Write your code here
    if(root == NULL || root->data == x || root->data == y) {
        return root ? root->data : -1;
    }

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if(left != -1 && right != -1) return root->data;

    return (left != -1) ? left : right;
}


*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};


// Function to find the lowest common ancestor
int lowestCommonAncestor(TreeNode<int>* root, int x, int y) {
    // Base case: if the root is null or if we've found either x or y
    if (root == nullptr || root->data == x || root->data == y) {
        return root ? root->data : -1;
    }

    // Recurse on the left and right subtrees
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    // If both left and right are non-null, this root is the LCA
    if (left != -1 && right != -1) {
        return root->data;
    }

    // If one side is null, return the non-null side
    return (left != -1) ? left : right;
}







int main() {
    // Example tree:
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4

    TreeNode<int>* root = new TreeNode<int>(3);
    root->left = new TreeNode<int>(5);
    root->right = new TreeNode<int>(1);
    root->left->left = new TreeNode<int>(6);
    root->left->right = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(0);
    root->right->right = new TreeNode<int>(8);
    root->left->right->left = new TreeNode<int>(7);
    root->left->right->right = new TreeNode<int>(4);

    int x = 5, y = 1;
    cout << "LCA of " << x << " and " << y << " is: " << lowestCommonAncestor(root, x, y) << endl;

    x = 7, y = 4;
    cout << "LCA of " << x << " and " << y << " is: " << lowestCommonAncestor(root, x, y) << endl;

    return 0;
}
