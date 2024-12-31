// Max Consecutive Ones-iii
//  Problem statement
// Given a binary array 'ARR' of size 'N', your task is to find the longest sequence of continuous 1’s that can 
// be formed by replacing at-most 'K' zeroes by ones. Return the length of this longest sequence of continuous 1’s.



/* Max Consecutive Ones-iii -> ( https://shorturl.at/P3ohb )

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int l=0, r=0, maxlen = 0, cntZeros = 0;

    while(r < n) {
        if(arr[r] == 0) cntZeros++;

        if(cntZeros > k) {
            if(arr[l] == 0) {
                cntZeros--;
            }
            l++;
        }

        if(cntZeros <= k) {
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
int maxConsecOnesiii(vector<int>& arr, int x) {
    int s = arr.size(), maxans = 0;

    for(int i=0; i < s; i++) {
        int cntZero = 0;
        for(int j=i; j < s; j++) {
            if (arr[j] == 0) cntZero++;
            if (cntZero <= x) {
                maxans = max(maxans, (j-i+1));
            }
            else break;
        }
    }

    return maxans;
}
*/




/*//Soln-2.1 OPtimal (using SLding Window & 2-Ptr via 2 while loops)
// TC:- O(2N), SC:- O(N)
int maxconsecutiveOnesiii(vector<int>& nums, int K) {
    int Lpt = 0, Rpt = 0, maxLen = 0, zeros = 0;

    while(Rpt < nums.size()) {
        // Expand the window by moving 'right'
        if (nums[Rpt] == 0) zeros++;

        //Shrink the window from the left if zeroCount exceeds K
        while(zeros > K) {
            if (nums[Lpt] == 0) {
                zeros--;
            }
            Lpt++;
        }

        //Update the maxLength with the size of the valid window
        if (zeros <= K) {
            maxLen = max(maxLen, (Rpt - Lpt + 1));
        }

        // Move RightPtr one place ahead
        Rpt++;
    }

    return maxLen;
}
*/




//Soln-2.2 OPtimal (using SLding Window & 2-Ptr via 2 while loops)
int maxConsecutiveOnesiii(vector<int>& ar, int k) {
    int l=0, r=0, maxlen = 0, cntzeros = 0;

    while(r < ar.size()) {
        if(ar[r] == 0) cntzeros++;

        if(cntzeros > k) {
            if(ar[l] == 0) {
                cntzeros--;
            }
            l++;
        }

        if(cntzeros <= k) {
            maxlen = max(maxlen, (r-l+1));
        }

        r++;
    }

    return maxlen;
}





int main() {

/*//Soln-1 Brute Force
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int x = 2;
    cout << "Maximum sequence of continuous 1's " << maxConsecOnesiii(arr, x) << endl;
*/


/*//Soln-2.1 OPtimal (using SLding Window & 2-Ptr, via 2 while loops)
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int K = 2;
    cout << "Maximum sequence of continuous 1's : " << maxconsecutiveOnesiii(nums, K) << endl;
*/


//Soln-2.2 OPtimal (using SLding Window & 2-Ptr, via 1 while loop)
    vector<int> ar = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout << "Maximum sequence of continuous 1's : " << maxConsecutiveOnesiii(ar, k) << endl;




    return 0;
}

