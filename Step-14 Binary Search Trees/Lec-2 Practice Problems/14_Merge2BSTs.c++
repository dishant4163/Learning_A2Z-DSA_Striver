// Merge 2 BST's 


// Problem-Link->
// https://www.naukri.com/code360/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar   

/* // solve Approach-1

void inorderT(TreeNode* root, vector<int>& ino) {
    if(!root) return;
    inorderT(root->left, ino);
    ino.push_back(root->data);
    inorderT(root->right, ino);
}

vector<int> mergeArr(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        } else {
            ans[k++] = b[j];
            j++;
        }
    }
    while(i < a.size()) {
        ans[k++] = a[i];
        i++;
    }
    while(j < b.size()) {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Write your code here.
    vector<int> bst1, bst2;

    inorderT(root1, bst1);
    inorderT(root2, bst2);

    return mergeArr(bst1, bst2);
}
*/


/* // Solve using Approach-2 (TC:- O(m+n), SC:- O(H1 + H2))

// Function to perform inorder traversal and store values in a vector
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

// Step 1: Convert BST into Sorted DLL in-place
void convertIntoSortedDLL(TreeNode* root, TreeNode*& head) {
    if (!root) return;

    // Recur for right subtree first
    convertIntoSortedDLL(root->right, head);

    // Link current node to head of DLL
    root->right = head;
    if (head != NULL) {
        head->left = NULL;
    }

    // Move head pointer to current node
    head = root;

    // Recur for left subtree
    convertIntoSortedDLL(root->left, head);
}

// Step 2: Merge two sorted doubly linked lists
TreeNode* mergeLL(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}


int cntLLNodes(TreeNode* head) {
    int cnt = 0;
    TreeNode *tmp = head;
    while(tmp != NULL) {
        cnt++;
        tmp = tmp->right;
    }
    return cnt;
}



// Step 3: Convert sorted DLL to balanced BST
TreeNode* sortedLLtoBST(TreeNode*& Head, int n) {
    // Base case: if the linked list is empty or has no elements
    if (n <= 0 || Head == NULL) return nullptr;

    // Recursively build the left subtree
    TreeNode* left = sortedLLtoBST(Head, n / 2);

    // The root of the BST is the current head of the linked list
    TreeNode* root = Head;
    root->left = left;  // Link left subtree

    // Move head pointer to the next node in the linked list
    Head = Head->right;

    // Recursively build the right subtree
    root->right = sortedLLtoBST(Head, n - n / 2 - 1);

    return root;
}

// Step 4: Main function to merge two BSTs
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Step-1: Convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Step-2: Merge sorted LL
    TreeNode* head = mergeLL(head1, head2);

    // Step-3: Convert sorted LL into BST
    TreeNode* bstRoot = sortedLLtoBST(head, cntLLNodes(head));

    // Step-4: Perform inorder traversal and return the result as a vector
    vector<int> result;
    inorderTraversal(bstRoot, result);
    return result;
}



*/




#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;
    TreeNode(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


//Soln-1 BRUTE Force (TC:- O(m+n), SC:- O(m+n))
 
//Step-1 Function to perform inorder traversal of the BST and store it in a vector
void inorderT(TreeNode* root, vector<int>& ino) {
    if(!root) return;

    inorderT(root->left, ino);
    ino.push_back(root->data);
    inorderT(root->right, ino);
}
 
//Step-2 Function to merge two Inorder sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        } else {
            ans[k++] = b[j];
            j++;
        }
    }

    while(i < a.size()) {
        ans[k++] = a[i];
        i++;
    }

    while(j < b.size()) {
        ans[k++] = b[j];
        j++;
    }

    return ans;
}
 
//Step-3 Inorder to BST / Function to convert a sorted array to a balanced BST
TreeNode *inorderToBST(int s, int e, vector<int>& ino) {
    if(s > e) return NULL; // base case
    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(ino[mid]);
    root->left = inorderToBST(s, mid-1, ino);
    root->right = inorderToBST(mid+1, e, ino);
    return root;
}


TreeNode *merge2BST(TreeNode *root1, TreeNode *root2) {
    //Step-1 store both BST's roots in Inorder
    vector<int> bst1, bst2;
    inorderT(root1, bst1);
    inorderT(root2, bst2);

    //Step-2 Merge 2 inorder-sorted arrays
    vector<int> mergedArr = mergeArrays(bst1, bst2);

    //Step-3 Inorder to BST for returning answer
    int start = 0, end = mergedArr.size() - 1;
    return inorderToBST(start, end, mergedArr);
}





// SOln-2 OPTIMAL Soln
// Solve using Approach-2 (TC:- O(m+n), SC:- O(H1 + H2))

//Step-1 Convert bst into sorted DLL
void convertIntoSortedDLL(TreeNode* root, TreeNode* &head) {
    if(!root) return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL) { // check head is not NUll bcz it will give NULL dLL
        head->left = NULL;
    }

    head = root;

    convertIntoSortedDLL(root->left, head);

}

//Step-2 Merge LL
TreeNode* mergeLL(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = NULL, *tail = NULL;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            if (!head) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if (!head) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}


// Count the number of nodes in the DLL
int countDLLNodes(TreeNode* head) {
    int cnt = 0;
    TreeNode* temp = head;
    while (temp) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}


// Convert sorted DLL to balanced BST
TreeNode* sortedLLtoBST(TreeNode*& head, int n) {
    if (n <= 0 || !head) return NULL;

    TreeNode* left = sortedLLtoBST(head, n / 2);
    TreeNode* root = head;
    root->left = left;

    head = head->right;
    root->right = sortedLLtoBST(head, n - n / 2 - 1);

    return root;
}

TreeNode* mergeTwoBST(TreeNode* root1, TreeNode* root2) {
    //Step-1: Convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //Step-2: Merge sorted LL
    TreeNode* head = mergeLL(head1, head2);

    //Step-3: Convert sortedLL into BST
    return sortedLLtoBST(head, countDLLNodes(head));
}






// Helper function for inorder traversal of the BST to print the result
void inorderPrint(TreeNode* root) {
    if(!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}


int main() {

// Creating first BST
    TreeNode *root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);

    // Creating second BST
    TreeNode *root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);


cout << "Solve by BRUTE Force Approch" << endl;
// Soln-1 BRUTE Force
    TreeNode* res = merge2BST(root1, root2);
    // Printing the inorder traversal of the merged BST
    inorderPrint(res);
    cout << endl << endl;



cout << "Solve by OPTIMAL Approch" << endl;
// Soln-2 OPTIMAL Soln
    TreeNode* ans = mergeTwoBST(root1, root2);
    inorderPrint(ans); 
    cout << endl << endl;




    return 0;
}
