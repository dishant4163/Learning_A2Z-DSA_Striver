// 1-D | DP on Subsequences | Maximum Sum of Non-Adjacent Elements


/*//Problem-Link-> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261 


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];

    for(int i = 1; i < n; i++) {
        int pick = nums[i];
        if(i > 1) pick += prev2;

        int notPick = 0 + prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

*/



#include<bits/stdc++.h>
using namespace std;

// Soln-1 MEMORIZATION Approach
int helpMemo(int ind, vector<int> &arr, vector<int> &dp) {
    if(ind == 0) return arr[ind];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick = arr[ind] + helpMemo(ind - 2, arr, dp);
    int notPick = 0 + helpMemo(ind - 1, arr, dp);

    return max(pick, notPick);
}

int maxNonAdjacentSum(int n, vector<int> &arr) {
    vector<int> dp(n, -1);
    return helpMemo(n-1, arr, dp);
}







//Soln-2 TABULATION Approach
int helpTab(int n, vector<int>& arr, vector<int>& dp) {
    //Edge Case
    dp[0] = arr[0];

    for(int i = 1; i < n; i++) {
        int pick = arr[i];
        //edge case for -ve indexes
        if(i > 1) pick += dp[i - 2];

        int notPick = 0 + dp[i - 1];

        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

int maxiNonAdjacentSum(int n, vector<int>& arr) {
    vector<int> dp(n, -1);

    return helpTab(n, arr, dp);
}







//Soln-3 SPACE OPTIMIZATION Approach
int maximumNonAdjacentSum(int n, vector<int>& arr) {
    int prev2 = 0;
    int prev = arr[0];

    for(int i=1; i < n; i++) {
        int pick = arr[i];
        // edge case for -ve indexes
        if(i > 1) pick += prev2;
        int notPick = 0 + prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}






int main() {

    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach & output is: " << maxNonAdjacentSum(n, arr) << endl << endl; 


//Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach & output is: " << maxiNonAdjacentSum(n, arr) << endl << endl;


//Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach & output is: " << maximumNonAdjacentSum(n, arr) << endl << endl;




    return 0;
}
