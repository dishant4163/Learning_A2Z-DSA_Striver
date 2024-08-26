/*(Count Occurences of a Number in a Sorted Array with Duplicates_Coding Ninja)-> https://bit.ly/42ZDqM4 

// Finding the First Occurrence
int firstOccur(vector<int>&arr, int n, int x) {
	int low=0, high = n-1;
	int first = -1;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if (arr[mid] == x) {
			first = mid;
			high = mid -1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return first;
}

// Finding the Last Occurrence
int lastOccur(vector<int>&arr, int n, int x) {
	int low=0, high = n-1;
	int last = -1;

	while(low <= high) {
		int mid = low + (high-low)/2;

		if (arr[mid] == x) {
			last = mid;
			low = mid + 1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return last;
}

// Checking first & last Occurrence
pair<int, int> firstAndLastPosition(vector<int>&arr, int n, int x){
	int first = firstOccur(arr, n, x);
	int last = lastOccur(arr, n, x);
	if (first == -1) return {-1, -1};
	return {first, last};
}

// Count function for counting occurrence
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int, int> ans = firstAndLastPosition(arr, n, x);
	if (ans.first == -1) return 0;// if doesn't exist then return 0
        // formula for count no of occueren=> end - start
        // { lastOccurrence - (firstOccurrence + 1) }
        return (ans.second - ans.first + 1);
}


*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Linear Search) 
   Approach:
  # The approach is simple. We will linearly search the entire array, and try to increase the counter whenever we get the target value in the array. Using a for loop that runs from 0 to n - 1, containing an if the condition that checks whether the value at that index equals target. If true then increase the counter, at last return the counter.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array
    Reason: We are traversing the whole array.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int count_1(vector<int>&ar1, int n1, int x) {
    int cnt1 = 0;
    for (int i=0; i<n1; i++) {
        //Count the Occurences
        if (ar1[i] == x) {
            cnt1++;
        }
    }
    return cnt1;
}





/*// Soln 2: Optimal(using Binary Search)   
  # Binary Search:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by 
  # Total number of occurrences = last occurrence - first occurrence + 1

   Algorithm/Intuition:
  #  We will get the first and the last occurrences of the number using the function firstAndLastPosition(). For the implementation details of the function, please refer to the previous article.
  #  After getting the indices, we will check the following cases:
>    If the first index == -1: This means that the target value is not present in the array. So, we will return 0 as the answer.
>    Otherwise: We will find the total number of occurrences like this:
>    The total number of occurrences  = (last index - first index + 1) and return this length as the answer.

   Complexity Analysis:
  # Time Complexity: O(2*logN), where N = size of the given array.
    Reason: We are basically using the binary search algorithm twice.
  # Space Complexity: O(1) as we are using no extra space.
*/
int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int k) {
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}





int main() {

// Soln 1: Brute Force(Linear Search)
    vector<int> ar1 = {2, 4, 6, 8, 8, 8, 11, 13, 15};
    int n1 = 9, x = 8;
    int sol = count_1(ar1, n1, x);
    cout << x << " is occurring " << sol << " times in the given array." << endl;



// Soln 2: Optimal(Binary Search)
    vector<int> arr =  {2, 4, 6, 8, 10, 10, 10, 11, 13};
    int n = 9, k = 10;
    int ans = count(arr, n, k);
    cout << k << " is occurring " << ans << " times in the given array." << endl;




    return 0;
}
