// 1-D | DP on Subsequences | House Robber-1


/*//Problem-Link-> https://www.naukri.com/code360/problems/house-robber_6211018

int houseRobber(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    int prev2 = 0;
    int prev = a[0];

    for(int i = 1; i < n; i++) {
        int pick = a[i];
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

int houserobber(int n, vector<int> &arr) {
    vector<int> dp(n, -1);
    return helpMemo(n-1, arr, dp);
}







//Soln-2 TABULATION Approach
int houseRobber(int n, vector<int>& arr) {
    vector<int> dp(n, -1);
    //Edge Case
    dp[0] = arr[0];

    for(int i = 1; i < n; i++) {
        int take = arr[i];
        if(i > 1) take += dp[i - 2];

        int notTake = 0 + dp[i - 1];

        dp[i] = max(take, notTake);
    }

    return dp[n-1];
}







//Soln-3 SPACE OPTIMIZATION Approach
int houseROBBER(int n, vector<int>& arr) {
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

    vector<int> arr{4, 1, 6, 10};
    int n = arr.size();

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach & output is: " << houserobber(n, arr) << endl << endl; 


//Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach & output is: " << houseRobber(n, arr) << endl << endl;


//Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach & output is: " << houseROBBER(n, arr) << endl << endl;




    return 0;
}
