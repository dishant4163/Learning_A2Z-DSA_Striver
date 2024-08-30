/*(Split Array-Largest Sum_Coding Ninja)-> https://bit.ly/3OiMPKa  



*/


/* Problem Statement: 
 Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
  A subarray is a contiguous part of the array.

 Pre-requisite: BS-18. Allocate Books or Book Allocation | Hard Binary Search


   Examples
Example 1:
 Input Format: N = 5, a[] = {1,2,3,4,5}, k = 3
 Result: 6
 Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

Example 2:
 Input Format: N = 3, a[] = {3,5,1}, k = 3
 Result: 5
 Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)   
 Intuition:- The extremely naive approach is to check all possible answers from max(arr[]) to sum(arr[]). The minimum value for which we can make k subarrays will be our answer.

   Algorithm:-
  #  First, we will find the maximum element and the summation of the given array.
  #  We will use a loop(say maxSum) to check all possible answers from max(arr[]) to sum(arr[]).
  #  Next, inside the loop, we will send ‘maxSum’, to the function countPartitions() function to get the number of partitions.
        The first value of ‘maxSum’, for which the number of partitions will be equal to ‘k’, will be our answer. So, we will return that particular value of ‘maxSum’.
  #  Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.

   Complexity Analysis:
  #  TimeComplexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPartitions() function for each number. Now, inside the countPartitions() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/





/*// Soln 2: Optimal(BS)
 Intuition:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Upon closer observation, we can recognize that our answer space, represented as [max(arr[]), sum(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.


   Algorithm:
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the number of subarrays returned by countPartitions():
  #  We will pass the potential value of ‘maxSum’, represented by the variable 'mid', to the ‘countPartitions()' function. This function will return the number of partitions we can make.
        If partitions > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.


   Complexity Analysis:
  # Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPartitions() function for the value of ‘mid’. Now, inside the countPartitions() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/







int main() {


    return 0;
}
