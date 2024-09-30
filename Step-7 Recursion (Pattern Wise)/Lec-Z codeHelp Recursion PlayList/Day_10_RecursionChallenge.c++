// Recusrion Day-10 Challenge | Rat in a Maze



#include<bits/stdc++.h>
using namespace std;



bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m) {
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}

void solve(vector<vector<int>> &m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path) {

    // u have visited x,y here

    // Base case
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    //rat have 4 choices i.e, D, L, R, U

    //Down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m,n,ans,newx, newy, visited, path);
        // Backtrack
        path.pop_back();
    }

    //Left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m,n,ans,newx, newy, visited, path);
        // Backtrack
        path.pop_back();
    }

    //Right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m,n,ans,newx, newy, visited, path);
        // Backtrack
        path.pop_back();
    }

    //UP
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m,n,ans,newx, newy, visited, path);
        // Backtrack
        path.pop_back();
    }



    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;

    // if src is start with 0
    if(m[0][0] == 0) {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    //create visited array
    vector<vector<int>> visited = m;
    // initialize with 0
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    //store path in empty string
    string path = "";
    solve(m, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}





int main() {

    // Example maze input
    int n;
    cout << "Enter the size of the maze (n): ";
    cin >> n;

    vector<vector<int>> m= (n, vector<int>(n));

    cout << "Enter the maze (0 for blocked, 1 for open):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    vector<string> paths = findPath(m, n);

    if (paths.empty()) {
        cout << "No path available" << endl;
    } else {
        cout << "Paths to reach the destination:" << endl;
        for (const string &path : paths) {
            cout << path << endl;
        }
    }


    return 0;
}


