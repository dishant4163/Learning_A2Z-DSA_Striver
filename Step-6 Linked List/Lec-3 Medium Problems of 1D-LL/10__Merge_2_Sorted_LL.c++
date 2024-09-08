//Merge two sorted Linked Lists -> https://bit.ly/3vjuaGQ    




/*// OPTIMAL Soln:-
//Merge two sorted Linked Lists


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* t1 = first;
    Node<int>* t2 = second;
    Node<int>* dummyNode = new Node<int>(-1);
    Node<int>* temp = dummyNode;
    while(t1 != nullptr && t2 != nullptr) {
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
    if(t1) temp->next = t1;
    else temp->next = t2;

    return dummyNode->next;
}



*/



