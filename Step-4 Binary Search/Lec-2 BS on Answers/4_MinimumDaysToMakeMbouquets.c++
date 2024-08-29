/*(Minimum days to make M bouquets_Coding Ninja)-> https://bit.ly/43ScDRY     

bool possible(vector<int>& arr, int day, int m, int k) {
	int n = arr.size();
	int cnt=0, numofBloom = 0;
	for (int i=0; i<n; i++){
		if(arr[i] <= day) {
			cnt++;
		}
		else {
			numofBloom += (cnt/k);
			cnt = 0;
		}
	}
	numofBloom += (cnt/k);
	return (numofBloom >= m);
}

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int n = arr.size();
	long long val = m*1ll * k*1ll;
	if (val > n) return -1;
	
	// find minimum & maximum element in the array
	int mini=INT_MAX, maxi=INT_MIN;
	for (int i=0; i<n; i++) {
		mini = min(mini, arr[i]);
		maxi = max(maxi, arr[i]);
	}

    // Apply BS
    int low = mini, high = maxi;
	while(low <= high) {
		int mid = low + (high - low) /2;
		if (possible(arr, mid, m, k)) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

*/


/* Problem Statement: 
 You are given 'N’ roses and you are also given an array 'arr'  where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
 You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
 Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. Return -1 if it is not possible.

Examples:-

Example 1: 
 Input Format: N = 8, arr[] = {7, 7, 7, 7, 13, 11, 12, 7}, m = 2, k = 3
 Result: 12
 Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

 Example 2:

Input Format: N = 5, arr[] = {1, 10, 3, 10, 2}, m = 3, k = 2
 Result: -1
 Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 flowers. But we are given only 5 flowers, so, we cannot make the bouquets.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Brute Force(Naive) 
   Intuition:- The extremely naive approach is to check all possible answers from min(arr[]) to max(arr[]). The minimum number for which possible() returns true, is our answer.

   Algorithm:
  #  If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
  #  We will run a loop(say i) from min(arr[]) to max(arr[]) to check all possible answers.
  #  Next, we will pass each potential answer, represented by the variable 'i' (which corresponds to a specific day), to the 'possible()' function. If the function returns true, indicating that we can create 'm' bouquets, we will return the value of 'i'.
  #  Finally, if we are outside the loop, we can conclude that is impossible to make m bouquets. So, we will return -1.

   Complexity Analysis
  # Time Complexity: O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
    Reason: We are running a loop to check our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
bool possible1(vector<int>&ar1, int day1, int m1, int k1) {
    int n1 = ar1.size();
    int cnt1 = 0, numOfBloom = 0;
    for (int i=0; i<n1; i++) {
        if (ar1[i] <= day1) {
            cnt1++;
        }
        else {
            numOfBloom += (cnt1/k1);
            cnt1 = 0;
        }
    }
    numOfBloom += (cnt1/k1);
    return numOfBloom >= m1;
}

int rosegarden1(vector<int> ar1, int k1, int m1) {
    int n1 = ar1.size();
    long long val = m1 * 1ll * k1 * 1ll;
    if (val > n1) return -1;
    // Find Minimum & Maximum
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i=0; i<n1; i++) {
        mini = min(mini, ar1[i]);
        maxi = max(maxi, ar1[i]);
    }

    //Apply Brute Force
    for(int i=mini; i<=maxi; i++) {
        if (possible1(ar1, i, m1, k1)) {
            return i;
        }
    }
    return -1;
}





/*// Optimal(BS)   
   BS:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Now, we are not given any sorted array on which we can apply binary search. But, if we observe closely, we can notice that our answer space i.e. [mini(arr[]), max(arr[])] is sorted. So, we will apply binary search on the answer space.

   Algorithm:
  #  If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
  #  Next, we will find the maximum element i.e. max(arr[]), and the minimum element i.e. min(arr[]) in the array.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to min(arr[]) and the high will point to max(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the value returned by possible():-
    We will pass the potential answer, represented by the variable 'mid' (which corresponds to a specific day), to the 'possible()' function.
        If possible() returns true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
        Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

 The steps from 3-5 will be inside a loop and the loop will continue until low crosses high.


   Complexity Analysis:-
  # Time Complexity: O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
    Reason: We are applying binary search on our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer ‘mid’, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
bool possible(vector<int>&arr, int day, int m, int k) {
    int n =arr.size();
    int cnt =0, numOfBloom = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            numOfBloom += (cnt/k);
            cnt = 0;
        }
    }
    numOfBloom += (cnt/k);
    return (numOfBloom >= m);
}

int roseGarden(vector<int>arr, int k, int m) {
    int n = arr.size();
    long long val = m*1ll * k*1ll;
    if(val > n) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i=0; i<= n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    //Apply BS
    int low = mini, high = maxi;
    while(low <= high) {
        int mid = low + (high - low)/2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}







int main() {

// Soln 1: Brute Force
    vector<int> ar1 = {7, 7, 7, 7, 13, 11, 12, 7};
    int k1 = 3;
    int m1 = 2;
    int ans1 = rosegarden1(ar1, k1, m1);
    if (ans1 == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans1 <<endl;



// Soln 2: Optimal
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << endl;




    return 0;
