/*//(Remove Duplicates From Sorted DLL_Coding Ninja)-> https://tinyurl.com/5n8ndcuu     


Node * removeDuplicates(Node *head)
{
    // Write your code here.
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data) {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;
        
        temp = temp->next;
    }
    return head;
}



*/




/*//(Remove Duplicates From UnSorted DLL_Coding Ninja)-> https://shorturl.at/15bsG    

// TC:- O(N)
// Sc:- O(N)


Node *removeDuplicates(Node *head)
{
    // Write your code here.
    Node* currentNode = head;
    Node* prevNode = NULL;
    unordered_map<int, bool> visitedNode;

    while(currentNode != NULL) {
        if (!visitedNode[currentNode->data]) {
            visitedNode[currentNode->data] = true;
            prevNode = currentNode;
            currentNode = currentNode->next;
        }
        else {
            prevNode->next = currentNode->next;
            free(currentNode);
        }
        currentNode = prevNode->next;
    }
    return head;
}


*/



