// Is Binary Tree Heap



/* is Binary Tree Heap-> ( https://shorturl.at/G1WXd )



*/


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int k) {
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

//function to count nodes recursively
int countNodes(Node* root) {
    //base case
    if(root == NULL) return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

//function to check is CBT/Complete Binary Tree
bool isCBT(Node* root, int index, int cnt ) {
    if(root == NULL) return true;
    if(index >= cnt) return false;
    else {
        bool left = isCBT(root->left, 2*index+1, cnt);
        bool right = isCBT(root->right, 2*index+2, cnt);
        return (left && right);
    }
}

//function to check is cbt is MAX-HEAP or not
bool isMaxOrder(Node* root) {
    //Leaf Node
    if(root->left == NULL && root->right == NULL) return true;

    //if only left exsits
    if(root->right == NULL) {
        return (root->data > root->left->data);
    }
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}



//main function
bool isBTHeap(Node* root) {
    int ind = 0;
    int totalCnt = countNodes(root);

    if( isCBT(root, ind, totalCnt) && isMaxOrder(root) ){
        return true;
    }
    else return false;
}

//TC:- O(N logk), SC:- O(K)






int main() {

//OPtimal Soln

/*// Binary Tree Representation
//        10
//      /    \
//     9      8
//    / \    / \
//   7   6  5   4
*/

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    cout << (isBTHeap(root) ?  "true" : "false") << endl;


    return 0;
}


