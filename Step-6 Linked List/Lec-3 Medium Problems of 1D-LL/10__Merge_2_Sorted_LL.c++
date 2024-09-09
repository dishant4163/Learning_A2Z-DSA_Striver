/*//Merge two sorted Linked Lists -> https://bit.ly/3vjuaGQ    

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2) {
    Node<int>* t1 = list1;
    Node<int>* t2 = list2;
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* temp = dummyNode;

    while(t1 != NULL && t2 != NULL) {
        if (t1->data <= t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    } 

    //if t1 & t2 exhausted in while loop and
    //still some elements left behind in t1 & t2
    if (t1) {
        temp->next = t1;
    }
    else {
        temp->next = t2;
    }

    return dummyNode->next;
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


/*//Soln 1: brute Force
 TC:- O(N1 + N2) + O(N logN) + O(N)
 SC:- O(N) + O(N1 + N2)
*/
//Function to convert Array to LL
Node* convertArr2LL(vector<int> ar) {
    Node* head = new Node(ar[0]);
    Node* mover = head;
    for(int i = 1; i < ar.size(); i++) {
        Node* temp = new Node(ar[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* sort2LL(Node* list1, Node* list2) {
    vector<int> ar;
    while(list1 != NULL) { // Tc- O(N1)
        ar.push_back(list1->data);
        list1 = list1->next;
    }

    while(list2 != NULL) { //Tc- O(N2)
        ar.push_back(list2->data);
        list2 = list2->next;
    }

// Sorting the vector Array
    sort(ar.begin(), ar.end()); //Tc- O(N logN)

    Node* head = convertArr2LL(ar); //Tc- O(N)

    return head;
}






/*// OPTIMAL Soln:-
//Merge two sorted Linked Lists
// TC:- O(N1 + N2)
// SC:- O(1)
*/
Node* sortTwoLLists(Node* first, Node* second)
{
    // Write your code here.
    Node* t1 = first;
    Node* t2 = second;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1 != NULL && t2 != NULL) {
        if (t1->data <= t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    //if some elements Left-behind in list1 & list2
    if (t1) temp->next = t1;
    else temp->next = t2;

    return dummyNode->next;
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

//Create a sorted linked list: 2->4->5->8->9
    Node* list1 = new Node(2);
    list1->next = new Node(4);
    list1->next->next = new Node(5);
    list1->next->next->next = new Node(8);
    list1->next->next->next->next = new Node(9);
//Printing the sorted Linked List-1
    cout<<"Print the sorted Linked List-1: ";
    printLinkedList(list1);
//Create a sorted linked list: 1->3->7->8->11->15
    Node* list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(7);
    list2->next->next->next = new Node(8);
    list2->next->next->next->next = new Node(11);
    list2->next->next->next->next->next = new Node(15);
//Print the sorted Linked List-2
    cout<<"Print the sorted Linked List-2: ";
    printLinkedList(list2);



//Soln 1: Brute Force
    Node* res = sort2LL(list1, list2);
    Node* temp = res;
    cout<<"Merged Linked List : " <<endl;
    while(temp) {
        cout << temp->data<<" ";
        temp = temp->next;
    }




//Soln 2: Optimal
    Node* ans = sortTwoLLists(list1, list2);

    Node* temp = ans;
    cout<<"Merged Linked List : " <<endl;
    while(temp) {
        cout << temp->data<<" ";
        temp = temp->next;
    }





    return 0;
}
