/*//(Rotate Matrix/Image by 90 Degrees_Coding Ninja)-> https://shorturl.at/dISxN   



*/

//Rotate Matrix Anti-Clockwise by 90 Degree-> https://shorturl.at/488oK



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force
   Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
   Complexity Analysis:-
  # Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
  # Space Complexity: O(N*N) to copy it into some other matrix.
*/
vector<vector<int>> rotate(vector<vector<int>> &matrix1) {
    int n1 = matrix1.size();
    vector<vector<int>> rotated1(n1, vector<int>(n1, 0));
    for (int i=0; i < n1; i++) {
        for (int j=0; j<n1; j++) {
            rotated1[j][n1 - i -1] = matrix1[i][j];
        }
    }

    return rotated1;
}






/*// Soln 2: Optimal
 Intuition: By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we TRANSPOSE the MATRIX and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

   Approach:
  # Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns).
  # Step 2: Reverse each row of the matrix.

   Complexity Analysis:
  # Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
  # Space Complexity: O(1).

*** Note-> TRANSPOSE MATRIX -> https://shorturl.at/wRA4V
*/
void rotate(vector<vector<int>> &matrix2) {
    int n2 = matrix2.size();
    // Transpose the Matrix
    for (int i = 0; i < n2; i++) {
        for (int j=0; j < i; j++) {
            swap(matrix2[i][j], matrix2[j][i]);
        }
    }

    // Reversing each Row of the Matrix
    for (int i=0; i < n2; i++) {
        reverse(matrix2[i].begin(), matrix2[i].end());
    }
}




int main() {

// Soln 1: Brute Force
    vector<vector<int>> ar1;
    ar1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> rotated1 = rotate(ar1);
    cout<<"Rotated Image"<<endl;
    for (int i=0; i < rotated1.size(); i++) {
        for (int j=0; j < rotated1[0].size(); j++) {
            cout << rotated1[i][j]<<" ";
        }
        cout << endl;
    }



// Soln 2: Optimal 
    vector<vector<int>> ar2;
    ar2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(ar2);
    cout<<"Rotated Image"<<endl;
    for (int i=0; i < ar2.size(); i++) {
        for (int j=0; j < ar2[0].size(); j++) {
            cout << ar2[i][j] << " ";
        }
        cout << endl;
    }




    return 0;
}

