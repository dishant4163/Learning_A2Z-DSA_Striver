// Print all the Nodes at a distance of K in a Binary Tree


/* // PRoblem-Link->
// https://www.codingninjas.com/studio/problems/print-nodes-at-distance-k-from-a-given-node_842560?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  


void markParents(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent_track) {
    queue<BinaryTreeNode<int>* > q;
    q.push(root);

    while(!q.empty()) {
        BinaryTreeNode<int>* temp = q.front(); q.pop();
        if(temp->left) {
            parent_track[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right) {
            parent_track[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_Track;
    markParents(root, target, parent_Track);

    unordered_map<BinaryTreeNode<int>*, bool> visited;
    queue<BinaryTreeNode<int>* > q;
    q.push(target);
    visited[target] = true;
    int curr_dist = 0;

    while(!q.empty()) {
        int size = q.size();
        if(curr_dist++ == K) break;

        for(int i=0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front(); q.pop();
            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent_Track[node] && !visited[parent_Track[node]]) {
                q.push(parent_Track[node]);
                visited[parent_Track[node]] = true;
            }
        }
    }

    vector<BinaryTreeNode<int>*> ans;
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); q.pop();
        ans.push_back(node); //// Push the actual node pointer
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


void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_Track, TreeNode* target) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front(); 
        q.pop();

        if(curr->left) {
            parent_Track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            parent_Track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_Track; // node->parent
    markParents(root, parent_Track, target);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int curr_distance = 0;

    while(!q.empty()) {
        int size = q.size();
        if(curr_distance++ == k) break;

        for(int i=0; i < size; i++) {
            TreeNode* curNode = q.front(); q.pop();

            if(curNode->left && !visited[curNode->left]) {
                q.push(curNode->left);
                visited[curNode->left] = true;
            }
            if(curNode->right && !visited[curNode->right]) {
                q.push(curNode->right);
                visited[curNode->right] = true;
            }
            if(parent_Track[curNode] && !visited[parent_Track[curNode]]) {
                q.push(parent_Track[curNode]);
                visited[parent_Track[curNode]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        ans.push_back(node->val);
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

    TreeNode* target = root->left;
    int k = 2;
    // Find nodes at distance 2 from the target node
    vector<int> result = distanceK(root, target, k); 

    // Print the elements at distance k from the target node
    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
