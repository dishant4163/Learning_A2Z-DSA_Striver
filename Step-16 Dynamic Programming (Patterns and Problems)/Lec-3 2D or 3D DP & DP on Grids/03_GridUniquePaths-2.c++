// DP on Grid: Grid Unique Paths-2 or Maze Obstacles



/*// Problem-Link-> https://www.naukri.com/code360/problems/unique-paths-ii_977241

//declare golbally
int mod = 1e9 + 7; // long answer do 'mod'

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int> prev(m, 0);
    for(int i=0; i < n; i++) {
        vector<int> temp(m, 0);
        for(int j=0; j < m; j++) {
            if(mat[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
            
            else if(i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }
            else {
                int up = 0, left = 0;
                if(i > 0) up = prev[j];
                if(j > 0) left = temp[j - 1];

                temp[j] = (up + left) % mod;
            }
        }
        prev = temp;
    }
    return prev[m-1];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    //Base Cases
    if(i > 0 && j > 0 && maze[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int up = memoHelp(i-1, j, maze, dp);
    int left = memoHelp(i, j-1, maze, dp);

    return dp[i][j] = up + left;
}

int mazeobstacles(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return memoHelp(n-1, m-1, maze, dp);
}






// Soln-2 TABULATION Approach
int mazeObstacleS(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            //Base Case-1
            if(i > 0 && j > 0 && maze[i][j] == -1) {
                dp[i][j] = 0;// no path bcz of obstacle at (i, j)
                continue;
            }
            // Base Case-2
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

    return dp[n-1][m-1];
}





// Soln-3 SPACE OPTIMIZATION Approach
int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<int> prev(m, 0);

    for(int i=0; i < n; i++) {
        vector<int> temp(m, 0);
        for(int j=0; j < m; j++) {
            //Base Case-1
            if(i > 0 && j > 0 && maze[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
            //Base Case-2
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
    return prev[m-1];
}






int main() {

    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Number of paths with obstacles: " << mazeobstacles(n, m, maze) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Number of paths with obstacles: " << mazeObstacleS(n, m, maze) << endl << endl;


// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "Number of paths with obstacles: " << mazeObstacles(n, m, maze) << endl << endl;




    return 0;
}
