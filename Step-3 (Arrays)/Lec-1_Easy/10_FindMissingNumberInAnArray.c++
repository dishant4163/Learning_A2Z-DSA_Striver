/*// (Find the missing number in an array_Coding Ninja)-> https://bit.ly/42VPspr

int missingNumber(vector<int>&a, int N) {
    // Write your code here.
    int xor1 = 0, xor2 = 0;

    for (int i=0; i<N-1; i++) {
        xor1 = xor1 ^ a[i];
        xor2 = xor2 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Find the Missing Number in an Array
/*// Soln 1. Naive Approach(Brute-force approach)
  Intuition:- For each number between 1 to N, we will try to find it in the given array using linear search. And if we don’t find any of them, we will return the number.

  Approach:- The algorithm steps are as follows:

  #  We will run a loop(say i) from 1 to N.
  #  For each integer, i, we will try to find it in the given array using linear search.
    -> For that, we will run another loop to iterate over the array and consider a flag variable to indicate if the element exists in the array. Flag = 1 means the element is present and flag = 0 means the element is missing.
    -> Initially, the flag value will be set to 0. While iterating the array, if we find the element, we will set the flag to 1 and break out from the loop.
Now, for any number i, if we cannot find it, the flag will remain 0 even after iterating the whole array and we will return the number.

  Complexity Analysis:-
  # Time Complexity: O(N2), where N = size of the array+1.
Reason: In the worst case i.e. if the missing number is N itself, the outer loop will run for N times, and for every single number the inner loop will also run for approximately N times. So, the total time complexity will be O(N2).

  # Space Complexity: O(1)  as we are not using any extra space.
*/
int missingNum1(vector<int> &ar1, int N1) {
    // Outer Loop that runs from 1 to N1
    for(int i=1; i<=N1; i++) {

        //flag variable to check if an element exists
        int flag1=0;
        // Search the Element using Linear Search
        for (int j=0; j<N1 - 1; j++) {
            if (ar1[j] == i) {
                // i is present in the array:
                flag1 = 1;
                break;
            }
        }
        // check if the element is missing (i.e flag == 0)
        if (flag1 == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}






/*// Soln 2. Better Approach (using Hashing)
  Intuition:- Using the hashing technique, we will store the frequency of each element of the given array. Now, the number( i.e. between 1 to N) for which the frequency will be 0, will be returned.

  Approach:- The algorithm steps are as follows:

  #  The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency of N as well).
  #  Now, for each element in the given array, we will store the frequency in the hash array.
  #  After that, for each number between 1 to N, we will check the frequencies. And for any number, if the frequency is 0, we will return it.

  Complexity Analysis:-
  # O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for checking the frequencies in the second step again O(N) is required. So, the total time complexity is O(N) + O(N).

  # Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
*/
int missingNum2(vector<int> &ar2, int N2) {
    // Hash Array
    int hash[N2 + 1] = {0};

    // Sorting the Frequencies:
    for (int i=0; i < N2-1; i++) {
        hash[ar2[i]]++;
    }

    // Checking the Frequencies for Number 1 to N:
    for (int i=1; i <= N2; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

     // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}






/*// Soln 3.1 . Optimal Soln (using Summation Approach)
   Intuition:- We know that the summation of the first N numbers is (N*(N+1))/2. We can say this S1. Now, in the given array, every number between 1 to N except one number is present. So, if we add the numbers of the array (say S2), the difference between S1 and S2 will be the missing number. Because, while adding all the numbers of the array, we did not add that particular number that is missing.

->      Sum of first N numbers(S1) = (N*(N+1))/2
->      Sum of all array elements(S2) = i = 0n-2a[i]
->      The missing number = S1-S2

   Approach:- The steps are as follows:

  # We will first calculate the summation of first N natural numbers(i.e. 1 to N) using the specified formula.
  # Then we will add all the array elements using a loop.
  # Finally, we will consider the difference between the summation of the first N natural numbers and the sum of the array elements.

   Complexity Analysis:-
   # Time Complexity: O(N), where N = size of array+1.
Reason: Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N times. So, the time complexity is O(N).
   # Space Complexity: O(1) as we are not using any extra space.
*/
int missingNum3(vector<int> &ar3, int m) {

    // SUMMATION of First N numbers:
    int sumN = (m * (m+1)) / 2;

    // SUMMATION of all ARRAY Elements
    int sum2 = 0;
    for (int i=0; i < m -1; i++) {
        sum2 += ar3[i];
    }

    int missingNum3 = sumN - sum2;
    return missingNum3;
}






/*// Soln 3.2 . Optimal Soln (using XOR)
   Intuition:- Two important properties of XOR are the following:

 ->  XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
 _>  XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

 ->  Now, let’s XOR all the numbers between 1 to N.
xor1 = 1^2^.......^N

 ->  Let’s XOR all the numbers in the given array.
xor2 = 1^2^......^N (contains all the numbers except the missing one).

 ->  Now, if we again perform XOR between xor1 and xor2, we will get:
xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N)

 ->  Here all the numbers except the missing number will form a pair and each pair will result in 0 according to the XOR property. The result will be = 0 ^ (missing number) = missing number (according to property 2).

So, if we perform the XOR of the numbers 1 to N with the XOR of the array elements, we will be left with the missing number.


   Approach:- The steps are as follows:
  #  We will first run a loop(say i) from 0 to N-2(as the length of the array = N-1).
  #  Inside the loop, xor2 variable will calculate the XOR of array elements i.e. xor2 = xor2 ^ a[i]. And the xor1 variable will calculate the XOR of 1 to N-1 i.e. xor1 = xor1 ^ (i+1).
  #  After the loop ends we will XOR xor1 and N to get the total XOR of 1 to N.
  #  Finally, the answer will be the XOR of xor1 and xor2.


   Complexity Analysis:-
  # Time Complexity: O(N), where N = size of array+1.
Reason: Here, we need only 1 loop to calculate the XOR. The loop runs for approx. N times. So, the time complexity is O(N).
  # Space Complexity: O(1) as we are not using any extra space.
*/
int missingNum4(vector<int> &ar4, int n) {
    int xor1 = 0, xor2 = 0;

    for (int i=0; i < n-1; i++) {
        xor2 = xor2 ^ ar4[i]; // XOR of Array Elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1... n-1]
    }

    xor1 = xor1 ^ n; // XOR up to [1...n]

    return (xor1 ^ xor2); // the missing number
}






int main(){

// Soln 1: Brute Force
    int N1 = 5;
    vector<int> ar1 = {1, 2, 4, 5};
    int ans1 = missingNum1(ar1, N1);
    cout<< "Missing number is " << ans1 << endl;



// Soln 2: Better 
    int N2 = 5;
    vector<int> ar2 = {1, 2, 4, 5};
    int ans2 = missingNum2(ar2, N2);
    cout<< "Missing Number is " << ans2 << endl;



// Soln 3.1: Optimal(Sum Appraoch)
    int m = 5;
    vector<int> ar3 = {1, 2, 4, 5};
    int ans3 = missingNum3(ar3, m);
    cout << "Missing Number is " << ans3 << endl;



// Soln 3.2: Optimal(using XOR)
// XOR is slight best then the sum bcz it can take '10^5' for more big use 'long'
    int n = 5;
    vector<int> ar4 = {1, 2, 4, 5};
    int ans4 = missingNum4(ar4, n);
    cout<<"Missing Number is " << ans4 <<endl;



    return 0;
}
