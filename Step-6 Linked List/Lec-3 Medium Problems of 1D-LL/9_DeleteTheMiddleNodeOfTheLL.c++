/*//(Delete the Middle Node of the LL_Coding Ninja)-> https://tinyurl.com/y2r52yz8     

Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* middleNode = slow->next;
    slow->next = slow->next->next;
    free(middleNode);

    return head;
}


*/


/* Problem Statement: 
 Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

*/



#include<bits/stdc++.h>
using namespace std;


//Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;  
    
     // Pointer to the next node in the list
    Node* next;     

    // Constructor with both data
    // and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as
    // a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};



/*// Soln 1: Brute Force
   Intuition-:
 Using the brute force approach, the middle node of a linked list can be determined by traversing the entire linked list initially to find the total number of nodes, denoted as `n`. Then we reset the temporary node `temp` to the head of the linked list and proceed to traverse to the node positioned at index `[n/2]`, which represents either the middle node in an odd-lengthed list or the node just before the middle node in an even-lengthed linked list.


   Algorithm:
Step 1: Traverse the linked list to count the number of nodes and store the length as `n`. Calculate the index of the middle node by dividing the total number of nodes by 2.
Step 2: Traverse the linked list again while keeping track of the node count to reach the middle node. 
Step 3: Once reaching the middle node, delete it by setting the next pointer of the previous node directly to the node after the middle node. Free the memory allocated to the middle node.


   Complexity Analysis:-
  # Time Complexity: O(N + N/2) The loop traverses the entire linked list once to count the total number of nodes then the loop iterates halfway through the linked list to reach the middle node. Hence, the time complexity is O(N + N/2) ~ O(N).
  # Space Complexity : O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 
*/
Node* removeMiddle(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int N = 0;
    while(temp != NULL) {
        N++;
        temp = temp->next;
    }

    int res = N / 2;
    temp = head;
    while(temp != head) {
        res--;
        if (res == 0) {
            Node* middle = temp->next;
            temp->next = temp->next->next;
            free(middle);
            break;
        }
        temp = temp->next;
    }
    return head;
}





/*// Soln 2: Optimal 
   Intuition:-
 The previous method requires the traversal of the linked list twice. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization where the middle node can be found in just one traversal.
 The 'slow' pointer advances one node at a time while the 'fast' pointer moves two nodes at a time. By doing so, when the 'fast' pointer reaches the end of the list, the 'slow' pointer will be at the middle node.
 Since we require `slow` to reach the node before the middle node, we give `fast` a head start!.


   Algorithm:-
Step 1: Check if the list is empty or contains only one node. If so, no middle node exists to delete, return NULL. Initialise 'slow' and 'fast' pointers at the head of the list.
    Move ‘fast’ two nodes ahead for the initial position as we have to reach the node previous to the middle node via slow.
Step 2: Move the 'fast' pointer two nodes ahead and the 'slow' pointer one node ahead in each iteration. Continue this process until the 'fast' pointer reaches the end of the list.
Step 3: Once the 'fast' pointer reaches the end, the 'slow' pointer will be at the middle node. Delete the middle node by skipping it from the linked list. 
Step 4: Return the head of the modified linked list.


   Complexity Analysis:-
  # Time Complexity: O(N/2) The algorithm traverses the linked list using the Tortoise and Hare approach. The code increments both 'slow' and 'fast' pointers at different rates, effectively covering about half the list before reaching the midpoint, hence the time complexity of the algorithm is O(N/2) ~ O(N).
  # Space Complexity: O(1) The algorithm uses a constant amount of extra space regardless of the size of the input (linked list). It doesn't use any additional data structures in proportion to the input size. Thus, the space complexity is O(1) (constant space). 
*/
Node* deleteMiddle(Node* head) {
    // If the list is empty or has only one node,
    // return NULL as there is no middle node to delete
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // Initialize slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;

    // Move 'fast' pointer twice as fast as 'slow'
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node by skipping it
    Node* middle = slow->next;
    slow->next = slow->next->next;
    free(middle);

    return head;
}






void printLL(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

// Soln 1: Brute Force
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = removeMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);



//Soln 2: Optimal
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Display the orignal linked list
    cout << "Orginal Linked List: ";
    printLL(head);

    // Deleting the middle node
    head = deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Orginal Linked List: ";
    printLL(head);




    return 0;
}
