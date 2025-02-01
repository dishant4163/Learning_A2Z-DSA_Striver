// Introduction to Dynamic Programming



#include<bits/stdc++.h>
using namespace std;


// Part-1:  MEMOIZATION
// TC:- O(N),   SC:- O(2N)
int fib(int n, vector<int> &dp) {
    //base case
    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}





int main() {


// Part-1:  MEMOIZATION
// TC:- O(N),   SC:- O(2N)
    int n = 9;

    vector<int> dp(n+1, -1);
    cout << "Answer solve using 'MEMOIZATION' is: " << fib(n, dp);




cout << endl << endl;




// Part-2:  TABULATION
// TC:- O(N),   SC:- O(N)
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Answer solve using 'TABULATION' is: " << dp[n];



cout << endl << endl;


// Part-3:  Space Optimization
// TC:- O(N),  SC:- O(1)
    int prev2 = 0;
    int prev = 1;

    for(int i = 2; i <= n; i++) {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    cout << "Answer solve using Space Optimizarion in TABULATION Code is: " << prev;





    return 0;
}

