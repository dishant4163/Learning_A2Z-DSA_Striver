//Introduction 2 DoublyLL(Learn about struct/class & how is node represented)

//Coding Ninja_Problems on DLL->


/*//(1_Introduction To Doubly Linked List)-> https://tinyurl.com/3fj6tvrt    

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node{arr[0]};
    Node* prev = head;
    for(int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i], nullptr, prev};
        prev->next = temp;
        prev = temp;
    }
    return head;
}

*/ 
/*//(2_Deletion of head of the DLL)-> https://tinyurl.com/mubc6f26     

Node * deleteHead(Node *head) {
    // Write your code here.
    if (head == NULL || head->next == NULL) return nullptr;

    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

*/
/*//(3_Deletion of tail of the DLL)-> https://tinyurl.com/4a9e8ceu   

Node * deleteLastNode(Node *head) {
    // Write your code here
    if(head == NULL || head->next == NULL) return nullptr;

    Node* tail = head;
    while(tail->next != NULL) {
        tail=tail->next;
    }

    Node* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;

    return head;
}

*/
/*//(_Deletion of the Kth node of the DLL)-> https://tinyurl.com/ytau6hwn   



*/
/*//(_Deletion of a given [node != head])-> https://tinyurl.com/2aady8f7     



*/
/*//(_Insertion before the head)-> https://tinyurl.com/58fyn6d8           



*/
/*//(_Insert after a given Node)-> https://tinyurl.com/26yh8tv7           



*/








#include<bits/stdc++.h>
using namespace std;


// I__Basic of Doubly Linked List

/* NOTE:
   # int data: This holds the data value that the node stores, which can be of any data type (in this case, an integer).
   # Node* next: This is a pointer to the next node in the linked list. It allows the nodes to be linked together, forming a sequence.
   # Node* back; : The introduction of the back pointer is the key change from a singly linked list node. This pointer allows traversal in the backward direction, making it suitable for doubly linked lists.

    Constructors: Both constructors have been updated to initialize the new back pointer. In the first constructor, Node(int data1, Node* next1, Node* back1), back is initialized with the provided value. In the second constructor, Node(int data1), the back is initialized to nullptr, just like the next.


   The class has two constructors:-
  #  The first constructor takes both the data and a pointer to the next node as parameters. It initializes the data and the next node accordingly.
  #  The second constructor takes only the data as a parameter and sets it next to nullptr. It could be that this node is the end of the list since there is no reference to the next node. We can append the next of this node later adding more nodes to the linked list.
*/
//Structure (struct/class) of Doubly LL:
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Ptr to next node in the list(forward direction)
    Node* back; // Ptr to previous node in the list(backward direction)

    public:
    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back = back1; // Addition of 'back' pointer for the doubly linked list.
    }

    public:
    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr; // Similar to a singly linked list.
        back = nullptr; // Addition of 'back' pointer initialization.
    }
};



// Function to return HEAD of LL
Node* functHeadCall(vector<int>&arr) {
    Node* head = new Node{arr[0]};
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i], nullptr, mover};
        mover->next = temp;
        mover = temp;
    }
    return head;
}


//Function to print the linked list starting from the given head
void printDll(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}




//1__Convert Array into D-LL:
Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node{arr[0]};
    Node* prev = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i], nullptr, prev};
        prev->next = temp;
        prev = temp; // or use ' prev = prev->temp; '
    }
    return head;
}






//II__Deletion of Node in DLL->
//2__Delete the Head of the DLL:
Node* deleteHead(Node* head) {
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}




//3__Delte the Tail of the DLL:
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;//previous tail
    delete tail;
    return head;
}




//4__Delete the Kth element of the DLL:
Node* removeKthElement(Node* head, int k) {
    if (head == NULL) {
        return NULL;
    }

    int cnt =0;
    Node* KtempNode = head;
    while(KtempNode != NULL) {
        cnt++;
        if (cnt == k) {
            break;
        }
        else {
            KtempNode = KtempNode->next;
        }
    }

    Node* prevNode = KtempNode->back;
    Node* nextNode = KtempNode->next;

    if (prevNode == NULL && nextNode == NULL) {
        return NULL;
    }
    else if (prevNode == NULL) {
        return deleteHead(head);
    }
    else if (nextNode == NULL) {
        return deleteTail(head);
    }
    prevNode->next = nextNode;
    nextNode->back = prevNode;

    KtempNode->back = nullptr;
    KtempNode->next = nullptr;
    delete KtempNode;

    return head;
}




//5__Delete the Node of the DLL:
void deleteNode(Node* tempNode) {
    Node* prevNode = tempNode->back;
    Node* frontNode = tempNode->next;

    if (frontNode == NULL) {
        prevNode->next = nullptr;
        tempNode->back = nullptr;
        free(tempNode);
        return;//only return bcz its a void function
    }
    prevNode->next = frontNode;
    frontNode->back = prevNode;

    tempNode->next = tempNode->back = nullptr;
    free(tempNode);
}






// III__Insertion of Node in DLL->
//6__Insertion of the Node BEFORE Head
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node{val, head, nullptr};
    head->back = newHead;

    return newHead;
}




//7__Insertion of the Node BEFORE Tail:
Node* insertBeforeTail(Node* head, int val){
    if(head->next == NULL) {
        return insertBeforeTail(head, val);
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node{val, tail, prev};
    prev->next = newNode;
    tail->back = newNode;
    return head;
}




//8__Insertion of the node BEFORE(kth Node):
Node* insertBeforeKthElement(Node* head, int k, int val){
    if (k == 1) {
        return insertBeforeHead(head, val);//beforeHead
    }

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node{val, temp, prev};
    prev->next = newNode;
    temp->back = newNode;
    return head;
}




//9__Insertion BEFORE the given NODE(Node != head):
void insertBeforeNode(Node* xnode, int val) {
    Node* prev = xnode->back;
    Node* newNode = new Node{val, xnode, prev};
    prev->next = newNode;
    xnode->back = newNode;
}






int main() {

//1__Convert Array into D-LL:
    vector<int> ar1 = {12, 5, 8, 7};
    Node* head = convertArr2DLL(ar1);
    printDll(head);



//2__Delete the Head of the DLL:
    vector<int> ar2 = {12, 5, 8, 7};
    Node* head = functHeadCall(ar2);
    head = deleteHead(head);
    printDll(head);



//3__Delte the Tail of the DLL:
    vector<int> ar3 = {12, 5, 8, 7};
    Node* head = functHeadCall(ar3);
    head = deleteTail(head);
    printDll(head);



//4__Delete the Kth element of the DLL:
    vector<int> ar4 = {12, 5, 8, 7};
    Node* head = functHeadCall(ar4);
    head = removeKthElement(head, 3);
    printDll(head);



//5__Delete the Node of the DLL:
    vector<int> ar5 = {12, 5, 8, 7};
    Node* head = functHeadCall(ar5);

    //given:- (Node != head)
    deleteNode(head->next->next);//Note:- don't delete head-node
    printDll(head);






//6__Insertion of the node BEFORE Head:
    vector<int> v = {12, 5, 8, 7};
    Node* head = functHeadCall(v);
    head = insertBeforeHead(head, 10);
    printDll(head);



//7__Insertion of the node BEFORE Tail:
    vector<int> v = {12, 5, 8, 7};
    Node* head = functHeadCall(v);
    head = insertBeforeTail(head, 20);
    printDll(head);



//8__Insertion of node BEFORE Kth node:
    vector<int> v = {12, 5, 8, 7};
    Node* head = functHeadCall(v);
    head = insertBeforeKthElement(head, 3, 27);
    printDll(head);



//9__Insertion BEFORE the given NODE:
    vector<int> ar5 = {12, 5, 8, 7};
    Node* head = functHeadCall(ar5);

    //given:- (Node != head)
    insertBeforeNode(head->next->next, 90);//Note:- don't delete head-node
    printDll(head);




    return 0;
}
