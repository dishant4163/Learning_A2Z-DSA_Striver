/*(Search Element in Rotated Sorted Array-i_Coding Ninja)-> https://bit.ly/3OmIp5d  

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low=0, high=n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == k) return mid;

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


*/

/* Problem Statement(unique elements): 
  Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

    Examples
   Example 1:
 Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
 Result: 4
 Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

   Example 2:
 Input Format: arr = [4,5,6,7,0,1,2], k = 3
 Result: -1
 Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(using Linear Search)   
   Intuition:- One straightforward approach we can consider is using the linear search algorithm. Using this method, we will traverse the array to find the location of the target value. If it is found we will simply return the index and otherwise, we will return -1.

   Algorithm:-
  #  We will traverse the array and check every element if it is equal to k. If we find any element, we will return its index.
  #  Otherwise, we will return -1.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array.
    Reason: We have to iterate through the entire array to check if the target is present in the array.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int LinearSearch(vector<int>&ar, int n, int k) {
    for (int i=0; i<n; i++) {
        if (ar[i] == k) {
            return i;
        }
    }
    return -1;
}





/*// Soln 2: Optimal(using Binary Search)   
   Algorithm:
The steps are as follows:
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Check if arr[mid] == target: If it is, return the index mid.
  #  Identify the sorted half, check where the target is located, and then eliminate one half accordingly:
>        If arr[low] <= arr[mid]: This condition ensures that the left part is sorted.
->            If arr[low] <= target && target <= arr[mid]: It signifies that the target is in this sorted half. So, we will eliminate the right half (high = mid-1).
->            Otherwise, the target does not exist in the sorted half. So, we will eliminate this left half by doing low = mid+1.
>        Otherwise, if the right half is sorted:
->            If arr[mid] <= target && target <= arr[high]: It signifies that the target is in this sorted right half. So, we will eliminate the left half (low = mid+1).
->            Otherwise, the target does not exist in this sorted half. So, we will eliminate this right half by doing high = mid-1.
  #  Once, the ‘mid’ points to the target, the index will be returned.
  #  This process will be inside a loop and the loop will continue until low crosses high. If no index is found, we will return -1.


    Key Observation: Though the array is rotated, we can clearly notice that for every index, one of the 2 halves will always be sorted. 
So, to efficiently search for a target value using this observation, we will follow a simple two-step process. 
  #  First, we identify the sorted half of the array. 
  #  Once found, we determine if the target is located within this sorted half. 
->      If not, we eliminate that half from further consideration. 
->      Conversely, if the target does exist in the sorted half, we eliminate the other half.

   Complexity Analysis:-
  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are using binary search to search the target.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int search(vector<int>&arr, int n, int x) {
    int low=0, high=n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;

        // If mid points the target:
        if(arr[mid] == x) return mid;

        //If left part is sorted:
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= x && x <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }

        //If Right part is sorted:
        else {
            if (arr[mid] <= x && x <= arr[high]) {
                //element exist:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}






int main() {

// Soln 1: Brute Force(using Linear Search)
    vector<int> ar = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n=9, k=1;
    int sol = LinearSearch(ar, n, k);
    if(sol == -1) {
        cout <<"Target is not present in the given array."<<endl;
    }
    else {
        cout <<"Target = " <<k<< ", present at the "<<sol<<"th index in the given array."<<endl;
    }



// Soln 2: Optimal(using Binary Search)
    vector<int> ar = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n=9, x=2;
    int ans = search(ar, n, x);
    if(ans == -1) {
        cout <<"Target is not present in the given array."<<endl;
    }
    else {
        cout <<"Target = " <<x<< ", present at the "<<ans<<"th index in the given array."<<endl;
    }





    return 0;
}