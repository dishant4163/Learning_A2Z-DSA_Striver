// Largest BST in Binary Tree


/*// Problem-Link->
// https://www.naukri.com/code360/problems/size-of-largest-bst-in-binary-tree_893103?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


class NodeValue {
public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue bstSubtreeHelper(TreeNode* root) {
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

    auto left = bstSubtreeHelper(root->left);
    auto right = bstSubtreeHelper(root->right);

    if (left.maxNode < root->data && root->data < right.minNode) {
        return NodeValue(min(root->data, left.minNode), 
        max(root->data, right.maxNode), 
        left.maxSize + right.maxSize + 1);
    }

    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}


int largestBST(TreeNode * root){
    // Write your code here.
    return bstSubtreeHelper(root).maxSize;
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

// SOLN-1 BRUTE Force Approach

// Function to check if a given root is a valid BST
bool isValidBST(TreeNode *root, int minVal, int maxVal) {
    if(!root) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

// Function to count the number of nodes given the root of a subtree
int countNodes(TreeNode* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the size of the largest BST subtree
int largestBSTSubTree(TreeNode* root) {
    if(!root) return 0;

    if(isValidBST(root, INT_MIN, INT_MAX)) {
        return countNodes(root);
    }
    else {
        int left = largestBSTSubTree(root->left);
        int right = largestBSTSubTree(root->right);
        return max(left, right);
    }
}





// Soln-2 OPTIMAL SOln
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
    private:
    NodeValue laregestBSTSubtreeHelper(TreeNode* root) {
        // Doing PostOrder Traversal
        //an empty tree is BST of size 0
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // get values from left & right subtree of current tree
        auto left = laregestBSTSubtreeHelper(root->left);
        auto right = laregestBSTSubtreeHelper(root->right);

    // Current node is greater than max in left AND smaller than min in right, it is a BST
        if(left.maxNode < root->val && root->val < right.minNode) {
            // it is a BST
            return NodeValue(min(root->val, left.minNode),
             max(root->val, right.maxNode),
             left.maxSize + right.maxSize + 1);
        }

    // OtherWise, return [-inf, inf] so that parent can't be vaild BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    public:
    int largestBSTSubtree(TreeNode *root) {
        return laregestBSTSubtreeHelper(root).maxSize;
    }
};





// Utility function to insert nodes into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// Utility function to perform inorder traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}


int main() {
Solution soln;

    // Create the BST
    TreeNode* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);

    // Create a new tree, attaching the
    // BST root as the left child of a new root
    TreeNode* newRoot = new TreeNode(6);
    newRoot->left = root;
    newRoot->right = new TreeNode(3);

cout << "Solve using Brute Force Approach" <<endl << endl;

    // Display the original tree using inorder traversal
    cout << "Original BST: ";
    inorderTraversal(newRoot);
    cout << endl;

    // Find the size of the largest BST subtree
    int largestBSTsize = largestBSTSubTree(newRoot);
    
    // Display the size of the largest BST subtree found
    cout << "Size of the largest BST subtree: " << largestBSTsize << endl << endl;


// Soln-2 OPTIMAL Soln
cout << "Solve using OPTIMAL Approach" << endl << endl;

    // Display the original tree using inorder traversal
    cout << "Original BST: ";
    inorderTraversal(newRoot);
    cout << endl;

    // Find the size of the largest BST subtree
    int largestBSTSize = soln.largestBSTSubtree(newRoot);
    
    // Display the size of the largest BST subtree found
    cout << "Size of the largest BST subtree: " << largestBSTSize << endl;



    return 0;
}
