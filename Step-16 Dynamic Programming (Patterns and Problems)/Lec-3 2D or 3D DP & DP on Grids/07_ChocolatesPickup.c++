// Chocolates Pickup (gfg) | Cherry Pickup-ii (LeetCode)


/*//Problem-Link-> https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885   

#include <bits/stdc++.h> 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> front(c, vector<int>(c, 0));
    vector<vector<int>> cur(c, vector<int>(c, 0));

    for(int j1=0; j1 < c; j1++) {
        for(int j2=0; j2 < c; j2++) {
            if(j1 == j2) front[j1][j2] = grid[r - 1][j1];
            else front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for(int i = r-2; i >= 0; i--) {
        for(int j1 = 0; j1 < c; j1++) {
            for(int j2 = 0; j2 < c; j2++) {
                int maxi = -1e9;

                for(int dj1 = -1; dj1 <= 1; dj1++) {
                    for(int dj2 = -1; dj2 <= 1; dj2++) {
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1+dj1 >= 0 && j1+dj1 < c && j2+dj2 >= 0 && j2+dj2 < c) {
                            value += front[j1 + dj1][j2 + dj2];
                        }
                        else value += -1e9;

                        maxi = max(value, maxi);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    return front[0][c - 1];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int maxChocoMemoHelp(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    //Base Case-1 (Out of Bounds)
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e9;
    //Base Case-2 (reached destination)
    if(i == r-1) {
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxi = -1e9;

    for(int dj1 = -1; dj1 <= +1; dj1++) {
        for(int dj2 = -1; dj2 <= +1; dj2++) {
            int value = 0;
            if(j1 == j2) value = grid[i][j1] + maxChocoMemoHelp(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
            else value = grid[i][j1] + grid[i][j2] + maxChocoMemoHelp(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int getmaximumchocolates(int n, int m, vector<vector<int>> &grid) {
    //Declaring 3D DP array dp[r][c][c]
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoMemoHelp(0, 0, m-1, n, m, grid, dp);
}




// Soln-2 TABULATION Approach
int getmaximumChocolates(int n, int m, vector<vector<int>> &grid) {
    //Declaring 3D DP array dp[r][c][c]
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int>(m, 0)));

    //Base Case (reached the destination i.e, the last row / (n-1)th row)
    for(int j1=0; j1 < m; j1++) {
        for(int j2=0; j2 < m; j2++) {
            if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
            else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                int maxi = -1e9;

                // Inner nested loops to try out 9 options (diagonal moves)
                for(int dj1 = -1; dj1 <= +1; dj1++) {
                    for(int dj2 = -1; dj2 <= +1; dj2++) {
                        int value = 0;

                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) {
                            value += dp[i+1][j1+dj1][j2+dj2];
                        }
                        else value += -1e9;

                        maxi = max(value, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}







// Soln-3 SPACE OPTIMIZATION Approach
int getMaximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    //Base Case (reached the destination i.e, the last row / (n-1)th row)
    for(int j1 = 0; j1 < m; j1++) {
        for(int j2 = 0; j2 < m; j2++) {
            if(j1 == j2) front[j1][j2] = grid[n-1][j1];
            else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                int maxi = -1e9;

                for(int dj1 = -1; dj1 <= +1; dj1++) {
                    for(int dj2 = -1; dj2 <= +1; dj2++) {
                        int value = 0;

                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];

                        if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m){
                            value += front[j1+dj1][j2+dj2];
                        }
                        else value += -1e9;

                        maxi = max(value, maxi);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][m-1];
}






int main() {

    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Maximum number of chocolates: " << getmaximumchocolates(n, m, matrix) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Maximum number of chocolates: " << getmaximumChocolates(n, m, matrix) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Maximum number of chocolates: " << getMaximumChocolates(n, m, matrix) << endl << endl;




    return 0;
}

