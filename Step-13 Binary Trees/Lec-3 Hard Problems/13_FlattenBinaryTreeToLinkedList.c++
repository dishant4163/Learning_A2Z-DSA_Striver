// Flatten Binary Tree to Linked List


/*// Problem-Link->
// https://www.naukri.com/code360/problems/flatten-binary-tree-to-linked-list_1112615   


*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Soln-1 BRUTE Force 

TreeNode* prev1 = NULL;

void flatten1(TreeNode* root1) {
    if(root1 == NULL) return;

    flatten1(root1->right);
    flatten1(root1->left);

    root1->right = prev1;
    root1->left = NULL;
    prev1 = root1;
}





// Soln-2 BETTER Soln
void flatten2(TreeNode* root2) {
    if(root2 == NULL) return;

    stack<TreeNode*> st;
    st.push(root2); 

    while(!st.empty()) {
        TreeNode* cur = st.top(); st.pop();

        if(cur->right != NULL) st.push(cur->right);
        if(cur->left != NULL) st.push(cur->left);
        if(!st.empty()) {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}





// Soln-3 OPtimal Soln
void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while(curr != NULL) {
        if(curr->left) {
            TreeNode* pre = curr->left;
            while(pre->right) {
                pre = pre->right;
            }

            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}





// Print the Preorder traversal of the Orignal BT
void printPreorder(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Print the BT along the Right Pointers after Flattening
void printFlattenTree(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

// Soln-1 Brute Force
cout << "********* This is solve using Brute Force Approch ********* " << endl << endl;
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    flatten1(root);
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl << endl;

// Soln-2 Better Approach
cout << "********* This is solve using Better Approch ********* " << endl << endl;
    cout << "BT Preorder: ";
    printPreorder(root);
    cout << endl;

    flatten2(root);
    cout << "Binary Tree after Flatten: ";
    printFlattenTree(root);
    cout << endl << endl;

// Soln-3 OPtimal Soln
cout << "********* This is solve using OPtimal Soln ********* " << endl << endl;
    cout << "BT Preorder: ";
    printPreorder(root);
    cout << endl;

    flatten(root);
    cout << "Binary Tree after Flatten: ";
    printFlattenTree(root);
    cout << endl << endl;




    return 0;
}
