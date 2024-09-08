/*//(Sort a Linked List_Coding Ninja)-> https://bit.ly/4aSKrTF     



*/


/* Problem Statement: 
 Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list. 


   Example:

Input:Linked List: 3 4 2 1 5
Output:Sorted List: 1 2 3 4 5
 Explanation: The input linked list when sorted from [3, 4, 2, 1, 5] results in a linked list with values: [1, 2, 3, 4, 5].
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



/*//Soln 1: Brute Force  
   Intuition:- 
 A naive solution could be converting the linked list into an array, sorting the array, and then creating a new linked list from the sorted array's values.


   Algorithm:-
 Step 1:Create an empty array to store the node values. Iterate the linked list using a temp pointer to the head and push the value of temp node into the array. Move temp to the next node.
 Step 2: Sort the array containing node values in ascending order.
 Step 3: Convert the sorted array back to a linked list reassigning the values from the sorted array and overwriting them sequentially according to their order in the array.


   Complexity Analysis:-
 # Time Complexity: O(N) + O(N log N) + O(N)where N is the number of nodes in the linked list.

    O(N) to traverse the linked list and store its data values in an additional array.
    O(N log N) to sort the array containing the node values.
    O(N) to traverse the sorted array and convert it into a new linked list.

 # Space Complexity : O(N)where N is the number of nodes in the linked list as we have to store the values of all nodes in the linked list in an additional array to sort them.
*/
Node* sortLinkedList(Node* head) {
    vector<int> ar;
    Node* temp = head;
    while(temp != NULL) {
        ar.push_back(temp->data);
        temp = temp->next;
    }

    sort(ar.begin(), ar.end());

    temp = head;

    for(int i=0; i < ar.size(); i++) {
        temp->data = ar[i];
        temp = temp->next;
    }
    return head;
}





/*//Soln 2: OPtimal  
   Intuition:-
 Instead of using an external array to store node values, we can employ a sorting algorithm without using any extra space. An in-place sorting algorithm like Merge Sort or Quick Sort adapted for linked lists can achieve this.
 Read more about Merge Sort here!Merge Sort Algorithm. A modified version of merge sort can operate directly on the linked list without using any additional space. This algorithm would divide the linked list into halves recursively until single nodes remain. These sorted halves of the linked list are merged back together in a sorted order.
 This approach employs the divide-and-conquer strategy:
    Divides the linked list into smaller parts until they become trivial to sort (single node or empty list).
    Merges and sorts the divided parts while combining them back together.


   Algorithm:-
 Step 1: Base Case If the linked list contains zero or one element, it is already sorted. Return the head node.
 Step 2: Split the ListFind the middle of the linked list using a slow and a fast pointer. Read more about this approach here!Middle Element in Linked List. Split the linked list into two halves at the middle node. The two halves will be left and right.
 Step 3: RecursionRecursively apply merge sort to both halves obtained in the previous step. This step continues dividing the linked list until there's only one node in each half.
 Step 4: Merge Sorted ListsMerge the sorted halves obtained from the recursive calls into a single sorted linked list. Compare the nodes from both halves and rearrange them to form a single sorted list. Update the head pointer to the beginning of the newly sorted list.
 Step 5: ReturnOnce the merging is complete, return the head of the sorted linked list.


   Complexity Analysis:-
  # Time Complexity: O(N log N)where N is the number of nodes in the linked list. Finding the middle node of the linked list requires traversing it linearly taking O(N) time complexity and to reach the individual nodes of the list, it has to be split log N times (continuously halve the list until we have individual elements).

  # Space Complexity : O(1) as no additional data structures or space is allocated for storage during the merging process. However, space proportional to O(log N) stack space is required for the recursive calls. THe maximum recursion depth of log N height is occupied on the call stack. 
*/
Node* sortLL(Node* head) {

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

//Soln 1: Brute Force
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLinkedList(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);



//Soln 2: Optimal
    // Linked List: 3 2 5 4 1 6
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(6);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);




    return 0;
}

