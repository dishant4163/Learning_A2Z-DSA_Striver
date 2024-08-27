/*(Find Peak Element_Coding Ninja)-> https://bit.ly/3BEDvZC     

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}


*/
/*  What is a peak element?
    A peak element in an array refers to the element that is greater than both of its neighbors. Basically, if arr[i] is the peak element, arr[i] > arr[i-1] and arr[i] > arr[i+1].
*/


/* Problem Statement: 
 Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity.

Pre-requisite: Binary Search Algorithm

Examples:
Example 1: Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
 Result: 7
 Explanation: In this example, there is only 1 peak that is at index 7.

Example 2: Input Format: arr[] = {1,2,1,3,5,6,4}
 Result: 1
 Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)  
   Intuition: A simple approach involves iterating through the array and checking specific conditions for each element to determine the peak. By considering all the necessary conditions, including edge cases, our final condition can be summarized as follows:
 If ((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])), we have found a peak. In such cases, we can return the index of the element satisfying this condition.


   Algorithm:
  #  We will start traversing the array and for every index, we will check the below condition.
  #  If((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])): whenever this condition is true for an element, we should return its index.
also update the 'index' variable with the corresponding index value, 'i'.
  # Finally, we will return ‘index’ as our answer.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array.
    Reason: We are traversing the entire array.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int findPeakElement_1(vector<int> &ar1) {
    int n1= ar1.size();
    for (int i=0; i<n1; i++) {
        //Checking for the peak:
        if ((i == 0 || ar1[i-1] < ar1[i]) && (i == n1-1 || ar1[i] > ar1[i+1]) ) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}





/*// Soln 2: Optimal(using BS)    
   Algorithm: The final steps will be as follows:

Note: At the start of the algorithm, we address the edge cases of identifying the peak element without requiring separate conditions during the check for arr[mid] inside the loop. And the search space will be from index 1 to n-2 as indices 0 and n-1 have already been checked in the edge cases.

  #  If n == 1: This means the array size is 1. If the array contains only one element, we will return that index i.e. 0.
  #  If arr[0] > arr[1]: This means the very first element of the array is the peak element. So, we will return the index 0.
  #  If arr[n-1] > arr[n-2]: This means the last element of the array is the peak element. So, we will return the index n-1.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Check if arr[mid] is the peak element:
    If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the peak element. We will return the index ‘mid’.
  #  If arr[mid] > arr[mid-1]: This means we are in the left half and we should eliminate it as our peak element appears on the right. So, we will do this:
    low = mid+1.
  #  Otherwise, we are in the right half and we should eliminate it as our peak element appears on the left. So, we will do this: high = mid-1. This case also handles the case for the index ‘mid’ being a common point of a decreasing and increasing sequence. It will consider the left peak and eliminate the right peak.


   Complexity Analysis:-
  #Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using binary search to find the minimum.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int findPeakElement(vector<int> &arr) {
    int n=arr.size();

    // Edge cases
    if (n==1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n-1] > arr[n-2]) return (n-1);

    int low = 1, high = n-2;
    while(low <= high) {
        int mid = low + (high - low)/2;

        //If arr[mid] is the peak:
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        }
        // If we are in the right:
        // Or, arr[mid] is a common point:
        else {
            high = mid - 1;
        }
    }

    return -1;
}






int main() {

// Soln 1: Brute Force(Naive_Linear Iteration) 
    vector<int> ar1 = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int sol = findPeakElement_1(ar1);
    cout<<"The peak is at the index: "<<sol<<endl;



// Soln 2: Optimal(using Binary Search)
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << endl;




    return 0;
}
