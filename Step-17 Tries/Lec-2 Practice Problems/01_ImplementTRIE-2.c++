// Implement Trie - II  | INSERT | countWordsEqualTo() | countWordsStartingWith() | Erase




/*// Problem-Link-> https://www.naukri.com/code360/problems/trie-delete-operation_1062663?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf 

#include <bits/stdc++.h> 

// Definition of TrieNode class
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


TrieNode* solution::deleteWord(TrieNode* root, string word) {
    // Write your code here
    TrieNode* node = root;
    for(int i=0; i < word.length(); i++) {
        int indexKey = word[i] - 'a';
        if(node->children[indexKey] == NULL) {
            return root;
        }
        node = node->children[indexKey];
    }

    return node;
}



*/



#include<bits/stdc++.h>
using namespace std;


struct Node{

    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        cntEndWith;
    }

    int getPrefix() {
        cntPrefix;
    }

};



class Trie {
private:

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for(int i=0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string word) {
        Node* node = root;
        for(int i=0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else {
                return;
            }
        }
        node->deleteEnd();
    }

};




int main() {

    Trie trie; 

    trie.insert( "apple" ); 
    trie.insert("app"); 
    cout << "Inserting strings 'apple', 'app' into Trie"<< endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl << endl; 
    cout << "Erasing word 'app' from trie"<< endl;
    trie.erase("app"); 
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl; 
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl;


    return 0;
}
