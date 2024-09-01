/*(Find Row with Maximum Number of 1's_Coding Ninja)-> https://bit.ly/3P0n95t  

int lB(vector<int>&ar, int n, int x) {
    int low = 0, high = n;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) /2;
        if (ar[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int cnt_max = 0;
    int ind = -1;

    for (int i=0; i<n; i++) {
        int cnt_ones = m - lB(matrix[i], m, 1);// no of 1 = size - first occur of 1 in the
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            ind = i;
        }
    }
    return  ind;
}

*/



/* Problem Statement:-
  You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones.
    Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

 Pre-requisite: Lower Bound implementation, Upper Bound implementation, & Find the first occurrence of a number.

   Examples
 Example 1: Input Format: n = 3, m = 3, 
mat[] = 
1 1 1
0 0 1
0 0 0

 Result: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).


 Example 2: Input Format: n = 2, m = 2 , 
mat[] = 
0 0
0 0
 Result: -1
Explanation: The matrix does not contain any 1. So, -1 is the answer
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force  
   Intuition

In the question, it is clearly stated that we should return -1 if the matrix does not contain any 1.

The extremely naive approach is to traverse the matrix as usual using nested loops and for every single row count the number of 1’s. Finally, we will return the row with the maximum no. of 1’s. If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index.


Algorithm:- The steps are as follows:
  #  First, we will declare 2 variables i.e. cnt_max(initialized with 0), and index(initialized with -1). The first variable will store the maximum number of 1’s we have got and the ‘index’ will store the row number.
  #  Next, we will start traversing the matrix. We will use a loop(say i) to select each row at a time.
  #  Now, for each row i, we will use another loop(say j) and count the number of 1’s in that row.
  #  After that, we will compare it with cnt_max and if the current number of 1’s is greater, we will update cnt_max with the current no. of 1’s and ‘index’ with the current row index.
  #  Finally, we will return the variable ‘index’. It will store the index of the row with the maximum no. of 1’s. And otherwise, it will store -1.

    Note: As we want the row with the minimum index, we will only update the index if the current number of 1’s is greater than cnt_max (we will not update if they are equal).


   Complexity Analysis:-
  #Time Complexity: O(n X m), where n = given row number, m = given column number.
    Reason: We are using nested loops running for n and m times respectively.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int rowWithMax1s_1(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        int cnt_ones = 0;
        for (int j = 0; j < m; j++) {
            cnt_ones += matrix[i][j];
        }
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}





/*// Soln 2: Optimal(using BS)  
  Intuition
 We are going to use the Binary Search algorithm to optimize the approach.
 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

 We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.

  Instead of counting the number of 1’s, we can use the following formula to calculate the number of 1’s:
 Number_of_ones = m(number of columns) - first occurrence of 1(0-based index).

   As, each row is sorted, we can find the first occurrence of 1 in each row using any of the following approaches:

  lowerBound(1) (ref: Implement Lower Bound)
  upperBound(0) (ref: Implement Upper Bound)
  firstOccurrence(1) (ref: First and Last Occurrences in Array)

    Note: Here, we are going to use the lowerBound() function to find the first occurrence. You can use the other methods as well.

   Algorithm:
  #  First, we will declare 2 variables i.e. cnt_max(initialized with 0), and index(initialized with -1). The first variable will store the maximum number of 1’s we have got and ‘index’ will store the row number.
  #  Next, we will start traversing the rows. We will use a loop(say i) to select each row at a time.
  #  Now, for each row i, we will use lowerBound() to get the first occurrence of 1. Now, using the following formula we will calculate the number of 1’s:
  #  Number_of_ones = m(number of columns) - lowerBound(1)(0-based index).
  #  After that, we will compare it with cnt_max and if the current number of 1’s is greater, we will update cnt_max with the current no. of 1’s and ‘index’ with the current row index.
  #  Finally, we will return the variable ‘index’. It will store the index of the row with the maximum no. of 1’s. And if the matrix does not contain any 1, it stores -1.

    Note: As we want the row with the minimum index, we will only update the index if the current number of 1’s is greater than cnt_max (we will not update if they are equal).


   Complexity Analysis:-
  # Time Complexity: O(n X logm), where n = given row number, m = given column number.
    Reason: We are using a loop running for n times to traverse the rows. Then we are applying binary search on each row with m columns.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}







int main() {

// Soln 1: Brute Force
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s_1(matrix, n, m) << '\n';



// Soln 2: Optimal(BS)
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';





    return 0;
}
