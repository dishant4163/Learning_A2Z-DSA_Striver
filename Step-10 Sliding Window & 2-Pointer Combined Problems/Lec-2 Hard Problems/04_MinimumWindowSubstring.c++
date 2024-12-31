// Minimum Window Substring


/* Minimum Window Substring -> ( https://shorturl.at/4WSlq )

string minSubstring(string &a, string &b) {
    // Write your code here.
    int l=0, r=0, minlen=INT_MAX, startInd= -1, cnt=0;
    vector<int> hashMp(256, 0);

    for(int i = 0; i < b.size(); i++) {
        hashMp[b[i]]++;
    }

    while(r < a.size()) {
        if(hashMp[a[r]] > 0) {
            cnt++;
        }

        hashMp[a[r]]--;

        while(cnt == b.size()) {
            if((r-l+1) < minlen) {
                minlen = (r-l+1);
                startInd = l;
            }

            hashMp[a[l]]++;

            if(hashMp[a[l]] > 0) {
                cnt--;
            }

            l++;
        }
        r++;
    }
    return (startInd == -1) ? "" : a.substr(startInd, minlen);
}


*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC: O(N x (N+M)) = O(N^2 + N x M),  SC:- O(256)
string minWinSubStr(string& a, string& b) {
    int minLen = INT_MAX, startInd = -1;

    // Iterate through all possible starting points
    for (int i = 0; i < a.size(); i++) {
        int hashArCnt[256] = {0}; // Initialize an array of size 256 to store character counts
        int Cnt=0; //Reset counter for each new starting index

        // Build the frequency table for string b
        for (int j = 0; j < b.size(); j++) {
            hashArCnt[b[j]]++;
        }

        // Check for the valid window from i onwards
        for (int j = i; j < a.size(); j++) {
            // If a[j] is part of b, we decrement the count
            if (hashArCnt[a[j]] > 0) {
                Cnt++;
            }

            // Decrement count of character a[j] after using it
            hashArCnt[a[j]]--;

            // If we've found a valid window (all chars in b are matched)
            if (Cnt == b.size()) {
                if ((j - i + 1) < minLen) {
                    minLen = (j - i + 1);
                    startInd = i;
                }
                break;  // We found a valid window, so break out
            }
        }
    }

    // Return the minimum window substring
    if(startInd == -1) {
        return ""; //return empty string
    }
    else {
        return a.substr(startInd, minLen);
    }
}
*/




//Soln-2 OPtimal
// TC:- O(),   SC:- O(256)
string minWindowSubstr(string& s, string& t) {
    int minlen=INT_MAX, l=0, r=0, cnt=0, startIndex=-1;
    int n = s.size(), m = t.size();
    //hashMap to track frequency of characters in t (ASCII values are between 0 and 255)
    vector<int> hashMap(256, 0);

    //Count frequency of each character in t and store it in hashMap
    for(int i=0; i < m; i++) {
        hashMap[t[i]]++;
    }

// Sliding window approach
    while(r < n) {
        if(hashMap[s[r]] > 0) {
            cnt++;
        }

        //Decrease the frequency of the current character in the map (we've seen it)
        hashMap[s[r]]--;

        //When we have a valid window (i.e., all characters from t are found in the current window)
        while(cnt == m) {
            //Update the minimum length window if the current window is smaller
            if((r-l+1) < minlen) {
                minlen = (r-l+1);
                startIndex = l;
            }

            // Try to shrink the window from the left by moving the left pointer 'l'
            hashMap[s[l]]++; //Increment frequency of the character s[l] as we're excluding it from the window

            //If the character at s[l] was part of the original t, reduce the count
            if(hashMap[s[l]] > 0) {
                cnt--;
            }
            l++;
        }

        r++;
    }

    return (startIndex == -1) ? "" : s.substr(startIndex, minlen);
}







int main() {

/*//Soln-1 Brute Force
    string a = "adobecodebanc", b = "abc";
    cout << "Minimum window is: " << minWinSubStr(a, b) << endl;
*/


//Soln-2 OPtimal Soln
    string s = "ddaaabbca", t = "abc";
    cout << "Minimum window is: " << minWindowSubstr(s, t) << endl;



    return 0;
}

