// Find Min/Max in BST


/* // Problem-Link-> Find Minimum Element in BST
// https://www.naukri.com/code360/problems/minimum-element-in-bst_8160462

int minVal(Node* root){
	// Write your code here.
	if(root == nullptr) return -1;

	while(root->left != nullptr) {
		root = root->left;
	}
	return root->data;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = right = nullptr;
    }
};


// Function to find the minimum value in the BST
int findMin(TreeNode* root) {
    if(!root) return -1;

    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum value in the BST
int findMax(TreeNode* root) {
    if(!root) return -1;

    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}



int main() {

    // Constructing the BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(10);

    // Find the minimum and maximum value in the BST
    int minVal = findMin(root);
    int maxVal = findMax(root);

    cout << "Minimum value in the BST: " << minVal << endl;
    cout << "Maximum value in the BST: " << maxVal << endl;

    return 0;
}
