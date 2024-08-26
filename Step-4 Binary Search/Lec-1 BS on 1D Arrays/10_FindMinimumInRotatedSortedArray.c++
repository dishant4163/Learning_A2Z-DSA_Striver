/*(Find Minimum in Rotated Sorted Array_Coding Ninja)-> https://bit.ly/42ChjLM  

int findMin(vector<int>& arr)
{
	// Write your code here.
	int low = 0, high = arr.size()-1;
	int ans = INT_MAX;

	while(low <= high) {
		int mid = low + (high-low)/2;

		// uncomment this for getting more optimized soln
        // if (arr[low] <= arr[high]) { //search space is already sorted then arr[low] will always be
        //the minimum in that search space:
        //     ans = min(ans, arr[low]);
        //     break;
        // }
		

		if(arr[low] <= arr[mid]) {
			ans = min(ans, arr[low]);
			low = mid + 1;
		}
		else {
			high = mid -1;
			ans = min(ans, arr[mid]);
		}
	}
	return ans;
}

*/ 


/* Problem Statement: 
 Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

Pre-requisites: Search in Rotated Sorted Array I,  Search in Rotated Sorted Array II & Binary Search algorithm
Examples


Example 1: 
 Input Format: arr = [4,5,6,7,0,1,2,3]
 Result:0
Explanation:Here, the element 0 is the minimum element in the array.

Example 2:
 Input Format: arr = [3,4,5,1,2]
 Result: 1
Explanation:Here, the element 1 is the minimum element in the array.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
 Naive Approach: One straightforward approach, we can consider is using the linear search algorithm. Using this method, we will find the minimum number from the array.

   Algorithm:
  #  First, we will declare a ‘mini’ variable initialized with a large number.
  #  After that, we will traverse the array and compare each element with the ‘mini’ variable. Each time the ‘mini’ variable will be updated with the minimum value i.e. min(mini, arr[i]).
  #  Finally, we will return ‘mini’ as our answer.

   Complexity Analysis
  # Time Complexity: O(N), N = size of the given array.
    Reason: We have to iterate through the entire array to check if the target is present in the array.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int findMin_1(vector<int>&ar1) {
    int n1 = ar1.size();
    int ans1 = INT_MAX;
    for (int i=0; i<n1; i++){
        ans1 = min(ans1, ar1[i]);
    }
    return ans1;
}





/*// Soln 2.1: Optimal(using Binary Search)  
   Algorithm:The steps are as follows:

We will declare the ‘ans’ variable and initialize it with the largest value possible. With that, as usual, we will declare 2 pointers i.e. low and high.

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Identify the sorted half, and after picking the leftmost element, eliminate that half.
        If arr[low] <= arr[mid]: This condition ensures that the left part is sorted. So, we will pick the leftmost element i.e. arr[low]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[low])). Now, we will eliminate this left half(i.e. low = mid+1).
        Otherwise, if the right half is sorted:  This condition ensures that the right half is sorted. So, we will pick the leftmost element i.e. arr[mid]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[mid])). Now, we will eliminate this right half(i.e. high = mid-1).
  #  This process will be inside a loop and the loop will continue until low crosses high. Finally, we will return the ‘ans’ variable that stores the minimum element.

   Complexity Analysis
  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using binary search to find the minimum.
  # Space Complexity: O(1)
    Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
int findMin_2(vector<int>&ar2) {
    int low=0, high = ar2.size() - 1;
    int mini = INT_MAX;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if (ar2[low] <= ar2[mid]) {
            mini = min(mini, ar2[low]);
            low = mid + 1;
        }
        else {
            high = mid - 1;
            mini = min(mini, ar2[mid]);
        }
    }
    return mini;
}





/*// Soln 2.2: Further Optimization(Using Binary Search) 
   Further Optimization(Using Binary Search):

 If both the left and right halves of an index are sorted, it implies that the entire search space between the low and high indices is also sorted. In this case, there is no need to conduct a binary search within that segment to determine the minimum value. Instead, we can simply select the leftmost element as the minimum.
 The condition to check will be arr[low] <= arr[mid] && arr[mid] <= arr[high]. We can shorten this into arr[low] <= arr[high] as well.
 If arr[low] <= arr[high]: In this case, the array from index low to high is completely sorted. Therefore, we can simply select the minimum element, arr[low], and update the 'ans' variable with the minimum value i.e. min(ans, arr[low]). Once this is done, there is no need to continue with the binary search algorithm.


   Algorithm: The steps are as follows:

We will declare the ‘ans’ variable and initialize it with the largest value possible. With that, as usual, we will declare 2 pointers i.e. low and high.

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  If arr[low] <= arr[high]: In this case, the array from index low to high is completely sorted. Therefore, we can select the minimum element, arr[low], and update the 'ans' variable with the minimum value i.e. min(ans, arr[low]). Once this is done, there is no need to continue with the binary search algorithm. So, we will break from this step.
  #  Identify the sorted half, and after picking the leftmost element, eliminate that half.
        If arr[low] <= arr[mid]: This condition ensures that the left part is sorted. So, we will pick the leftmost element i.e. arr[low]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[low])). Now, we will eliminate this left half(i.e. low = mid+1).
        Otherwise, if the right half is sorted:  This condition ensures that the right half is sorted. So, we will pick the leftmost element i.e. arr[mid]. Now, we will compare it with 'ans' and update 'ans' with the smaller value (i.e., min(ans, arr[mid])). Now, we will eliminate this right half(i.e. high = mid-1).
  #  This process will be inside a loop and the loop will continue until low crosses high. Finally, we will return the ‘ans’ variable that stores the minimum element.

*/
int findMin_3(vector<int>&ar3) {
    int low=0, high = ar3.size() - 1;
    int mini = INT_MAX;

    while(low <= high) {
        int mid = low + (high-low)/2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if(ar3[low] <= ar3[high]) {
            mini = min(mini, ar3[low]);
            break;
        }

         //if left part is sorted:
        if (ar3[low] <= ar3[mid]) {
            // keep the minimum:
            mini = min(mini, ar3[low]);
            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:
            high = mid - 1;// Eliminate right half:
            // keep the minimum:
            mini = min(mini, ar3[mid]);
        }
    }
    return mini;
}







int main() {

// Soln 1: Brute Force
    vector<int> ar1 = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans1 = findMin_1(ar1);
    cout << "The minimum element is: " << ans1 <<endl; 



// Soln 2.1: Optimal(using Binary Search)
    vector<int> ar2 = {4, 5, 6, 7, 1, 2, 3};
    int ans2 = findMin_2(ar2);
    cout << "The minimum element is: " << ans2 << endl;


// Soln 2.2: Further Optimization(Using Binary Search)
    vector<int> ar3 = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans3 = findMin_3(ar3);
    cout << "The minimum element is: " << ans3 << endl;


    return 0;
}
