//Introduction To LinkedList__Coding Ninja-> Problems on LL
/*//(Convert an array to LL_Coding Ninja->  https://tinyurl.com/55cy4jtd )

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node{arr[0]};
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i]};
        mover->next = temp;
        mover = temp;
    }
    return head;
}

*/

/*//(Count Nodes/Length of LL_Coding Ninja->  https://tinyurl.com/kvdu6t2s )

int length(Node *head)
{
	//Write your code here
    int cnt = 0;
    Node* temp = head;
    // do traversal for counting the element
    while(temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

*/

/*//(Search an element_Coding Ninja->  https://tinyurl.com/27c9b349 )  

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>* temp = head;// type cast temp as per the problem
    while(temp) {
        if (temp->data == k) return 1;
        temp = temp->next;
    }
    return 0;
}

*/




#include<bits/stdc++.h>
using namespace std;


//1__Basic of Linked List

/* NOTE:- 
 Structures: didn't uses concepts of OOP's. So, that we can uses the 'class'-which even uses concepts of OOP's.
 The keyword ‘class’ is used to declare a class.
    for e.g,

class Node {
    // statement
};


   Key Differences:
  1 Default Access Modifiers:
-> In a struct, members are public by default.
-> In a class, members are private by default.
   If you want the linked list nodes or the list itself to have public members, using a struct might be more convenient. However, if you want to enforce encapsulation and have private members, then class might be preferable.

  2 Inheritance:
-> struct and class both support inheritance, but the default access level for base classes is different: struct defaults to public inheritance, while class defaults to private inheritance.

  3 Convention:
-> struct is often used for simple data structures with public data, whereas class is used for more complex types where encapsulation and private data are important.
*/


struct Node{ // Node is class which is self define class
    public:
// constructor is used to initialize the object
    int data;// these are the object of class 
    Node* next;// these are the object of class 

    public://declaring constructor
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

// We can have multiple constructor
    public://this 1 is not to passing 'nullptr' again-again
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};



// 2__Convert ARRAY to LINKEDLIST:
Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node{arr[0]};
    Node* mover = head;
    for (int i=1; i < arr.size(); i++) {
        Node* temp = new Node{arr[i]};
        mover->next = temp; 
        mover = temp;// OR mover->next ;
    }
    return head;

// Note:- We didn't convert array to LL. 
// We just return 1st element of array as the start/head of the LL.

}





//3__Traversal in LL:
Node* traversalinLL(vector<int> &v) {
    Node* head = new Node{v[0]};
    Node* mover = head;
    for (int i=1; i<v.size(); i++) {
        Node* temp = new Node{v[i]};
        mover->next = temp;
        mover = temp;
    }
    return head;
}





//4__Length of LL:
// Function to return head for finding Length
Node* findlengtLL(vector<int> &v2) {
    Node* head = new Node{v2[0]};
    Node* mover = head;
    for (int i=1; i < v2.size(); i++) {
        Node* temp = new Node{v2[i]};
        mover->next = temp; 
        mover = temp;// OR mover->next ;
    }
    return head;
}

//code for finding Length of LL
int lengthOfLL(Node* head){
    int cnt = 0;
    //do traversal in LL to find Length
    Node* temp = head;
    while(temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}





//5__Search/Check an Element Present or Not:
//Function to return head for searching element
Node* findElementinLL(vector<int> &v2) {
    Node* head = new Node{v2[0]};
    Node* mover = head;
    for (int i=1; i < v2.size(); i++) {
        Node* temp = new Node{v2[i]};
        mover->next = temp; 
        mover = temp;// OR mover->next ;
    }
    return head;
}

//code for finding element in LL
int checkElePresent(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if (temp->data == val) return 1;// resent return 1
        temp = temp->next;
    }
    return 0;// not present return 0
}






int main() {

//1__Basic of LL
    vector<int> ar1 = {2, 5, 8, 7};
    //technically always this snipet
    Node* y = new Node{ar1[0], nullptr};
    cout << "Pointer to this memory location being printed " << y<<endl;


    //What if- we didn't define 'new' keyword & Node*
    //Then we just create Object where things are store
    Node x = Node{ar1[0]};
    //How to access Object Elements
    cout<<"To print data "<< x.data <<" & to print pointer location "<< x.next << endl;


    //How to access data & pointer location with 'new'
    Node* z = new Node{ar1[0]};
    cout<<"To print data "<< z->data <<" & to print pointer location "<< z->next <<endl;





//2__Convert ARRAY to LINKEDLIST:
    vector<int> arr = {9, 18, 27, 36};
    Node* head = convertArr2LL(arr);
    cout << head->data;





//3__Traversal in LL:
    vector<int> v = {2, 1, 3, 8};
    Node* head = traversalinLL(v);
    //now do traversal
    Node* temp = head;
    while(temp) {
        cout << temp->data<<" ";
        temp = temp->next;
    }





//4__Length of LL:
    vector<int> v2 = {1, 5, 11, 17};
    Node* head = findlengtLL(v2);
    cout<< "Length of given LL is " << lengthOfLL(head);





//5__Search/Check an Element Present or Not: 
    vector<int> b = {5, 9, 11, 17};
    Node* head = findElementinLL(b);
    cout << checkElePresent(head, 5);






    return 0;
}
