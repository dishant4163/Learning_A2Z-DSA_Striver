// Deletion & Insertion in 1D LinkedList

/*//(Delete Node In A LL_Coding Ninja)-> https://shorturl.at/cQ2Ve     

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    if (node == NULL){
        return ;
    } 

    //LinkedListNode<int>* newNode = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    
}

*/

/*//(Insertion In A Singly LL_Coding Ninja)-> https://shorturl.at/ZzW7k   

Node * insert(Node * head, int n, int pos, int val) {
    // Write your code here
    Node* newNode = new Node(val);

    //if pos is at 1st
    if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    //current pts to the node at pos
    Node* curr = head;
    ///prev pts to the node at pos-1
    Node* prev = NULL;

    //loop for reaching at the current pos
    while(pos > 0 && curr) {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    prev->next = newNode;
    newNode->next = curr;

    return head;
}

*/



#include<bits/stdc++.h>
using namespace std;


// Node class for a linked list
class Node {
public:
    int data; // Data of the node
    Node* next; // Pointer to the next node in the list

// Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

// Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};



// Function to return HEAD of LL
Node* functHead(vector<int>&arr) {
    Node* head = new Node{arr[0]};
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i]};
        mover->next = temp;
        mover = temp;
    }
    return head;
}


//Function to print the linked list starting from the given head
void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}





//I- DELETION in LinkedList(head, tail, kth/position, value/element)
//1.1__Delete HEAD of the LL:
// Function to delete the HEAD node of a LL & return the new head
Node* removesHead(Node* head) {
    if (head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}




//1.2__Delete the TAIL of the LL:
Node* removesTail(Node* head) {
    //If the list is empty or has only 1 node, return NULL
    if (head == NULL || head->next == NULL) return NULL;
    // Initialize a temp pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    free(temp->next);//or delete temp->next;
    // Set the next of the second last node to nullptr,
    // effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;    
}




//1.3__Delete Kth element of the LL:
Node* removesKthEle(Node* head, int k) {
    //Edge Case-1, if LL is empty
    if (head == NULL) return head;
    // Edge Case-2, if LL have only 1 elle
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //Edge Case-3
    int cnt =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;

        if (cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}




//1.4__Delete given Value of the LL:
Node* deleteVal(Node* head, int val) {
    if (head == NULL) return head;

    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if (temp->data == val) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}






//II- INSERTION in LinkedList(head, tail, kth/position, value/element)
//2.1__Insert the element at the Head of the LL:
Node* insertHead(Node* head, int insertVal) {
    Node* temp = new Node(insertVal, head);
    return temp;
    // OR " return new Node(val, head); " 
    
}




//2.2__Insert at the Last/Tail of the LL:
Node* insertTail(Node* head, int val) {
    if (head == NULL) {
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNODE = new Node(val);
    temp->next = newNODE;

    return head;
}




//2.3__Insert at the Kth element in the LL:
Node* insertAtKthPosition(Node* head, int el, int K) {
    if (head == NULL) {
        if(K == 1) {
            return new Node(el);
        }
        else {
            return head;
        }
    }

    if(K == 1) {
        return new Node(el, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if (cnt == (K-1)) {
        //create X node to store new ele at Kth positio
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;
}





//2.4__Insert the Element before the VALUE x in the LL:
Node* insertBeforeValue(Node* head, int ele, int val){
    if(head == NULL) return NULL;

    if(head->data == val) {
        return new Node(ele, head);
    }

    Node* temp = head;
    while(temp->next != NULL) {
        if (temp->next->data == val){
            Node* newNODEx = new Node(ele, temp->next);
            temp->next = newNODEx;
            break;
        }
        temp = temp->next;
    }


    return head;
}






int main() {

//1.1__Delete Head of the LL:
    vector<int> ar1 = {1, 2, 3, 4, 5};
    Node* head = functHead(ar1);
    head = removesHead(head);
    print(head);



//1.2__Delete TAIL of the LL:
    vector<int> ar2 = {11, 22, 33, 44};
    Node* head = functHead(ar2);
    //Call the deleteTail function to delete the last node
    head = removesTail(head);
    printLL(head);// Print the LL after deletion tail



//1.3__Delete Kth element of the LL:
    vector<int> ar3 = {3, 9, 15, 21, 27};
    int k = 3;
    Node* head = functHead(ar3);
    head = removesKthEle(head, k);
    printLL(head);



//1.4__Delete given Value of the LL:
    vector<int> ar4 = {3, 9, 15, 21, 27};
    int val = 27;
    Node* head = functHead(ar4);
    head = deleteVal(head, val);
    printLL(head);





//2.1__Insert the element at the Head of the LL:
    vector<int> a1 = {20, 30, 40, 50};
    int insertVal = 10;
    Node* head = functHead(a1);
    head = insertHead(head, insertVal); 
    // OR head = new Node(inserVal, head);
    printLL(head);



//2.2__Insert at the Last/Tail of the LL:
    vector<int> a2 = {1, 2, 3, 4};
    int val = 500;
    Node* head = functHead(a2);
    head = insertTail(head, val);
    printLL(head);



//2.3__Insert at the Kth element in the LL:
    vector<int> a3 = {1, 2, 3, 4};
    int el=11, K = 2;
    Node* head = functHead(a3);
    head = insertAtKthPosition(head, el, K);
    printLL(head);



//2.4__Insert the Element before the VALUE x in the LL:
    vector<int> a4 = {1, 7, 11, 44};
    int ele=300, val = 44;
    Node* head = functHead(a4);
    head = insertBeforeValue(head, ele, val);
    printLL(head);






    return 0;
}
