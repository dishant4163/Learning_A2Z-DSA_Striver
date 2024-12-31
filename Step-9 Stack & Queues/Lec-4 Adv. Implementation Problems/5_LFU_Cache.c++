// Implement Least Frequently Used(LFU) Cache


/* Implement LFU Cache -> ( https://shorturl.at/C7jQN )

#include <bits/stdc++.h>

// declaring Node with key, value and frequency count 
struct Node{
    int key;
    int value;
    int cnt; // Stores the frequency count (how many times the key has been accessed)
    Node* next;
    Node* prev;

    Node(int KEY, int VALUE) {
        key = KEY;
        value = VALUE;
        cnt = 1; // Frequency starts at 1 because the node is being added to the cache
        next = prev = nullptr;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addAfterHead(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> keyNodeMp;
    unordered_map<int, List*> freqListMP;
    int maxSizeCache;
    int minFreq; // check frequency of LFU 
    int curSize; // count currSize

    void updateFreqListMap(Node* node) {
        keyNodeMp.erase(node->key);
        freqListMP[node->cnt]->removeNode(node);

        if(node->cnt == minFreq && freqListMP[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if (freqListMP.find(node->cnt + 1) != freqListMP.end()) {
            nextHigherFreqList = freqListMP[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addAfterHead(node);
        freqListMP[node->cnt] = nextHigherFreqList;
        keyNodeMp[node->key] = node;
    }

public:
    LFUCache(int capacity) {
        // Write your code here.
        maxSizeCache = capacity;
        minFreq = 0; // check frequency of LFU 
        curSize = 0; // count currSize
    }

    int get(int key) {
        // Write your code here.
        // if key found
        if(keyNodeMp.find(key) != keyNodeMp.end()) {
            Node* newNode = keyNodeMp[key];
            int val = newNode->value;
            updateFreqListMap(newNode);
            return val;
        }

        //else not found
        return -1;
    }

    void put(int key, int value) {
        // Write your code here.
        if(maxSizeCache == 0) return;

        if(keyNodeMp.find(key) != keyNodeMp.end()) {
            Node* newNode = keyNodeMp[key];
            newNode->value = value;
            updateFreqListMap(newNode);
        }
        else {
            if (curSize == maxSizeCache) {
                List* list = freqListMP[minFreq];
                keyNodeMp.erase(list->tail->prev->key);
                freqListMP[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;

            //new values has to be added who is not there previously
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMP.find(minFreq) != freqListMP.end()) {
                listFreq = freqListMP[minFreq];
            }
            Node* newnode = new Node(key, value);
            listFreq->addAfterHead(newnode);
            keyNodeMp[key] = newnode;
            freqListMP[minFreq] = listFreq;
        }
    }
};


*/


#include<bits/stdc++.h>
using namespace std;


// declaring Node with key, value and frequency count 
struct Node{
    int key;
    int value;
    int cnt; // Stores the frequency count (how many times the key has been accessed)
    Node* next;
    Node* prev;

    Node(int KEY, int VALUE) {
        key = KEY;
        value = VALUE;
        cnt = 1; // Frequency starts at 1 because the node is being added to the cache
        next = prev = nullptr;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addAfterHead(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyNodeMp;
    unordered_map<int, List*> freqListMP;
    int maxSizeCache;
    int minFreq; // check frequency of LFU 
    int curSize; // count currSize 

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0; // check frequency of LFU 
        curSize = 0; // count currSize 
    }

    void updateFreqListMap(Node* node) {
        keyNodeMp.erase(node->key);
        freqListMP[node->cnt]->removeNode(node);

        if(node->cnt == minFreq && freqListMP[node->cnt]->size == 0) {
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        if(freqListMP.find(node->cnt + 1) != freqListMP.end()) {
            nextHigherFreqList = freqListMP[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addAfterHead(node);
        freqListMP[node->cnt] = nextHigherFreqList;
        keyNodeMp[node->key] = node;
    }


    int get(int key) {
        // if key found
        if(keyNodeMp.find(key) != keyNodeMp.end()) {
            Node* newNode = keyNodeMp[key];
            int val = newNode->value;
            updateFreqListMap(newNode);
            return val;
        }

        //else not found
        return -1;
    }

    void put(int key, int value) {
        if(maxSizeCache == 0) return;

        if(keyNodeMp.find(key) != keyNodeMp.end()) {
            Node* newNode = keyNodeMp[key];
            newNode->value = value;
            updateFreqListMap(newNode);
        }
        else {
            if (curSize == maxSizeCache) {
                List* list = freqListMP[minFreq];
                keyNodeMp.erase(list->tail->prev->key);
                freqListMP[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;

            //new values has to be added who is not there previously
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMP.find(minFreq) != freqListMP.end()) {
                listFreq = freqListMP[minFreq];
            }
            Node* newnode = new Node(key, value);
            listFreq->addAfterHead(newnode);
            keyNodeMp[key] = newnode;
            freqListMP[minFreq] = listFreq;
        }
    }
};





int main() {

    LFUCache cache(2); // capacity = 2

    cache.put(1, 1); // cache = {1=1}
    cache.put(2, 2); // cache = {1=1, 2=2}
    cout << cache.get(1) << endl; // returns 1, cache = {2=2, 1=1}
    cache.put(3, 3); // evicts key 2, cache = {1=1, 3=3}
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4); // evicts key 1, cache = {3=3, 4=4}
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}