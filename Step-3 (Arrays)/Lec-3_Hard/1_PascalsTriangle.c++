/*//(Pascal's Triangle_Coding Ninja)-> https://bit.ly/3jY4iuF

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) {
        ans.push_back(generateRow(i));
    }

    return ans;
}

*/

/* Types of Variation in Pascal's Triangle
Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.
*/


#include<bits/stdc++.h>
using namespace std;


// VARIATION 1-> Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
/* Naive Approach

 We have an easier formula to find out the element i.e. r-1Cc-1. Let’s try to analyze the formula to find the value of the combination assuming r-1 as n and c-1 as r:

nCr = n! / (r! * (n-r)!)

Calculating the value of nCr:

  Naive Approach: 

 We can separately calculate n!, r!, (n-r)! and using their values we can calculate nCr. This is an extremely naive way to calculate. The time complexity will be O(n)+O(r)+O(n-r).
*/
/* Optimal Approach

Approach:- The steps are as follows:

  #  First, we will consider r-1 as n and c-1 as r.
  #  After that, we will simply calculate the value of the combination using a loop. 
  #  The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
  #  Finally, the calculated value of the combination will be our answer.

   Complexity Analysis:-
  # Time Complexity: O(c), where c = given column number.
    Reason: We are running a loop for r times, where r is c-1.
  # Space Complexity: O(1) as we are not using any extra space.

*/
 // Optmal Code->
int nCr_1(int n1, int r1) {
    long long res1 = 1;

    // Calculating nCr
    for (int i=0; i < r1; i++) {
        res1 = res1 * (n1 - i);
        res1 = res1/(i + 1);
    }
    return res1;
}

int pascalTriangle_1(int r1, int c1) {
    int element1 = nCr_1(r1 - 1, c1 - 1);
    return element1;
}






// VARIATION 2-> Given the row number n. Print the n-th row of Pascal’s triangle.
/* Naive Approach
   Intuition:- In this approach, for every column from 1 to n, we will calculate the element (n, c)(where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. Thus, we will print the row.  

   Approach:- The steps are as follows:
  #  We will use a loop(say c) to iterate over each column i.e. from 1 to n. And for each column, we will do the following steps:
>       First, we will consider n-1 as n and c-1 as r.
>       After that, we will simply calculate the value of the combination using a loop. 
>       The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
>       Finally, we will print the element.
  #  Finally, the entire row will be printed.

   Complexity Analysis:- 
  # Time Complexity: O(n*r), where n is the given row number, and r is the column index which can vary from 0 to n-1.
    Reason: We are calculating the element for each column. Now, there are total n columns, and for each column, the calculation of the element takes O(r) time where r is the column index.
  # Space Complexity: O(1) as we are not using any extra space.
*/
// Naive Code->
int nCr_2(int n2, int r2) {
    long long res2 = 1;

    // Calculating nCr
    for (int i=0; i < r2; i++) {
        res2 = res2 * (n2 - i);
        res2 = res2 / (i + 1);
    }
    return res2;
}

void pascalTriangle_2(int n2) {
    // printing the entire row n
    for (int c2 = 1; c2 <= n2; c2++) {
        cout <<nCr_2(n2 - 1, c2 - 1)<<" ";
    }
    cout << endl;
}

/* Optimal Approach 
   Approach:- The steps are as follows:

  #  First, we will print the 1st element i.e. 1 manually.
  #  After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
  #  Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i) and then divide it by i itself.
  #  Thus, the entire row will be printed.

*** Note: If we want to store the row elements, we just need to store each element instead of printing it.

   Complexity Analysis:-
  # Time Complexity: O(N) where N = given row number. Here we are using only a single loop.
  # Space Complexity: O(1) as we not using any extra space.
*/
// Optimal Code->
void pascalTriangle_3(int n3) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    // Printing the rest of the part
    for (int i = 1; i < n3; i++) {
        ans = ans * (n3 - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}






// VARIATION 3-> Given the number of rows n. Print the first n rows of Pascal’s triangle.
/* Naive Approach
   Intuition:- The naive approach is basically a combination of variation 1 and variation 2. Here, for every row from 1 to n, we will try to generate all the row elements by simply using the naive approach of variation 2. So, we will use the same code as variation 2(naive approach), inside a loop (i.e. row runs from 1 to n).

   Approach:- The steps are as follows:
  #  First, we will run a loop(say row) from 1 to n.
  #  We will use a loop(say col) to iterate over each column i.e. from 1 to n. And inside the nested loops, we will do the following steps:
>       First, we will consider row-1 as n and col-1 as r.
>       After that, we will simply calculate the value of the combination using a loop. 
>       The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
>       Finally, we will add the element to a temporary list.
  #  After calculating all the elements for all columns of a row, we will add the temporary list to our final answer list.
  #  Finally, we will return the answer list.  

   Complexity Analysis:-
  # Time Complexity: O(n*n*r) ~ O(n3), where n = number of rows, and r = column index.
    Reason: The row loop will run for approximately n times. And generating a row using the naive approach of variation 2 takes O(n*r) time complexity.
  # Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can be still considered as O(1).
*/
// Naive Code->
int nCr_3(int n4, int r4) {
    long long res4 = 1;

    // calculating nCr
    for (int i = 0; i < r4; i++) {
        res4 = res4 * (n4 - i);
        res4 = res4 / (i + 1);
    }

    return res4;
}

vector<vector<int>> pascalTriangle_4(int n4) {
    vector<vector<int>> ans2;

    //Store the entire pascal's triangle
    for (int row = 1; row <= n4; row++) {
        vector<int> tempList; // temporary list
        for (int col = 1; col <= row; col++) {
            tempList.push_back(nCr_3(row - 1, col - 1));
        }
        ans2.push_back(tempList);
    }
    return ans2;
}

/*// Optimal Approach
   Intuition:- Now, in the optimal approach of variation 2, we have learned how to generate a row in O(n) time complexity. So, in order to optimize the overall time complexity, we will be using that approach for every row. Thus the total time complexity will reduce.

   Approach:- The steps are as follows:

  #  First, we will run a loop(say row) from 1 to n.
  #  Inside the loop, we will call a generateRow() function and add the returned list to our final answer. Inside the function we will do the following:
>       First, we will store the 1st element i.e. 1 manually.
>       After that, we will use a loop(say col) that runs from 1 to n-1. It will store the rest of the elements.
>       Inside the loop, we will use the specified formula to print the element. We will multiply the previous answer by (row-col) and then divide it by col itself.
>       Thus, the entire row will be stored and returned.
  #  Finally, we will return the answer list.  

   Complexity Analysis:-
  # Time Complexity: O(n2), where n = number of rows(given).
    Reason: We are generating a row for each single row. The number of rows is n. And generating an entire row takes O(n) time complexity.
  # Space Complexity: In this case, we are only using space to store the answer. That is why space complexity can still be considered as O(1).

*/
// Optimal Code->
vector<int> generateRow(int row) {
    long long ans5 = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans5 = ans5 * (row - col);
        ans5 = ans5 / col;
        ansRow.push_back(ans5);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n5) {
    vector<vector<int>> ans5;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n5; row++) {
        ans5.push_back(generateRow(row));
    }
    return ans5;
}






int main() {

// Variation-1 
// Code(Optimal)
    int r1 = 5; // row number
    int c1 = 3; // col number
    int element1 = pascalTriangle_1(r1, c1);
    cout << "The element at position (r1, c1) is: "<< element1 << endl;



// Variation-2 
// Code (Naive)
    int n2 = 5;
    pascalTriangle_2(n2);

// Code (Optimal)
    int n3 = 5;
    pascalTriangle_3(n3);



// Variation-3 
 Code (Naive)
    int n4 = 5;
    vector<vector<int>> ans2 = pascalTriangle_4(n4);
    for (auto it: ans2) {
        for (auto ele: it) {
            cout << ele <<" ";
        }
        cout << endl;
    }

// Code (Optimal)
    int n5 = 5;
    vector<vector<int>> ans5 = pascalTriangle(n5);
    for (auto it : ans5) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }




    return 0;
}

