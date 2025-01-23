// (Two Sum - iv) in BST | Check if there exists a pair with Sum K


/*// Problem Link->
// https://www.naukri.com/code360/problems/pair-sum-in-bst._920493?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


class BSTit{
    private:
    stack<BinaryTreeNode *> st;
    bool revIno = true; // means RightNodeLeft

    void pushAll(BinaryTreeNode * node) {
        while (node != NULL) {
            st.push(node);
            if(revIno == true) node = node->right;
            else node = node->left;
        }
    }

    public:
    BSTit (BinaryTreeNode *root, bool isRev) {
        revIno = isRev;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        BinaryTreeNode *temp = st.top();
        st.pop();
        if(!revIno) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }
};


bool pairSumBst(BinaryTreeNode *root, int k) {
    // Write your code here
    if(!root) return false;

    BSTit l(root, false);
    BSTit r(root, true);

    int i = l.next(), j = r.next();

    while(i < j) {
        if(i+j == k) return true;
        else if (i+j < k) i = l.next();
        else j = r.next();
    }
    return false;
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Soln-1 BRUTE Force
// TC:- O(n) + O(n) = O(2n),  SC:- O(n)

void inoderTraversal(TreeNode* root, vector<int>& inorder) {
    if(!root) return;

    inoderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inoderTraversal(root->right, inorder);
}

bool findtarget1(TreeNode* root, int k) {
    vector<int> inorder;
    inoderTraversal(root, inorder);

    int l = 0, r = inorder.size() - 1;
    while(l < r) {
        int sum = inorder[l] + inorder[r];
        if(sum == k) return true;
        else if(sum < k) l++;
        else r--;
    }

    return false;
}





// Soln-2 OPtimal
// TC:- O(N), SC:- O(H)

class BSTiterator{
    private:
    stack<TreeNode *> st;
    // reverse = true means before() or RightNodeLeft
    // reverse = false means next() or LeftNodeRight
    bool reverse = true;

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            if(reverse == true) node = node->right;
            else node = node->left;
        }
    }

    public:
    BSTiterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode *temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }
};


class Solution {
public:

bool findTarget(TreeNode* root, int k) {
    if(root == NULL) return false;

    BSTiterator l(root, false); //means next()
    BSTiterator r(root, true); // means before()

    int i = l.next(), j = r.next(); // j means r.before()
    while(i < j) {
        if(i + j == k) return true;
        else if (i + j < k) i = l.next();
        else j = r.next();
    }

    return false;
}

};




void printInOrder(TreeNode* root) {
    if(!root) return;
    printInOrder(root->left);
    cout << root->data <<" ";
    printInOrder(root->right);
}

int main() {

    //Sample BST-> 7 3 15 -1 -1 9 20
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Tree Initialized: ";
    printInOrder(root);
    cout << endl << endl;


// SOLN-1 Brute Force but only case of interview 
// else for coding platform it is optimal soln
// TC- O(2N), SC:- O(N)
cout << "Solve using BRUTE Approach  => ";
    int Target = 10;
    bool res = findtarget1(root, Target);
    if (res) {
        cout << "Pair with sum " << Target << " exists." << endl;
    } else {
        cout << "Pair with sum " << Target << " does not exist." << endl;
    }
cout << endl;


// Soln-2 Optimal Approach
cout << "Solve using OPTIMAL Approach  => ";
Solution sol;
    int target = 22;
    bool exists = sol.findTarget(root, target);
    if (exists) {
        cout << "Pair with sum " << target << " exists." << endl;
    } else {
        cout << "Pair with sum " << target << " does not exist." << endl;
    }



    return 0;
}
