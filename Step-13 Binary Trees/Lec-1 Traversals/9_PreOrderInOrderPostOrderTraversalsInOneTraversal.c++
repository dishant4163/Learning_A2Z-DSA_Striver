// Preorder Inorder Postorder Traversals in One Traversal


/* // Problem-Link->
// https://www.naukri.com/code360/problems/tree-traversals_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    


vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> ino, pre, post;
    // If the tree is empty, return empty traversals
    if(root == NULL) return {ino, pre, post};

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            ino.push_back(it.first->data);
            it.second = 3;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }

    return {ino, pre, post};
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



vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> pre, ino, post;
    // If the tree is empty, return empty traversals
    if(root == NULL) return {pre, ino, post};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second = 2;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2) {
            ino.push_back(it.first->data);
            it.second = 3;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    // vector<vector<int>> res;
    // res.push_back(pre);
    // res.push_back(in);
    // res.push_back(post);
    // return res;

    // another way
    return {pre, ino, post};
}



// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}




// Main function
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}