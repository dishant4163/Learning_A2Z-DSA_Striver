// Longest Repeating Character Replacement


/* Longest Repeating Substring -> ( https://shorturl.at/kh7D5 )

int longestRepeatingSubstring(string &str, int k) {
    // Write your code here.
    int l=0, r=0, maxlen=0, maxfreq=0, n=str.size();
    vector<int> hashAr(26, 0);

    while(r < n) {
        hashAr[str[r] - 'A']++;

        maxfreq = max(maxfreq, hashAr[str[r] - 'A']);

        if ((r-l+1) - maxfreq > k) {
            hashAr[str[l] - 'A']--;
            maxfreq = 0;
            l++;
        }

        if((r-l+1) - maxfreq <= k) {
            maxlen = max(maxlen , (r-l+1));
        }

        r++;
    }

    return maxlen;
}

*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(N^2),  SC:- O(26)
int longestsubStrCharReplace(string& Str, int K) {
    int s = Str.size(), maxLen = 0;

    for(int i=0; i < s; i++) {
         vector<int> hashArr(26, 0);  //Frequency array for characters in the substring
        int maxFreq = 0;  //Reset maxFreq for each new starting point

        for(int j=i; j < s; j++) {
            hashArr[Str[j] - 'A']++; //Increment frequency of the current character

            //Update the max frequency in the substring
            maxFreq = max(maxFreq, hashArr[Str[j] - 'A']); 

            //Calculate the number of changes needed
            int Changes = (j-i+1) - maxFreq; //len - maxfreq

            if(Changes <= K) {
                maxLen = max(maxLen, (j-i+1)); //Update maxLen if current substring is valid
            }
            else break; //No need to continue expanding the substring
        }
    }

    return maxLen;
}
*/




/*//Soln-2.1 OPtimal (using 2-ptr & Sliding window with Array, 2-loops)
// TC:- O(N+N) x 26 => O(52N),  SC:- (26)
int longestSubStrCharsReplace(string& str, int x) {
    int Lptr =0, Rptr = 0, maxLEN = 0, maxFREQ =0, m=str.size();
    vector<int> hashARR(26, 0);

    while(Rptr < m) { // <-- this will take O(N)
        hashARR[str[Rptr] - 'A']++;

        maxFREQ = max(maxFREQ, hashARR[str[Rptr] - 'A']);

        while((Rptr-Lptr+1) - maxFREQ > x) { // <-- this will also take near about O(N)
            hashARR[str[Lptr] - 'A']--;
            maxFREQ = 0;

            for(int i=0; i <26; i++) { //<-- this will take O(26)
                maxFREQ = max(maxFREQ, hashARR[str[Lptr] - 'A']);
            }

            Lptr++;
        }

        if((Rptr-Lptr+1) - maxFREQ <= x) {
            maxLEN = max(maxLEN, (Rptr-Lptr+1));
        }

        Rptr++;
    }

    return maxLEN;
}
*/




// Soln-2.2 OPtimal (using 2-ptr & Sliding window with HashMap)
// TC:- O(N), SC:- O(26)
int longestSubStrCharReplace(string& s, int k) {
    int l=0, r=0, maxlen=0, maxfreq=0, n=s.size();
    vector<int> hashAr(26, 0);

    while(r < n) {
        hashAr[s[r] - 'A']++;

        maxfreq = max(maxfreq, hashAr[s[r] - 'A']);

        if((r-l+1) - maxfreq > k) {
            hashAr[s[l] - 'A']--;
            maxfreq=0;

            l++;
        }

        if((r-l+1) - maxfreq <= k) {
            maxlen = max(maxlen, (r-l+1));
        }

        r++;
    }

    return maxlen;
}







int main() {

/*//Soln-1 Brute Force
    string Str = "AABABBA";
    int K = 2;
    cout << "Maximum length string after replcement is: " << longestsubStrCharReplace(Str, K) << endl;
*/


/*//Soln-2.1 OPtimal (using 2-ptr & Sliding window with Array, 2-loops)
    string str = "MLLLLLLWWVVVVVBBBVVVYYYVVVVV";
    int x = 7;
    cout << "Maximum length string after replcement is: " << longestSubStrCharsReplace(str, x) << endl;
*/


//Soln-2.2 MOST-OPtimal (using 2-ptr & Sliding window with HashMap/array, 1-loop)
    string s = "MLLLLLLWWVVVVVBBBVVVYYYVVVVV"; // output is 20
    int k = 7;
    cout << "Maximum length string after replcement is: " << longestSubStrCharReplace(s, k) << endl;




    return 0;
}

