// Longest Palindromic Substring | Leetcode 5 | Strings | Odd and even length approach 


/* //Longest Palindromic Substring (Coding Ninjas ->  https://shorturl.at/UJIf9  )

string longestPalinSubstring(string str) {
    // Write your code here.
    int start = 0;
    int maxLen = 1;
    int n = str.length();

    for (int i=1; i < n; i++) {
        //Even Length plaindrome
        int left = i-1;
        int right = i;
        while(left >= 0 && right < n && str[left] == str[right]) {
            if ((right - left + 1) > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }

        //Odd Length Palindrome
        left = i-1;
        right = i+1;
        while(left >= 0 && right < n && str[left] == str[right]) {
            if((right - left + 1) > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

    return str.substr(start, maxLen);
}

*/


#include<bits/stdc++.h>
using namespace std;


string longestPalindrome(string str) {
    int start = 0;
    int maxLen = 1;
    int n = str.length();

    for (int i=1; i < n; i++) {
        // Even length palindrome
        int l = i-1;
        int r = i;
        while(l >= 0 && r < n && str[l] == str[r]) {
            if((r-l+1) > maxLen) {
                maxLen = r-l+1;
                start = l;
            }
            l--;
            r++;
        }

        // Odd length palindrome
        l = i-1;
        r = i+1;
        while(l >= 0 && r < n && str[l] == str[r]) {
            if((r-l+1) > maxLen) {
                maxLen = r-l+1;
                start = l;
            }
            l--;
            r++;
        }
    }

    return str.substr(start, maxLen);
}


int main() {

    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = longestPalindrome(input);
    cout << "The longest palindromic substring is: " << result << endl;





    return 0;
}


