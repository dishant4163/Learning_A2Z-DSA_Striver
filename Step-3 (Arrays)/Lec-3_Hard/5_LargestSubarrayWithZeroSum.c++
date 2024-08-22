// Before doing this problem revise Kadane's Algo(4 generating subarray)
// & then Check the Lec-1_Eassy->14th problem

/*(Largest Subarray with Zero Sum_Coding Ninja)-> https://bit.ly/42OqnNq    



*/


/* Problem Statement: 
Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Example 1:

   Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
   Result: 5
  Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive approach)
   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
  #  If the sum equals k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.

   Intuition:- We will check the sum of every possible subarray and consider the one with the sum k and the maximum length among them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all the subarrays with sum k, we will consider the one with the maximum length.

->   Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

   Complexity Analysis:-
  # Time Complexity: O(N^3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

  # Space Complexity: O(1) as we are not using any extra space.
*/
/*int getLongestZeroSumSubarrayLength_1(vector<int> &arr) {
    int n1 = arr.size();
    int maxLen = 0;

    for (int i = 0; i<n1; i++) {
        for (int j = i; j < n1; j++) {
            int sum1 = 0;
            for (int k=i; k <= j; k++) {
                sum1 += arr[k];
            }

            if (sum1 == 0) maxLen = max(maxLen, j-i+1);
        }
    }


    return maxLen;
}
*/




/*// Soln 2: Better_Optimizing Naive Approach(Using two loops)
   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. 
  #  If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays with sum k, we will consider the one with the maximum length by comparing all the lengths.

   Intuition:- If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

->   Assume previous subarray = arr[i……j-1]
->   current subarray = arr[i…..j]
->   Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

->   This is how we can remove the third loop and while moving the j pointer, we can calculate the sum.

   Complexity Analysis:-
  # Time Complexity: O(N^2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.
  Space Complexity: O(1) as we are not using any extra space.
*/
/*int getLongestZeroSumSubarrayLength_2(vector<int> &ar2){
    int n2 = ar2.size();
    int maxLen2 = 0;

    for (int i = 0; i<n2; i++) {
        int sum2 = 0;
        for (int j=i; j<n2; j++) {
            sum2 += ar2[j];

            if (sum2 == 0) maxLen2 = max(maxLen2, j-i+1);
        }
    }

    return maxLen2;
}
*/




/*// Soln 3: Optimal Approach(Using Hashing)
   Intuition:-
   Now let’s say we know that the sum of subarray(i, j) = S, and we also know that the sum of subarray(i, x) = S where i < x < j. We can conclude that the sum of subarray(x+1, j) = 0.

Let us understand the above statement clearly,

So in this problem, we’ll store the prefix sum of every element, and if we observe that 2 elements have the same prefix sum, we can conclude that the 2nd part of this subarray sums to zero.

   Approach: 
  #  First, let us initialize a variable say sum = 0 which stores the sum of elements traversed so far and another variable says max = 0 which stores the length of the longest subarray with sum zero.
  #  Declare a HashMap<Integer, Integer> which stores the prefix sum of every element as a key and its index as a value.
  #  Now traverse the array, and add the array element to our sum. 
    (i)  If sum = 0, then we can say that the subarray until the current index has a sum = 0,      so we update max with the maximum value of (max, current_index+1)
    (ii)  If the sum is not equal to zero then we check the hashmap if we’ve seen a subarray with this sum before
<->  if HashMap contains sum -> this is where the above-discussed case occurs (subarray with equal sum), so we update our max 
<->  else -> Insert (sum, current_index) into hashmap to store prefix sum until the current index

  #     After traversing the entire array our max variable has the length of the longest substring having a sum equal to zero, so return max.

*** NOTE: we do not update the index of a sum if it’s seen again because we require the length of the longest subarray.

   Complexity Analysis:-
  # Time Complexity: O(N), as we are traversing the array only once.
  # Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
*/
/*int getLongestZeroSumSubarrayLength_3(vector<int> &arr) {
    int n = arr.size();

    unordered_map<int, int> preSumMap;
    int maxLen3 = 0;
    int sum3 = 0;

    for (int i=0; i < n; i++) {
        sum3 += arr[i];
        if (sum3 == 0) {
            maxLen3 = i+1;
        }
        else {
            if (preSumMap.find(sum3) != preSumMap.end()) {
                maxLen3 = max(maxLen3, i-preSumMap[sum3]);
            }
            else {
                preSumMap[sum3] = i;
            }
        }
    }

    return maxLen3;
}
*/




int main () {

/*// Soln 1: Brute Force(Naive-3 loops)
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int maxLen = getLongestZeroSumSubarrayLength_1(arr);
    cout << "The length of the Longest Subarray with Zero Sum is: "<<maxLen<<endl;
*/


/*// Soln 2: Better(using 2 loops)
    vector<int> ar2 = {9, -3, 3, -1, 6, 1, -5, -1};
    int maxLen2 = getLongestZeroSumSubarrayLength_2(ar2);
    cout << "The length of the Longest Subarray with Zero Sum is: "<<maxLen2<<endl;
*/


/*// Soln 3: Optimal
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    int maxLen3 = getLongestZeroSumSubarrayLength_3(arr);
    cout << "The length of the Longest Subarray with Zero Sum is: "<<maxLen3<<endl;
*/



    return 0;
}

