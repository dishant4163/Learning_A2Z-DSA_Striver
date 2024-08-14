/*//(Kadane's Algorithm-Maximum Subarray Sum in an Array_Coding Ninja)-> https://bit.ly/3HZltTa

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long sum = 0;
    long long maxi = arr[0];// or LONG_MIN;

    for (int i=0; i < n; i++) {
        sum += arr[i];

        //If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
        //update the maximum
        maxi = max(maxi, sum);
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;
    return maxi;
}

*/

/*Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.
*/



#include<bits/stdc++.h>
using namespace std;




/*//Soln 1: Brute Force
   Intuition:- We will check the sum of every possible subarray and consider the maximum among them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will consider the maximum one.

   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).

->   Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

   Complexity Analysis:-
  # Time Complexity: O(N3), where N = size of the array.
->   Reason: We are using three nested loops, each running approximately N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int maxSubArraySum1(int ar1[], int n1) {
    int maxi1 = INT_MIN; // Maximum Sum

    for (int i=0; i < n1; i++) {
        for (int j=0; j < n1; j++) { //Subarray = ar[i...j]
        int sum1 = 0;
        //add all the elements of subarray
        for (int k=i; k <= j; k++) {
            sum1 += ar1[k];
        }
        maxi1 = max(maxi1, sum1);
        }
    }
    return maxi1;
}






/*//Soln 2: Better(slightly change in brute force soln)
 Intuition: If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

-> Assume previous subarray = arr[i……j-1]
current subarray = arr[i…..j]
Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

-> This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. Among all the sums the maximum one will be the answer.

   Complexity Analysis:-
  # Time Complexity: O(N2), where N = size of the array.
->   Reason: We are using two nested loops, each running approximately N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int maxSubArraySum2(int ar2[], int n2) {
    int maxi2 = INT_MIN;//Maximum sum

    for (int i=0; i<n2; i++) {
        int sum2 = 0;
        for (int j = i; j < n2; j++) {
        // current subarray = ar[i....j]
        // add the current element ar[j]
        //to the sum i.e., sum of ar[i...j-1]
        sum2 += ar2[j];
        maxi2 = max(maxi2, sum2);// Getting the Maximum
        }
    }
    return maxi2;
}






/*//Soln 3: Optimal Approach(Kadane's Algo)
 Intuition:The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

->  Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

Thus we can solve this problem with a single loop.

   Approach:- The steps are as follows:

  #  We will run a loop(say i) to iterate the given array.
  #  Now, while iterating we will add the elements to the sum variable and consider the maximum one.
  #  If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.

->   Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

This is applicable to all the approaches discussed above.

But if this case is not explicitly mentioned we will not consider this case.


   Complexity Analysis:-
  # Time Complexity: O(N), where N = size of the array.
->  Reason: We are using a single loop running N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
long long maxSubArraySum3(int ar3[], int n3) {
    long long maxi3 = INT_MIN;// Maximum Sum
    long long sum3 = 0;

    for (int i=0; i < n3; i++) {
        sum3 += ar3[i];

        if (sum3 > maxi3) {
            maxi3 = sum3;
        }

        //If sum < 0: discard the sum calculated
        if (sum3 < 0) {
            sum3 = 0;
        }
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;
    return maxi3;
}


// Slightly more OPTIMAL
// int sum = 0;
// int maxi = arr[0];
//   for (int i=0; i<n; i++) {
//    sum += arr[i];
//
//    maxi = max(maxi,sum);
//
//    if(sum<0)
//        sum =0;
//   }
//    return maxi;






int main() {

//Soln 1:Brute Force
    int ar1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int maxSum1 = maxSubArraySum1(ar1, n1);
    cout<<"The maximum subarray sum is: "<<maxSum1<<endl;



//Soln 2:Better 
    int ar2[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int maxSum2 = maxSubArraySum2(ar2, n2);
    cout<<"The maximum subarray sum is: "<<maxSum2<<endl;



//Soln 3:Optimal
    int ar3[] = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int n3 = sizeof(ar3) / sizeof(ar3[0]);
    long long maxSum3 = maxSubArraySum3(ar3, n3);
    cout<<"The maximum subarray sum is: "<<maxSum3<<endl;



    return 0;
}