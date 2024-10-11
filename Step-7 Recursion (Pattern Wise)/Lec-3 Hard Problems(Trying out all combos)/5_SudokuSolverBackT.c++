// Sudoku Solver | Backtrack

/* Sudoku Solver (Coding Ninjas ->  https://shorturl.at/NAURM  )

#include <bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>>& board, int value) {
    
    for (int i=0; i < board.size(); i++) {
        //check for row
    if(board[row][i] == value) return false;
    //check for col
    if(board[i][col] == value) return false;
    //check in 3x3 grid individualy of matrix 9x9
    if(board[3 * (row/3) + i/3][3* (col/3) + i%3] == value) return false;
    }

    return true;
}


bool solve(vector<vector<int>>& board) {
    //size of sudoku board
    int n = board[0].size();

    for(int row=0; row < n; row++) {
        for(int col=0; col < n; col++) {

            //check cell is empty
            if(board[row][col] == 0) {
                for(int val = 1; val <= 9; val++) {
                    //is safe to place
                    if(isSafe(row, col, board, val)) {
                        board[row][col] = val;
                    //Recursive Call
                    bool nextSolnIsPossible = solve(board);

                    if(nextSolnIsPossible) return true;
                    else { // backtrack
                       board[row][col] = 0;
                    }
                    }
                }
                return false; // solution not found
            }
        }
    }
    return true; // solution found
}


void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}

*/
