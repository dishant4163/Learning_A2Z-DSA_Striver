// Convert BST to Min Heap


/*Convert BST to MinHeap-> (https://shorturl.at/EmyVP)

#include <bits/stdc++.h> 
//Following is the Binary Tree node structure:

// class BinaryTreeNode {

// public :
// 	int data;
// 	BinaryTreeNode* left;
// 	BinaryTreeNode* right;

// 	BinaryTreeNode(int data) {
// 	this -> left = NULL;
// 	this -> right = NULL;
// 	this -> data = data;
// 	}
// };



void inorderTravers(BinaryTreeNode* root, vector<int>& inOrderAr) {
	if(root == NULL) return;

	inorderTravers(root->left, inOrderAr); // left subtree
	inOrderAr.push_back(root->data); // visit node
	inorderTravers(root->right, inOrderAr); // right subtree
}

void preBuildMinHeap(BinaryTreeNode* root, vector<int>& inOrderAr, int& index) {
	if(root == NULL) return;

	root->data = inOrderAr[index++];
	preBuildMinHeap(root->left, inOrderAr, index);
	preBuildMinHeap(root->right, inOrderAr, index);
}


BinaryTreeNode* convertBST(BinaryTreeNode* root) {
	// Write your code here.
	vector<int> ans;

	//Step-1 Perform InOrder traversal to get all elements in sorted array
	inorderTravers(root, ans);

	//Step-2 Rebuild the tree from the sorted elements
	int i = 0;
	preBuildMinHeap(root, ans, i);

// return Root of the tree
	return root;
}

*/



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


//function to perform in-order traversal and store the elements in a vector
void inorderTraver(Node* root, vector<int>& arEl) {
    if(root == NULL) return;

    inorderTraver(root->left, arEl); // left subtree
    arEl.push_back(root->data); // visit node
    inorderTraver(root->right, arEl); // right subtree
}

//function to rebuild the tree from the sorted elements
void buildMinHeap(Node* root, vector<int>& arEl, int& index) {
    if(root == NULL) return;

    //Update root data to current element in sorted array
    root->data = arEl[index++];
    //recursive call on the Left-Subtree
    buildMinHeap(root->left, arEl, index);
    //recursive call on the right-Subtree
    buildMinHeap(root->right, arEl, index);
}



//Main function to convert BST to Min Heap
void BST2MinHeap(Node* root) {
    //Step-1 Perform InOrder traversal to get all elements in sorted array
    vector<int> ans;
    inorderTraver(root, ans);

    //Step-2 Rebuild the tree from the sorted elements
    int ind = 0;
    buildMinHeap(root, ans, ind);
}


// Function to print the tree (in-order traversal)
void printInorder(Node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    printInorder(root->left);
    printInorder(root->right);

}



int main() {

// Constructing the Binary Search Tree (BST)
/*//Example Tree
//          4
//        /   \
//       2     6
//      / \   / \
//     1   3 5   7
*/
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);


    //Convert the BST to a Min Heap
    BST2MinHeap(root);

    cout << "Converted Min Heap (In-order): ";
    printInorder(root);
    cout << endl;


    return 0;
}

