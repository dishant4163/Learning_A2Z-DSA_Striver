// Minimum time taken to BURN the Binary Tree from a Node 


/* // Problem-Link->
// https://www.naukri.com/code360/problems/time-to-burn-tree_630563  


int findMaxPath(BinaryTreeNode<int>* target, map<BinaryTreeNode<int>*, BinaryTreeNode<int>* >& mp) {
    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    map<BinaryTreeNode<int>*, int> visited;
    visited[target] = 1;
    int timer = 0;

    while(!q.empty()) {
        int s = q.size(), flag = 0;

        for(int i=0; i <s; i++) {
            auto node = q.front(); q.pop();

            if(node->left && !visited[node->left]) {
                flag = 1; visited[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]) {
                flag = 1; visited[node->right] = 1;
                q.push(node->right);
            }
            if(mp[node] && !visited[mp[node]]) {
                flag = 1; visited[mp[node]] = 1;
                q.push(mp[node]);
            }
        }
        if(flag) timer++;
    }

    return timer;
}

BinaryTreeNode<int>* bfs2MappedParents(BinaryTreeNode<int>* root, int start, map<BinaryTreeNode<int>*, BinaryTreeNode<int>* >& mp) {
    if(root == NULL) return NULL;

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* ans = NULL;
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); q.pop();

        if(node->data == start) ans = node;
        if(node->left) {
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            mp[node->right] = node;
            q.push(node->right);
        }
    }

    return ans;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    // Write your code here
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>* > mp;
    BinaryTreeNode<int>* target = bfs2MappedParents(root, start, mp);
    int timer = findMaxPath(target, mp);

    return timer;
}

*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


int findMaxPath(BinaryTreeNode<int>* target, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mp) {
    queue<BinaryTreeNode<int>* >q;
    q.push(target);
    map<BinaryTreeNode<int>*, int> visited;
    visited[target] = 1;
    int Timer = 0;

    while(!q.empty()) {
        int s = q.size(), flag = 0;

        for(int i=0; i < s; i++) {
            auto node = q.front(); q.pop();

            if(node->left && !visited[node->left]) {
                flag = 1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]) {
                flag = 1;
                visited[node->right] = 1;
                q.push(node->right);
            }

            if(mp[node] && !visited[mp[node]]) {
                flag = 1;
                visited[mp[node]];
                q.push(mp[node]);
            }
        }
        if(flag) Timer++;
    }
    return Timer;
}


BinaryTreeNode<int>* bfs2MapParents(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& mp, int start) {
    if(!root) return nullptr;

    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    BinaryTreeNode<int>* ans = NULL;
    while(!q.empty()) {
        BinaryTreeNode<int>* node = q.front(); q.pop();

        if(node->data == start) ans = node;

        if(node->left) {
            mp[node->left] = node;
            q.push(node->left);
        }
        if(node->right) {
            mp[node->right] = node;
            q.push(node->right);
        }
    }
    return ans;
}


int timeToBurnBT(BinaryTreeNode<int>* root, int start) {
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> mp;
    BinaryTreeNode<int>* target = bfs2MapParents(root, mp, start);
    int Timer = findMaxPath(target, mp);

    return Timer;
}



int main() {

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(6);
    root->left->left->right = new BinaryTreeNode<int>(7);

    int target = 2;

    cout << "Minimum time taken to BURN the Binary Tree from Node " << target << ": " << timeToBurnBT(root, target) << endl;

    return 0;
}
