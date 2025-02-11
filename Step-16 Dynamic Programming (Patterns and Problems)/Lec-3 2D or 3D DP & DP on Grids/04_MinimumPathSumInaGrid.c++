// DP on Grid: Minimum Path Sum In a Grid


/*//Problem-Link->  https://www.naukri.com/code360/problems/minimum-path-sum_985349

#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, 0);

    for(int i=0; i < m; i++) {
        vector<int> cur(n, 0);
        for(int j=0; j < n; j++) {
            if(i==0 && j==0) cur[j] = grid[i][j];
            else {
                int up = grid[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;

                int left = grid[i][j];
                if(j > 0) left += cur[j-1];
                else left += 1e9;

                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[n-1];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    //Base case-1
    if(i == 0 && j == 0) return matrix[i][j];
    //Base case-2
    if(i < 0 || j < 0) return 1e9; //or return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + memoHelp(i-1, j, matrix, dp);
    int left = matrix[i][j] + memoHelp(i, j-1, matrix, dp);

    return dp[i][j] = min(up, left);
}

int minsumpath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memoHelp(n-1, m-1, matrix, dp);
}





// Soln-2 TABULATION Approach
int minsumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            //Base Case
            if(i == 0 && j == 0) dp[i][j] = matrix[i][j];

            else {
                int up = matrix[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;

                int left = matrix[i][j];
                if(j > 0) left += dp[i][j-1];
                else left += 1e9;

                dp[i][j] = min(up, left);
            }

        }
    }

    return dp[n-1][m-1];
}





// Soln-3 SPACE OPTIMIZATION Approach
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0);

    for(int i=0; i < n; i++) {
        vector<int> cur(m, 0);
        for(int j=0; j < m; j++) {
            if(i==0 && j==0) cur[j] = matrix[i][j];
            else {
                int up = matrix[i][j];
                if(i > 0) up += prev[j];
                else up += 1e9;

                int left = matrix[i][j];
                if(j > 0) left += cur[j-1];
                else left += 1e9;

                cur[j] = min(up, left);
            }
        }
        prev = cur;
    }
    return prev[m-1];
}





int main() {

    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Minimum sum path: " << minsumpath(n, m, matrix) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Minimum sum path: " << minsumPath(n, m, matrix) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl << endl;


    return 0;
}
