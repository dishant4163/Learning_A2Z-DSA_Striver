// Fruits into Basket

/* Fruits and Baskets -> ( https://shorturl.at/2MmY4 )

int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int lptr = 0, rptr = 0, maxlen = 0;
    unordered_map<int, int> mp;

    while(rptr < n) {
        mp[arr[rptr]]++;

        if(mp.size() > 2){
            mp[arr[lptr]]--;

            if(mp[arr[lptr]] == 0) {
                mp.erase(arr[lptr]);
            }

            lptr++;
        }

        if(mp.size() <= 2) {
            maxlen = max(maxlen, (rptr - lptr + 1));
        }

        rptr++;
    }

    return maxlen;
}

*/



#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force (using 2 for loops & set)
// TC:- O(N x N)    SC:- O(3) -> bcz, in set storing 3 element to check and not more than that
int maxfruitsBaskets(vector<int>& nums) {
    int s = nums.size(), maxans = 0;

    for(int i=0; i < s; i++) {
        unordered_set<int> st;
        for(int j = i; j < s; j++) {
            st.insert(nums[j]);

            if (st.size() <= 2) {
                maxans = max(maxans, (j-i+1));
            }
            else break; // is set size is >= 2
        }
    }

    return maxans;
}
*/




/*//SOln-2.1 OPtimal (using Sliding-window & 2-ptr. 2 while loops)
// TC:- O(2N), SC:- O(3) -> bcz, in map storing 3 elements & whenever it increase same time erasing too extra ele
int maxFruitsBaskets(vector<int>& arr) {
    int m = arr.size(), Lptr = 0, Rptr = 0, maxLen = 0;
    unordered_map<int, int>mpp;

    while(Rptr < m) {
        mpp[arr[Rptr]]++;

        if(mpp.size() > 2) {
            while(mpp.size() > 2) { 
                mpp[arr[Lptr]]--;

                if(mpp[arr[Lptr]] == 0) {
                    mpp.erase(arr[Lptr]);
                }
                Lptr++;
            }
        }

        if(mpp.size() <= 2) {
            maxLen = max(maxLen, (Rptr - Lptr + 1));
        }

        Rptr++;
    }

    return maxLen;
}
*/




//Soln-2.2 MostOPtimal (using Sliding-window & 2-ptr. 1 while loop)
int findMaxFruitsBaskets(vector<int>& ar){
    int n = ar.size(), lpt = 0, rpt = 0, maxlen = 0;
    unordered_map<int, int> mp;

    while(rpt < n) {
        mp[ar[rpt]]++;

        if(mp.size() > 2) {
            mp[ar[lpt]]--;

            if(mp[ar[lpt]] == 0) {
                mp.erase(ar[lpt]);
            }
            lpt++;
        }

        if(mp.size() <= 2) {
            maxlen = max(maxlen, (rpt - lpt + 1));
        }

        rpt++;
    }

    return maxlen;
}




int main() {

/*//Soln-1 Brute Force
    vector<int> fruitsArr = {1, 1, 2, 3, 4}; 
    cout << "Maximum fruits in baskets is: " << maxfruitsBaskets(fruitsArr) << endl;
    // output is  3
*/


/*//Soln-2.1 OPtimal (using Sliding-window & 2-ptr. via 2 while loops)
    vector<int> Fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Maximum fruits in baskets with at most 2 distinct type fruit: " << maxFruitsBaskets(Fruits) << endl; // output is 5
*/


//Soln-2.2 OPtimal (using Sliding-window & 2-ptr. via 1 while loops)
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Maximum fruits in baskets with at most 2 distinct type fruit: " << findMaxFruitsBaskets(fruits) << endl; // output is 5



    return 0;
}

