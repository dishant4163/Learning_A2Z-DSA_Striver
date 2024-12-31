// Count number of substrings with exactly k distinct characters
// This problem is based on -> Longest Substring with At Most K Distinct Characters


/* Count With K Different Characters -> ( https://shorturl.at/SEKbD )


#include<bits/stdc++.h>

int atMostKDistinctSubstring(string& s, int k) {
    int l=0, r=0, cnt=0, ans = 0;
    vector<int> mpAr(26, 0);

    while(r < s.size()) {
        mpAr[s[r] - 'a']++;

        if(mpAr[s[r] - 'a'] == 1) cnt++;

        while(cnt > k) {
            mpAr[s[l] - 'a']--;
            if(mpAr[s[l] - 'a'] <= 0) cnt--;
            l++;
        }

        ans += (r-l+1);
        r++;
    }

    return ans;
}

int countSubStrings(string str, int k) {
    // Write your code here.

    //this problem is based on "Substring with At-Most K Distinct Characters"
    return atMostKDistinctSubstring(str, k) - atMostKDistinctSubstring(str, k-1);
}


*/



#include<bits/stdc++.h>
using namespace std;

int atMostKDistinctSubstring(string& s, int k) {
    int l = 0, r = 0, cnt = 0, ans = 0;
    vector<int> mpAr(26, 0);  // Frequency array to store the count of characters.

    while (r < s.size()) {
        mpAr[s[r] - 'a']++;  // Increment the frequency of the character at r

        if (mpAr[s[r] - 'a'] == 1) cnt++;  // If it's a new character, increment distinct count

        while (cnt > k) {
            mpAr[s[l] - 'a']--;  // Reduce frequency of character at l
            if (mpAr[s[l] - 'a'] == 0) cnt--;  // If a character's count reaches 0, reduce distinct count
            l++;  // Shrink the window from the left
        }

        ans += (r - l + 1);  // All substrings ending at r with at most k distinct characters
        r++;  // Expand the window by moving the right pointer
    }

    return ans;  // Return total count of substrings with at most k distinct characters
}

int countSubStrings(string str, int k) {
    // To count substrings with exactly k distinct characters
    return atMostKDistinctSubstring(str, k) - atMostKDistinctSubstring(str, k - 1);
}





int main() {
    string str = "abcabc";
    int k = 2;
    cout << "Number of substrings with exactly " << k << " distinct characters: " << countSubStrings(str, k) << endl;
    return 0;
}

