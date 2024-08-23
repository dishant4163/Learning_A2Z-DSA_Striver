/*(Find the repeating and missing numbers_Coding Ninja)-> https://bit.ly/3MC5iAx   

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size(); // size of the array

    long long SN = (n*(n+1)) / 2;
    long long S2N = (n*(n+1)*(2*n+1)) / 6;

    long long S = 0, S2 = 0;
    for (int i=0; i<n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    
    long long val1 = S - SN; // x-y
    long long val2 = S2 - S2N;
    val2 = val2 / val1; // x+y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

*/


/* Problem Statement: 
 You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

   Example :- 
  # Input Format:  array[] = {3,1,2,5,3}
  # Result: {3,4)
  # Explanation: A = 3 , B = 4 
Since 3 is appearing twice and 4 is missing
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
   Intuition: For each number between 1 to N, we will try to count the occurrence in the given array using linear search. And the element with occurrence as 2 will be the repeating number and the number with 0 occurrences will be the missing number.

   Approach: The steps are as follows:
  #  We will run a loop(say i) from 1 to N.
  #  For each integer, i, we will count its occurrence in the given array using linear search.
  #  We will store those two elements that have the occurrence of 2 and 0.
  #  Finally, we will return the elements.

   Complexity Analysis:-
  # Time Complexity: O(N2), where N = size of the given array.
    Reason: Here, we are using nested loops to count occurrences of every element between 1 to N.
  # Space Complexity: O(1) as we are not using any extra space.
*/
vector<int>findMissingRepeatingNumbers_1(vector<int> ar1) {
    int n1 = ar1.size();
    int repeating1 = -1, missing1 = -1;

    //Find the repeating and missing number
    for (int i=1; i <= n1; i++) {
        int cnt1=0; //Count the occurrences
        for (int j=0; j<n1; j++) {
            if (ar1[j] == i) cnt1++;
        }

        if (cnt1 == 2 ) repeating1 = i;
        else if (cnt1 == 0) missing1 = i;

        if (repeating1 != -1 && missing1 != -1) break;
    }

    return {repeating1, missing1};
}





/*// Soln 2: Better(Using Hashing{hasharray})
   Intuition:- Instead of counting the occurrences every time, using the hashing technique, we will store the frequency of each element between 1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.

*** Note: Here, we can solve this problem using a hash array.

   Approach:- The steps are as follows:
  #  The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
  #  We will iterate all the elements of the given array and update the hash array accordingly i.e. hash[a[i]] = hash[a[i]]+1.
  #  Now, we will iterate on the hash array and return the two elements with frequencies 2 and 0.

   Complexity Analysis:- 
  # Time Complexity: O(2N), where N = the size of the given array.
    Reason: We are using two loops each running for N times. So, the time complexity will be O(2N).
  # Space Complexity: O(N) as we are using a hash array to solve this problem.
*/
vector<int>findMissingRepeatingNumbers_2(vector<int> ar2) {
    int n2 = ar2.size();

    int hash[n2 + 1] = {0};
    for (int i=0; i<n2; i++) {
        hash[ar2[i]]++;
    }

    int repeating2 = -1, missing2 = -1;
    for (int i=1; i <= n2; i++){
        if (hash[i] == 2) repeating2 = i;
        else if (hash[i] == 0) missing2 = i;

        if (repeating2 != -1 && missing2 != -1) {
            break;
        }
    }
    return {repeating2, missing2};
}





/*// Soln 3.1: Optimal(Using Maths)
   Intuition:

The idea is to convert the given problem into mathematical equations. Since we have two variables i.e. missing and repeating, we will try to form two linear equations. And then we will find the values of two variables using those equations.

Assume the repeating number to be X and the missing number to be Y.

In the array, the numbers are between 1 to N, and in that range, one number is missing and one number is occurring twice.

    > Step 1: Form equation 1:

Now, we know the summation of the first N numbers is:

Sn = (N*(N+1))/2

Let’s say, S = the summation of all the elements in the given array.

Therefore, S - Sn = X - Y…………………equation 1

    > Step 2: Form equation 2:

Now, we know the summation of squares of the first N numbers is:

S2n = (N*(N+1)*(2N+1))/6

Let’s say, S2 = the summation of squares of all the elements in the given array.

Therefore, S2-S2n = X2-Y2...................equation 2

From equation 2 we can conclude,

X+Y = (S2 - S2n) / (X-Y) [From equation 1, we get the value X-Y] ………… equation 3

From equation 1 and equation 3, we can easily find the value of X and Y. And this is what we want.




   Approach:- Assume the repeating number to be X and the missing number to be Y.

The steps are as follows:
  #  First, find out the values of S and Sn and then calculate S - Sn (Using the above formulas).
  #  Then, find out the values of S2 and S2n and then calculate S2 - S2n.
  #  After performing steps 1 and 2, we will be having the values of X + Y and X - Y. Now, by substitution of values, we can easily find the values of X and Y.

   Complexity Analysis:- 
  # Time Complexity: O(N), where N = the size of the given array.
    Reason: We are using only one loop running for N times. So, the time complexity will be O(N).
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
vector<int>findMissingRepeatingNumbers_3(vector<int> ar) {
    long long n = ar.size();

    // Find Sn and S2n:
    //sum of 1st 'n' natural numbers
    long long SN = (n*(n+1)) / 2; 
    // Square of 1st 'n' natural numbers
    long long S2N = (n*(n+1)*(2*n+1)) / 6;

    // Calculate S and S2:
    long long S=0, S2=0;
    for (int i = 0; i < n; i++) {
        S += ar[i];
        S2 += (long long)ar[i] * (long long)ar[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN; // x-y

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1; // x+y

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}





/*// Soln 3.2: Optimal(Using XOR)  
   Approach:-The steps are as follows:

  #  For the first step, we will run a loop and calculate the XOR of all the array elements and the numbers between 1 to N. Let’s call this value xr.
  #  In order to find the position of the first set bit from the right, we can either use a loop or we can perform AND of the xr and negation of (xr-1) i.e. (xr & ~(xr-1)).
  #  Now, we will take two variables i.e. zero and one. Now, we will check the bit of that position for every element (array elements as well as numbers between 1 to N).
>       If the bit is 1: We will XOR that element with variable one.
>       If the bit is 0: We will XOR that element with variable zero.
  #  Finally, we have two variables i.e. two numbers zero and one. Among them, one is repeating and the other is missing. It’s time to identify them. 
>       We will traverse the entire array and check how many times variable zero appears. 
>       If it appears twice, it will be the repeating number, otherwise, it will be the missing. Now, based on variable zero’s identity, we can easily identify in which category, variable one belongs.

   Complexity Analysis:-
  # Time Complexity: O(N), where N = the size of the given array.
    Reason: We are just using some loops running for N times. So, the time complexity will be approximately O(N).
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
//vector<int> findMissingRepeatingNumbers_4(vector<int> ar4) {

//}








int main() {

// Soln 1: Brute(Naive)
    vector<int> ar1 = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans1 = findMissingRepeatingNumbers_1(ar1);
    cout << "The repeating and missing numbers are: {" << ans1[0] << ", " << ans1[1] << "}\n" ;



// Soln 2: Better(using Hashing(hasharray))
    vector<int> ar2 = {4, 3, 6, 2, 1, 1};
    vector<int> ans2 = findMissingRepeatingNumbers_2(ar2);
    cout << "The repeating and missing numbers are: {" << ans2[0] << ", " << ans2[1] << "}\n";



// Soln 3.1: Optimal(using Maths)
    vector<int> ar = {4, 3, 6, 2, 1, 1};
    vector<int> ans3 = findMissingRepeatingNumbers_3(ar);
    cout << "The repeating and missing numbers are: {" << ans3[0] << ", " << ans3[1] << "}\n";



// Soln 3.2: Optimal(using XOR)







    return 0;
}

