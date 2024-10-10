// Consecutive Characters | Strings | Leetcode 1446


/* Consecutive Characters (Leetcode-1446 ->  https://shorturl.at/vR8v3  )

int maxPower(string s) {
    int ans = 1;
    int curLenCnt = 1;

    for (int i=1; i < s.size(); i++) { // loop begins from 2nd character i.e, from index 1
        if (s[i] == s[i-1]) {
            curLenCnt++;
        } else {
            ans = max(ans, curLenCnt);
            curLenCnt = 1;
        }
    }
    // last check
    ans = max(ans, curLenCnt);

    return ans;
}

*/


/* Problem Statement

 The power of the string is the maximum length of a non-empty substring that contains only one unique character.
 Given a string s, return the power of s.


 # Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.

*/


#include<bits/stdc++.h>
using namespace std;


int maxPower(string s) {
    int ans = 1; //keep track of the maximum length of consecutive characters we've found
    int currLenSubStr = 1; //count the current length of consecutive characters as we loop through the string

    for (int i=1; i < s.size(); i++) { //loop begin from 2nd character i.e, index 1 to end of string
        if (s[i] == s[i-1]) {
            currLenSubStr++;
        } else {
            ans = max(ans, currLenSubStr);
            currLenSubStr = 1;// Reset for the new character
        }
    }
    ans = max(ans, currLenSubStr); // Final check for the last substring

    return ans;
}




int main() {

    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = maxPower(input);
    cout << "The maximum power of the string is: " << result << endl;



    return 0;
}


