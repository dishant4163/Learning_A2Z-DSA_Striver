// Recusrion Day-10 Challenge | Rat in a Maze


/* Rat In A Maze(Coding Ninjas)-> https://shorturl.at/jNfR9       

#include <bits/stdc++.h> 

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &arr) {
    if((y>=0 && y<n) && (x>=0 && x<n) && visited[y][x] == 0 && arr[y][x] ==1 ) {
        return true;
    }
    else {
        return false;
    }
}

void solve(vector<vector<int>>& arr, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path) {
    // Base Case 
    if (y == n-1 && x == n-1) {
        ans.push_back(path);
        return;
    }

    visited[y][x] = 1;

    // rat have 4 choices, U | D | L | R
    // UP
    int newx = x;
    int newy = y-1;
    if(isSafe(newx, newy, n, visited, arr)) {
        path.push_back('U');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //DOWN
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, arr)) {
        path.push_back('D');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //LEFT
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, arr)) {
        path.push_back('L');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //RIGHT
    newx = x+1;
    newy = y;
    if(isSafe(newx, newy, n, visited, arr)) {
        path.push_back('R');
        solve(arr, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // when function call return, mark visited as false(backtrack)
    visited[y][x] = 0;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    // Write your code here.
    vector<string> ans;

    // if src start from 0
    if(arr[0][0] == 0) {
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    // create a visited to keep track of movement
    vector<vector<int>> visited = arr;
    //initialize with 0
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = 0;
        }
    }

    //store path in string
    string path = "";
    solve(arr, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

*/



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


