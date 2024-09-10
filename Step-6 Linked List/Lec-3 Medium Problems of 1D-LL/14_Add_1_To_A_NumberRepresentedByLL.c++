/*//Add 1 to a Number Represented by LL_Coding Ninja ->  https://tinyurl.com/3hrjsb36    

int addCarry(Node* temp) {
    //Base case of recursive function
    if (temp == NULL) return 1;

    int carry = addCarry(temp->next);
    //start backtracking the recursive stackspace
    temp->data += carry;

    if (temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}


Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = addCarry(head);

    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}


*/

#include<bits/stdc++.h>
using namespace std;


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



/*//Soln 1: Brute Force(using Reversing)
 Number is represented in linked list such that each digit corresponds to a node in linked list. Add 1 to it. For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0) 

Below are the steps :   
  # Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
  # Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. Keep moving to the next node while there is a carry.
  # Reverse modified linked list and return head.

   Complexity Analysis:
  # TC:- O(3N)
  # SC:- O(1)
*/
Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node* add1ToLL(Node* head) {
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while(temp != NULL) {
        temp->data = temp->data + carry;
        // If no carry is needed
        if(temp->data < 10) {
            carry = 0;
            break;
        }
        // If there’s a carry (i.e., data >= 10)
        else {
            temp->data = 0;
            carry = 1; // carry over to the next node.
        }
        temp = temp->next;
    }

    // if still Carry is 1 then we neeed new Node
    // Before the head of the LL
    if(carry == 1) {
        Node* newNode = new Node(1); //Create a new node with data with carry 1.
        head = reverseLL(head);
        newNode->next = head;
        return newNode;
    }
    else {
        head = reverseLL(head);
    }
    return head;
}





/*//Soln 2: Recursive/Optimal (without reversing LL)
   Approach:-
1. Recursive Carry Addition (addCarry function):
  # This function traverses the linked list recursively from the end to the beginning to handle the carry addition.
  # Base Case: If the current node (temp) is NULL, it returns 1 to indicate a carry is needed.
  # Recursive Case: It recursively calls itself with the next node. After processing the next node, it adds the carry value to the current node’s data.
  # Carry Handling:-
        If the updated data in the current node is less than 10, it means no carry is needed, so it returns 0.
        If the data is 10 or more, it sets the data to 0 (effectively resetting it) and returns 1 to indicate that a carry is needed for the next node.

2. Adding One to the Number (addOne function):
  # It calls addCarry with the head of the linked list to process the carry addition.
  # If addCarry returns 1, it means there was a carry from the most significant digit (the head of the list), so a new node with value 1 is created, and this new node becomes the new head of the list.
  # If no carry is needed (i.e., addCarry returns 0), it simply returns the original head of the list.


STEPS:-
 1. Initiate the carry addition process by calling addOne with the head of the linked list.
 2. Recursively traverse the linked list from the end using addCarry to process each node.
 3. Update each node’s value and manage carry:-
    If adding carry results in a value less than 10, no further carry is needed.
    If the value is 10 or more, reset it to 0 and pass carry to the next node.
 4. Handle carry at the most significant digit:-
    If there’s still a carry after processing all nodes, create a new node with value 1 and set it as the new head.


   Complexity Analysis:
  # Time Complexity:- O(N)
  # Space Complexity:- O(N)
    Reason-> stroing in stackspace for recursion
*/
int addCarry(Node* temp) {
//Recursion Function for adding carry
    if(temp == NULL) return 1; //Base case of recursive function

    int carry = addCarry(temp->next);
    //start backtracking the recursive stackspace
    temp->data += carry;

    if (temp->data < 10) return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry =  addCarry(head);

    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    //simple returs head:(no need to define else statement)
    return head;
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
    //Creating the LL: 1 -> 9 -> 9 -> 9
    Node *head = new Node(1); 
    head->next = new Node(9); 
    head->next->next = new Node(9); 
    head->next->next->next = new Node(9); 

    cout << "List is: "; 
    printLinkedList(head); 

    head = add1ToLL(head); 

    cout << "Resultant list is: "; 
    printLinkedList(head); 



//Soln 2: OPtimal
    // Creating the LL: 9 -> 9 -> 9 -> 9
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    cout << "List is: "; 
    printLinkedList(head); 

    head = addOne(head); 

    cout << "Resultant list is: "; 
    printLinkedList(head); 




    return 0;
}
