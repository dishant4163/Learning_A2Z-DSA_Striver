/*//(Reverse Linked List in groups of Size K_Coding Ninja)->  https://tinyurl.com/4dbz8fnn    


Node* reverseLL(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* getKthNode(Node* temp, int k) {
    k -= 1;
    while(temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp != NULL) {
        Node* kthNode = getKthNode(temp, k);
        if (kthNode == NULL) {
            if(prevLast) prevLast->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (temp == head) {
            head = kthNode;
        } else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}


*/


/* Problem Statement: 
 Given the head of a singly linked list of `n` nodes and an integer `k`, where k is less than or equal to `n`. Your task is to reverse the order of each group of `k` consecutive nodes, if `n` is not divisible by `k`, then the last group of remaining nodes should remain unchanged.


Example:
 Input Format-> LL: 1  2  3  4  5  6  7  8  9  10 , K=3
 Output: 3  2  1  6  5  4  9  8  7  10
   Explanation:
  Group 1: Reverse nodes 1 -> 2 -> 3 to become 3 -> 2 -> 1.
  Group 2: Reverse nodes 4 -> 5 -> 6 to become 6 -> 5 -> 4.
  Group 3: Reverse nodes 7 -> 8 -> 9 to become 9 -> 8 -> 7.
  Node 10 remains as is since there are no more groups of size K remaining.
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

/* Approach:-
 The approach simplifies reversing linked list nodes by breaking the list into segments of K nodes and reversing each segment individually. Starting from the head, the algorithm traverses the list to identify segments of K nodes. Upon finding a segment, it reverses it, returning the modified list. If a segment has less than K nodes left (ie. remaining nodes at the end), they are left unaltered. 

 To implement this (complex) algorithm we can break down the process into three parts:

 `reverseLinkedList`: This function takes the head of a segment as input and reverses the linked list formed by that segment. It operates by utilizing the classic iterative 3-pointer method to reverse the direction of pointers within the segment. Read about this algorithm in detail here Reverse Linked List.

 `getKthNode`: The purpose of this function is to identify the end of a segment of K nodes in the linked list. Given a starting node, it traverses K nodes in the list and returns the Kth node, allowing the segmentation of the list into smaller parts for reversal.

 `kReverse`: The main function orchestrates the reversal process. It iterates through the linked list and identifies segments of K nodes using getKthNode. For each identified segment, it utilizes reverseLinkedList to reverse the nodes within that segment. This iterative approach efficiently reverses the linked list nodes in groups of K.


   Algorithm:-
 Step 1: Initialise a pointer `temp` to the head of the linked list. Using `temp`, traverse to the Kth Node iteratively.

 Step 2: On reaching the Kth Node, preserve the Kth Node’s next node as `nextNode` and set the Kth Node’s next pointer to `null`. This effectively breaks the linked list in a smaller list of size K that can be reversed and attached back.
 Step 3: Treat this segment from `temp` to Kth Node as an individual linked list and reverse it. This can be done via the help of a helper function `reverseLinkedList` which has been discussed in detail in this article Reverse Linked List.
 Step 4: The reversed linked list segment returns a modified list with `temp` now at its tail  and the `KthNode` pointing to its head. Update the `temp`s `next` pointer to `nextNode`.
    If we are at the first segment of K nodes, update the head to `Kth Node`.
 Step 5: Continue this reversal for further groups. If a segment has fewer than K Nodes, leave them unmodified and return the new head. Use the prevLast pointer to maintain the link between the end of the previous reversed segment and the current segment.


   Complexity Analysis:-
  # Time Complexity: O(2N) The time complexity consists of actions of reversing segments of K and finding the Kth node which operates in linear time. Thus, O(N) + O(N) = O(2N), which simplifies to O(N).
  # Space Complexity: O(1) The space complexity is O(1) as the algorithm operates in place without any additional space requirements.
*/

Node* reverseLL(Node* head) {
// using iterative way to Reverse LL:
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Function to get the Kth Node in the LL:
Node* getKthNode(Node* temp, int k) {
    k -= 1;
    while(temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}


Node* kReverse(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;
    while(temp != NULL) {
        Node* kthNode = getKthNode(temp, k);
        if (kthNode == NULL) {
            if(prevLast) prevLast->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (temp == head) {
            head = kthNode;
        } else{
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}



// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = kReverse(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
