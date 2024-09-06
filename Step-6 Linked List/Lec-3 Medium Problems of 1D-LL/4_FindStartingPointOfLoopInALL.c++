/*//(Find Starting Point of Loop in a LL_Coding Ninja)-> : https://tinyurl.com/4c5a64xv    

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; //as starting point
        }
    }
    return NULL;
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


/*//Soln 1: Brute Force (HashMap)   
   Intuition:- The starting point of a loop of the linked list is the first node we visit twice during its traversal. It's the point where we realise that we are no longer moving forward in the list but rather entering a cycle.

   Algorithm:-
  # Step 1:Traverse through the LL using the traversal technique of assigning a temp node to the head and iterating by moving to the next element till we reach null. 
  # Step 2: While traversing, keep a track of the visited nodes in the map data structure. 

    Note: Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.

  # Step 3: If a previously visited node is encountered again, that proves that there is a loop in the linked list hence return that node.
  # Step 4: If the traversal is completed, and we reach the last point of the LL which is null, it means there was no loop, hence we return null.


   Complexity Analysis:-
  # Time Complexity: O(N) The code traverses the entire linked list once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).
  # Space Complexity : O(N) The code uses a hash map/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.
*/
Node* detectLoopStart(Node* head) {
    // Use temp to traverse the linked list
    Node* temp = head;
    
    // hashmap to store all visited nodes
    unordered_map<Node*, int> mp;
    
    // Traverse the list using temp
    while(temp!=NULL){
        // check if temp has been encountered again
        if(mp.count(temp)!=0){
            // A loop is detected hence return temp
            return temp;
        }
        // store temp as visited
        mp[temp] = 1;
        // iterate through the list
        temp = temp->next;
    }

    // If no loop is detected, return nullptr
    return nullptr;
}





/*//Soln 2: Optimal    
   Intuition:- The previous method uses O(N) additional memory, which can become quite large as the linked list length grows. To enhance efficiency, the Tortoise and Hare Algorithm is introduced as an optimization.

   Algorithm:-
  # Step 1: Initialise two pointers, `slow` and `fast`, to the head of the linked list. `slow` will advance one step at a time, while `fast` will advance two steps at a time. These pointers will move simultaneously.
  # Step 2: Traverse the linked list with the `slow` and `fast` pointers. While traversing, repeatedly move `slow` one step and `fast` two steps at a time. 
  # Step 3: Continue this traversal until one of the following conditions is met:

>   `fast` or `fast.next` reaches the end of the linked list (i.e., becomes null). In this case, there is no loop in the linked list, and the algorithm terminates by returning null.
>   `fast` and `slow` pointers meet at the same node. This indicates the presence of a loop in the linked list.

  # Step 4: Reset the `slow` pointer to the head of the linked list. Move `fast` and `slow` one step at a time until they meet again. The point where they meet again is the starting point.


   Complexity Analysis:-
  # Time Complexity: O(N) The code traverses the entire linked list once, where 'n' is the number of nodes in the list. This traversal has a linear time complexity, O(n).
  # Space Complexity : O(1) The code uses only a constant amount of additional space, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constant space complexity, O(1). 
*/
Node* firstNode(Node* head) {
    // Initialize a slow and fast 
    // pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast) {
            
             // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}







int main() {

//Soln 1: Brute Force(hashmap)
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = detectLoopStart(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }



//Soln 2: Optimal
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = firstNode(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: "<< loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }





    return 0;
}
