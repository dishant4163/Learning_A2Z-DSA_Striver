// 1D-DP: Frog Jump With K Distances (follow up of Frog Jump)


/*// Problem-Link-> https://www.naukri.com/code360/problems/minimal-cost_8180930  


int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int miniSteps = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                miniSteps = min(miniSteps, jump);
            }
        }
        dp[i] = miniSteps;
    }
    return dp[n-1];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, vector<int>& height, int k, vector<int>& dp) {
    //base case
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int miniSteps = INT_MAX;

    for(int j = 1; j <= k; j++) {
        if(ind - j >= 0) {
            int jump = memoHelp(ind - j, height, k, dp) + abs(height[ind] - height[ind - j]);
            miniSteps = min(jump, miniSteps);
        }
    }

    return dp[ind] = miniSteps;
}

int frogjump2(int n, int k, vector<int> &height){
    // initialize memoization array 
    vector<int> dp(n, -1); // 0-based indexing

    return memoHelp(n-1, height, k, dp); // Start the recursion from the last index
}








//Soln-2 TABULATION Approach

/*// Hiding the recursive implementation of Tabulation
// int tabHelp(int n, int k, vector<int> &height, vector<int> &dp) {
//     dp[0] = 0;

//     for(int i = 1; i < n; i++) {
//         int miniSteps = INT_MAX;

//         for(int j = 1; j <= k; j++) {
//             if(i - j >= 0) {
//                 int jump = dp[i - j] + abs(height[i] - height[i - j]);
//                 miniSteps = min(miniSteps, jump);
//             }
//         }
//         dp[i] = miniSteps;
//     }

//     return dp[n - 1]; // The result is stored in the last element of dp
// }

*/

int frogJump2(int n, int k, vector<int> &height) {
    vector<int> dp(n, -1);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int miniSteps = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                miniSteps = min(jump, miniSteps);
            }
        }
        dp[i] = miniSteps;
    }
    return dp[n- 1];
}







int main() {

    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1); // Initialize a memoization array for the main function

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach & output is: " << frogjump2(n, k, height) << endl << endl; 


//Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach & output is: " << frogJump2(n, k, height) << endl << endl;



    return 0;
}
