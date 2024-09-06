/*//(Find Length of Loop in Linked List_Coding Ninja)->  https://tinyurl.com/5n78kcda    

int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow != fast) {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}


int lengthOfLoop(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return findLength(slow, fast);
        }
    }
    return 0;
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


/*//Soln 1: Brute Force (hashing)
   Intuition:- Finding the length of the loop of a linked list is an extension of Detection of Loop so review that article and make sure you are thorough with its approaches.
 In recap, a loop in a linked list occurs when there is at least one node that, when used as a starting point, allows us to return to it during traversal.
 While traversing the linked list, employ a timer against each node to keep track of the number of nodes you've visited before it. Once a previously visited node is encountered again, the length of the loop can be determined by subtracting the timer values at the two instances of visiting that particular node.
 Hence it's important to keep track of nodes and the timer value associated with them. This can be implemented using a hashmap with nodes as the key and the timer as the value.


   Algorithm:
  # Step 1: Traverse through the LL using the traversal technique of assigning a temp node to the head and iterating by moving to the next element till we reach null. While traversing, keep track of the Visited nodes and the timer value associated in the map data structure.
  # Step 2: Continue traversing till a node that has already been visited is found. The difference between its timer value in the hashmap and the current timers value will be the length of the linked list.
  # Step 3: If the traversal is completed, and we reach the last point of the linked list which is null, it means there was no loop, hence we return false.


   Complexity Analysis:-
  # Time Complexity: O(N * 2 * Log(N)) The code traverses the entire linked list at least once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).
  # Space Complexity: O(N) The code uses a hashmap/dictionary to store encountered nodes, which can take up to O(N) additional space, where ‘N' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.
*/
int lengthOfCycle(Node* head) {
    unordered_map<Node* , int> visitedNodes;
    Node* temp = head;
    int timer = 0;

    while(temp != NULL) {
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            int length = timer - visitedNodes[temp];
            return length;
        }
    visitedNodes[temp] = timer;
    temp = temp->next;
    timer++;
    }

    return 0;
}





/*//Soln 2: Optimal    
   Intuition: Tortoise and Hare Algorithm
 The previous method uses O(N) additional memory. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.
 The Tortoise and Hare approach has been discussed in this article. 


   Algorithm:-
  # Step 1: Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time, while `fast` will advance two steps at a time. These pointers will move simultaneously.
  # Step 2: Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and `fast` two steps at a time.
  # Step 3: Continue this traversal until one of the following conditions is met:

    `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop in the linked list hence it is linear, and the algorithm terminates by returning 0.
    `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list as we have seen in the detection of loop.

    This is the point where the slow and fast have met proving that there is a loop in the linked list. From here onwards we start counting for the length of this loop.

  # Step 4: Initialise a counter with zero and traverse the linked list using the `fast` pointer again, but this time only move one step at a time while incrementing the counter with each node visited. As the fast pointer reaches back at the slow pointer, the value of the counter will represent the length of the loop.


   Complexity Analysis:-
  # Time Complexity: O(N) The code traverses the entire linked list once, where 'n' is the number of nodes in the list. This traversal has a linear time complexity, O(n).
  # Space Complexity: O(1) The code uses only a constant amount of additional space, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constant space complexity, O(1).
*/

// Function to return the lenght of loop when slow & fastare on the same node
int findLength(Node* slow, Node* fast){
    
    // count to keep track of 
    // nodes encountered in loop
    int cnt = 1;
    
    // move fast by one step
    fast = fast->next;
    
    // traverse fast till it 
    // reaches back to slow
    while(slow!=fast){
        
        // at each node increase
        // count by 1 and move fast
        // forward by one step
        cnt++;
        fast = fast->next;
    }
    
    // loop terminates when fast reaches
    // slow again and the count is returned
    return cnt;
}
// Function to find the length
// of the loop in a linked list
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;     
        // Move fast two steps
        fast = fast->next->next;

        // Step 2: If the slow and fast pointers
        // meet, there is a loop
        if (slow == fast) {
            // return the number of nodes
            // in the loop
            return findLength(slow, fast);
        }
    }

    // Step 3: If the fast pointer
    // reaches the end, there is no loop
    return 0; 
}






int main() {

//Soln 1: Brute Force (hashing)
    // Create a sample linked
    // list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfCycle(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }



//Soln 2: Optimal(Tortoise & Hare Algo)
    // Create a sample linked
    // list with a loop
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }




    return 0;
}
