/*(Painter's Partition Problem_Coding Ninja)-> https://bit.ly/3XM8oFS   



*/


/* Problem Statement: 
 Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

 Pre-requisite: BS-18. Allocate Books or Book Allocation | Hard Binary Search

   Examples:

Example 1:
 Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
 Result: 10
 Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
 Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
 Result: 60
 Explanation: We can divide the first 3 boards for one painter and the last board for the second painter.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(using Naive)   
 Intuition:- The extremely naive approach is to check all possible answers from max(arr[]) to sum(arr[]). The minimum time for which we can paint all the boards will be our answer.


   Algorithm:-
  # First, we will find the maximum element and the summation of the given array.
  #  We will use a loop(say time) to check all possible answers from max(arr[]) to sum(arr[]).
  #  Next, inside the loop, we will send ‘time’, to the function countPainters() function to get the number of painters to whom we can allocate the boards.
        The first value of ‘time’, for which the number of painters will be lesser or equal to ‘k’, will be our answer. So, we will return that particular value of ‘time’.
  #  Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.


   Complexity Analysis:
  # Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPainters() function for each number. Now, inside the countPainters() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/





/*// Soln 2: Optimal(BS)
 Intuition- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Upon closer observation, we can recognize that our answer space, represented as [max(arr[]), sum(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

   Algorithm:-
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the number of painters returned by countPainters():
  #  We will pass the potential value of time, represented by the variable 'mid', to the ‘countPainters()' function. This function will return the number of painters we need to paint all the boards.
        If painters > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
 The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.

   Complexity Analysis:
  # Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPainters() function for the value of ‘mid’. Now, inside the countPainters() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/








int main() {

// Soln 1: Brute Force



// Soln 2: Optimal




    return 0;
}
