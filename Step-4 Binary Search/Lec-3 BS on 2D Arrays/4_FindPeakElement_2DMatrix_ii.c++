/*(Find Peak Element in 2D Matrix_Coding Ninja)-> https://bit.ly/3Ckb4Rb   

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    // Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        int maxRowIndex = findMaxIndex(mat, n, m, mid);
        int left = mid-1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid+1 < m ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};    
}

*/



/* Problem Statement:-
 You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.
 You need to find the location of a peak element in it. If there are multiple answers, find any of them.
 A peak element is a cell with a value strictly greater than all its adjacent cells.
 Assume the grid to be surrounded by a perimeter of ‘-1s’.

    You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.

    Note: In the output, you will see '0' or '1', where '0' means your answer is wrong, and '1' means your answer is correct.

   Examples:-
 Sample Input 1:
n=2, m=2
8 6
10 1
Sample Output 1:
1       
Explanation of sample output 1: For g = [[8,6],[10,1]],
Answer = [1,0].
 There is only one peak element that is present at [1,0].

 Sample Input 2:
n=3, m=3
1 2 3
4 5 6
7 8 9   
Sample Output 2:
1
Explanation of sample output 2:
For g = [[1, 2, 3], [4, 5, 6], [7, 8, 9]],
Answer = [2,2].
 There is only one peak element that is present at [2,2].
*/


#include<bits/stdc++.h>
using namespace std;

/*//Optimal(using BS) [soln-> https://rb.gy/i7z8g3   ]
  Tc:- O(log(n*m))
  Sc:- O(1)
*/

int findMaxIndex(vector<vector<int>>& mat, int n, int m, int col) {
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    // Write your code here.
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m-1;
    while(low <= high) {
        int mid = low + (high - low)/2;
        int maxRowIndex = findMaxIndex(mat, n, m, mid);
        int left = mid-1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid+1 < m ? mat[maxRowIndex][mid + 1] : -1;

        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};    
}



int main() {



    return 0;
}

