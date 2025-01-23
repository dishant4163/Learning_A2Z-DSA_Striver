// BST Iterator


/* // Problem Link->
// https://www.naukri.com/code360/problems/bst-iterator_1112601  


class BSTiterator {
    private:
    stack<TreeNode<int>* > st;

    void pushAll(TreeNode<int>* node) {
        for(; node != NULL; st.push(node), node = node->left);
    }

    public:
    BSTiterator(TreeNode<int> *root) {
        // write your code here
        pushAll(root);
    }

    int next() {
        // write your code here
        TreeNode<int>* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }

    bool hasNext() {
        // write your code here
        return !st.empty();
    }
};


    // Your BSTIterator object will be instantiated and called as such:
    // BSTIterator iterator(root);
    // while(iterator.hasNext())
    // {
    //     print(iterator.next());
    // }

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    // Value of the node
    int val;
    // Pointer to the left child node
    TreeNode* left;
    // Pointer to the right child node
    TreeNode* right;
    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BRUTE Force
class BSTiterator {
    private:
    vector<int> inorderTraversal;
    int ptr;

    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        inorderTraversal.push_back(root->val);
        inOrder(root->right);
    }

    public:
    BSTiterator(TreeNode* root) {
        ptr = -1;
        inOrder(root);
    }

    bool HasNext() {
        return ptr + 1 < inorderTraversal.size();
    }

    int Next() {
        ptr++;
        return inorderTraversal[ptr];
    }
};




// OPtimal SOln 
class BSTIterator {
    private:
    stack<TreeNode*> st;

    public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    private:
    void pushAll(TreeNode *node) {
        for(; node != NULL; st.push(node), node = node->left);
    }
};





void printInOrder(TreeNode* root) {
    if(!root) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}


int main() {

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    
    cout << "Tree Initialised: ";
    printInOrder(root);
    cout << endl << endl;

    BSTiterator bstIterator1(root);

    // Function calls and their outputs
    cout << "Functions Called:" << endl;
    cout << "BSTIterator()" << endl;
    cout << "next(): " << bstIterator1.Next() << endl;
    cout << "next(): " << bstIterator1.Next() << endl;
    cout << "hasNext(): " << (bstIterator1.HasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator1.Next() << endl;
    cout << "hasNext(): " << (bstIterator1.HasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator1.Next() << endl;
    cout << "hasNext(): " << (bstIterator1.HasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator1.Next() << endl;
    cout << "hasNext(): " << (bstIterator1.HasNext() ? "true" : "false") << endl;
cout << endl << endl;



// OPtimal Soln

    cout << "Tree Initialised: ";
    printInOrder(root);
    cout << endl;
// Create a BSTIterator object initialized with the root of the BST
    BSTIterator bstIterator(root);

// Function calls and their outputs
    cout << "Functions Called:" << endl;
    cout << "BSTIterator()" << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;





    return 0;
}
