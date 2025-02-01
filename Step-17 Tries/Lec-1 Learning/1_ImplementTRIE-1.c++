// Implement TRIE-I


/*// Problem-Link-> https://www.naukri.com/code360/problems/trie-implementation_1062581?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf



// Definition of TrieNode class.

// class TrieNode {
// public:
//     TrieNode * children[26];
//     bool isEnd;
//     TrieNode()
//     {
//         isEnd=false;
//         for(int i=0;i<26;i++)
//             children[i]=NULL;
//     }

// };


TrieNode *root = new TrieNode();

void solution::insert(string word) {
    // Write your code here.
    TrieNode *node = root;
    for(int i = 0; i < word.length(); i++) {
        int containsKey = word[i] - 'a';
        if(!node->children[containsKey]) {
            node->children[containsKey] = new TrieNode();
        }
        node = node->children[containsKey];
    }
    node->isEnd = true;
}

bool solution::search(string word) {
    // Write your code here.
    TrieNode *node = root;
    for(int i = 0; i < word.length(); i++) {
        int containsKey = word[i] - 'a';
        if(!node->children[containsKey]) {
            return false;
        }
        node = node->children[containsKey];
    }
    return (node != NULL && node->isEnd);
}

bool solution::startsWith(string word) {
    // Write your code here.
    TrieNode *node = root;
    for(int i = 0; i < word.length(); i++) {
        int containsKey = word[i] - 'a';
        if(!node->children[containsKey]) {
            return false;
        }
        node = node->children[containsKey];
    }
    return true;
}

*/



#include<bits/stdc++.h>
using namespace std;


// Node structure for Trie
struct Node {
    // array to store links to child nodes each index represents a letter
    Node *links[26];
    //Flag indicates if the node marks the end of a word
    bool flag = false;


    // Check if the node contains a specific key (letter)
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); // is not NULL means this ch exists in trie
    }


    // Insert a new node with a specific key (letter) into the Trie
    void put(char ch, Node *newNode) {
    // for this character the reference Node is this newNode 
        links[ch - 'a'] = newNode;
    }


    // Get the node with a specific key (letter) from the Trie
    Node *get(char ch) {
        return links[ch - 'a'];
    }


    // Set the current node as the end of a word
    void setEnd() {
        flag = true;
    }


    // Check if the current node marks the end of a word
    bool isEnd() {
        return flag;
    }

};


// Trie class
class Trie {
private:
    Node *root;

public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new Node();
    }


    // Inserts a word into the Trie
    // Time Complexity O(len), where len is the length of the word
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new Node()); // new Node() means to new trie while inserting
            }
            // Move to the reference trie next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }


    // Returns if the word is in the trie
    bool search(string word) {
        Node *node = root;
        for(int i=0; i < word.length(); i++) {
            // if this not contains word[i]
            if(!node->containsKey(word[i])) {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]); //i.e, it constains word[i]
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }


    // Returns if there is any word in the trie that 
    // starts with the given prefix
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(!node->containsKey(prefix[i])) {
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]); //i.e, letter found there is word with the given prefix
        }
        // The prefix is found in the Trie
        return true;
    }

};




int main() {

    Trie trie;

    cout << "Inserting words: Striver, Striving, String, Strike" << endl;
    trie.insert("striver");
    trie.insert("striving");
    trie.insert("string");
    trie.insert("strike");
    cout << endl;

    cout << "Search if Strawberry exists in trie: " <<
    (trie.search("strawberry") ? "True" : "False")<< endl;
    cout << endl;

    cout << "Search if Strike exists in trie: " <<
    ( trie.search("strike") ? "True" : "False" )<< endl;
    cout << endl;

    cout << "If words is Trie start with Stri: " <<
    (trie.startsWith("stri") ? "True" : "False" )<< endl;
    cout << endl;

    return 0;
}
