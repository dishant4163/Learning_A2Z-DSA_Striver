//(Add 2 Numbers Represented as LinkedList_Coding Ninja)->   https://tinyurl.com/5n98urdv    


Node* addTwoNumbers(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* currentptr = dummyNode;
    Node* t1 = list1;
    Node* t2 = list2;
    int carry = 0;

    while(list1 != NULL || list2 != NULL) {
        int sum = carry;

        if (t1) sum += t1->data;
        if (t2) sum += t2->data;

        Node* newNode = new Node(sum%10);
        carry = sum / 10;

        currentptr->next = newNode;
        currentptr = currentptr->next;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }

    if (carry) {
        Node* newNode = new Node(carry);
        currentptr->next = newNode;
    }

    return dummyNode->next;
}





/* Problem Statement: 
 Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:
 Input Format: (Pointer/Access to the head of the two linked lists)

num1  = 243, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]

 Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or                                                original number and then add them as → 342 + 465 = 807. Refer to the image below.



 Input Format: 
(Pointer/Access to the head of the two linked lists)

l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

Result: [8,9,9,9,0,0,0,1]

 Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the     original number and then add them as → 9999999 + 9999 = 8999001.

*/






