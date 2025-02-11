// 1D-DP: Frog Jump


/*// Problem-Link-> https://www.naukri.com/code360/problems/frog-jump_3621012

//solve using SPACE OPTIMIZATION
int frogJump(int n, vector<int> &heights) {
    // Write your code here.
    int prev2 = 0, prev1 = 0;

    for(int i=1; i < n; i++) {
        int jump1 = prev1 + abs(heights[i] - heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1) jump2 = prev2 + abs(heights[i] - heights[i-2]);

        int curi = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curi;
    }
    return prev1;
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int solve(int ind,vector<int> &heights,  vector<int> &dp) {
    //Base Case
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int jump1 = solve(ind-1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int jump2 = INT_MAX;
    if(ind > 1) {
        jump2 = solve(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);
    }

    return dp[ind] = min(jump1, jump2);
}

// Main function
int frogjump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);

    return solve(n-1, heights, dp);
}






//Soln-2 TABULATION Approach
int frogJump(int n, vector<int>& heights) {
    vector<int> dp(n, -1); // 0-based indexing
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int jump1 = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int jump2 = INT_MAX;
        if(i > 1) {
            jump2 = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(jump1, jump2);
    }

    return dp[n - 1]; // ans stored at last index
}








//Soln-3 SPACE OPTIMIZATION Approach
int frogJUMP(int n, vector<int> &heights) {
    int prev2 = 0, prev1 = 0;

    for(int i = 1; i < n; i++) {
        int jump1 = prev1 + abs(heights[i] - heights[i-1]);
        int jump2 = INT_MAX;
        if(i > 1) jump2 = prev2 + abs(heights[i] - heights[i - 2]);

        int curi = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curi;
    }

    return prev1;
}








int main() {

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n=height.size();


    vector<int> dp(n, -1);
    cout << "Solve using MEMORIZATION Approach & output is: " << frogjump(n, height) << endl << endl;

    cout << "Solve using TABULATION Approach & output is: " << frogJump(n, height) << endl << endl;

    cout << "Solve using SPACE OPTIMIZATION Approach & output is: " << frogJUMP(n, height) << endl << endl;




    return 0;
}
