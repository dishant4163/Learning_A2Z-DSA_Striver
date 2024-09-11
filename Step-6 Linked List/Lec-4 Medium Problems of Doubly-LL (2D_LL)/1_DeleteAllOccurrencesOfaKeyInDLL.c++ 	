/*//(Delete all occurrences of a key in DLL_Coding Ninja)->  https://tinyurl.com/yc7znssk   


Node * deleteAllOccurrences(Node* head, int key) {
    // Write your code here.
    Node* temp = head;

    while(temp != NULL) {
        if (temp->data == key) {
            // if this is the head of the LL then 
            // post deletion the head will be updated
            if (temp == head) {
                head = head->next;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if (nextNode != NULL) nextNode->prev = prevNode;
            if (prevNode != NULL) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }

    return head;
}



*/

// Complexity Analysis of the Above code is:
// TC:- O(N) 
// SC:- O(1)


