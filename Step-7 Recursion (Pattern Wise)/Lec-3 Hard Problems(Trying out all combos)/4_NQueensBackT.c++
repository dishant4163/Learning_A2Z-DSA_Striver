// Backtracking Day 2 | N-Queen Problem


#include<bits/stdc++.h>
using namespace std;




/* // OPtimal Soln-1
// TC:- O(N!) and SC:- O(N*N) + O(N) approx => O(N*N)

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

    // NOTE:- there is no need to check for same col
    // bcz we were moving left to right direction, also no need to check direction up, down, upper & lower diagonal & left to right

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

        x++;
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
*/




/*// More Optimal Soln-2
// Time Complexity: O(N!) & Space Complexity: O(N*N) + O(1) ->due to hashmap

unordered_map<int, bool> checkRow;
unordered_map<int, bool> checkUprLeftDiagonal;
unordered_map<int, bool> checkLowrLeftDiagonal;

bool safe2Move(int row, int col, vector<vector<int>>& Board, int m) {
    // check for same row
    if(checkRow[row]) return false;
    // upper left diagonal check
    if(checkUprLeftDiagonal[(m-1) + (col-row)]) return false;
    // lower left diagonal check
    if(checkLowrLeftDiagonal[row + col]) return false;

    // safe to place
    return true;
}


void Solve(int col, vector<vector<vector<int>>>& Ans, vector<vector<int>> Board, int m) {
    // Base Case
    if (col == m) {
        Ans.push_back(Board);
        return;
    }

    //Solve 1 case only and left other cases on recursion to solve
    for (int row=0; row<m; row++) {
        if(safe2Move(row, col, Board, m)) {
            Board[row][col] = 1;
            checkRow[row] = true;
            checkUprLeftDiagonal[(m-1) + (col-row)] = true;
            checkLowrLeftDiagonal[row + col] = true;
            Solve(col+1, Ans, Board, m); // Recursive Call

            // BackTrack
            Board[row][col] = 0;
            checkRow[row] = false;
            checkUprLeftDiagonal[(m-1) + (col-row)] = false;
            checkLowrLeftDiagonal[row + col] = false;   
        }
    }
}

vector<vector<vector<int>>> mQueens(int m) {
    vector<vector<int>> Board(m, vector<int> (m, 0)); //board with size m & initialize with 0
    vector<vector<vector<int>>> Ans;
    Solve(0, Ans, Board, m);
    return Ans;
}
*/







int main() {

/* // Optimal Soln - 1
    int n;
    cout << "Enter the number of Queens (n): ";
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
*/



/*// Optimal Soln - 2
    int m;
    cout << "Enter the number of Queens (m): ";
    cin >> m; // read size of the board (m)

    // call the nQueens function to get all solutions
    vector<vector<vector<int>>> res = mQueens(m);

    if (res.empty()) {
        cout << "No solutions exist for " << m << " queens." << endl;
    } else {
        cout << "Solutions for " << m << " queens:" << endl;
        for (const auto& soln : res) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << (soln[i][j] ? "Q " : ". ");
                }
                cout << endl;
            }
            cout << endl; // Print a newline between different solutions
        }
    }
*/



    return 0;
}


