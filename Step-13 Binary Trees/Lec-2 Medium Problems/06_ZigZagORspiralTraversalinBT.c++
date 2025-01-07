// Zig Zag Traversal Of Binary Tree


/* // Problem-Link->
// https://www.naukri.com/code360/problems/zig-zag-traversal_1062662   

#include<queue>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {
    // Write your code here!
    vector<int> ans;
    if(root == NULL) return ans;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    bool L2R = true;

    while(!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for(int i=0; i < n; i++) {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            int index = L2R ? i : (n - 1 - i);
            level[index] = temp->data;

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }

        // for(int i=0; i < n; i++) { // causing increase in complexity 
        //     ans.push_back(level[i]);
        // }

        // so uses this 
        ans.insert(ans.end(), level.begin(), level.end());
        L2R = !L2R;
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
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


vector<vector<int>> ZigZagLevelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);
    //declaring flag
    bool L2R = true;

    while(!q.empty()) {
        int n = q.size();
        vector<int> level(n);

        for(int i=0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            int index = L2R ? i : (n-1-i);
            level[index] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        L2R = !L2R;
        ans.push_back(level);
    }
    return ans;
}




int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get the zigzag level order traversal
    vector<vector<int>> result = ZigZagLevelOrder(root);
    for(const auto& it : result) {
        for(int ans : it) {
            cout << ans << " ";
        }
    }


}
