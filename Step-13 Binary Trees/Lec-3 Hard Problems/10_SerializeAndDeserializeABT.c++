// Serialize And Deserialize a Binary Tree


/* // Problem-Link->
// https://www.codingninjas.com/studio/problems/serialize-and-deserialize-binary-tree_920328?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf 


string serializeTree(TreeNode<int> *root) {
//Write your code here for serializing the tree
    if(!root) return "";
    string s = "";
    queue<TreeNode<int>* > q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* curr = q.front(); q.pop();
        if(curr == NULL) s.append("#,");
        else s.append(to_string(curr->data)+ ",");
        if(curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized) {
//Write your code here for deserializing the tree
    if(serialized.empty()) return nullptr;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>* > q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int>* node = q.front(); q.pop();

        getline(s, str, ',');
        if(str != "#") {
            TreeNode<int>* LeftNode = new TreeNode<int>(stoi(str));
            node->left = LeftNode;
            q.push(LeftNode);
        }

        getline(s, str, ',');
        if(str != "#") {
            TreeNode<int>* RightNode = new TreeNode<int>(stoi(str));
            node->right = RightNode;
            q.push(RightNode);
        }
    }
    return root;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


string serialize(TreeNode* root) {
    if(!root) return "";

    string s = "";
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        if(curr == NULL) s.append("#,");
        else s.append(to_string(curr->val) + ",");
        if(curr != NULL) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}


TreeNode* deserialize(string data) {
    if(data.empty()) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        getline(s, str, ',');
        if(str == "#") node->left = NULL;
        else {
            TreeNode* LeftNode = new TreeNode(stoi(str));
            node->left = LeftNode;
            q.push(LeftNode);
        }

        getline(s, str, ',');
        if(str == "#") node->right = NULL;
        else {
            TreeNode* RightNode = new TreeNode(stoi(str));
            node->right = RightNode;
            q.push(RightNode);
        }
    }
    return root;
}



void inorder(TreeNode* root) {
    if(!root) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}



int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
