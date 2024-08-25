/*(Implement Upper Bound_Coding Ninja)-> https://bit.ly/3IoKGce  

int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	int low = 0, high = n-1;
	int ans = n;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if (arr[mid] > x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

*/


/*//Problem Statement: 
 Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

Pre-requisite: Binary Search algorithm

   Examples
Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation:Index 3 is the smallest index such that arr[3] > x.

Example 2:
Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation:Index 4 is the smallest index such that arr[4] > x.
*/
/*What is Upper Bound?
 The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

->> But if any such index is not found, the upper bound algorithm returns n i.e. size of the given array. The main difference between the lower and upper bound is in the condition. For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Brute Force(Naive using linear search)
  Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array starting from the beginning. During this traversal, each element will be compared with the target value, x. The index, i, where the condition arr[i] > x is first satisfied, will be the answer.

   Complexity Analysis:-
  # Time Complexity: O(N), where N = size of the given array.
    Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.
  # Space Complexity: O(1) as we are using no extra space.
*/
int upB(vector<int> arr, int x1, int n1) {
    for (int i=0; i<n1; i++) {
        if (arr[i] > x1) {
            return i;
        }
    }
    return n1;
}




/*// Optimal(Using Binary Search)   
 > As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows:

 > We will declare the 2 pointers and an ‘ans’ variable initialized to n i.e. the size of the array(as If we don’t find any index, we will return n).

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
  #  Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
>   Case 1 - If arr[mid] > x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
>   Case 2 - If arr[mid] <= x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.

    The above process will continue until the pointer low crosses high.

   Complexity Analysis:-
  # Time Complexity: O(logN), where N = size of the given array.
    Reason: We are basically using the Binary Search algorithm.
  # Space Complexity: O(1) as we are using no extra space.
*/
int upb(vector<int>&ar, int x, int n) {
    int low=0, high=n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        //maybe an answer
        if(ar[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}




int main() {

// Soln 1: Brute Force
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n1 = 6, x1 = 9;
    int sol = upB(arr, x1, n1);
    cout <<"The upper bound is the index: "<<sol<<endl;



// Soln 2: Optimal(using BS)
    vector<int> ar = {3, 5, 8, 9, 15, 19};
    int n=6, x=9;
    int ind = upb(ar, x, n);
    cout<<"The upper bound is the index: "<<ind<<endl;



    return 0;
}

