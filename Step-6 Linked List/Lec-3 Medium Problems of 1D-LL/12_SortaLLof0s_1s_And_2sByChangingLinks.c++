/*//(Sort a LL of 0's, 1's and 2's By Changing Links_Coding Ninja)-> https://tinyurl.com/4mv3k36t      

Node* sortList(Node *head){
    // Write your code here.
    if (head == NULL || head->next == NULL) return head;

    // Initialize dummy nodes for 0's, 1's, and 2's
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp != NULL) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        }
        else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Terminate the last nodes of each list
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = nullptr;

    // Update the new head  
    Node* newHead = zeroHead->next;
    // clean up dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}


*/




#include<bits/stdc++.h>
using namespace std;


// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};





/*//Soln 1: Brute Force(traversing & changing data)
   Approach:-
 The idea is to traverse the linked List and count the number of nodes having values 0, 1 and 2 and store them in an array of size 3, say cnt[] such that:
    cnt[0] = count of nodes with value 0
    cnt[1] = count of nodes with value 1
    cnt[2] = count of nodes with value 2
 Now, traverse the linked list again to fill the first cnt[0] nodes with 0, then next cnt[1] nodes with 1 and finally cnt[2] nodes with 2.


   Complexity Analysis:-
 # TC:- O(2N)
 # SC:- O(1)

*/
Node* sortLList0s1s2s(Node *head){
    // Write your code here.
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    while(temp != NULL) {
        if(temp->data == 0) cnt0 ++;
        else if (temp->data == 1) cnt1++;
        else cnt2++;

        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if (cnt0) {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1) {
            temp->data = 1;
            cnt1--;
        }
        else {
            temp->data = 2;
            cnt2--;
        }

        temp = temp->next;
    }

    return head;
}





/*//Soln 2: Optimal(by changing Links)     
   Approach:
The idea is to maintain 3 pointers named zero, one and two to point to current ending nodes of linked lists containing 0, 1, and 2 respectively. For every traversed node, we attach it to the end of its corresponding list:
    If the current node’s value is 0, append it after pointer zero and move pointer zero to current node.
    If the current node’s value is 1, append it after pointer one and move pointer one to current node.
    If the current node’s value is 2, append it after pointer two and move pointer two to current node.
Finally, we link all three lists. To avoid many null checks, we use three dummy pointers zeroD, oneD and twoD that work as dummy headers of three lists.


   Complexity Analysis:-
 # TC:- O(N)
 # SC:- O(1)
*/
Node* sortLL0s1s2s(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Initialize dummy nodes for 0's, 1's, and 2's
    Node* zerodummyHead = new Node(-1);
    Node* onedummyHead = new Node(-1);
    Node* twodummyHead = new Node(-1);

    Node* zero = zerodummyHead;
    Node* one = onedummyHead;
    Node* two = twodummyHead;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Terminate the last nodes of each list
    zero->next = (onedummyHead->next) ? (onedummyHead->next) : (twodummyHead->next);
    one->next = twodummyHead->next;
    two->next = NULL;

    // Get the new head and clean up dummy nodes
    Node* newHead = zerodummyHead->next;

    delete zerodummyHead;
    delete onedummyHead;
    delete twodummyHead;

    return newHead;
}






// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}


int main() {

// Soln 1: Brute Force
    //Create a linked list: 1->1->2->1->0->NULL 
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printLinkedList(head);

    sortLList0s1s2s(head);

    cout << "Linked List after Sorting:";
    printLinkedList(head);



//Soln 2: Optimal
//Create a linked list: 1->0->2->2->0->NULL 
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printLinkedList(head);

    head = sortLL0s1s2s(head);

    cout << "Linked List after Sorting:";
    printLinkedList(head);





    return 0;
}
