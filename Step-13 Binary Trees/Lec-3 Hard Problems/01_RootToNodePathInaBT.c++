// Print Root to Node Path in a Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/path-in-a-tree_3843990

bool getPath(TreeNode<int>* root, int x, vector<int>& ar) {
	if(!root) return false;

	ar.push_back(root->data);
	if(root->data == x) return true;

	if( getPath(root->left, x, ar) || getPath(root->right, x, ar) ) return true;

	ar.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x) {
    // Write your code here.
	vector<int> ans;
	if (root == NULL) return ans;

	getPath(root, x, ans);

	return ans;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool getPath(TreeNode* root, int x, vector<int>& ar) {
	if(!root) return false;

	ar.push_back(root->data);
	if(root->data == x) return true;

	if( getPath(root->left, x, ar) || getPath(root->right, x, ar) ) return true;

	ar.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode* root, int x) {
    // Write your code here.
	vector<int> ans;
	if (root == NULL) return ans;

	getPath(root, x, ans);

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

    int targetLeafValue = 7;

    vector<int> path = pathInATree(root, targetLeafValue);

    cout << "Path from root to leaf with value " << targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }



    return 0;
}
