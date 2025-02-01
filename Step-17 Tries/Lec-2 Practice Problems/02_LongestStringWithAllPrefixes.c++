// Longest String with All Prefixes / CompletecString



// Problem-Link-> https://www.naukri.com/code360/problems/longest-common-prefix_2090383  



#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
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
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else {
                return false;
            }
        }
        return true;
    }

};



string completeString(int n, vector<string>& arr) {
    Trie* obj = new Trie();
    for(auto &it : arr) {
        obj->insert(it);
    }

    string longest = "";

    for(auto &it : arr) {
        if(obj->checkIfPrefixExists(it)) {
            if(it.size() > longest.size()) {
                longest = it;
            }
            else if(it.size() == longest.size() && it < longest) {
                longest = it;
            }
        }
    }

    if(longest.empty()) return "None";
    return longest;
}



int main() {

    // Initialize a vector of strings
    vector<string> strings = {"striver", "strive", "striving", "striven", "strived", "striv"};

    // Find the longest complete string in the vector
    string longestComplete = completeString(strings.size(), strings);

    // Print the longest complete string
    cout << "Longest complete string: " << longestComplete << endl;


    return 0;
}
