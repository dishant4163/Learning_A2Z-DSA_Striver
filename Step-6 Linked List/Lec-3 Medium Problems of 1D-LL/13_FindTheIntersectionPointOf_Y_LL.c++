/*//(Find The Intersection Point of Y LL_Coding Ninja)-> : https://tinyurl.com/yc344rnt 



*/



#include<bits/stdc++.h>
using namespace std;


class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};


/*// Soln 1: Brute Force
   Approach: We know intersection means a common attribute present between two entities. Here, we have linked lists as given entities. 

  What should be the common attribute for two linked lists? 
 If you believe a common attribute is a node's value, then think properly! If we take our example 1, there we can see both lists have nodes of value 3. But it is not the first intersection node. So what’s the common attribute?

 It is the node itself that is the common attribute. So, the process is as follows:-

  # Keep any one of the list to check its node present in the other list. Here, we are choosing the second list for this task.
  # Iterate through the other list. Here, it is the first one. 
  # Check if the both nodes are the same. If yes, we got our first intersection node.
  # If not, continue iteration.
  # If we did not find an intersection node and completed the entire iteration of the second list, then there is no intersection between the provided lists. Hence, return null.

   Complexity Analysis:-
  # Time Complexity: O(m*n)
 Reason: For each node in list 2 entire lists 1 are iterated. 
  # Space Complexity: O(1)
 Reason: No extra space is used.
*/



/*// Soln 2.1: Better(HASHING)
 Approach:- Can we improve brute-force time complexity? In brute force, we are basically performing “searching”. We can also perform searches by Hashing. Taking into consideration that hashing process takes O(1) time complexity. So the process is as follows:-
  # Iterate through list 1 and hash its node address. Why? (Hint: depends on the common attribute we are searching)
  # Iterate through list 2 and search the hashed value in the hash table. If found, return node.

   Complexity Analysis:-
  # Time Complexity: O(n+m)
 Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
  # Space Complexity: O(n)
 Reason: Storing list 1 node addresses in unordered_set.
*/



/*// Soln 2.2: Better (Difference in Length) 
   Approach:

    We will reduce the search length. This can be done by searching the length of the shorter linked list. How? Let’s see the process.

  # Find the length of both lists.
  # Find the positive difference between these lengths.
  # Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
  # Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.


   Complexity Analysis:-
  # Time Complexity:- O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
 Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.

  # Space Complexity: O(1)
 Reason: No extra space is used.
*/



/*// Soln 3: Optimal 
   Approach:- The difference of length method requires various steps to work on it. Using the same concept of difference of length, a different approach can be implemented. The process is as follows:-
  # Take two dummy nodes for each list. Point each to the head of the lists.
  # Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.


   Complexity Analysis:-
  # Time Complexity: O(2*max(length of list1,length of list2)).
 Reason: Uses the same concept of the difference of lengths of two lists.

  # Space Complexity: O(1)
 Reason: No extra data structure is used
*/








//utility function to print linked list created
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}


int main() {



    return 0;
}
