/*//(Find Pairs with Given Sum in DLL_Coding Ninja)-> https://tinyurl.com/y4xca7e5       


Node* findTail(Node* head) {
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}


vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data) {
        if (left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k) {
            left = left->next;
        }
        else right = right->prev;
    }
    return ans;
}



*/



/*// Brute Force:-
    Steps and Approach

# Node Structure:
        A Node has three components:
            data: The value stored in the node.
            next: Pointer to the next node in the list.
            prev: Pointer to the previous node in the list.

# Creating the List:
        In the main function, a doubly linked list is created with nodes having values 1 through 5, connected both forwards and backwards.

# Finding Pairs with Given Sum:
        Outer Loop: Iterate through the list using ptr1.
        Inner Loop: For each ptr1, iterate through the list starting from ptr1->next using ptr2.
        Check Sum: For each pair (ptr1, ptr2), check if their values add up to k. If they do, store the pair.

# Printing the Results:
        Once pairs are found, they are printed in the format (value1, value2).

# Memory Management:
        The code doesn’t include the cleanup of dynamically allocated memory, which should be done to avoid memory leaks.
*/

/*// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to find all pairs with a given sum
vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> result;
    Node* ptr1 = head;

    // Traverse the list with the first pointer
    while (ptr1 != nullptr) {
        Node* ptr2 = ptr1->next;

        // Traverse the list with the second pointer
        while (ptr2 != nullptr) {
            // Check if the sum of the pair equals k
            if (ptr1->data + ptr2->data == k) {
                result.push_back(make_pair(ptr1->data, ptr2->data));
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return result;
}

// Helper function to print pairs
void printPairs(const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
}


*/

/*//Complexity Analysis:-
  Time Complexity:
    Outer Loop: Runs n times, where n is the number of nodes in the list.
    Inner Loop: For each node in the outer loop, the inner loop potentially runs n-1 times (worst case).
    Thus, the time complexity is O(N^2), because for each node, it compares with every other node.

  Space Complexity:

    Result Storage: In the worst case, the number of pairs could be O(N^2), (if all pairs are valid).
    The space complexity for storing the result is O(N^2).

So, the overall space complexity is O(N^2), primarily due to storing the pairs.
*/




/* OPtimal 
    Steps and Approach
1. Find the Tail of the List:
  # Function: findTail(Node* head)
  # Purpose: To find the last node (tail) of the doubly linked list.
  # How It Works:
        Start from the head node.
        Traverse the list until reaching the last node (where next is NULL).
        Return this last node.

2. Finding Pairs with Given Sum:
  # Function: findPairs(Node* head, int k)
  # Purpose: To find and return all pairs of nodes where the sum of their values is equal to k.
  # How It Works:
    Initialization:
        Create an empty vector ans to store the pairs.
        Check if the list is empty (head == NULL). If so, return the empty vector.
        Initialize two pointers: left starting from the head and right from the tail (using findTail function).

3. Finding Pairs:
    Iterate while left is less than right (i.e., as long as the pointers haven't crossed):
        Check if the sum of left->data and right->data is equal to k:
            If yes, add this pair to ans, then move left to the next node and right to the previous node.
        If the sum is less than k, move left to the next node (to increase the sum).
        If the sum is greater than k, move right to the previous node (to decrease the sum).

4. Return Results:
    After exiting the loop, return the ans vector containing all valid pairs.
*/

/* Node* findTail(Node* head) {
    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    return tail;
}


vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head); // TC: O(N)

    while(left->data < right->data) { // TC: O(N)
        if (left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k) {
            left = left->next;
        }
        else right = right->prev;
    }
    return ans;
}


*/



/*// Complexity Analysis:-
  # Time Complexity: O(N + N) = O(2N) because each node is processed at most twice.
  # Space Complexity: O(N) due to storage of pairs.


*/
