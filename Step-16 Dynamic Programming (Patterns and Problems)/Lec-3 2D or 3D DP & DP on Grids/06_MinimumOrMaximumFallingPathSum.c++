// Minimum/Maximum Falling Path Sum

//Maximum Falling Path Sum
/*// Problem Link-> https://www.naukri.com/code360/problems/maximum-path-sum-in-the-matrix_797998


int getMaxPathSum(vector<vector<int>> &matrix){
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();

    vector<int> prev(m, 0), cur(m, 0);

    for(int j=0; j < m; j++) prev[j] = matrix[0][j];

    for(int i = 1; i < n; i++) {
        for(int j=0; j < m; j++) {
            int up = matrix[i][j] + prev[j];

            int ld = matrix[i][j];
            if(j-1 >= 0) ld += prev[j-1];
            else ld += -1e8;

            int rd = matrix[i][j];
            if(j+1 < m) rd += prev[j+1];
            else rd += -1e8;

            cur[j] = max({up, ld, rd});
        }
        prev = cur;
    }

    int maxi = -1e8;
    for(int j=0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}

*/


// Minimum Falling Path Sum
/*// Problem-Link-> https://www.naukri.com/code360/problems/minimum-falling-path-sum_893012


int minFallingPathSum(vector<vector<int>> &matrix, int n) {
    // Write your code here.
    vector<int> prev(n, 0), cur(n, 0);

    for(int j = 0; j < n; j++) prev[j] = matrix[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0) leftDiagonal += prev[j-1];
            else leftDiagonal += 1e9;

            int rightDiagonal = matrix[i][j];
            if(j+1 < n) rightDiagonal += prev[j+1];
            else rightDiagonal += 1e9;

            cur[j] = min(up, min(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }

    int mini = 1e9;
    for(int j = 0; j < n; j++) {
        mini = min(mini, prev[j]);
    }

    return mini;
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if(j < 0 || j >= mat[0].size()) return -1e8;
    if(i == 0) return mat[0][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = mat[i][j] + memoHelp(i-1, j, mat, dp);
    int leftDiagonal = mat[i][j] + memoHelp(i-1, j-1, mat, dp);
    int rightDiagonal = mat[i][j] + memoHelp(i-1, j+1, mat, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getmaxpathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = -1e8;
    for(int j = 0; j < m; j++) {
        maxi = max(maxi, memoHelp(n-1, j, matrix, dp));
    }

    return maxi;
}







// Soln-2 TABULATION Approach
int getmaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base Case
    for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i-1][j];

            // Left diagonal direction (if it's a valid move)
            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += -1e8;

            // Right diagonal direction (if it's a valid move)
            int rightDiadonal = matrix[i][j];
            if(j+1 < m) rightDiadonal += dp[i-1][j+1];
            else rightDiadonal += -1e8;

            dp[i][j] = max(up, max(leftDiagonal, rightDiadonal));
        }
    }

    int maxi = -1e8;
    for(int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n-1][j]);
    }

    return maxi;
}







// Soln-3 SPACE OPTIMIZATION Approach
int getMaxPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();

    vector<int> prev(m, 0), cur(m, 0);

    for(int j = 0; j < m; j++) prev[j] = matrix[0][j];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];

            int leftDiagonal = matrix[i][j];
            if(j-1 >= 0) leftDiagonal += prev[j-1];
            else leftDiagonal += -1e8;

            int rightDiagonal = matrix[i][j];
            if(j+1 < m) rightDiagonal += prev[j+1];
            else rightDiagonal += -1e8;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal));
        }
        prev = cur;
    }

    int maxi = -1e8;
    for(int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]);
    }

    return maxi;
}






int main() {

    // Define the matrix as a 2D vector
    vector<vector<int>> matrix{{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Minimum path sum: " << getmaxpathSum(matrix) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Minimum path sum: " << getmaxPathSum(matrix) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Minimum path sum: " << getMaxPathSum(matrix) << endl << endl;




    return 0;
}
