// Inorder Successor & Predecessor in BST


/*// Problem-Link->
// https://www.naukri.com/code360/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   


pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    // Write your code here.
    TreeNode *pre = NULL, *suc = NULL;

    while(root != NULL) {
        if(key < root->data) {
            suc = root;
            root = root->left;
        }
        else if (key > root->data) {
            pre = root;
            root = root->right;
        }
        else {
            if(root->left != NULL) {
                TreeNode *temp = root->left;
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                pre = temp;
            }
            if(root->right != NULL) {
                TreeNode *temp = root->right;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                suc = temp;
            }
            break;
        }
    }

    return {pre ? pre->data : -1, suc ? suc->data : -1};
}

*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int x){
        data = x;
        left = right = nullptr;
    }
};



pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    TreeNode *pre = NULL, *suc = NULL;

    while(root != NULL) {
        if(key < root->data) {
            suc = root;
            root = root->left;
        }
        else if (key > root->data) {
            pre = root;
            root = root->right;
        }
        else {
            if(root->left != NULL) {
                TreeNode *temp = root->left;
                while(temp->right != NULL) {
                    temp = temp->right;
                }
                pre = temp;
            }
            if(root->right != NULL) {
                TreeNode *temp = root->right;
                while(temp->left != NULL) {
                    temp = temp->left;
                }
                suc = temp;
            }
            break;
        }
    }

    return {pre ? pre->data : -1, suc ? suc->data : -1};
}




TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    TreeNode* pre = NULL;
    while(root != NULL) {
        if(root->data >= p->data) {
            root = root->left;
        } else {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}


TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode *succ = NULL;
    while(root != NULL) {
        if(p->data >= root->data) {
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }
    return succ;
}




int main() {

    TreeNode *root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->right = new TreeNode(80);
    root->right->left = new TreeNode(60);


    int key = 40;
    pair<int, int> result = predecessorSuccessor(root, key);

    cout << "Predecessor: " << result.first << "  " << "Successor: " << result.second << endl;





    cout << endl << endl;
    cout << "Individually checking Predecessor & Successor" << endl;
    TreeNode* p = root->left->right;
    TreeNode *predecessor = inorderPredecessor(root, p);
    if (predecessor != nullptr) {
        cout << "Inorder Successor of " << p->data << " is: " << predecessor->data << endl;
    } else {
        cout << "Inorder Successor of " << p->data << " does not exist." << endl;
    }

    TreeNode* successor = inorderSuccessor(root, p);
    if (successor != nullptr) {
        cout << "Inorder Successor of " << p->data << " is: " << successor->data << endl;
    } else {
        cout << "Inorder Successor of " << p->data << " does not exist." << endl;
    }


    return 0;
}
