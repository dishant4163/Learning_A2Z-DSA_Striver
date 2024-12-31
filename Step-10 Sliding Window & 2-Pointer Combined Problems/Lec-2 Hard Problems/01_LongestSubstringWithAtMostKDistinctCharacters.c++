// Longest Substring With At Most K Distinct Characters



/* Longest Substring With At Most K Distinct Characters -> ( https://shorturl.at/EMiQL )

#include<bits/stdc++.h>

int kDistinctChars(int k, string &str) {
    // Write your code here
    int l = 0, r = 0, maxlen = 0, n = str.size();
    unordered_map<char, int> mp;

    while(r < n){
        mp[str[r]]++;

        if(mp.size() > k) {
            mp[str[l]]--;

            if(mp[str[l]] == 0) {
                mp.erase(str[l]);
            }
            
            l++;
        }

        if(mp.size() <= k) {
            maxlen = max(maxlen, (r-l+1));
        }

        r++;
    }

    return maxlen;
}


*/



#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(N^2), SC:- O(256) in map for storing chars
int kdistinctchar(string& str, int x) {
    int s = str.length(), maxans = 0;
    unordered_map<char, int> mpp; // char, freq

    // Edge case: empty string
    if (s == 0) return 0;

    for(int i=0; i < s; i++) {
        mpp.clear(); //clear bzc for starting new set of substring
        for(int j=i; j < s; j++) {
            mpp[str[j]]++;

            if(mpp.size() <= x) {
                maxans = max(maxans, (j-i+1));
            }
            else break; //No need to check further if more than 'x' distinct chars
        }
    }
    return maxans;
}
*/




/*//Soln-2.1 OPtimal (using Sliding-window & 2-ptr. via 2 while loops)
// TC:- O(2N),   SC:- O(N)
int kdistinctChars(string& S, int K) {
    int size = S.size(), maxLen = 0, Lpt = 0, Rpt =0;
    unordered_map<char, int> Mp; // char, freq

    while(Rpt < size) {
        Mp[S[Rpt]]++;

        while(Mp.size() > K) {
            Mp[S[Lpt]]--;

            if(Mp[S[Lpt]] == 0) {
                Mp.erase(S[Lpt]);
            }
            Lpt++;
        }

        if(Mp.size() <= K) {
            maxLen = max(maxLen, (Rpt - Lpt + 1));
        }

        Rpt++;
    }

    return maxLen;
}
*/




//Soln-2.2 Most OPtimal (using Sliding-window & 2-ptr. via 1 while loops)
int kDistinctChars(string& s, int k) {
    int n = s.size(), maxlen = 0, Lptr = 0, Rptr =0;
    unordered_map<char, int> mp; // char, freq

    while(Rptr < n) {
        mp[s[Rptr]]++;

        while(mp.size() > k) {
            mp[s[Lptr]]--;

            if(mp[s[Lptr]] == 0) {
                mp.erase(s[Lptr]);
            }
            Lptr++;
        }

        if(mp.size() <= k) {
            maxlen = max(maxlen, (Rptr - Lptr + 1));
        }

        Rptr++;
    }

    return maxlen;
}




int main() {

/*//Soln-1 Brute Force
    string str = "aaabbccd";
    int x = 2;
    cout << "Longest Substring with at most " << x << " distinct characters is: " << kdistinctchar(str, x) << endl;
*/


/*//Soln-2.1 OPtimal (using Sliding-window & 2-ptr. via 2 while loops)
    string S = "aaabbccd";
    int K = 2;
    cout << "Longest Substring with at most " << K << " distinct characters is: " << kdistinctChars(S, K) << endl;
*/


//Soln-2.2 Most OPtimal (using Sliding-window & 2-ptr. via 1 while loops)
    string s = "aaabbccd";
    int k = 2;
    cout << "Longest Substring with at most " << k << " distinct characters is: " << kDistinctChars(s, k) << endl;





    return 0;
}

