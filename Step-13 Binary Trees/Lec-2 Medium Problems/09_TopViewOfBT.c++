// Top-View of Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/top-view-of-binary-tree_799401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf   

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode<int>* temp = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end()) mpp[line] = temp->data;

        if(temp->left != NULL) {
            q.push({temp->left, line-1});
        }
        if(temp->right != NULL) {
            q.push({temp->right, line+1});
        }
    }

    for(auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};



vector<int> topView(Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        Node* temp = it.first;
        int line = it.second;

        if(mp.find(line) == mp.end()) mp[line] = temp->data;

        if(temp->left != NULL) q.push({temp->left, line-1});
        if(temp->right != NULL) q.push({temp->right, line+1});
    }

    for(auto it : mp) {
        ans.push_back(it.second);
    }

    return ans;
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int> res = topView(root);

    // Print the result
    cout << "Top View Traversal: ";
    for(auto node: res){
        cout << node << " ";
    }

    return 0;
}
