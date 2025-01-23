// Floor in a BST


/* // Problem-Link->
// https://www.codingninjas.com/codestudio/problems/floor-from-bst_625868?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

int Floor(BinaryTreeNode<int> *node, int input){
	int floor = -1;
	while(node) {
		if(node->data == input) {
			floor = node->data;
			return floor;
		}

		if(input > node->data) {
			floor = node->data;
			node = node->right;
		} else {
			node = node->left;
		}
	}
	return floor;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        data = x;
        left = right = nullptr;
    }
};


int floorInBST(TreeNode* root, int key) {
    int floor = -1;
    while(root) {
        if(root->data == key) {
            floor = root->data;
            return floor;
        }

        if(key > root->data) {
            floor = root->data;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
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


    int target = 8;
    int res = floorInBST(root, target);

    if(res != -1){
        cout << "Floor of " << target << " is: " << res << endl;
    }
    else{
        cout << "No floor found!";
    }

    return 0;
}
