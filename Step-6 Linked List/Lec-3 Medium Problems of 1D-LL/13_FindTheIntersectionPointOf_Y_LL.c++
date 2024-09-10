/*//(Find The Intersection Point of Y LL_Coding Ninja)-> : https://tinyurl.com/yc344rnt 

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL) return NULL;

    Node* temp1 = firstHead;
    Node* temp2 = secondHead;
    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = secondHead;
        if(temp2 == NULL) temp2 = firstHead;
    }
    return temp1;
}

*/



#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};

//utility function to insert node at the end of the LL
void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}


/*// Soln 1: Brute Force(using 2 nested Loops)
   Approach: We know intersection means a common attribute present between two entities. Here, we have linked lists as given entities. 

  What should be the common attribute for two linked lists? 
 If you believe a common attribute is a node's value, then think properly! If we take our example 1, there we can see both lists have nodes of value 3. But it is not the first intersection node. So what’s the common attribute?

 It is the node itself that is the common attribute. So, the process is as follows:-

  # Keep any one of the list to check its node present in the other list. Here, we are choosing the second list for this task.
  # Iterate through the other list. Here, it is the first one. 
  # Check if the both nodes are the same. If yes, we got our first intersection node.
  # If not, continue iteration.
  # If we did not find an intersection node and completed the entire iteration of the second list, then there is no intersection between the provided lists. Hence, return null.

   Complexity Analysis:-
  # Time Complexity: O(m*n)
 Reason: For each node in list 2 entire lists 1 are iterated. 
  # Space Complexity: O(1)
 Reason: No extra space is used.
*/
Node* intersectionPresent1(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;

    while(head2 != NULL) {
        Node* temp = head1;
        while(temp != NULL) {
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
}





/*// Soln 2.1: Brute Force(Hash Set )
 Approach:- Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-
  # Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
  # Iterate through list 2 and search the hashed value in the hash table. If found, return node.

   Complexity Analysis:-
  # Time Complexity: O(n+m)
 Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
  # Space Complexity: O(n)
 Reason: Storing list 1 node addresses in unordered_set.
*/
Node* intersectionPresent2(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;

    unordered_set<Node* > visitSet;
    while(head1 != NULL) {
        visitSet.insert(head1);
        head1 = head1->next;
    }
    while(head2 != NULL) {
        if (visitSet.find(head2) != visitSet.end()) {
            return head2;
        }
        head2 = head2->next;
    }
    return NULL;
}





/*// Soln 2.2: Better (Difference in Length) 
   Approach:

    We will reduce the search length. This can be done by searching the length of the shorter linked list. How? Let’s see the process.

  # Find the length of both lists.
  # Find the positive difference between these lengths.
  # Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
  # Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.


   Complexity Analysis:-
  # Time Complexity:- O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
 Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.

  # Space Complexity: O(1)
 Reason: No extra space is used.
*/
int getDifference(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;
    while(head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            len1++;//Increment the length of the 1st list
            head1 = head1->next;//Move to next node in the 1st list
        }
        if (head2 != NULL) {
            len2++; //Increment the length of the 2nd list
            head2 = head2->next;// Move to the next node in the 2nd list
        }
    }
    //if difference is neg-> length of list2 > length of list1 else vice-versa
    return len1 - len2;
}


Node* intersectionPresent3(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;
    // Calculate the length difference
    int diff = getDifference(head1, head2);

    if (diff < 0) { // If diff is negative:
        while (diff++ != 0) head2 = head2->next; // Move head2 ahead by |diff| nodes
    }
    else { //If diff is non-negative:
        while(diff-- != 0) head1 = head1->next; // Move head1 ahead by diff nodes
    }
    while(head1 != NULL) {
        //if both nodes are same
        if (head1 == head2) return head1;
        // Move both pointers to the next node
        head2 = head2->next;
        head1 = head1->next;
    }

    return head1; // Return NULL if no intersection
}





/*// Soln 3: Optimal 
   Approach:- The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
  # Take two dummy nodes for each list. Point each to the head of the lists.
  # Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.


   Complexity Analysis:-
  # Time Complexity: O(2*max(length of list1,length of list2)).
 Reason: Uses the same concept of the difference of lengths of two lists.

  # Space Complexity: O(1)
 Reason: No extra data structure is used
*/
Node* intersectionPresent4(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = head2;
        if(temp2 == NULL) temp2 = head1;
    }
    return temp1;
}








//utility function to print linked list created
void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}

int main() {

// creation of both lists 
    Node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    insertNode(headSec,3);
    Node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);



// Soln 1: Brute Force
    //checking if intersection is present
    Node* ansNode1 = intersectionPresent1(head1, head2);
    if(ansNode1 == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<ansNode1->num<<endl;



// Soln 2.1: Better (Hash Set)
    //checking if intersection is present
    Node* ansNode2 = intersectionPresent2(head1,head2);
    if(ansNode2 == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<ansNode2->num<<endl;



// Soln 2.2: Better (Difference in Length)
    //checking if intersection is present
    Node* answerNode = intersectionPresent3(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;



//Soln 3: OPtimal
    //checking if intersection is present
    Node* answerNode = intersectionPresent4(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;





    return 0;
}
