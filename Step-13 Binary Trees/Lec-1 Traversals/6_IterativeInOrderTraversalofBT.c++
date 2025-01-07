// Iterative Inorder Traversal of BT using Stack


/* // Code-Problem-Link->
// https://www.naukri.com/code360/problems/inorder-traversal_3839605?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<stack>
vector<int> getInOrderTraversal(TreeNode *root) {
    // Write your code here.
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> inorder;

    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};



vector<int> inOrder(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> inorder;

    while(true) {
        if(node != NULL) {
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}



int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
