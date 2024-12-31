// Length of Longest Substring Without Repeating Characters


/* Longest Substring Without Repeating Characters -> https://shorturl.at/dtfON  

#include <bits/stdc++.h> 
int lengthOfLongestSubstring(string &s) {
    // Write your code here.
    int n = s.length();
    int lPtr = 0, rPtr = 0, maxlen = 0;

    //BASE CASE
    if(n == 0) return 0;

    vector<int> hashAr(256, -1);

    while(rPtr < n) {
        if(hashAr[s[rPtr]] != -1 && hashAr[s[rPtr]] >= lPtr) {
            lPtr = hashAr[s[rPtr]] + 1;
        }

        maxlen = max(maxlen, (rPtr - lPtr + 1));
        hashAr[s[rPtr]] = rPtr;
        rPtr++;
    }

    return maxlen;
}

*/


#include<bits/stdc++.h>
using namespace std;

/*// Soln-1 Brute Force
// Time Complexity: O(N^2)
// Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

int solve(string& str) {
    int size = str.length();
    int maxiLen = 0;

    for(int i=0; i < size; i++) {
        int hashAr[256] = {0};
        for(int j=i; j < size; j++) {
            if(hashAr[str[j]] == 1) break;
            maxiLen = max(maxiLen, (j-i+1));

            // Mark this character as seen by setting hashAr[str[j]] = 1
            hashAr[str[j]] = 1;
        }
    }

    return maxiLen;
}
*/




// Soln-2 OPtimal Soln
int longestSubstr(string& Str) {
    int S = Str.length();
    int lptr = 0, rptr = 0, maxans = 0;

    //base case
    if (S == 0) return 0;

    vector<int> hashArr(256, -1); //hasharray initialize with 256 characters and assign value is -1

    // unordered_map<char, int> mp;

    while(rptr < S) {
        if (hashArr[Str[rptr]] != -1 && hashArr[Str[rptr]] >= lptr) {
            lptr = hashArr[Str[rptr]] + 1; //update leftptr
        }

        maxans = max(maxans, (rptr - lptr + 1));
        hashArr[Str[rptr]] = rptr;
        rptr++;
    }

    return maxans;
}








int main() {

/*// Soln-1 Brute Force
    string str = "takeUforward";
    cout << "Length of longest substring without repeating characters is: " << solve(str) << endl;
*/


// Soln-2 OPtimal Soln
    string S = "abcdecdzf";
    cout << "Length of longest substring without repeating characters: " << longestSubstr(S) << endl; 


    return 0;
}
