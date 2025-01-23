// Construct a BT from Inorder & Preorder Traversal


/* // Problem-Link->
// https://www.naukri.com/code360/problems/construct-binary-tree-from-inorder-and-preorder-traversal_920539?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

TreeNode<int>* help2BuildBT(vector<int>&preO, int preStart, int preEnd, vector<int>& inO, int inStart, int inEnd, map<int, int> inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode<int>* root = new TreeNode<int> (preO[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = help2BuildBT(preO, preStart+1, preStart + numsLeft, inO, inStart, inRoot-1, inMap);
    root->right = help2BuildBT(preO, preStart + numsLeft + 1, preEnd, inO, inRoot+1, inEnd, inMap);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
	// Write your code here
    map<int, int> inMap;
    for(int i=0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode<int>* root = help2BuildBT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper Function
TreeNode* help2BuildBT(vector<int>& preO, int preStart, int preEnd, vector<int>& inO, int inStart, int inEnd, map<int, int> inMap) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preO[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = help2BuildBT(preO, preStart+1, preStart + numsLeft, inO, inStart, inRoot-1, inMap);
    root->right = help2BuildBT(preO, preStart+numsLeft+1, preEnd, inO, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap;
    for(int i=0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    TreeNode* root = help2BuildBT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    return root;
}


// Function to print the inorder traversal of a tree
void printInorder(TreeNode* root){
    if(!root) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print the given vector
void printVector(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Preorder Vector: ";
    printVector(preorder);

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created: ";
    printInorder(root);
    cout << endl;


    return 0;
}
