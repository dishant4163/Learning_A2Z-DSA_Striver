/*//(Check if the given LL is Palindrome or Not_Coding Ninja)-> https://tinyurl.com/2p869csv   

Node* reverseLL(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}


bool isPalindrome(Node *head)
{
    // write your code here
    if(head == NULL || head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLL(slow->next);

    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if (first-> data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Node class represents a node in a LL
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


/*//Soln 1: Brute Force    
   Intuition:- A straightforward approach to checking if the given linked list is a palindrome or not is to temporarily store the values in an additional data structure. We can use a stack for this. By pushing each node onto the stack as we traverse the list, we effectively store the data values in the reverse order. Once all the nodes are stored in the stack, we traverse the linked list again comparing each node's value with the values popped from the top of the stack. 

   Algorithm:-
  # Step 1: Create an empty stack. This stack will be used to temporarily store the nodes from the original linked list as we traverse it.
  # Step 2: Traverse the linked list using a temporary variable `temp` till it reaches null. At each node, push the value at the current node onto the stack.
  # Step 3: Set variable `temp` back to the head of the linked list. While the stack is not empty, compare the value at the temp node to the value at the top of the stack. Pop the stack and move the temp to the next node till it reaches the end.
    During the comparison, if at any point the values do not match, the linked list is not a palindrome and hence returns false.
  # Step 4: If all values match till emp reaches the end, it means that the linked list is a palindrome, as the values read the same way both forward and backward hence we return true.


   Complexity Analysis:-
  # Time Complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.
  # Space Complexity: O(N) We use a stack to store the values of the linked list, and in the worst case, the stack will have all N values,  ie. storing the complete linked list. 
*/
bool checkPalindrome(Node* head) {
    Node* temp = head;
    stack<int> st;
    while(temp != NULL) {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(temp->data != st.top()) {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}





/*//Soln 2: Optimal       
   Intuition:- The previous approach uses O(N) additional space, which can be avoided by reversing only half of the linked list and comparing the first and second halves. If they match, reverse the portion that was originally reversed, and then return true else return false.
 To implement this in-order reversal of the second half and its comparison with the first half has to be done in phases. The first step is dividing the first and second half of the linked list by recognizing the middle node using the Tortoise and Hare Algorithm

   Algorithm:
  # Step 1: Check if the linked list is empty or has only one node. If that’s the case, it is a palindrome by definition, so return true.
  # Step 2: Initialise two pointers, ‘slow’ and ‘fast’, to find the middle of the linked list using the Tortoise and Hare Algorithm. The ‘slow’ pointer advances by one step at a time, while the ‘fast’ pointer advances by two steps at a time. Continue this until the ‘fast’ pointer reaches the end of the list or is the second last on the list. The ‘slow’ pointer will now be in the middle of the linked list.
  # Step 3: Reverse the second half of the linked list starting from the middle (the ‘slow->next’ node). This is done by calling the reverse linked list function and returning the head of the new reversed linked list. Learn more about reversing the linked list.
  # Step 4: Create two pointers, ‘first’ and ‘second’, where ‘first’ points to the head of the linked list, and ‘second’ points to the new head of the reversed second half.
  # Step 5: Compare data values of nodes from both halves. If the values do not match, it means the list is not a palindrome. In this case, return ‘false’. Continue moving both ‘first’ and ‘second’ pointers through their respective halves, comparing the data values until one of them reaches the end of the list.
  # Step 6: After the comparison, reverse the second half back to its original state using the reverse linked list function and join back the linked list to its original state. Since all the values matched in the first half and reversed in the second half, return true. In case it does not match, return false.


   Complexity Analysis:-
  # Time Complexity: O (2* N) The algorithm traverses the linked list twice, dividing it into halves. During the first traversal, it reverses one-half of the list, and during the second traversal, it compares the elements of both halves. As each traversal covers N/2 elements, the time complexity is calculated as O(N/2 + N/2 + N/2 + N/2), which simplifies to O(2N), ultimately representing O(N). 
  # Space Complexity: O(1) The approach uses a constant amount of additional space regardless of the size of the input linked list. It doesn't allocate any new data structures that depend on the input size, resulting in a space complexity of O(1).
*/
//Function to reverse LL
Node* reverseLL(Node* head) {
    if (head==NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseLL(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node* head) {
    if(head==NULL || head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLL(slow->next);

    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if (first->data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}







// Function to print the LL
void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

//Soln 1: Brute Force
    //Create a LL with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Check if the linked list is a palindrome
    if (checkPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }




//Soln 2: Optimal
    //Create a LL with values 1, 2, 3, 2, & 1 (12321, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }





    return 0;
}
