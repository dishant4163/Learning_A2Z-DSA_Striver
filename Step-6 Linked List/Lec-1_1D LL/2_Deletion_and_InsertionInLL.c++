// Deletion & Insertion in 1D LinkedList

/*//(Delete Node In A LinkedList_Coding Ninja)-> https://shorturl.at/cQ2Ve     



*/



#include<bits/stdc++.h>
using namespace std;


// Node class for a linked list
class Node {
public:
    int data; // Data of the node
    Node* next; // Pointer to the next node in the list

// Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

// Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};



// Function to return HEAD of LL
Node* functHead(vector<int>&arr) {
    Node* head = new Node{arr[0]};
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i]};
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//Function to print the linked list starting from the given head
void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}





// DELETION in LinkedList(head, tail, kth/position, value/element)
/*//1.1__Delete HEAD of the LL:
// Function to delete the HEAD node of a LL & return the new head
Node* removesHead(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
*/



/*//1.2__Delete the TAIL of the LL:
Node* removesTail(Node* head) {
    //If the list is empty or has only 1 node, return NULL
    if (head == NULL || head->next == NULL) return NULL;
    // Initialize a temp pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    free(temp->next);//or delete temp->next;
    // Set the next of the second last node to nullptr,
    // effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;    
}
*/



/*//1.3__Delete Kth element of the LL:
Node* removesKthEle(Node* head, int k) {
    //Edge Case-1, if LL is empty
    if (head == NULL) return head;
    // Edge Case-2, if LL have only 1 elle
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //Edge Case-3
    int cnt =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;

        if (cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
*/



/*//1.4__Delete given Value of the LL:
Node* deleteVal(Node* head, int val) {
    if (head == NULL) return head;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if (temp->data == val) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
*/










int main() {

/*//1.1__Delete Head of the LL:
    vector<int> ar1 = {1, 2, 3, 4, 5};
    Node* head = functHead(ar1);
    head = removesHead(head);
    print(head);
*/


/*//1.2__Delete TAIL of the LL:
    vector<int> ar2 = {11, 22, 33, 44};
    Node* head = functHead(ar2);
    //Call the deleteTail function to delete the last node
    head = removesTail(head);
    printLL(head);// Print the LL after deletion tail
*/


/*//1.3__Delete Kth element of the LL:
    vector<int> ar3 = {3, 9, 15, 21, 27};
    int k = 3;
    Node* head = functHead(ar3);
    head = removesKthEle(head, k);
    printLL(head);
*/


/*//1.4__Delete given Value of the LL:
    vector<int> ar4 = {3, 9, 15, 21, 27};
    int val = 27;
    Node* head = functHead(ar4);
    head = deleteVal(head, val);
    printLL(head);
*/






    return 0;
}
