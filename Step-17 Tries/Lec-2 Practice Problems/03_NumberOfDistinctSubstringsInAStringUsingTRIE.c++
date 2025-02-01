// Number of Distinct Substrings in a String Using Trie


/*// Problem-Link-> https://www.naukri.com/code360/problems/count-distinct-substrings_985292


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

int countDistinctSubstrings(string &s) {
    // Write your code here.
    Node* root = new Node();
    int cnt = 0, n = s.size();

    for(int i=0; i < n; i++) {
        Node* node = root;
        for(int j=i; j < n; j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }

    return cnt+1;
}


*/



#include<bits/stdc++.h>
using namespace std;

// Soln-1 BRUTE FORCE (using SET)

// Function to count all distinct substrings of a given string
set<string> cntDistinctSubstrings(const string& s) {
    set<string> st;
    int n = s.size();

    for(int i=0; i < n; i++) {
        string cntStr = "";
        for(int j=i; j < n; j++) {
            cntStr += s[j];
            st.insert(cntStr);
        }
    }

    return st;
}




// SOLN-2 OPTIMAL SOln (Using TRIE)

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


int countDistinctSubstrings(string &str) {
    Node* root = new Node();
    int len = str.size(), cnt = 0;

    for(int i=0; i < len; i++) {
        Node* node = root;
        for(int j=i; j < len; j++) {
            if(!node->containsKey(str[j])) {
                node->put(str[j], new Node());
                cnt++;
            }
            node = node->get(str[j]);
        }
    }

    return cnt + 1;
}







int main() {

// Soln-1
cout << "Soln-1 via BRUTE FORCE" << endl << endl;
    string s = "abab";
    cout << "Given String: " << s << endl;

    // Call the function to
    // count distinct substrings
    set<string> substrings = cntDistinctSubstrings(s);
    int cnt = 0;
    // Print the distinct substrings
    cout << "Distinct Substrings:" << endl;
    for (const auto& substr : substrings) {
        cout << substr << endl;
        cnt++;
    }
    cout << endl;
    // Count + 1 as we have to count
    // the empty string as well
    cout << "Number of distinct substrings: "<< cnt + 1<< endl << endl;



// Soln-2 OPTIMAL Approach (Using TRIE)
cout << "Soln-2  OPTIMAL SOln using TRIE" << endl;
    string str = "abab";  
    cout << "Current String: " << str << endl;
    // Input string
    cout << "Number of distinct substrings: " << countDistinctSubstrings(str) << endl;



    return 0;
}

