// Construct a BT from Inorder & Postorder Traversal


/* // Problem-Link->
// https://www.naukri.com/code360/problems/construct-binary-tree-from-inorder-and-postorder-traversal_1266106   

TreeNode<int>* help2BuildBT(vector<int>& inO, int inStart, int inEnd, vector<int>& postO, int postStart, int postEnd, map<int, int>& mp) {
    if(postStart > postEnd || inStart > inEnd) return NULL;

    TreeNode<int>* root = new TreeNode<int> (postO[postEnd]);
    int inRoot = mp[postO[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = help2BuildBT(inO, inStart, inRoot-1, postO, postStart, postStart+numsLeft-1, mp);
    root->right = help2BuildBT(inO, inRoot+1, inEnd, postO, postStart + numsLeft, postEnd-1, mp);

    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	// Write your code here.
    if(inOrder.size() != postOrder.size()) return NULL;

    map<int,int> mp;
    for(int i=0; i < inOrder.size(); i++) {
        mp[inOrder[i]] = i;
    }

    return help2BuildBT(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1, mp);
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


TreeNode* help2BuildBT(vector<int>& inO, int inStart, int inEnd, vector<int>& postO, int postStart, int postEnd, map<int,int>& mp) {
    if(inStart > inEnd || postStart > postEnd) return NULL;

    TreeNode* root = new TreeNode(postO[postEnd]);
    int inRoot = mp[postO[postEnd]];
    int numsLeft = inRoot - inStart;

    root->left = help2BuildBT(inO, inStart, inRoot-1, postO, postStart, postStart + numsLeft-1, mp);
    root->right = help2BuildBT(inO, inRoot+1, inEnd, postO, postStart + numsLeft, postEnd-1, mp);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size()) return NULL;

    map<int, int> mp;
    for(int i=0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    return help2BuildBT(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
}


// Function to print the inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Function to print the given vector
void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


int main() {

    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    // Display the input vectors
    cout << "Inorder Vector: ";
    printVector(inorder);
    cout << endl;

    cout << "Postorder Vector: ";
    printVector(postorder);
    cout << endl;

    // Build the BT & print its inorder traversal
    TreeNode* root = buildTree(inorder, postorder);

    cout << "Unique Binary Tree Created from Inorder and PostOrder Traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}
