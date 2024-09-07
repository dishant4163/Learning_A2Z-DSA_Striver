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



/*//Soln-1: Brute Force    */
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






/*//Soln-2: Optimal          */
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
