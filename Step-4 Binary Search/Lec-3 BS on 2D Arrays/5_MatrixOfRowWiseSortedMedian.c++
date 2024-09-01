/*(Median of Row Wise Sorted Matrix_Coding Ninja)-> https://shorturl.at/Qk9PG      

int upBound(vector<int> &arr, int x, int n) {
    int low =0, high = n-1;
    int ans = n;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int cntSmallEquals(vector<vector<int>> &mat, int n, int m, int x) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += upBound(mat[i], x, m);
    }
    return cnt;
}


int median(vector<vector<int>> &mat, int m, int n) {
    // Write your code here.
    int low = INT_MAX;
    int high = INT_MIN;
    n = mat.size();
    m = mat[0].size();
    for (int i=0; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }

    int req = n*m / 2;
    while(low <= high) {
        int mid = low + (high-low)/2;
        int smallEqual = cntSmallEquals(mat, n, m, mid);
        if (smallEqual <= req) {
            low = mid + 1;
        }
        else {
            high = mid -1;
        }
    }
    return low;
}

*/


/* Problem Statement:-
 Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.

    Note: MXN is odd.


   Examples

Example 1: Input Format:M = 3, N = 3, 
matrix[][] =
1 4 9 
2 5 6
3 8 7
 Result: 5
 Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5

Example 2:
 Input Format:M = 3, N = 3, 
matrix[][] =
1 3 8 
2 3 4
1 2 5
 Result: 3
 Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3

*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute   
 Intuition:- The extremely naive approach is to use a linear array/list to store the elements of the given matrix. Now, we will sort the list and return the middle element.

   Algorithm:-
  #  We will use a loop(say i) to select a particular row at a time.
  #  Next, we will use another loop(say j) for every row to traverse each column.
  #  Inside the loops, we will store each element, matrix[i][j] to a linear array/list.
  #  Finally, we will return the middle element of that linear array.


   Complexity Analysis:-
  #Time Complexity: O(MXN) + O(MXN(log(MXN))), where M = number of row in the given matrix, N = number of columns in the given matrix.
    Reason: At first, we are traversing the matrix to copy the elements. This takes O(MXN) time complexity. Then we are sorting the linear array of size (MXN), that takes O(MXN(log(MXN))) time complexity.
  # Space Complexity: O(MXN) as we are using a temporary list to store the elements of the matrix.
*/
int median1(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;

    //traverse the matrix and
    //copy the elements to list:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
        }
    }

    //sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}





/*// Soln 2: Optimal(BS)  
 Intuition:- Now, if we wish to further optimize the previous approach we cannot afford to check every element. So, we have to eliminate some parts to reduce the time complexity under O(MXN). This is where the binary search algorithm comes in.

 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

Observations:
  What is the search space where we will apply binary search?
    If we carefully observe, our answer lies between the smallest and the largest number in the given matrix. So, the search space will be [min(matrix), max(matrix)].

  While applying binary search how to check if an element ‘x’ is a possible median?
    If ‘x’ is the median, the number of elements smaller or equal to ‘x’ will be surely greater than (MXN) // 2 (integer division).

  How to check how many numbers are smaller or equal to an element ‘mid’?
    One of the ways is to traverse the whole matrix and count the numbers. But in that case, the time complexity will be high. So, we have to find other ways. It is given that the matrix is row-wise sorted. So, we can apply the concept of upper bound
        For every particular row, we will find the upper bound of the current element ‘mid’. The index returned will be the number of smaller or equal elements in that row.
        We will do it for each row and add them to get the total number for the whole matrix.
        Mathematically, smaller_equal_in_row = upperBound(matrix[row], mid)


 We will just convert the above observation into code.

   Algorithm:-
  #  Calculate min(matrix) and max(matrix): As the given matrix is row-wise sorted the minimum element will be the minimum element in the first column and the maximum will be the maximum in the last column.
  #  Place the 2 pointers low and high: Initially, we will place the pointers. The pointer low will point to min(matrix) and the high will point to max(matrix).
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula: mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Use the calculateSmallEqual() function to get the number of elements <= mid: Inside the function, we will use the above-mentioned upper bound formula for each row and calculate the total number of elements <= mid. Then we will return the total number from the function calculateSmallEqual().
  #  If smallEqual <= (M*N) // 2: We can conclude that our median must be a bigger number. So, we will eliminate the left i.e. the smaller half (low = mid+1).
  #  If smallEqual > (M*N) // 2: We can conclude that the element mid might be the median. But we have to reach the smallest number to find the actual median. So, in this case, we will remove the right half( i.e. high = mid-1).

 The steps from 3-6 will be inside a loop and the loop will continue until low crosses high.


   Complexity Analysis:-
 Time Complexity: O(log(109)) X O(M(logN)), where M = number of rows in the given matrix, N = number of columns in the given matrix.
    Reason: Our search space lies between [0, 109] as the min(matrix) can be 0 and the max(matrix) can be 109. We are applying binary search in this search space and it takes O(log(109)) time complexity. Then we call countSmallEqual() function for every ‘mid’ and this function takes O(M(logN)) time complexity.
 Space Complexity : O(1) as we are not using any extra space
*/
int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
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

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}






int main() {

// Soln 1: Brute Force
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median1(matrix, m, n);
    cout << "The median element is: " << ans << endl;



// Soln 2: Optimal
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;




    return 0;
}
