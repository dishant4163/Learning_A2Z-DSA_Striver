/*(Find out how many times the array has been rotated_Coding Ninja)-> https://bit.ly/3MsMNOG     

#include<bits/stdc++.h>

int findKRotation(vector<int> &arr){
    // Write your code here.    
    int low=0, high= arr.size()-1;
    int ans = INT_MAX;
    int index = -1;

    while(low <= high) {
        int mid= low + (high-low)/2;

        if (arr[low] <= arr[high]) {
            if(arr[low] < ans){
                index=low;
                ans=arr[low];
            }
        }

        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index=low;
                ans=arr[low];
            }
            low = mid+1;
        }
        else {
            high = mid - 1;
            if(arr[mid] < ans){
                index=mid;
                ans=arr[mid];
            }
        }
    }
    return index;
}

*/

/* Problem Statement: 
 Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

 Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm


   Examples
Example 1:
 Input Format: arr = [4,5,6,7,0,1,2,3]
 Result: 4
 Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Example 2:
 Input Format: arr = [3,4,5,1,2]
 Result: 3
 Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.
*/


#include<bits/stdc++.h>
using namespace std;
// Observation: 
// We can easily observe that the number of rotations in an array is equal to the index(0-based index) of its minimum element.
// So, in order to solve this problem, we have to find the index of the minimum element.

/*// Soln1: Brute Force    
   Algorithm:
  #  First, we will declare an ‘ans’ and an ‘index’ variable initialized with a large number and -1 respectively.
  #  Next, we will iterate through the array and compare each element with the variable called ‘ans’. Whenever we encounter an element 'arr[i]' that is smaller than ‘ans’, we will update ‘ans’ with the value of 'arr[i]' and also update the 'index' variable with the corresponding index value, 'i'.
  #  Finally, we will return ‘index’ as our answer.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array.
    Reason: We have to iterate through the entire array to check if the target is present in the array.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int findKRotation_1(vector<int> &ar1) {
    int n1 = ar1.size();
    int sol = INT_MAX, index = -1;

    for(int i=0; i<n1; i++) {
        if(ar1[i] < sol) {
            sol = ar1[i];
            index = i;
        }
    }
    return index;
}





/*// Soln 2: Optimal   
   Algorithm:- The steps are as follows:
 To begin, we will declare the variable 'ans' and initialize it with the largest possible value. Additionally, we will have two pointers, 'low' and 'high', as usual. In this case, we will also introduce an 'index' variable and initialize it with -1.

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  If arr[low] <= arr[high]: In this case, the array from index low to high is completely sorted. Therefore, we can select the minimum element, arr[low].
  #  Now, if arr[low] < ans, we will update ‘ans’ with the value arr[low] and ‘index’ with the corresponding index low.
  #  Once this is done, there is no need to continue with the binary search algorithm. So, we will break from this step.
  #  Identify the sorted half, and after picking the leftmost element, eliminate that half.
        If arr[low] <= arr[mid]:
        This condition ensures that the left part is sorted. So, we will pick the leftmost element i.e. arr[low].
        Now, if arr[low] < ans, we will update ‘ans’ with the value arr[low] and ‘index’ with the corresponding index low.
        After that, we will eliminate this left half(i.e. low = mid+1).
        Otherwise, if the right half is sorted:  This condition ensures that the right half is sorted. So, we will pick the leftmost element i.e. arr[mid].
        Now, if arr[mid] < ans, we will update ‘ans’ with the value arr[mid] and ‘index’ with the corresponding index mid.
        After that, we will eliminate this right half(i.e. high = mid-1).
  #  This process will be inside a loop and the loop will continue until low crosses high. Finally, we will return the ‘index’ variable that stores the index of the minimum element.

   Complexity Analysis

  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using binary search to find the minimum.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int findKRotation(vector<int>&ar) {
    int n = ar.size();
    int low = 0, high=n-1;
    int ans = INT_MAX, index=-1;

    while(low <= high) {
        int mid = low + (high - low)/2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (ar[low] <= ar[high]) {
            if (ar[low] < ans) {
                index = low;
                ans = ar[low];
            }
            break;
        }

        //if left part is sorted:
        if (ar[low] <= ar[mid]) {
            // keep the minimum:
            if (ar[low] < ans) {
                index = low;
                ans = ar[low];
            }
            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:
            // keep the minimum:
            if (ar[mid] < ans) {
                index = mid;
                ans = ar[mid];
            }
            // Eliminate right half:
            high = mid - 1;
        }
    }

    return index;
}






int main (){

// Soln 1:Brute Force(Linear Search)
    vector<int> ar1 = {4, 5, 1, 2, 3};
    int sol = findKRotation_1(ar1);
    cout<<"The array is rotated "<<sol<<" times." <<endl;



// Soln 2: Optimal(using Binary Search)
    vector<int> ar = {6, 7, 8, 9, 1 ,2, 3, 4, 5};
    int ans = findKRotation(ar);
    cout<<"The array is rotated "<<ans<<" times."<<endl;




    return 0;
}
