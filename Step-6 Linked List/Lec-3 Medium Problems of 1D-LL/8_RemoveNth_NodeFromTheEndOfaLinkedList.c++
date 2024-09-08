/*//(Remove N-th node from the end of a Linked List_Coding Ninja)-> https://tinyurl.com/4txecfpz    

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* slowp = head;
    Node* fastp = head;

    for(int i=0; i < K; i++) {
        fastp = fastp->next;
    }

    if(fastp == NULL) {
        return head->next;
    }

    while(fastp->next != NULL) {
        slowp = slowp->next;
        fastp = fastp->next;
    }

    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}

*/



#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with 
    //only data (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// Function to print the linked list
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}



/*//Soln-1: Brute Force    
   Intuition:- The simplest way to delete the Nth node from the end is to delete the (L-N+1)th node from the start of the linked list, where L is the total length of the linked list.

   Algorithm:-
1. Initialize a temp pointer that will be used to traverse the list.

2. Create a cnt variable and initialize it to 0. Traverse the linked list, and at each node, increment cnt. Finally, when the pointer reaches NULL, return cnt, which contains the total length of the linked list.

3. Now, after knowing the length of the linked list, the first sub-problem is solved. To solve the second sub-problem, we will follow the steps that we used to delete the Kth node of the linked list.

4. To delete the (L-N+1)th node of the linked list, create a new temp pointer to the head. Initialize a variable res to L-N, and start iterating the linked list while decrementing res at each node. Once res equals 0, we know that temp will be pointing to the (L-N)th node, therefore, stop the traversal.

5. To create a new link, point the (L-N)th node to the (L-N+2)th node of the linked list, effectively skipping the (L-N+1)th node.

6. Finally, free up the memory being occupied by the (L-N+1)th node, thus deleting this node.

   Complexity Analysis
  # Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.
  # Space Complexity:  O(1), as we have not used any extra space.
*/
Node* DeleteNthNodefromLast(Node* head, int k) {
    if(head == NULL) return NULL;

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    if(cnt == k){
        Node* newHead = head->next;
        delete (head);
        return newHead;
    }

    int sol = cnt - k;
    temp = head;
    while(temp != NULL) {
        sol--;
        if (sol == 0) {
            break;
        }
        temp = temp->next;
    }

    Node* DelNode =  temp->next;
    temp->next = temp->next->next;
    delete (DelNode);

    return head;
}






/*//Soln-2: Optimal          
   Intuition:- 
 The brute force, in the worst case, has a time complexity of O(2*L), where L is the length of the linked list. Therefore, it is not the most efficient algorithm, as we are traversing the entire list twice.
 To enhance efficiency, we will involve two pointers, a fast pointer and a slow pointer. The fast-moving pointer will initially be exactly N nodes ahead of the slow-moving pointer. After which, both of them will move one step at a time. When the fast pointer reaches the last node, i.e., the L-th node, the slow is guaranteed to be at the (L-N)-th node, where L is the total length of the linked list.


   Algorithm:-
1. Initialize two pointers, `slow` and `fast`, to the head of the linked list. Initially, only fast will move till it crosses N nodes, after which both of the pointers will move simultaneously.
2. Traverse the linked list till the fast pointer reaches the last node, that is, the Lth Node, at this stage, the slow pointer is guaranteed to be at the (L-N)th node.
3. Point this slow pointer to the (L-N+2)th node, effectively skipping the Nth node from the end or the (L-N+1)th node from the start.
4. Finally, free up the space occupied by this to delete it.


   Complexity Analysis:-
  # Time Complexity: O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list.
  # Space Complexity: O(1), as we have not used any extra space.
*/
Node* DeleteNthNodefromEnd(Node* head, int N) {
    // Create two pointers, fastp and slowp
    Node* fastp = head;
    Node* slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL) {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    Node* delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}





int main() {

//Soln-1: Brute Force
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromLast(head, k);
    printLL(head);



//Soln-2: Optimal
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);





    return 0;
}
