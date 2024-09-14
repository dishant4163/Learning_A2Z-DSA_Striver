/*//(Merge K Sorted Linked Lists_Coding Ninja)->  https://shorturl.at/hq9F4    





*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};



/*Soln 1: Brute Force
   Approach Used:-
1. Convert Linked Lists to Array:
    Iterate through each linked list in the ListArr vector.
    For each linked list, traverse it and extract all the node values into a single array (arr).

2. Sort the Array:
    Use the sort function from the C++ STL to sort the array. This step ensures that all values are in ascending order.

3. Convert Array Back to Linked List:
    Create a new linked list by converting the sorted array back into a linked list. This is done by initializing a new head node and iterating through the sorted array to link nodes sequentially.

4. Return the Merged Sorted Linked List:
    The newly created linked list, which is sorted, is returned as the result.

    Detailed Steps/Algorithm
1. Initialization:
    Create an empty vector<int> arr to hold all the node values from all linked lists.

2. Extract Node Values:
    For each linked list in ListArr:
        Traverse the linked list.
        Append each node's data to arr.

4. Sort the Array:
    Apply sort(arr.begin(), arr.end()) to sort the values in ascending order.

5. Convert Sorted Array to Linked List:
    Call convertArr2LL(arr) to create a new linked list where nodes are ordered according to the sorted array.

6. Output the Result:
    Print the linked list to verify the correctness of the merging operation.


    Algorithm Steps:-
  # Initialization:
        Create an empty array, arr, to store all node values from the linked lists.

  # Extract Values from Each Linked List:
        For each linked list in the input vector ListArr:
            Set a pointer current to the head of the linked list.
            While current is not null:
                Append the data of current to the array arr.
                Move current to the next node (current = current->next).

  # Sort the Array:
        Apply the sorting function to arr to sort all extracted values in ascending order.

  # Convert Sorted Array to Linked List:
    If the array arr is empty, return NULL as the result.
    Create a new linked list:
        Initialize the head of the new linked list with the first element of the sorted array.
        Maintain a pointer current to the last node in the new linked list.
        For each remaining element in the sorted array:
                Create a new node with the current element value.
                Set the next pointer of the current node to this new node.
                Move the current pointer to this new node.

  # Return the Merged Sorted Linked List:
    Return the head of the newly created linked list.



    Complexity Analysis:-
  # TC:- O(N*k) + O(M logM) + O(M),  where M = N*k
  # SC:- O(M) + O(M)
*Node* convertArr2LL(vector<int> &arr) {
    if(arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* mergeKLists1(vector<Node*> &ListArr) {
    vector<int> arr;
    for(int i=0; i <ListArr.size(); i++) {
        Node* temp = ListArr[i]; //temp at head of lists
        while(temp != NULL) {
            //put lists data into vector array
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }

    sort(arr.begin(), arr.end());
    Node* head = convertArr2LL(arr);
    return head;





/* Soln 2: Better 
   Approach:-
 The code you provided does this in two main steps:

  # Merge Two Sorted Linked Lists:
    This function merges two individual sorted linked lists into one sorted linked list.
  # Merge K Sorted Linked Lists:
    This function uses the above method to merge multiple sorted linked lists into a single sorted linked list.


   Step-by-Step Algorithm:-
1. Merge Two Sorted Linked Lists
  # Initialization:
    Create a dummy node (dummyNode) to help build the merged list. This dummy node acts as a placeholder to simplify the merging process.
        Use a pointer (temp) that will keep track of the last node in the merged list.
  # Merging Process:
    While both input lists (list1 and list2) are not empty:
        Compare the data values of the current nodes of list1 and list2.
        Append the node with the smaller value to the merged list (temp->next).
        Move the pointer (temp) to the newly added node.
        Move the pointer of the list from which the node was taken to the next node.
  # Attach Remaining Nodes:
    After one of the lists is exhausted, attach the rest of the non-empty list to the merged list.
  # Return the Merged List:
    Return the next node of the dummy node (dummyNode->next), which is the head of the merged list.

2. Merge K Sorted Linked Lists
  # Initial Check:
    If the list of linked lists (ListArr) is empty, return NULL because there are no lists to merge.
  # Merge Process:
    Initialize the result (head) with the first linked list (ListArr[0]).
        Iterate through the remaining linked lists in ListArr:
            Merge the current head list with the next list in ListArr using the merge2SortedLL function.
            Update head to be the result of this merge operation.
  # Return the Final Merged List:
    After processing all linked lists, return the final merged list (head).


   Complexity Analysis:-
  # TC:- O(N1 + N2) + O(N logK)
    Reason:- merge2SortedLL Time Complexity: O(N1​+N2​), where N1​ and N2​ are the number of nodes in the two lists being merged.
    mergeKLists2 Time Complexity: O(N logK), where N is the total number of nodes across all linked lists, and K is the number of linked lists.

  # SC:- O(1)
*Node* merge2SortedLL(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            // Move to the next node in list1
            list1 = list1->next;
        } else {
            temp->next = list2;
            // Move to the next node in list2
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Attach the remaining nodes of list1 or list2
    if (list1) {
        temp->next = list1;
    }
    else {
        temp->next = list2;
    }

    return dummyNode->next;
}

Node* mergeKLists2(vector<Node*> &ListArr) {
    // Check for empty list array
    if(ListArr.empty()) return NULL;

    Node* head = ListArr[0];
    for (int i=1; i < ListArr.size(); i++) {
        //using Recusrion to Merge 2 Sorted LL:
        head = merge2SortedLL(head, ListArr[i]);
    }
    return head;





/* Soln 3: Optimal(using Priority Queue)
   
*/
Node* mergeKLists(vector<Node*> &ListArr) {
    
}







// Function to print nodes in a given LL
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
}


int main() {

    int k = 3; 
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);


// Soln 1: Brute Force
    Node* head1 = mergeKLists1(arr);
    printList(head1);


// Soln 2: Better 
    Node* head2 = mergeKLists2(arr);
    printList(head2);


// Soln 3: Optimal
    Node* head = mergeKLists(arr);
    printList(head);





    return 0;
}

