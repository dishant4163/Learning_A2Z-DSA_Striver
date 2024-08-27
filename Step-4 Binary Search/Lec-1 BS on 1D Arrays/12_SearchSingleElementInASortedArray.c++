/*(Search Single Element in a Sorted Array_Coding Ninja)-> https://bit.ly/3pBahrX      

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n=arr.size();
    // Check for the EDGE Cases:
	if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
	if(arr[n-1] != arr[n-2]) return arr[n-1];

	int low = 1, high = n - 2;
	while(low <= high) {
		int mid = low + (high - low) / 2;
        //if arr[mid] is the single element:
		if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
			return arr[mid];
		}

		if((mid%2 ==1 && arr[mid - 1] == arr[mid]) || (mid%2 == 0 && arr[mid] == arr[mid + 1]) ) {
			//Eleminate the Left Half
			low = mid + 1;
		}
		else {
			//Eleminate the Right Half
			high = mid - 1;
		}
	}
	return -1;
}

*/


/* Problem Statement: 
 Given an array of N integers. Every number in the array except one appears twice. Find the single number in the array.

 Pre-requisite: Binary Search Algorithm

   Examples
Example 1: Input Format: arr[] = {1,1,2,2,3,3,4,5,5,6,6}
 Result: 4
 Explanation: Only the number 4 appears once in the array.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1.1: Brute Force(Naive)    
   Intuition : A crucial observation to note is that if an element appears twice in a sequence, either the preceding or the subsequent element will also be the same. But only for the single element, this condition will not be satisfied. So, to check this the condition will be the following:

    If arr[i] != arr[i-1] and arr[i] != arr[i+1]: If this condition is true for any element, arr[i], we can conclude this is the single element.

Edge Cases:

    If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
    If i == 0: This means this is the very first element of the array. The only condition, we need to check is: arr[i] != arr[i+1].
    If i == n-1: This means this is the last element of the array. The only condition, we need to check is: arr[i] != arr[i-1].

So, we will traverse the array and we will check for the above conditions.

   Algorithm:The steps are as follows:

  #  At first, we will check if the array contains only 1 element. If it is, we will simply return that element.
  #  We will start traversing the array. Then for every element, we will check the following.
  #  If i == 0: If we are at the first index, we will check if the next element is equal.
        If arr[i] != arr[i+1]: This means arr[i] is the single element and so we will return arr[i].
  #  If i == n-1: If we are at the last index, we will check if the previous element is equal.
        If arr[i] != arr[i-1]: This means arr[i] is the single element and so we will return arr[i].
  #  For the elements other than the first and last, we will check: If arr[i] != arr[i-1] and arr[i] != arr[i+1]: If this condition is true for any element, arr[i], we can conclude this is the single element. And we should return arr[i].

   Complexity Analysis
  # Time Complexity: O(N), N = size of the given array.
    Reason: We are traversing the entire array.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicate_1(vector<int>& ar1) {
    int n1 = ar1.size();
    if (n1 == 1) return ar1[0];
    for (int i=0; i<n1; i++) {
        if (i == 0) {
            if(ar1[i] != ar1[i+1]) return ar1[i];
        }
        else if (i == n1 - 1) {
            if (ar1[i] != ar1[i-1]) return ar1[i];
        }
        else {
            if(ar1[i] != ar1[i+1] && ar1[i] != ar1[i-1]){
                return ar1[i];
            }
        }
    }
    return -1;
}





/*// Soln 1.2: Brute Force(using XOR)     
   Intuition(naive):
We can simplify the above approach using the XOR operation. We need to remember 2 important properties of XOR:
    a ^ a = 0, XOR of two same numbers results in 0.
    a ^ 0 = a, XOR of a number with 0 always results in that number.

Now, if we XOR all the array elements, all the duplicates will result in 0 and we will be left with a single element.

   Algorithm:
  #  We will declare an ‘ans’ variable initialized with 0.
  #  We will traverse the array and XOR each element with the variable ‘ans’.
  #  After complete traversal, the ‘ans’ variable will store the single element and we will return it.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array.
    Reason: We are traversing the entire array.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicate_2(vector<int>& ar2) {
    int n2 = ar2.size();
    int ansXR = 0;
    // XOR all the Elements
    for (int i=0; i<n2; i++) {
        ansXR = ansXR ^ ar2[i];
    }
    return ansXR;
}





/*// Soln 2: Optimal(using Binary Search)  
   Algorithm:The steps are as follows:

    If n == 1: This means the array size is 1. If the array contains only one element, we will return that element only.
    If arr[0] != arr[1]: This means the very first element of the array is the single element. So, we will return arr[0].
    If arr[n-1] != arr[n-2]: This means the last element of the array is the single element. So, we will return arr[n-1].
    Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
    Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
    Check if arr[mid] is the single element:
    If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the single element. We will return arr[mid].
    If (mid % 2 == 0 and arr[mid] == arr[mid+1])
    or (mid%2 == 1 and arr[mid] == arr[mid-1]): This means we are in the left half and we should eliminate it as our single element appears on the right. So, we will do this:
    low = mid+1.
    Otherwise, we are in the right half and we should eliminate it as our single element appears on the left. So, we will do this: high = mid-1.


   Complexity Analysis

  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using the Binary Search algorithm.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int singleNonDuplicate_2(vector<int>& arr) {
    int n = arr.size();
    //Edge Cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n-2;

    while(low <= high) {
        int mid = low + (high-low) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        if ((mid%2 == 1 && arr[mid] == arr[mid-1]) || (mid%2 == 0 && arr[mid] == arr[mid + 1])) {
            //Eleminate the Left Half
            low = mid + 1;
        }
        else {
            //Eleminate the Right Half
            high = mid - 1;
        }
    }
    return -1;
}






int main() {

// Soln 1.1: Brute Force(Naive)
    vector<int> ar1 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int sol1 = singleNonDuplicate_1(ar1);
    cout << "The single element is: " << sol1 << endl;



// Soln 1.2: Brute Force(using XOR)
    vector<int> ar2 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int sol2 = singleNonDuplicate_2(ar2);
    cout << "The single element is: " << sol2 << endl;



// Soln 2: Optimal(using Binary Search)
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate_2(arr);
    cout << "The single element is: " << ans << endl;





    return 0;
}
