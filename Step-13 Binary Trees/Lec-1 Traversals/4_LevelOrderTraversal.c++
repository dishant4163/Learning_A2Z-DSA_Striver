// Level Order Traversal / Level Order Traversal in Spiral form of a Binary Tree


/* // Code-Problem-Link->
// https://www.naukri.com/code360/problems/zigzag-binary-tree-traversal_920532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        ans.push_back(node->data);
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
    }

    return ans;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;

    // Default constructor for TreeNode
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with a value
    // parameter for TreeNode
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value, left
    // child, and right child
    // parameters for TreeNode
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;

        for(int i=0; i < q.size(); i++) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
            level.push_back(temp->val);
        }
        ans.push_back(level);
    }

    return ans;
}



// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the
    // vector and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {

    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> result = levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) {
        printVector(level);
    }

    return 0;
}
