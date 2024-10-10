// Word Pattern | Strings | Leetcode 290

/* Word Pattern (Leetcode 290 ->  https://shorturl.at/aoDqX  )

bool wordPattern(string pattern, string s) {
        vector<string> v;
        int i = 0;
        string temp = "";
        while(i < s.size()){
            if(s[i] == ' '){
                v.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
            i++;
        }
        v.push_back(temp);

        if(v.size() != pattern.size()){
            return false;
        }
        unordered_map<char, string> m;
        set<string> st;
        for(int i = 0; i < pattern.size(); i++){
            if(m.find(pattern[i]) != m.end()){ //pattern in  hashmap
                if(m[pattern[i]] != v[i]){
                    return false;
                }
            }
            else{
                if(st.count(v[i]) > 0){
                    return false;
                }
                m[pattern[i]] = v[i];
                st.insert(v[i]);
            }
        }
        return true;
    }

*/

/* Problem Statement
 Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
  # Each letter in pattern maps to exactly one unique word in s.
  # Each unique word in s maps to exactly one letter in pattern.
  # No two letters map to the same word, and no two words map to the same letter.

  Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation: The bijection can be established as:
    'a' maps to "dog".
    'b' maps to "cat".


  Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

*/

#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string &S, string &PT)
{
    // Write your code here
    vector<string> word;
    int i = 0;
    string temp = "";

    while (i < S.size())
    {
        if (S[i] == ' ')
        {   // If the current character is a space
            // Add the current word (stored in temp) to the word vector.
            word.push_back(temp);
            temp = ""; // Reset temp to start building the next word
        }
        else
        {                 // If the character is not a space
            temp += S[i]; // add it to temp to continue forming the current word
        }
        i++; // Move to the next character
    }
    word.push_back(temp); // in case the string doesn't end with a space

    if (word.size() != PT.size())
        return false;

    unordered_map<char, string> mp;
    set<string> st;

    for (int i = 0; i < PT.size(); i++)
    {
        if (mp.find(PT[i]) != mp.end())
        { // If char already has a mapping in mp
            if (mp[PT[i]] != word[i])
            {
                return false;
            }
        }
        else
        { // If the character is not already mapped
            if (st.count(word[i]) > 0)
            {
                return false;
            }
            mp[PT[i]] = word[i]; // If the character is not mapped, map it to the current word
            st.insert(word[i]);  //  Add the current word to the set to track it as used
        }
    }
    return true;
}

int main()
{

    // Input strings
    string S, PT;

    // Read the input string S (the sentence)
    cout << "Enter the sentence: ";
    getline(cin, S);

    // Read the pattern string PT
    cout << "Enter the pattern: ";
    cin >> PT;

    // Check if the string S follows the pattern PT
    if (wordPattern(S, PT))
    {
        cout << "The string follows the pattern." << endl;
    }
    else
    {
        cout << "The string does not follow the pattern." << endl;
    }

    return 0;
}

