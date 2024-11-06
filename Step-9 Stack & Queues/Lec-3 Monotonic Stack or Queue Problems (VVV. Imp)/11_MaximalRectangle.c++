// Maximal Rectangle / Maximum Size Rectangle Sub-matrix With All 1's






#include<bits/stdc++.h>
using namespace std;

/*// OPtimal Soln(using Prefix SUM + Stack(based on Area of Largest Rectangle in Histogram))

  Intuition:- To get the histogram array for each row, we will use a height array of size m(m = no. of columns of the matrix). This array will primarily store 0’s and the ith index will represent the ith column of the matrix. Now, we will iterate every column of each row and if any column contains 1, we will increase the value of that column index by 1 in the height array(i.e. height[col]++). Otherwise, we will set 0 to the indices of the height array. Thus we will get the histogram array for each row. Then, for each row, we will calculate the maximum area.


  Approach:- Pre-requisite function: largestRectangleArea(). Returns the area of the largest rectangle of a histogram.

 To know the implementation of the function, refer to the article:  Area of largest rectangle in Histogram

   The algorithm steps are as follows:-

  # Declare a height array of size m(where m = no. of columns of the matrix).
  # Now, we will run a loop to visit all the rows of the matrix.
  # Now inside the loop, for each row, iterate over every column, and if a cell contains 1 we will increase the value of the column index by 1 in the height array i.e. height[col]++. But if the cell contains 0, we will set 0 for that column index in the height array.
  # Once every cell gets visited, we will pass the height array i.e. the histogram array to the largestRectangleArea() function and store the maximum area for the row.
  # Now, among all the areas calculated for all rows, we will keep the maximum one as our answer.

   Complexity Analysis:-

    Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
 # Reason: O(N) for running a loop to check all rows. Now, inside that loop, O(M) is for visiting all the columns, and another O(M) is for the function we are using. The function takes linear time complexity. Here, the size of the height array is M, so it will take O(M).

    Space Complexity: O(M), where M = total no. of columns.
*/
int largestRectInHist(vector<int>& ar) {
    int maxArea = 0;
    stack<int> st;
    ar.push_back(0);

    for(int i=0; i < ar.size(); i++) {
        while(!st.empty() && ar[st.top()] >= ar[i]) {
            int ht = ar[st.top()];
            st.pop();

            int wd = st.empty() ? i : i-st.top()-1;
			// (i-st.top()-1) to calculate the width of the rectangle
			maxArea = max(maxArea, ht * wd);
        }

        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    int maxiArea = 0;
    //declare 2D-prefixSum Arr
    vector<int> pSumAr(c, 0);

    for(int i=0; i < r; i++) {
        for(int j=0; j < c; j++) {
            if(mat[i][j] == 1) pSumAr[j]++;
            else pSumAr[j] = 0;
        }
        int histArea = largestRectInHist(pSumAr);
        maxiArea = max(maxiArea, histArea);
    }
    return maxiArea;
}



int main() {

//OPtimal Soln (using Prefix SUM + Stack)
    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    // int n = 4, m = 5;
    int maxiArea = maximalRectangle(mat);
    cout << "The maximum size of Rectangle Sub-matrix With All 1's is: " << maxiArea << "\n"; //Output should be 6




    return 0;
}

