// Merge K Sorted Linked List



/* Megre K sorted Linked List -> ( https://shorturl.at/bQ371 )

Node* mergeKLists(vector<Node*> &lists){
    // Write your code here.
    int K=lists.size();
        Node *head=new Node(-1), *temp=head;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<K;i++){
            Node *temp1=lists[i];
            while(temp1!=NULL){
                pq.push(temp1->data);
                temp1=temp1->next;
            }
        }

        while(!pq.empty()){
            Node *newNode=new Node(pq.top());
            pq.pop();
            head->next=newNode;
            head=head->next;
        }
    return temp->next;  
}


*/



#include<bits/stdc++.h>
using namespace std;


class node {
public:
    int data;
    node* next;
    node(int DATA) {
        data = DATA;
        next = nullptr;
    }
};



//BRUTE FORCE
//Function to merge k sorted linked lists
node* mergeksortedLL(vector<node*>& arr) {
    //Vector to store all node DATAues
    vector<int> res;

    //Step-1 Extract all node values from each LL into 'res'
    for(node* head : arr) {
        while(head != nullptr) {
            res.push_back(head->data);
            head = head->next;
        }
    }

    //Step-2 Sort the vector of res
    sort(res.begin(), res.end());

    //Step-3 Create a new LL with the sorted values
    if(res.empty()) return nullptr; //If no lists were provided, return nullptr

    //Create the head of the new linked list
    node* head = new node(res[0]);
    node* current = head;

    //rebuild the linked list with sorted values
    for(int i = 1; i < res.size(); i++) {
        current->next = new node(res[i]);
        current = current->next;
    }

     return head; // Return the merged sorted linked list
}






//OPtimal soln (using minheap)
class compare {
public:
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }
};

node* mergeKLists(vector<node*> & listAr){
    priority_queue<node*, vector<node*>, compare > minheap;
    int k = listAr.size();

    //BASE case
    if(k == 0) return NULL;

    for(int i=0; i < k; i++) {
        if(listAr[i] != NULL) minheap.push(listAr[i]);
    }

    node* head = NULL;
    node* tail = NULL;

    while(!minheap.empty()) {
        node* topNode = minheap.top();
        minheap.pop();

        if(topNode->next != NULL) {
            minheap.push(topNode->next);
        }

        if(head == NULL) { //answer LL is empty
            head = topNode;
            tail = topNode;
        }
        else { // insert at LL
            tail->next = topNode;
            tail = topNode;
        }
    }

    return head;
}





// Function to print nodes in a given LL
void printList(node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


int main() {

//BRUTE FORCE
    int K = 3; 

    vector<node*> arr(K);

    arr[0] = new node(1);
    arr[0]->next = new node(3);
    arr[0]->next->next = new node(5);
    arr[0]->next->next->next = new node(7);

    arr[1] = new node(2);
    arr[1]->next = new node(4);
    arr[1]->next->next = new node(6);
    arr[1]->next->next->next = new node(8);

    arr[2] = new node(0);
    arr[2]->next = new node(9);
    arr[2]->next->next = new node(10);
    arr[2]->next->next->next = new node(11);

    node* soln = mergeksortedLL(arr);
    printList(soln);
    cout << endl;



//OPTimal Soln
    int k = 3; 

    vector<node*> ar(k);

    ar[0] = new node(11);
    ar[0]->next = new node(13);
    ar[0]->next->next = new node(15);
    ar[0]->next->next->next = new node(17);

    ar[1] = new node(12);
    ar[1]->next = new node(14);
    ar[1]->next->next = new node(16);
    ar[1]->next->next->next = new node(18);

    ar[2] = new node(10);
    ar[2]->next = new node(19);
    ar[2]->next->next = new node(20);
    ar[2]->next->next->next = new node(21);

    node* result = mergeKLists(ar);
    printList(result);
    cout << endl;



    return 0;
}

