// Subarray with K Different integers


/* Subarrays With ‘K’ Distinct Values  -> ( https://shorturl.at/H39So )

//Function for findind No. of SubArrays where Diff. values <= K
int findNumOfSubArforDistinctValue(vector<int>& arr, int n, int k) {
    int l=0, r=0, cnt=0;
    unordered_map<int, int> mp;

    while(r < n) {
        mp[arr[r]]++;

        while(mp.size() > k) {
            mp[arr[l]]--;

            if(mp[arr[l]] == 0) mp.erase(arr[l]);
            l++;
        }

        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
}


int kDistinctSubarrays(vector<int> &arr, int n, int k) {
    // Write your code here
    return findNumOfSubArforDistinctValue(arr, n, k) - findNumOfSubArforDistinctValue(arr, n, k-1);
}


*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(N x N),   SC:- O(N)
int subArrKDistinctInt(vector<int>& arr, int x) {
    int s = arr.size(), Cnt = 0;

    for(int i=0; i < s; i++) {
        unordered_map<int, int> mpp; // O(N)
        for(int j=i; j < s; j++) {
            mpp[arr[j]]++;

            if(mpp.size() == x) Cnt++;
            else if (mpp.size() > x) break;
        }
    }
    return Cnt;
}
*/




//Soln-2 Optimal 
//TC:- O(N + N) assuming Map works in constant time,   SC:- O(N) -> using map

//Function for findind No. of SubArrays where Diff. Integers <= K
int numOfSubArforDistinctValues(vector<int>& nums, int k) {
    int n=nums.size(), l=0, r=0, cnt=0;
    unordered_map<int, int> mp;

    while(r < n) {
        mp[nums[r]]++;

        while(mp.size() > k) {
            mp[nums[l]]--;

            if(mp[nums[l]] == 0) {
                mp.erase(nums[l]);
            }

            l++;
        }

        cnt = cnt + (r-l+1);
        r++;
    }
    return cnt;
}

// main function 
int subArKDistinctInt(vector<int>& ar, int k) {
    return numOfSubArforDistinctValues(ar, k) - numOfSubArforDistinctValues(ar, k-1);
}





int main() {

/*//Soln-1 Brute Force
    vector<int> arr = {1, 2, 1, 3, 4};
    int x = 3;
    cout << "Number of Subarrays with k distinct Integers is: " <<subArrKDistinctInt(arr, x) << endl;
*/


//Soln-2 OPtimal Soln
    vector<int> ar = {1, 2, 1, 3, 4};
    int k = 3;
    cout << "Number of Subarrays with k distinct Integers is: " << subArKDistinctInt(ar, k) << endl;




    return 0;
}
