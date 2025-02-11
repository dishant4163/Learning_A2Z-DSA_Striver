// Subset Sum equal to Target | DP on Subsequences


/*// Problem-Link-> https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954 


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1, false), cur(k+1, false);
    //Base Case-1
    prev[0] = cur[0] = true;
    //Base Case-2
    if(arr[0] <= k) prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target - arr[ind]];

            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}

*/


// Subset Sum_Link-> https://www.naukri.com/code360/problems/subset-sum_630213  






#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
bool memoHelp(int index, int target, vector<int>& arr, vector<vector<int>> &dp) {
    //Base Case-1
    if(target == 0) return true;
    //Base Case-2
    if(index == 0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    bool notTake = memoHelp(index-1, target, arr, dp);
    bool take = false;
    if(arr[index] <= target) take = memoHelp(index-1, target - arr[index], arr, dp);

    return dp[index][target] = take || notTake;
}

bool subsetsumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return memoHelp(n-1, k, arr, dp);
}





// Soln-2 TABULATION Approach
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));

    //Base Case-1: If the target sum is 0, we can always achieve it by taking no elements
    for(int i=0; i < n; i++) dp[i][0] = true;

    //Base case-2: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];

            //Store the result in DP array for the current subproblem
            dp[ind][target] = take || notTake;
        }
    }

    return dp[n-1][k];
}




// Soln-3 SPACE OPTIMIZATION Approach
bool subSetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    vector<bool> cur(k+1, false);
    //Base Case-1: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = cur[0] = true;

    //Base Case-2: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if(arr[0] <= k) prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target - arr[ind]];

            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}







int main() {

    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    if (subsetsumToK(n, k, arr)) cout << "Subset with the given target found";
    else cout << "Subset with the given target not found";
cout << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    if (subsetSumToK(n, k, arr)) cout << "Subset with the given target found";
    else cout << "Subset with the given target not found";
cout << endl << endl;


// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    if (subSetSumToK(n, k, arr)) cout << "Subset with the given target found";
    else cout << "Subset with the given target not found";
cout << endl << endl;



    return 0;
}
