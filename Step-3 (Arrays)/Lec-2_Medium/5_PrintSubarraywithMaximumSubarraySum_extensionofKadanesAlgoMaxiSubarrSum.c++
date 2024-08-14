//Print SubArray with Maximum Subarray Sum(Extension Version of "Maximum Subarray Sum i.e., KADANE's Alogrithm")

// NOTE:- It is same as Maximum Subarray Sum with Slightly Changes
// i.e., Printing the Subarray with Maximum SubArray Sum



#include<bits/stdc++.h>
using namespace std;


/* Soln : OPTIMAL (Kadane's Algo but slightly change)
   Algorithm / Intuition:-

  There might be more than one subarray with the maximum sum. We need to print any of them.

   Intuition: Our approach is to store the starting index and the ending index of the subarray. Thus we can easily get the subarray afterward without actually storing the subarray elements.

  If we carefully observe our algorithm, we can notice that the subarray always starts at the particular index where the sum variable is equal to 0, and at the ending index, the sum always crosses the previous maximum sum(i.e. maxi).

->    So, we will keep a track of the starting index inside the loop using a start variable.
->    We will take two variables ansStart and ansEnd initialized with -1. And when the sum crosses the maximum sum, we will set ansStart to the start variable and ansEnd to the current index i.e. i.

The rest of the approach will be the same as Kadane’s Algorithm.

   Complexity Algorithm:-
  # Time Complexity:- O(N), where N = size of the array.
->  Reason: We are using a single loop running N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i=0; i < n; i++) {
        // Starting Index
        if (sum == 0) start = i;

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }

        //Printing the Subarray
        cout<<"The Subarray is: [";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << arr[i] << " ";
        }
        cout <<"] " <<endl;;
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;


    return maxi;

}


int main(){
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;


    return 0;
}
