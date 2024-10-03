// Backtracking Day 2 | N-Queen Problem


#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>>& board, vector<vector<int>>& ans, int n) {
    vector<int> temp;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}


bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;
    // check for same Row
    while(y >= 0) {
        if(board[x][y] == 1)
        return false;

        y--;
    }

    x = row;
    y = col;
    // check for diagonal-2 means lower diagonal from right-left
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) 
        return false;

        x--;
        y--;
    }

    x = row;
    y = col;
    // check for diagonal-1 means upper diagonal from right-left
    while(x < n && y >= 0) {
        if(board[x][y] == 1) 
        return false;

        x+1;
        y--;
    }

    // sab safe h koi attack nhi kar raha h so return true
    return true;
}



void solve(int col, vector<vector<int>>& ans, vector<vector<int>>& board, int n) {
    // Base Case
    if(col == n) {
        addSolution(board, ans, n);
        return;
    }

    // solve only 1 case & rest will solve by Recursion
    for(int row=0; row < n; row++) {
        // if placing queen is safe(means not to attack)
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, ans, board, n);

            // BackTrack
            board[row][col] = 0;
        }
    }
}


vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int> (n, 0)); // board with size n & initailize with 0
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}



int main() {

    int n;
    cout << "Enter the value of n: ";
    cin >> n; // read size of the board (n)

    // call the nQueens function to get all solutions
    vector<vector<int>> solutions = nQueens(n);

    if (solutions.empty()) {
        cout << "No solutions exist for " << n << " queens." << endl;
    } else {
        cout << "Solutions for " << n << " queens:" << endl;
        for (const auto& solution : solutions) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << (solution[i * n + j] ? "Q " : ". ");
                }
                cout << endl;
            }
            cout << endl; // Print a newline between different solutions
        }
    }



    return 0;
}

