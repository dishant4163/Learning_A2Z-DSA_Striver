/*// (LRU Cache Implementation_Coding Ninja)-> https://shorturl.at/NdqU4



*/

/* What is LRU Cache?
 Cache replacement algorithms are efficiently designed to replace the cache when the space is full. The Least Recently Used (LRU) is one of those algorithms. As the name suggests when the cache memory is full, LRU picks the data that is least recently used and removes it in order to make space for the new data. The priority of the data in the cache changes according to the need of that data i.e. if some data is fetched or updated recently then the priority of that data would be changed and assigned to the highest priority, and the priority of the data decreases if it remains unused operations after operations.

   Operations on LRU Cache:
    LRUCache (Capacity c): Initialize LRU cache with positive size capacity c.
    get (key): Returns the value of key ‘k’ if it is present in the cache otherwise it returns -1. Also updates the priority of data in the LRU cache.
    put (key, value): Update the value of the key if that key exists, Otherwise, add a key-value pair to the cache. If the number of keys exceeds the capacity of the LRU cache then dismiss the least recently used key.
*/

#include <bits/stdc++.h>
using namespace std;

/* Soln : OPtimal Approach(using Doubly LL & Hashing)
   Steps to Implement LRU Cache

1. Understand the Basics:
  # Cache: A storage layer that keeps a limited number of items.
  # Least Recently Used: When the cache is full and needs space, the item that hasn't been used for the longest time will be removed.

2. Data Structures: To efficiently manage the LRU cache, you typically need two main data structures:
  # Hash Map: To store key-value pairs for quick access.
  # Doubly Linked List: To keep track of the order of access (most recently used to least recently used).

3. Setup:
  # Hash Map: Each key maps to a node in the doubly linked list.
  # Doubly Linked List: Nodes represent the cache items and their order of usage.

4. Operations:
  # Access/Update: When an item is accessed or updated, it needs to be moved to the front of the doubly linked list (most recently used).
  # Add: When adding a new item, if the cache is full, remove the item at the end of the list (least recently used).
  # Delete: Remove an item from both the hash map and the doubly linked list.


   Implementation Details:
1. Initialization:
  # Create a hash map (cache) and a doubly linked list (list).
  # Define constants for the capacity of the cache.

2. Hash Map Operations:
  # get(key): If the key is in the hash map, move the corresponding node to the front of the list and return the value. If not, return a default value (e.g., -1).
  # put(key, value): If the key is already in the hash map, update the value and move the node to the front. If not, add the key-value pair. If the cache exceeds its capacity, remove the node from the end of the list and delete the corresponding key from the hash map.

2. Doubly Linked List Operations:
  # Add to Front: Insert a new node at the beginning of the list.
  # Remove Node: Remove a node from the list, which involves updating the pointers of the neighboring nodes.


   Complexity Analysis of LRU Cache:
  #Time Complexity:
    put() operation: O(1) i.e. time required to insert or update new key-value pair is constant
    get() operation: O(1) i.e. time required to get the value of a key is constant
  #Space Complexity: O(c) where c is the capacity of the Cache.

*/

// LRU Cache class
class LRUCache
{
public:

  // Constructor to initialize the cache with a given capacity
  LRUCache(int capacity)
  {

  }

  // Function to get the value for a given key if it exists, otherwise return -1
  int get(int key)
  {
    
  }

  // Function to put a key-value pair into the cache
  void put(int key, int value)
  {
    
  }

  // Add a node right after the head
  // (most recently used position)
  void add(Node *node)
  {
  }

  // Remove a node from the list
  void remove(Node *node)
  {
    
  }
};

int main()
{

  // Soln Optimal :
  LRUCache cache(2); // Create a cache with capacity 2

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl; // returns 1
  cache.put(3, 3);              // evicts key 2
  cout << cache.get(2) << endl; // returns -1 (not found)
  cache.put(4, 4);              // evicts key 1
  cout << cache.get(1) << endl; // returns -1 (not found)
  cout << cache.get(3) << endl; // returns 3
  cout << cache.get(4) << endl; // returns 4

  return 0;
}
