// Iterative Postorder Traversal of Binary Tree Using 1 Stack


/* // Problem-Link->
// https://www.naukri.com/code360/problems/postorder-traversal_2035933?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> postorder;
    if(root == NULL) return postorder;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        postorder.push_back(temp->data);
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }
    reverse(postorder.begin(), postorder.end());

    return postorder;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// A better approach with same O(2N) TC and O(N) space. 
// Postorder is : Left Right Root

// Reverse Postorder is: Root Right Left
// Try Finding Reverse Postorder like preorder using one stack O(N) time and O(N) space
// Then reverse the resultant vector, that will be the answer O(N) time

// Overall O(2N) time and O(N) space



vector<int> postOrder(Node* root) {
    vector<int> postorder;
    if(root == NULL) return postorder;

    stack<Node*> st;
    st.push(root);
    while(!st.empty()) {
        Node* temp = st.top();
        st.pop();
        postorder.push_back(temp->data);
        if(temp->left) st.push(temp->left);
        if(temp->right) st.push(temp->right);
    }

    reverse(postorder.begin(), postorder.end());

    return postorder;
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

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
