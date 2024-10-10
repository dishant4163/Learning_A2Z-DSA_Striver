// Isomorphic Strings | Leetcode 


/* // Isomorphic Strings (Coding Ninja ->  https://shorturl.at/HneHz   )

bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    if (str1.size() != str2.size()) return false;

    char unordered_map_str1[128] = {0};
    char unordered_map_str2[128] = {0};

    for (int i=0; i < str1.size(); i++) {
        if (unordered_map_str1[str1[i]] != unordered_map_str2[str2[i]]) {
            return false;
        }

        unordered_map_str1[str1[i]] = i+1;
        unordered_map_str2[str2[i]] = i+1;
    }

    return true;
}

*/



#include<bits/stdc++.h>
using namespace std;

// Solution 1
bool isIsomorphic1(string a, string b) {
    // if (a.length() != b.length()) return false;

    int lenStr = a.size();//both str have same use1 of them
    char arSeen[128] = {};// have take char arr of 128 ascii character
    for(int i=0; i < lenStr; i++) {
        char c = a[i];
        if (!arSeen[c]) {
            for (char a: arSeen) if (a == b[i]) return false;
            arSeen[c] = b[i];
        } else if (arSeen[c] != b[i]) return false;
    }
    return true;
}






// Solution-2 apply this approach
bool isIsomorphic(string s, string t) {
    // if(s.size() != t.size()) return false;

// declaring hashmaps with assigned value as 0 
    char map_s[128] = {0}; //unordered_map can b used
    char map_t[128] = {0};

    for (int i=0; i < s.size(); i++) {
        if (map_s[s[i]] != map_t[t[i]]) return false;
        map_s[s[i]] = i+1;
        map_t[t[i]] = i+1;
    }

    return true; //given strings are isomorphic 
}







int main() {


// Solution-1
    string str1, str2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    // Check if they are isomorphic
    if (isIsomorphic1(str1, str2)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }





// Solution-2 
    string Str1, Str2;

    // Input two strings
    cout << "Enter the first string: ";
    cin >> Str1;
    cout << "Enter the second string: ";
    cin >> Str2;

    // Check if they are isomorphic
    if (isIsomorphic(Str1, Str2)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }





    return 0;
}
