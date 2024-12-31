// Implement Least Recently Used(LRU) Cache


/* Implement LRU Coding Ninjas-> ( https://shorturl.at/WVWgA )

#include<bits/stdc++.h>

class LRUCache {
public:
    class Node {
    public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key1 , int value1) {
        key = key1;
        value = value1;
        next = nullptr;
        prev = nullptr;
    }
};

private:
    unordered_map<int, Node*> mp;
    int capa;
    Node* head = new Node(-1, -1); // Dummy head
    Node* tail = new Node(-1, -1); // Dummy tail

    //function to add a node to the front of the head in DLL(mark it as most recently used
    void addNodeToFront(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    //function to remove a node from the DLL
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }    


public:
    LRUCache(int capacity) {
        // Write your code here
        capa = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // Write your code here
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* resnode = mp[key];
        deleteNode(resnode);
        addNodeToFront(resnode);

        return resnode->value;
    }

    void put(int key, int value) {
        // Write your code here
        if(mp.find(key) != mp.end()) { // Key exists, update the value and move the node to the front
            Node* existingNode = mp[key];
            existingNode->value = value;
            deleteNode(existingNode);
            addNodeToFront(existingNode);
        }
        else { // Key does not exist
            if(mp.size() == capa) {
                //Cache is full, remove the least recently used (LRU) item most lru i.e., tail->prev->key
                Node* node = tail->prev;
                mp.erase(node->key);
                deleteNode(node);
            }

            // Create a new node, insert it into the cache and list
            Node* node = new Node(key, value);
            mp[key] = node;
            addNodeToFront(node);
        }
    }
};

*/



#include<bits/stdc++.h>
using namespace std;

// OPtimal Soln (using DLL & HashMap(unordered_map))
class LRUCache {
public:
    // declare Node for DLL
    class Node {
        public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int KEY, int VALUE) {
            key = KEY;
            value = VALUE;
            next = nullptr;
            prev = nullptr;
        }
    };

private:
    unordered_map<int, Node*> mp;
    int capa;
    Node* head = new Node(-1, -1); // Dummy head
    Node* tail = new Node(-1, -1); // Dummy tail

    //function to add a node After the head in DLL(mark it as most recently used)
    void addNodeAterHead(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    //function to remove a node from the DLL
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

public:
    LRUCache(int capacity) {
        capa = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // if map doesn't have key
        if(mp.find(key) == mp.end()) return -1;

        //if map have the key
        Node* referNode = mp[key];
        deleteNode(referNode);
        addNodeAterHead(referNode);

        return referNode->value;
    }

    void put(int key, int value) {
        // Key exists, update the value and move the node to the front
        if(mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->value = value;
            deleteNode(existingNode);
            addNodeAterHead(existingNode);
        }
        else { // Key does not exist or cache is full already
            if(mp.size() == capa) {
                Node* node = tail->prev;
                //Cache is full, remove the least recently used (LRU) item most lru i.e., tail->prev->key
                mp.erase(node->key);
                deleteNode(node);
            }

            // Create a new node, insert it into the cache and list
            Node* node = new Node(key, value);
            mp[key] = node;
            addNodeAterHead(node);
        }
    }


};




int main() {


// OPtimal Soln (using DLL & HashMap(unordered_map))
    LRUCache cache(2);

    cache.put(1, 1); 
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout  << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;


    return 0;
}