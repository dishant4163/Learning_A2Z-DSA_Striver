// Maximum Width of a Binary Tree



/* // Problem-Link->
// https://www.naukri.com/code360/problems/maximum-width-in-binary-tree_763671?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   


int getMaxWidth(TreeNode<int> *root) {
    // Write your code here.
    int ans = 0;
    if(!root) return ans;

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        ans = max(ans, size);

        for(int i=0; i < size; i++) {
            TreeNode<int>* temp = q.front();
            q.pop();

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }

    return ans;
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


int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    if(!root) return ans;

    queue<pair<TreeNode* , int >> q;
    q.push({root, 0});

    while(!q.empty()) {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;

        for(int i=0; i < size; i++) {
            int cur_id = q.front().second - mmin;
            TreeNode* temp = q.front().first;
            q.pop();

            if(i == 0) first = cur_id;
            if(i == size-1) last = cur_id;

            if(temp->left) q.push({temp->left, cur_id*2+1});
            if(temp->right) q.push({temp->right, cur_id*2+2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}





int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int maxWidth = widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: " << maxWidth << endl;


    return 0;
}
