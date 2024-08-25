/*(Floor & Ceil in Sorted Array_Coding Ninja)-> https://shorturl.at/XSPzA     

int floor(vector<int>&arr, int n, int x){
	int low = 0, high=n-1;
	int ans = -1;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if(arr[mid] <= x) {
			ans = arr[mid];
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}
	return ans;
}

int ceil(vector<int>&arr, int n, int x){
    int low = 0, high=n-1;
	int ans = -1;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if(arr[mid] >= x) {
			ans = arr[mid];
			high = mid-1;
		}
		else {
			low = mid +1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int f = floor(a, n, x);
	int c = ceil(a, n, x);

	return make_pair(f, c);
}

*/



/* Problem Statement: 
 You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
  # The floor of x is the largest element in the array which is smaller than or equal to x.
  # The ceiling of x is the smallest element in the array greater than or equal to x.

Pre-requisite: Lower Bound & Binary Search

   Examples:-
Example 1: 
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/



/* What is the FLOOR of x?
  The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).


    What is the CEILING of x?
  The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).
*/


#include<bits/stdc++.h>
using namespace std;

/*  Algorithm / Intuition:

    Ceil:
We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
  #  Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
>    Case 1 - If arr[mid] >= x: This condition means that the index arr[mid] may be an answer. So, we will update the ‘ans’ variable with arr[mid] and search in the left half if there is any smaller number that satisfies the same condition. Here, we are eliminating the right half.
>    Case 2 - If arr[mid] < x: In this case, arr[mid] cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.

The above process will continue until the pointer low crosses high.




Floor: 
We will declare the 2 pointers and an ‘ans’ variable initialized to -1 (If we don’t find any index, we will return -1).

  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
  #  Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
>    Case 1 - If arr[mid] <= x: The index arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
>    Case 2 - If arr[mid] > x: arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.

The above process will continue until the pointer low crosses high.
*/
int findFloor(int arr[], int n, int x) {
    int low =0, high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] <= x) { //for Floor, no in arr <= x
            ans = arr[mid]; // return arr element as mid
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x) {
    int low =0, high = n-1;
    int ans = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] >= x) { //for Ceil, no in arr >= x
            ans = arr[mid]; // return arr element as mid
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}




int main() {

    int  arr[] = {10, 20, 30, 40, 50};
    int n = 5, x = 25;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout<<"The floor & ceil are: "<<ans.first<<" "<<ans.second<<endl;


    return 0;
}
