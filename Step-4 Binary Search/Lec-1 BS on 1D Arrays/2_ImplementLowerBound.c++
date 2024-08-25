/*(Implement Lower Bound_Coding Ninja)-> https://bit.ly/43967G5  

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0, high = n-1;
    int ans = n;

	while(low <= high) {
		int mid = low + (high-low) / 2;

		if (arr[mid] >= x) {
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


/*// Problem Statement: 
 Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

Pre-requisite: Binary Search algorithm

    Example:
Example 1: Input Format:N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2: Input Format:N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/
/* What is Lower Bound?
 The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

->> The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Brute Force(Naive linear search)
> Let’s understand how we can find the answer using the linear search algorithm. With the knowledge that the array is sorted, our approach involves traversing the array starting from the beginning. During this traversal, each element will be compared with the target value, x. The index, i, where the condition arr[i] >= x is first satisfied, will be the answer.

   Complexity Analysis
  # Time Complexity: O(N), where N = size of the given array.
    Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.
  # Space Complexity: O(1) as we are using no extra space.
*/
int lB(vector<int> ar1, int n1, int x1) {
    for (int i =0; i<n1; i++) {
        if (ar1[i] >= x1) { // LOWER BOUND
            return i;
        }
    }
    return n1;
}





/*// Optimal(using Binary Search)  
 > As the array is sorted, we will apply the Binary Search algorithm to find the index. The steps are as follows:
 > We will declare the 2 pointers and an ‘ans’ variable initialized to n i.e. the size of the array(as If we don’t find any index, we will return n).

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
  #  Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
>   Case 1 - If arr[mid] >= x: This condition means that the index mid may be an answer. So, we will update the ‘ans’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition. Here, we are eliminating the right half.
>   Case 2 - If arr[mid] < x: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.

    The above process will continue until the pointer low crosses high.

   Complexity Analysis
  # Time Complexity: O(logN), where N = size of the given array.
Reason: We are basically using the Binary Search algorithm.
  # Space Complexity: O(1) as we are using no extra space.
*/ 
int lowerBound(vector<int> ar, int n, int x) {
    int low=0, high = n-1;
    int ans = n;

    while(low < high) {
        int mid = low + (high - low) / 2;
        // maybe answer
        if(ar[mid] >= x) {
            ans = mid;
            //Look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}






int main() {

// Brute Force
    vector<int> ar1 = {3, 5, 8, 15, 19};
    int n1 = 5, x1 = 9;
    int sol = lB(ar1, n1, x1);
    cout<<"The lower bound is the Index: "<<sol<<endl;



// Optimal (BS)
    vector<int> ar = {3, 5, 8, 15, 19};
    int n=5, x = 9;
    int ind = lowerBound(ar, n, x);
    cout<<"The lower bound is the index: "<<ind<<endl;




    return 0;
}
