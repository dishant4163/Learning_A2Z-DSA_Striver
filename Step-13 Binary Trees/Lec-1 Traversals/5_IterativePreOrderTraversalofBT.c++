// Iterative PreOrder Traversal of BT using Stack


/* // Code-Problem-link->
// https://www.naukri.com/code360/problems/preorder-binary-tree_5948?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf     

#include<bits/stdc++.h>
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> preorder;

    if(root == NULL) {
        return preorder;
    }

    stack<TreeNode<int>*> st;
    st.push(root);

    while(!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != nullptr) {
            st.push(root->right);
        }
        if(root->left != nullptr) {
            st.push(root->left);
        }
    }

    return preorder;
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


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    if(root == nullptr) {
        return preorder;
    }

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != nullptr) {
            st.push(root->right);
        }
        if(root->left != nullptr) {
            st.push(root->left);
        }
    }

    return preorder;
}




int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Getting the preorder traversal
    vector<int> result = preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}
