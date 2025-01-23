// Vertical Order Traversal of BT


/* // Problem-Link->
// https://www.naukri.com/code360/problems/vertical-order-traversal_3622711?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf     


#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root){
	// Write your code here.
    vector<int> ans;
    if(!root) return ans;

    map<pair<int, int>, multiset<int>> mpp;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0,0}});

    while(!q.empty()) {
        auto p = q.front();
        q.pop();

        TreeNode<int>* temp = p.first;
        int x = p.second.first, y = p.second.second;
        mpp[{x,y}].insert(temp->data);
        if(temp->left != NULL) q.push({temp->left, {x-1, y+1}});
        if(temp->right != NULL) q.push({temp->right, {x+1, y+1}});
    }

    for (auto it : mpp) {
        ans.insert(ans.end(), it.second.begin(), it.second.end());
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


vector<vector<int>> findVertical(Node* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node* , pair<int, int>>> todo;
    todo.push({root, {0, 0}});

    while(!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        Node* temp = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->data);

        if(temp->left) {
            todo.push({temp->left, {x-1, y+1}});
        }
        if(temp->right) {
            todo.push({temp->right, {x+1, y+1}});
        }
    }

    vector<vector<int>> ans;
    for (auto p : nodes) {
        vector<int> level;
        for(auto q : p.second) {
            level.insert(level.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(level);
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

    // Get the Vertical traversal
    vector<vector<int>> verticalTraversal = findVertical(root);

    // Print the result
    cout << "Vertical Traversal: ";
    for(auto res : verticalTraversal) {
        for(auto it : res) {
            cout << it << " ";
        }
    }

    return 0;
}
