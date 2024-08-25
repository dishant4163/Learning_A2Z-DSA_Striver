/*(Binary Search: Find X in sorted array _Coding Ninja)-> https://bit.ly/41wXCne   

//using Recursive Method
int bS(vector<int> &nums, int low, int high, int target) {
    
    if (low > high) return -1;

    int mid = low + (high-low) / 2;

    if (nums[mid] == target) return mid;
    else if(target > nums[mid]) {
        return bS(nums, mid+1, high, target);
    }
    else {
        return bS(nums, low, mid-1, target);
    }
}

int search(vector<int> &nums, int target) {
    // Write your code here.
    return bS(nums, 0, nums.size()-1, target);
}

*/


/* Problem statement:
   You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.
*/
/* Note:
  #  Binary search is only applicable in a sorted search space. The sorted search space does not necessarily have to be a sorted array. It can be anything but the search space must be sorted.
  #  In binary search, we generally divide the search space into two equal halves and then try to locate which half contains the target. According to that, we shrink the search space size.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Iterative Implementation:  
   Algorithm:

Now, we will apply the binary search algorithm in the given array:

  #  Step 1: Divide the search space into 2 halves:
  #  In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Step 2: Compare the middle element with the target:
  #  In this step, we can observe 3 different cases:
    #   If arr[mid] == target: We have found the target. From this step, we can return the index of the target possibly.
    #   If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next search space will be the right half.
    #   If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next search space will be the left half.
  #  Step 3: Trim down the search space:
  #  Based on the probable location of the target we will trim down the search space.
    #   If the target occurs on the left, we should set the high pointer to mid-1. Thus the left half will be the next search space.
    #   Similarly, if the target occurs on the right, we should set the low pointer to mid+1. Thus the right half will be the next search space.

The above steps will continue until either we found the target or the search space becomes invalid i.e. high < low. By definition of search space, it will lose its existence if the high pointer is appearing before the low pointer.

   Complexity Analysis:-
  # Time Complexity: In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

  # So the overall time complexity is O(logN), where N = size of the given array.
*/
/*int binarySearch(vector<int>&nums, int target1) {
    int n1 = nums.size();
    int low = 0, high = n1 - 1;

    //Perform the steps:
    while(low <= high) {
        int mid1 = low + (high - low) / 2;
        if (nums[mid1] == target1) return mid1;
        else if (target1 > nums[mid1]) return low = mid1 + 1;
        else high = mid1 - 1;
    }
    return -1;
}
*/




/*// Recursive implementation:   
   Approach: Assume, the recursive function will look like this: binarySearch(nums, low, high). It basically takes 3 parameters i.e. the array, the low pointer, and the high pointer. In each recursive call, we will change the value of low and high pointers to trim down the search space. Except for this, the rest of the steps will be the same.

The steps are as follows:
  #  Step 1: Divide the search space into 2 halves:
    In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Step 2: Compare the middle element with the target and trim down the search space:
    In this step, we can observe 3 different cases:
>       If arr[mid] == target: We have found the target. From this step, we can return the index of the target, and the recursion will end.
>       If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next recursion call will be binarySearch(nums, mid+1, high).
>       If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next recursion call will be binarySearch(nums, low, mid-1).
    Base case: The base case of the recursion will be low > high. If (low > high), the search space becomes invalid which means the target is not present in the array.

   Complexity Analysis:-
  # Time Complexity: In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

  # So the overall time complexity is O(logN), where N = size of the given array.
*/
/*int bS(vector<int>&arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high-low) / 2;
    if (arr[mid] == target) return mid;
    else if (target > arr[mid]) {
        return bS(arr, mid+1, high, target);
    }
    else {
    return bS(arr, low, mid-1, target);
    }
}

int search(vector<int>&arr, int target) {
    return bS(arr, 0, arr.size()-1, target);
}
*/



int main() {

/*// Iterative Implementation
    vector<int> num = {3, 4, 6, 7, 9, 12, 16, 17};
    int target1 = 6;
    int ind = binarySearch(num, target1);
    if (ind == -1) {
        cout <<"The target is not pressent."<<endl;
    }
    else { 
        cout <<"The target is at index: "<<ind<<endl;
    }
*/


/*// Recursive Implementation
    vector<int> ar = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 16;
    int ind = search(ar, target);
    if (ind == -1) {
        cout << "The target is not present."<<endl;
    }
    else {
        cout << "The target is at index: "<<ind<<endl;
    }
*/



    return 0;
}
