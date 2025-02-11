// Grid Unique Paths : DP on Grids


/* //Problem-Link->  https://www.naukri.com/code360/problems/unique-paths_1081470

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> prev(n, 0);

	for(int i=0; i < m; i++) {
		vector<int> temp(n, 0);
		for(int j=0; j < n; j++) {
			if(i == 0 && j == 0) {
				temp[j] = 1;
				continue;
			}

			int up = 0, left = 0;
			if(i > 0) up = prev[j];
			if(j > 0) left = temp[j - 1];

			temp[j] = up + left;
		}
		prev = temp;
	}
	return prev[n-1];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelpCountWays(int i, int j, vector<vector<int>>& dp) {
    //Base Case-1
    if(i < 0 || j < 0) return 0;
    //Base Case-2
    if(i == 0 && j == 0) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int up = memoHelpCountWays(i-1, j, dp);
    int left = memoHelpCountWays(i, j-1, dp);

    return dp[i][j] = up + left;
}

int uniquepaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoHelpCountWays(m - 1, n - 1, dp);
}







// Soln-2 TABULATION Approach

/* int tabHelpCountWays(int m, int n, vector<vector<int>> &dp) {

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            //Base case
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;// Skip the rest of the loop and continue with the next iteration
            }

            int up = 0, left = 0;

            if(i > 0) up = dp[i - 1][j];
            if(j > 0) left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[m-1][n-1];
}
*/

int uniquepathS(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if(i > 0) up = dp[i-1][j];
            if(j > 0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[m-1][n-1];

    //return tabHelpCountWays(m, n, dp);
}








// Soln-3 SPACE OPTIMIZATION Approach
int uniquePaths(int m, int n) {
	vector<int> prev(n, 0);

    for(int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        for(int j = 0; j < n; j++) {
            //base case
            if(i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if(i > 0) up = prev[j];
            if(j > 0) left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n-1];
}




int main() {

int m = 3;
    int n = 2;

// Soln-1 MEMORIZATION Approach
    // Call the uniquePaths function and print the result.
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << uniquepaths(m, n) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << uniquepathS(m, n) << endl << endl;



// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << uniquePaths(m, n) << endl << endl;


    return 0;
}
