/*//(Segregate Odd & Even Nodes in LinkedList_Coding Ninja)-> https://tinyurl.com/47fu86tm  

Node* oddEvenList(Node* head)
{
	// Write your code here.
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
    
}

*/




#include<bits/stdc++.h>
using namespace std;


class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail; // head and tail of the LinkedList


// Function to print the LinkedList
void PrintList(ListNode *head) {
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}


// Function for creating a LinkedList
void InsertatLast(int value) {
    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}



//OPtimal Soln-1
ListNode *SegregatetoOddEVen()
{
    // creating Heads of Odd and Even LinkedLists
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        // Breaking the Link of the curr Node.
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1) // If odd Node,append to odd LinkedList
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else // If Even Node,append to even LinkedList
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    // Appending Odd LinkedList at end of EvenLinkedList
    return evenHead->next;
} 




int main() {

//Optimal Soln-1
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    ListNode *newHead = SegregatetoOddEVen();
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);



    return 0;
}
