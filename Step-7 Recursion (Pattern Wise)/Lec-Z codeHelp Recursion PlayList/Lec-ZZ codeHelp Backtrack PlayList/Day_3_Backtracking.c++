// Backtracking Day-3 | Sudoku Solver Problem


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int value) {
    for(int i=0; i < board.size(); i++) {
        // check for Row
        if(board[row][i] == value) //check in row at ith-col is val same
            return false;
        //check for Col
        if(board[i][col] == value) // check in col in ith-row is val same
            return false;
        // check in (3 x 3) individual matrix in 9x9
        if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == value)
            return false;
    }
    return true;
}


bool solve(vector<vector<int>>& board) {
    // size of sudoku board
    int n = board[0].size();

    for(int row=0; row < n; row++) {
        for(int col=0; col < n; col++) {

            //check cell is empty
            if(board[row][col] == 0) {
                for(int val = 1; val <= 9; val++) {
                    // is safe to place value
                    if(isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        //Recursive Call
                        bool nextSolutionPossible = solve(board);
                        if(nextSolutionPossible)
                            return true;
                        else {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false; // not found the solution 
            }
        }
    }
    return true; // solution found :-)
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
}


int main() {






    return 0;
}
