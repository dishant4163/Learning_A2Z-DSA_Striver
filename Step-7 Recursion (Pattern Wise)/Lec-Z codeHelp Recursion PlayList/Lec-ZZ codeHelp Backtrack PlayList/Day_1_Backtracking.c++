// Backtracking Day 1 | Rat in Maze Problem


#include<bits/stdc++.h>
using namespace std;


bool isSafe(int newx, int newy, int n, vector<vector<bool>>& visited, vector<vector<int>>& arr) {
    if((newx >= 0 && newx<n) && (newy >= 0 && newy<n) && visited[newx][newy] == 0 && arr[newx][newy] == 1) {
        return true;
    }
    else {
        return false;
    }
}


void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) {
    // Base Case
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

// rat can moves in 4 way i.e., (U, D, L, R)
// inOrder to get Lexicographcal Sort ans we were doing in moves in sorted way i.e, -> D, L, R, U

int dirx[] = {1, 0, 0, -1};
int diry[] = {0, -1, 1, 0};
char dirMove[] = {'D', 'L', 'R', 'U'};

for(int i=0; i < 4; i++) {
    int newX = x + dirx[i];
    int newY = y + diry[i];
    if (isSafe(newX, newY, n, visited, arr)) {
        solve(newX, newY, arr, n, ans, visited, path + dirMove[i]);
    }
}

/*// From here we can make code more shorter
// via Using Arrays & arrays
    // DOWN
    if(isSafe(x+1, y, n, visited, arr)){
        solve(x+1, y, arr, n, ans, visited, path + 'D');
    }

    // LEFT
    if(isSafe(x, y-1, n, visited, arr)){
        solve(x, y-1, arr, n, ans, visited, path + 'L');
    }

    // RIGHT
    if(isSafe(x, y+1, n, visited, arr)){
        solve(x, y+1, arr, n, ans, visited, path + 'R');
    }

    // UP
    if(isSafe(x-1, y, n, visited, arr)){
        solve(x-1, y, arr, n, ans, visited, path + 'U');
    }

*/

    visited[x][y] = 0; // Backtrack
}


vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    //write your code here
    vector<string> ans;
    vector<vector<bool>> visited (n, vector<bool> (n, 0));
    string path = "";

    // If the starting point is blocked
    if(arr[0][0] == 0){
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}


int main() {


    int n;
    cout << "Enter the size of the maze (n x n): ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    cout << "Enter the maze (0 for blocked, 1 for open): " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<string> paths = searchMaze(arr, n);
    
    if (paths.empty()) {
        cout << "No paths available." << endl;
    } else {
        cout << "Possible paths: " << endl;
        for (const string& path : paths) {
            cout << path << endl;
        }
    }




    return 0;
}
