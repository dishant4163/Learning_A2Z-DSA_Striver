/*//(Set Matrix Zeros_Coding Ninja)-> https://bit.ly/3CukQke 

#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.

	// int col[m] ={0}; --> matrix[0][..]
	// int row[n] ={0}; --> matrix[..][0]
	int col0 = 1;
	//Step 1: Traverse the matrix and
    // mark 1st row & col accordingly
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if(matrix[i][j] == 0) {
			  // mark the i-th row
				matrix[i][0] = 0;
              // mark the j-th column
                if (j != 0)
                    matrix[0][j] = 0;
				else
					col0 = 0;
            }
		}
	}

	//Step 2: Mark with 0 from (1,1) to (n-1, m-1)
    for (int i= 1; i < n; i++) {
		for (int j= 1; j < m; j++) {
			if (matrix[i][j] != 0) {
			    // check for col or row
			    if (matrix[0][j] == 0 || matrix[i][0] ==0) {
					matrix[i][j] = 0;
				}  
			}
		}
	}

	//Step 3: Finally mark the 1st col & then 1st row
	if (matrix[0][0] == 0) {
		for (int j=0; j < m; j++) matrix[0][j] = 0;
	}
	if(col0 == 0) {
		for (int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}


    return matrix;
}

*/

//Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.



#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force Approach
   Approach:-The steps are the following:

  #  First, we will use two loops(nested loops) to traverse all the cells of the matrix.
  #  If any cell (i,j) contains the value 0, we will mark all cells in row i and column j with -1 except those which contain 0.
  #  We will perform step 2 for every cell containing 0.
  #  Finally, we will mark all the cells containing -1 with 0.
  #  Thus the given matrix will be modified according to the question.

->   Note: Here, we are assuming that the matrix does not contain any negative numbers. But if it contains negatives, we need to find some other ways to mark the cells instead of marking them with -1.


   Complexity Analysis:-
  # Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
>  Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
  # Space Complexity: O(1) as we are not using any extra space.
*/
void markRow (vector<vector<int>> &matrix1, int n1, int m1, int i) {
 // set all non-zero elements as -1 in the row i
    for (int j=0; j<m1; j++) {
        if (matrix1[i][j] != 0) {
            matrix1[i][j] = -1;
        }
    }
}

void markCol (vector<vector<int>> &matrix1, int n1, int m1, int j) {
 // set all non-zero elements as -1 in the col j
    for (int i=0; i < n1; i++) {
        if (matrix1[i][j] != 0) {
            matrix1[i][j] = -1;
        }
    }
}


vector<vector<int>> zeroMatrix1(vector<vector<int>> &matrix1, int n1, int m1) {

    // Set -1 for rows & cols
    // that contains 0. Don't mark any 0 as -1

    for(int i=0; i < n1; i++) {
        for(int j=0; j < m1; j++) {
            if (matrix1[i][j] == 0) {
                markRow(matrix1, n1, m1, i);
                markCol(matrix1, n1, m1, j);
            }
        }
    }

    //Finally, mark all -1 as 0
    for (int i=0; i < n1; i++) {
        for (int j=0; j < m1; j++) {
            if (matrix1[i][j] == -1) {
                matrix1[i][j] = 0;
            }
        }
    }

    return matrix1;

}






/*//Soln 2: Better Approach(using 2 extra Arrays)
 In the previous approach, we were marking the row and column with -1 while traversing the matrix. Here we will reduce the time complexity by marking the cells after the traversal.

   Approach (Using two extra arrays):
The steps are as follows:
  #  First, we will declare two arrays: a row array of size N and a col array of size M and both are initialized with 0.
  #  Then, we will use two loops(nested loops) to traverse all the cells of the matrix.
  #  If any cell (i,j) contains the value 0, we will mark ith index of row array i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements in the ith row and jth column will be 0 in the final matrix.
  #  We will perform step 3 for every cell containing 0.
  #  Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) for which either row[i] or col[j] is marked as 1.
  #  Thus we will get our final matrix.

    Intuition:- In the previous approach, we were marking the cells with -1 while traversing the matrix. But in this approach, we are not marking the entire row and column instead, we are marking the ith index of row array i.e. row[i], and jth index of col array i.e. col[j] with 1. These marked indices of the two arrays, row and col will tell us for which rows and columns we need to change the values to 0. For any cell (i, j), if the row[i] or col[j] is marked with 1, we will change the value of cell(i, j) to 0.

 >  Here we are marking the cells after traversal whereas in the previous case, we were marking the cells while traversal. That is how the time complexity reduces in this case.

   Complexity Analysis:-
  # Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
 >  Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

  # Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
>  Reason: O(N) is for using the row array and O(M) is for using the col array.
*/
vector<vector<int>> zeroMatrix2(vector<vector<int>> &matrix2, int n2, int m2) {
    int row[n2] = {0}; // row array
    int col[m2] = {0}; // col array

    //Traverse the Matrix
    for (int i=0; i < n2; i++) {
        for (int j=0; j < m2; j++) {
            if (matrix2[i][j] == 0) {
                // mark ith index of row with 1
                row[i] = 1;
                // mark jth index of col with 1
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1
    for (int i=0; i < n2; i++) {
        for (int j=0; j < m2; j++) {
            if (row[i] || col[j]) {
                matrix2[i][j] = 0;
            }
        }
    }

    return matrix2;

}






/*// Soln 3: Optimal
 Intuition:- In the previous approach, the time complexity is minimal as the traversal of a matrix takes at least O(N*M)(where N = row and M = column). In this approach, we can just improve the space complexity. So, instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked with 0. But here comes a problem. If we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix will serve the purpose of the row array. And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array.

   Approach:
 The steps are as follows:

  #  First, we will traverse the matrix and mark the proper cells of 1st row and 1st column with 0 accordingly. The marking will be like this: if cell(i, j) contains 0, we will mark the i-th row i.e. matrix[i][0] with 0 and we will mark j-th column i.e. matrix[0][j] with 0.
>    If i is 0, we will mark matrix[0][0] with 0 but if j is 0, we will mark the col0 variable with 0 instead of marking matrix[0][0] again.
  #  After step 1 is completed, we will modify the cells from (1,1) to (n-1, m-1) using the values from the 1st row, 1st column, and col0 variable.
>    We will not modify the 1st row and 1st column of the matrix here as the modification of the rest of the matrix(i.e. From (1,1) to (n-1, m-1)) is dependent on that row and column.
  #  Finally, we will change the 1st row and column using the values from matrix[0][0] and col0 variable. Here also we will change the row first and then the column.
>    If matrix[0][0] = 0, we will change all the elements from the cell (0,1) to (0, m-1), to 0.
>    If col0 = 0, we will change all the elements from the cell (0,0) to (n-1, 0), to 0.

   Complexity Analysis:-
  # Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
 >  Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
  # Space Complexity: O(1) as we are not using any extra space.
*/
vector<vector<int>> zeroMatrix3(vector<vector<int>> &matrix3, int n3, int m3) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // Step 1: Traverse the matrix and
    // mark 1st row & col accordingly
    for (int i=0; i < n3; i++) {
        for (int j=0; j < m3; j++) {
            if (matrix3[i][j] == 0){
                // mark i-th row
                matrix3[i][0] = 0;

            // mark j-th column
            if (j != 0)
                matrix3[0][j] = 0;
            else
                col0 = 0;
            }
        }
    }

    //Step 2: Mark with 0 from (1,1) to (n-1, m-1)
    for (int i=1; i < n3; i++) {
        for (int j=1; j < m3; j++) {
            if (matrix3[i][j] != 0) {
                //Check for col & row
                if (matrix3[i][0] == 0 || matrix3[0][j] ==0) {
                    matrix3[i][j] = 0;
                }
            }
        }
    }

    //Step 3: Finally mark the 1st col & then 1st row
    if (matrix3[0][0] == 0) {
        for (int j=0; j < m3; j++) {
            matrix3[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i=0; i < n3; i++) {
            matrix3[i][0] = 0;
        }
    }

    return matrix3;

}




int main() {

// Soln 1: Brute Force
    vector<vector<int>> matrix1 = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    int n1 = matrix1.size();
    int m1 = matrix1[0].size();
    vector<vector<int>> ans1 = zeroMatrix1(matrix1, n1, m1);
    cout<<"The Final Matrix is: "<<endl;
    for (auto it: ans1) {
        for (auto ele: it) {
            cout << ele <<" ";
        }
        cout << endl;
    }



// Soln 2: Better Approach
    vector<vector<int>> matrix2 = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}};
    int n2 = matrix2.size();
    int m2 = matrix2[0].size();
    vector<vector<int>> ans2 = zeroMatrix2(matrix2, n2, m2);
    cout<<"The Final Matrix is: "<<endl;
    for (auto it: ans2) {
        for (auto ele: it) {
            cout << ele <<" ";
        }
        cout << endl;
    }



// Soln 3: Optimal
    vector<vector<int>> matrix3 = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
    int n3 = matrix3.size();
    int m3 = matrix3[0].size();
    vector<vector<int>> ans3 = zeroMatrix3(matrix3, n3, m3);
    cout<<"The Final Matrix is: "<<endl;
    for (auto it: ans3) {
        for (auto ele: it) {
            cout << ele <<" ";
        }
        cout << endl;
    }




    return 0;
}



