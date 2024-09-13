/*//(Clone LL with Random & Next Pointer_Coding Ninja)->  https://tinyurl.com/ytkm6xuz 


void insertCopyInBetween(Node* head) {
	Node *temp = head;
	while(temp != nullptr) {
		Node *copyNode = new Node(temp->data);
		copyNode->next = temp->next;
		temp->next = copyNode;
		temp = temp->next->next;
	}
}

void connectRandomPointers(Node* head) {
	Node* temp = head;
	while(temp != nullptr) {
		Node *copyNode = temp->next;

		if (temp->random != nullptr) {
			copyNode->random = temp->random->next;
		} else{
			copyNode->random = nullptr;
		}

		temp = temp->next->next;
	}
}

Node* getDeepCopyList(Node* head) {
	Node* dummyNode = new Node(-1);
	Node* res = dummyNode;
	Node* temp = head;
	while(temp != nullptr) {
		res->next = temp->next;
		res = res->next;

		temp->next = temp->next->next;
		temp = temp->next;
	}

	return dummyNode->next;
}


Node *cloneLL(Node *head){
	// Write your code here.
	if(head == nullptr) return nullptr;

	insertCopyInBetween(head);

	connectRandomPointers(head);

	return getDeepCopyList(head);
}


*/



/* Problem Statement: 
 Given a linked list where every node in the linked list contains two pointers:
  # ‘next’ which points to the next node in the list.
  # ‘random’ which points to a random node in the list or ‘null’.
Create a ‘deep copy’ of the given linked list and return it. 
*/


#include <bits/stdc++.h>
using namespace std;


// Node class to represent elements in the LL
class Node {
public:
    // Data stored in the node
    int data;           
     // Pointer to the next node
    Node *next;        
    // Pointer to a random
    // node in the list
    Node *random;       

    // Constructors for Node class
    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    // Constructor with data,
    // next, and random pointers
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};


/* Soln 1: Brute Force
   Intuition:-
  To create a deep copy of the original linked list we can use a map to establish a relationship between original nodes and their copied nodes.
  We traverse the list first to create a copied node for each original node then traverse and establish the correct connections between the copied nodes similar to the arrangement of next and random pointers of the original pointers. In the end, return the head of the copied list obtained from the map.


   Algorithm:-
  # Step 1:Initialise variables ‘temp’ as a pointer to the head of the original linked list to traverse it. Create an empty unordered_map, to map original nodes to their corresponding copied nodes.
  # Step 2: Iterate through the original linked list and for each node in the linked list create a new node with the same data value as the original data. Map the original node to its copied node in the map.
  # Step 3: Iterate through the original list again but this time connect the pointers of the copied nodes in the same arrangement as the original node:
    Get the copied node corresponding to the original node using the map.
    Set the next pointer of the copied node to the copied node mapped to the original node’s next node.
    Set the random pointer of the copied node to the original node’s next node copied from the map.
  # Step 4: Return the head of the deep copied list which is obtained by retrieving the copied nodes mapped to the original head from the map.


   Complexity Analysis:-
  # Time Complexity: O(2N) where N is the number of nodes in the linked list. The linked list is traversed twice, once for creating copies of each node and for the second time to set the next and random pointers for each copied node. The time to access the nodes in the map is O(1) due to hashing.
  # Space Complexity : O(N)+O(N)where N is the number of nodes in the linked list as all nodes are stored in the map to maintain mappings and the copied linked lists takes O(N) space as well.
*/
Node* cloneLL1(Node* head) {
    if(head == NULL) return NULL;

    Node* temp = head;
    unordered_map<Node* , Node*> mp;
    while(temp != NULL) {
        Node* newNode = new Node(temp->data);
        mp[temp] = newNode;
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        Node* copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}






/* Soln 2: Optimal 
   Intuition:-
 The previous approach uses an extra space complexity of creating mappings between the original and copied nodes. Instead of creating duplicate nodes and storing them in a map, insert it in between the original node and the next node for quick access without the need for additional space.
 Traverse the list again to set the random pointer of copied nodes to the corresponding copied node duplicating the original arrangement. As a final traversal, separate the copied and original nodes by detaching alternate nodes.


   Algorithm:-
  # Step 1: Traverse the original node and create a copy of each node and insert it in between the original node and the next node.
  # Step 2: Traverse this modified list and for each original node that has a random pointer, set the copied node’s random pointer to the corresponding copies random node. If the original node’s random pointer is full, set the copied node’s random pointe to null as well.
  # Step 3: RecursionTraverse the modified list again and extract the coped nodes by breaking the links between the original nodes and the copied nodes. Revert the original list to its initial state by fixing the next pointers.
  # Step 4: Return the head of the deep copy obtained after extracting the copied nodes from the modified list.


   Complexity Analysis:-
  # Time Complexity: O(3N)where N is the number of nodes in the linked list. The algorithm makes three traversals of the linked list, once to create copies and insert them between original nodes, then to set the random pointers of the copied nodes to their appropriate copied nodes and then to separate the copied and original nodes.
  # Space Complexity : O(N) where N is the number of nodes in the linked list as the only extra additional space allocated it to create the copied list without creating any other additional data structures.
*/
//Function to insert copy of each Node in b/w the original node
void insertCopyInBetween(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        // Create a new node with the same data
        Node* copyNode = new Node(temp->data);
        //Point the copy's next to the original node's next
        copyNode->next = temp->next;
        //Point the original node's next to the copy
        temp->next = copyNode;
        //Move to the next original node
        temp = temp->next->next;
    }
}

//Function to connect Random pointers to the copied nodes
void connectRandomPointers(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        Node* copyNode = temp->next;

        // If the original node has a random pointer
        if (temp->random != NULL) {
            // Point the copied node's random to the
            // corresponding copied random node
            copyNode->random = temp->random->next;
        } else{
            // Set the copied node's random to
            // null if the original random is null
            copyNode->random = NULL;
        }
        // Move to the Next original Node
        temp = temp->next->next;
    }
}

//Function to Retrieve the Deep-Copy of LL from original LL
Node* getDeepCopyList(Node* head) {
    // Create a dummy node
    Node* dummyNode = new Node(-1);
    // Initialize a result pointer
    Node* res = dummyNode;
    Node* temp = head;

    while(temp != NULL) {
        //Creating a new List by pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the
        // initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }

    // Return the deep copy of the
    // list starting from the dummy node
    return dummyNode->next;
}

// Function to clone the linked list
Node* cloneLL(Node* head) {
    //If the original list is empty, return null
    if (head == NULL) return NULL;
    //Step 1: Insert copy of nodes in between
    insertCopyInBetween(head);
    // Step 2: Connect random pointers of copied nodes
    connectRandomPointers(head);
    //Step 3: Retrieve the deep copy of the LL & Return it.
    return getDeepCopyList(head);
}





// Function to print the cloned linked list
void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}



int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;



// Soln 1: Brute Force
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL1(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);




// Soln 2: OPtimal
    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);






    return 0;
}


