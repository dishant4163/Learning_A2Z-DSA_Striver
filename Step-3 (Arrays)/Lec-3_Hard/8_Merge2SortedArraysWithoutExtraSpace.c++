/*(Merge two Sorted Arrays Without Extra Space_Coding Ninja)->    



*/


/* Problem statement: 
 Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

   Example:
  # Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 3, arr2[] = [2 3 9]

Output: arr1[] = [1 2 3 4]  arr2[] = [8 9 10]

  # Explanation:- After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive) 
   Intuition:- Intuition is pretty straightforward. As the given arrays are sorted, we are using 2 pointer approach to get a third array, that contains all the elements from the given two arrays in the sorted order. Now, from the sorted third array, we are again filling back the given two arrays.

   Approach:- The steps are as follows:
Assume the size of the given arrays are n and m.

  #  We will first declare a third array, arr3[] of size n+m, and two pointers i.e. left and right, one pointing to the first index of arr1[] and the other pointing to the first index of arr2[].
  #  The two pointers will move like the following:
>       If arr1[left] < arr2[right]: We will insert the element arr1[left] into the array and increase the left pointer by 1.
>       If arr2[right] < arr1[left]: We will insert the element arr2[right] into the array and increase the right pointer by 1.
>       If arr1[left] == arr2[right]: Insert any of the elements and increase that particular pointer by 1.
>       If one of the pointers reaches the end, then we will only move the other pointer and insert the rest of the elements of that particular array into the third array i.e. arr3[].
  #  If we move the pointer like the above, we will get the third array in the sorted order.
  #  Now, from sorted array arr3[], we will copy first n(size of arr1[]) elements to arr1[], and the next m(size of arr2[]) elements to arr2[].

   Complexity Analysis:-
  # Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
    Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for filling back the two given arrays from arr3[].
  # Space Complexity: O(n+m) as we use an extra array of size n+m.
*/





/*// Soln 2.1: Optimal(without using any extra space)
   Intuition:- If we merge the given array, one thing we can assure is that arr1[] will contain all the smaller elements and arr2[] will contain all the bigger elements. This is the logic we will use. Using the 2 pointers, we will swap the bigger elements of arr1[] with the smaller elements of arr2[] until the minimum of arr2[] becomes greater or equal to the maximum of arr1[].

   Approach:- The steps are as follows:  
The sizes of the given arrays are n(size of arr1[]) and m(size of arr2[]).

  #  We will declare two pointers i.e. left and right. The left pointer will point to the last index of the arr1[](i.e. Basically the maximum element of the array). The right pointer will point to the first index of the arr2[](i.e. Basically the minimum element of the array).
  #  Now, the left pointer will move toward index 0 and the right pointer will move towards the index m-1. While moving the two pointers we will face 2 different cases like the following:
>       If arr1[left] > arr2[right]: In this case, we will swap the elements and move the pointers to the next positions.
>       If arr1[left] <= arr2[right]: In this case, we will stop moving the pointers as arr1[] and arr2[] are containing correct elements.
  #  Thus, after step 2, arr1[] will contain all smaller elements and arr2[] will contain all bigger elements. Finally, we will sort the two arrays.

   Complexity Analysis:-
  # Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
    Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
  # Space Complexity: O(1) as we are not using any extra space.
*/





/*// Soln 2.2:  
   Intuition:- Similar to optimal approach 1, in this approach, we will use two pointers i.e. left and right, and swap the elements if the element at the left pointer is greater than the element at the right pointer. 

 > But the placing of the pointers will be based on the gap value calculated. The formula to calculate the initial gap is the following:

Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

 > Assume the two arrays as a single continuous array and initially, we will place the left pointer at the first index and the right pointer at the (left+gap) index of that continuous array.

 > Now, we will compare the elements at the left and right pointers and move them by 1 place each time after comparison. While comparing we will swap the elements if the element at the left pointer > the element at the right pointer. After some steps, the right pointer will reach the end and the iteration will be stopped.

 > After each iteration, we will decrease the gap and will follow the same procedure until the iteration for gap = 1 gets completed. Now, after each iteration, the gap will be the following:

gap = ceil( previous gap / 2)

 > The whole process will be applied to the imaginary continuous array constructed using arr1[] and arr2[].

   Approach:- The steps are as follows:

  #  First, assume the two arrays as a single array and calculate the gap value i.e. ceil((size of arr1[] + size of arr2[]) / 2).
  #  We will perform the following operations for each gap until the value of the gap becomes 0:
>       Place two pointers in their correct position like the left pointer at index 0 and the right pointer at index (left+gap).
>       Again we will run a loop until the right pointer reaches the end i.e. (n+m). Inside the loop, there will be 3 different cases:
->          If the left pointer is inside arr1[] and the right pointer is in arr2[]: We will compare arr1[left] and arr2[right-n] and swap them if arr1[left] > arr2[right-n].
->          If both the pointers are in arr2[]: We will compare arr1[left-n] and arr2[right-n] and swap them if arr1[left-n] > arr2[right-n].
->          If both the pointers are in arr1[]: We will compare arr1[left] and arr2[right] and swap them if arr1[left] > arr2[right].
>       After the right pointer reaches the end, we will decrease the value of the gap and it will become ceil(current gap / 2). 
  #  Finally, after performing all the operations, we will get the merged sorted array.

   Complexity Analysis:-
  # Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
    Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).
  # Space Complexity: O(1) as we are not using any extra space.
*/ 








int main(){

// Soln 1:



// Soln 2.1:



// Soln 2.2:




    return 0;
}
