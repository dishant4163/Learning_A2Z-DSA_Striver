// 1D-DP : Climbing Stairs


/*// Problem-Link-> https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650


#include <bits/stdc++.h>

// Solved using Sapce OPtimized DP
// TC:- O(N),  SC:- O(1)
int countDistinctWays(int nStairs) {
    //  Write your code here.
    int mod = 1e9 + 7;
    int prev2 = 1;
    int prev1 = 1;

    for(int i = 2; i <= nStairs; i++) {
        int curri = (prev1 + prev2) % mod;
        prev2 = prev1;
        prev1 = curri;
    }

    return prev1;
}





// Solve using TABULATION
// TC:- O(N),   SC:- O(N)
// int countDistinctWays(int nStairs) {
//     //  Write your code here.
//     int mod = 1e9 + 7;

//     vector<int> dp(nStairs + 1, -1);

//     dp[0] = 1;
//     dp[1] = 1;

//     for(int i=2; i <= nStairs; i++) {
//       dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
//     }

//     return dp[nStairs];
// }


*/



#include<bits/stdc++.h>
using namespace std;



// Solve using TABULATION
// TC:- O(N),   SC:- O(N)
int countDistinctWays(int nStairs) {
    //  Write your code here.
    // int mod = 1e9 + 7;

    vector<int> dp(nStairs + 1, -1);

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i <= nStairs; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]);
    }

    return dp[nStairs]; // do mod for larger cases
}



// Solved using Sapce OPtimized DP
// TC:- O(N),  SC:- O(1)

int countWays(int n) {
    int prev2 = 1; // 1 bcz from 0th stair can jump 1
    int prev1 = 1; // same from 1th stair can jump 1

    for(int i = 2; i <= n; i++) {
        int curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }

    return prev1;
}




int main() {

// Solve using Space OPtimization
    int n = 3;
    cout <<  "The output is: " << countWays(n);

cout << endl << endl;

// Solve using TABULATION
    cout <<  "The output is: " << countDistinctWays(n);


    return 0;
}
