// Kth largest/smallest element in BST


/*// Problem-Link->
// https://www.naukri.com/code360/problems/kth-smallest-node-in-bst_920441?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf    


void inorder(TreeNode<int>* root, vector<int>& v) {
    if(root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int kthSmallest(TreeNode<int> *root, int k) {
    //  Write the code here.
    vector<int> ar;
    inorder(root, ar);

    int kSmall = ar[k-1];
    return kSmall;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};



//Soln-1_Brute Force Approach
void inOrder(TreeNode *root, vector<int>& ar) {
    if(!root) return;

    inOrder(root->left, ar);
    ar.push_back(root->data);
    inOrder(root->right, ar);
}

// Function to find Kth smallest and Kth largest elements
pair<int, int> findKth(TreeNode *node, int K) {
    vector<int> ar;
    inOrder(node, ar);

    int Klargest = ar[ar.size() - K];
    int KSmallest = ar[K-1];

    return {KSmallest, Klargest}; // return make_pair(kSmallest, kLargest)
}





//Soln-2_OPtimal Approach
// Helper function to perform reverse inorder traversal to find Kth largest element
void reverseInorder(TreeNode* node, int& count, int k, int& kLarge){
    if(!node || count >= k) return;

    reverseInorder(node->right, count, k, kLarge);
    count++;
    if(count == k) {
        kLarge = node->data;
        return;
    }
    reverseInorder(node->left, count, k, kLarge);
}

// Helper function to perform inorder traversal to find Kth smallest element
void inorder(TreeNode* node, int& count, int k, int& kSmall) {
    if(!node || count >= k)return;

    inorder(node->left, count, k, kSmall);
    count++;
    if(count == k) {
        kSmall = node->data;
        return;
    }
    inorder(node->right, count, k, kSmall);
}

// Function to find Kth smallest and Kth largest elements
pair<int, int> findkth(TreeNode *root, int k) {
    int  kSmallest = INT_MIN, kLargest = INT_MIN;

    int cnt = 0;
    inorder(root, cnt, k, kSmallest);
    cnt = 0;
    reverseInorder(root, cnt, k, kLargest);

    return make_pair(kSmallest, kLargest);
}






void printInOrder(TreeNode *root) {
    if(root == NULL) return;

    printInOrder(root->left);
    cout << root->data <<" ";
    printInOrder(root->right);
}

int main() {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

cout << "Solve using *** BRUTE Force Approach ***" <<endl;
    cout << "Binary Search Tree: " ;
    printInOrder(root);
    cout << endl;

    int K = 3; 
    cout << "K = " << K << endl;

    // Find the Kth smallest and Kth largest elements
    pair<int, int> KthElements = findKth(root, K);

    // Output the results
    cout << "Kth smallest element: " << KthElements.first << endl;
    cout << "Kth largest element: " << KthElements.second << endl << endl;



cout << "Solve using *** OPtimal Approach ***" << endl;
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = findkth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;





    return 0;
}
