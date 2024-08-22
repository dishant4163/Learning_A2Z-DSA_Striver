/*(Merge Overlapping Sub-intervals_Coding Ninja)-> href="https://bit.ly/3pAeTyp"    



*/


/* Problem Statement: 
Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

   Example 1:
 Input:- intervals=[[1,3],[2,6],[8,10],[15,18]]
 Output:- [[1,6],[8,10],[15,18]]
 Explanation:- Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
   Approach:- The steps are as follows:
  #  First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
  #  After that, we will select one interval at a time using a loop(say i) and insert it into our answer list(if the answer list is empty or the current interval cannot be merged with the last interval of the answer list). While traversing and inserting we will skip the intervals that lie in the last inserted interval of our answer list.
  #  Now, for each interval arr[i], using another loop (say j) we are going to check the rest of the intervals(i.e. From index i+1 to n-1) if they can be merged with the selected interval.
  #  Inside loop j, we will continue to merge all the intervals that lie in the selected interval. 
>        How to check if the current interval can be merged with the selected interval:
#        We will compare the current interval’s start with the end of the selected interval. If the start is smaller or equal to the end, we can conclude the current interval can be a part of the selected interval. So, we will update the selected interval’s end with the maximum(current interval’s end, selected interval’s end) in the answer list(not in the original array).
  #  We will break out of loop j, from the first element that cannot be a part of the selected interval.
>        How to check if the current interval is not a part of the selected interval:
#        We will compare the current interval’s start with the end of the selected interval. If the start is greater than the end, we can conclude the current interval cannot be a part of the selected interval.
  #  Finally, we will return the answer list.

   Intuition:- The intuition of this approach is pretty straightforward. We are just grouping close intervals by sorting the given array. After that, we merge an interval with the other by checking if one can be a part of the other interval. For this checking, we are first selecting a particular interval using a loop and then we are comparing the rest of the intervals using another loop.

   Complexity Analysis:-
  # Time Complexity:- O(N*logN) + O(2*N), where N = the size of the given array.
    Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N^2.
  # Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/





/*// Soln 2: Optimal
   Intuition:In the previous approach, while checking the intervals, we first selected an interval using a loop and then compared it with others using another loop. But in this approach, we will try to do the same using a single loop. Let’s understand how:

We will start traversing the given array with a single loop. At the first index, as our answer list is empty, we will insert the first element into the answer list. While traversing afterward we can find two different cases:

-> Case 1: If the current interval can be merged with the last inserted interval of the answer list:
In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 

-> Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.

*** Note: Within the previous approach, we have already discussed how to check if the current interval can or cannot be merged with the other interval.


   Approach:

The steps are as follows:

  #  First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
  #  After that, we will start traversing the array using a loop(say i) and insert the first element into our answer list(as the answer list is empty).
  #  Now, while traversing we will face two different cases:
>        Case 1: If the current interval can be merged with the last inserted interval of the answer list:
        In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward. 
>        Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
        In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
  #  Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.

   Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.

   Complexity Analysis:-
  # Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
    Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
  # Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/









int main() {

// Soln 1: Brute 



// Soln 2: Optimal





    return 0;
}
