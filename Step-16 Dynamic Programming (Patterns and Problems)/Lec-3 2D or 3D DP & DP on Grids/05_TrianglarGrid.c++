// DP on grid : Minimum path sum in Triangular Grid



/*// Problem-Link-> https://www.naukri.com/code360/problems/triangle_1229398 

#include <bits/stdc++.h> 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int> front(n, 0);
	vector<int> cur(n, 0);

	for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];

	for(int i = n - 2; i >= 0; i--) {
		for(int j=i; j >= 0; j--) {
			int down = triangle[i][j] + front[j];
			int diagonal = triangle[i][j] + front[j+1];
			cur[j] = min(down, diagonal);
		}
		front = cur;
	}
	return front[0];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp) {
    //Base Case
    if(i == n-1) return triangle[n-1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + memoHelp(i+1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + memoHelp(i+1, j+1, triangle, n, dp);

    return dp[i][j] = min(down, diagonal);
}

int minimumpathsum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return memoHelp(0, 0, triangle, n, dp); // (0,0) is the fixed starting point
}





// Soln-2 TABULATION Approach
int minimumpathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for(int j=0; j < n; j++) dp[n-1][j] = triangle[n-1][j];

    // Iterate through the triangle rows in reverse order
    for(int i = n - 2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}





// Soln-3 SPACE OPTIMIZATION Approach
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row

    for(int j = 0; j < n; j++) front[j] = triangle[n-1][j];

    for(int i = n-2; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];
            cur[j] = min(down, diagonal);
        }
        front = cur;
    }

    return front[0];
}






int main() {

    // Define the triangle as a 2D vector
    vector<vector<int>> triangle{ {1},
                                  {2, 3},
                                  {3, 6, 7},
                                  {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Minimum path sum: " << minimumpathsum(triangle, n) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Minimum path sum: " << minimumpathSum(triangle, n) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Minimum path sum: " << minimumPathSum(triangle, n) << endl << endl;





    return 0;
}
