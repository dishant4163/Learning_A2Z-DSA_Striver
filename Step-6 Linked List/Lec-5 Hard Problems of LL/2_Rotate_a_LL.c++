/*//(Rotate a Linked List(by K Times/Place)_Coding Ninja)-> : https://tinyurl.com/ye23ua58    


Node* findNthNode(Node* temp, int k) {
    int cnt = 1;
    while(temp != NULL) {
        if (cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}


Node* rotateRight(Node* head, int k) {
    if (head == NULL || k==0 ) return head;

    //Calculate the length of the list:
    Node* tail = head;
    int len=1;
    while(tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    if (k%len == 0) return head;
    //when k is more than length of list
    k = k%len;

    tail->next = head;

    Node* newLastNode = findNthNode(head, len-k);
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

*/






#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
        int num;
        Node* next;
        Node(int a) {
            num = a;
            next = NULL;
        }
};


//utility function to insert node at the end of the list
void insertNode(Node* &head,int val) {
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


/* //Soln 1: Brute Force
Approach:-
  # We have to move the last element to first for each k.
  # For each k, find the last element from the list. Move it to the first.


   Complexity Analysis:-
  # Time Complexity: O(Number of nodes present in the list*k).
    Reason: For k times, we are iterating through the entire list to get the last element and move it to first.
  # Space Complexity: O(1)
    Reason: No extra data structures is used for computations
*/
Node* rotateRight1(Node* head, int k1) {
    if (head == NULL || head->next == NULL) return head;

    for (int i=0; i < k1; i++) {
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        Node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}





/* //Soln 2: OPtimal
   Approach:-
 > Let’s take an example:
  head = [1,2,3,4,5] k = 2000000000

 If we see a brute force approach, it will take O(5*2000000000) which is not a good time complexity when we can optimize it.
 We can see that for every k which is multiple of the length of the list, we get back the original list. Try to operate brute force on any linked list for k as a multiple of the length of the list.
 This gives us a hint that for k greater than the length of the list, we have to rotate the list for k%length of the list. This reduces our time complexity.


   Steps to the algorithm:-
  # Calculate the length of the list.
  # Connect the last node to the first node, converting it to a circular linked list.
  # Iterate to cut the link of the last node and start a node of k%length of the list rotated list.


   Complexity Analysis:-
  # Time Complexity: O(length of list) + O(length of list - (length of list%k))
    Reason: O(length of the list) for calculating the length of the list. O(length of the list - (length of list%k)) for breaking link.
  # Space Complexity: O(1)
    Reason: No extra data structure is used for computation.
*/
Node* rotateRight(Node* head, int k) { // function to rotate list by k times
    if(head == NULL || k == 0) return head;

    //calculating length
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        length++;
        temp = temp->next;
    }

    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}






//utility function to print list
void printList(Node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}


int main() {
    Node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);


//Soln 1: Brute Force
    cout<<"Original list: ";
    printList(head);
    
    int k1 = 2;
    Node* newHead = rotateRight1(head,k1);//calling function for rotating right of the nodes by k times
    
    cout<<"After "<<k1<<" iterations: ";
    printList(newHead);//list after rotating nodes



//Soln 2: OPtimal
    cout<<"Original list: ";
    printList(head);
    
    int k = 3;
    Node* newHead = rotateRight(head,k);//calling function for rotating right of the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes





    return 0;
}
