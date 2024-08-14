/*(Longest Subarray with sum K | [Postives and Negatives]_Coding Ninja)-> https://bit.ly/3mNSZ9u

int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int n = nums.size();// size of the array

    map<long long, int> PreSumMap;
    long long sum = 0;
    int maxLen =0;
    // calculate the Prefix sum till Index i
    for (int i=0; i<n; i++) {
        sum += nums[i];
    // if the sum = k, update the maxLen
        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }

        // calculate the sum of remaining part i.e. x-k
        long long rem = sum - k;

        //Calculate the length and update maxLen
        if (PreSumMap.find(rem) != PreSumMap.end() ){
            int Len = i - PreSumMap[rem];
            maxLen = max(maxLen, Len);
        }

        //Finally, update the map checking the conditions
        if (PreSumMap.find(sum) == PreSumMap.end() ){
            PreSumMap[sum] = i;
        }
    }
    return maxLen;
}
*/



#include<bits/stdc++.h>
using namespace std;


//Longest Subarray with given Sum K | [Postives and Negatives]
/*// Soln 1: Brute(Naive Approach)
 Approach:- The steps are as follows:

  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
  #  If the sum equals k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.

   Intuition:- We will check the sum of every possible subarray and consider the one with the sum k and the maximum length among them. To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all the subarrays with sum k, we will consider the one with the maximum length.

->   Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

   Complexity Analysis:-
  # Time Complexity: O(N^3) approx., where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.

  # Space Complexity: O(1) as we are not using any extra space.
*/
int getLongestSubarray1(vector<int> &ar1, long long k1) {
    int n1 = ar1.size(); //size of the array.

    int len1=0;
    for(int i=0; i<n1; i++) { // starting index
        for(int j=i; j<n1; j++) { // ending index
            // add all the elements of subarray = a[i...j]
            long long sum1 = 0;
            for(int K=i; K <= j; K++) {
                sum1 += ar1[K];
            }

            if(sum1 == k1) {
                len1 = max(len1, j-i+1);
            }
        }
    }
    return len1;
}






/*// Soln 2: Better_Optimizing Naive Approach(Using two loops)
   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. 
  #  If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays with sum k, we will consider the one with the maximum length by comparing all the lengths.

   Intuition:- If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

->   Assume previous subarray = arr[i……j-1]
->   current subarray = arr[i…..j]
->   Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

->   This is how we can remove the third loop and while moving the j pointer, we can calculate the sum.

   Complexity Analysis:-
  # Time Complexity: O(N^2) approx., where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.
  Space Complexity: O(1) as we are not using any extra space.
*/
int getLongestSubarray2(vector<int> &ar2, long long k2) {
    int n2 = ar2.size(); // Size of the Array

    int len2 = 0;
    for (int i=0; i<n2; i++) { // starting index
        long long sum2 = 0; //Sum Variable
        for (int j=i; j<n2; j++) { // Ending Index
            //add all the elements of subarray = a[i...j]
            sum2 += ar2[j];

            if (sum2 == k2) {
                len2 = max(len2, j-i+1);
            }
        }
    }
    return len2;
}






/*// Soln 3: Optimal Approach(Using Hashing)
   Approach:- The steps are as follows:

  #  First, we will declare a map to store the prefix sums and the indices.
  #  Then we will run a loop(say i) from index 0 to n-1  (n=size of the array).
  #  For each index i, we will do the following:
->      We will add the current element i.e. a[i] to the prefix sum.
->      If the sum is equal to k, we should consider the length of the current subarray i.e. i+1. We will compare this length with the existing length and consider the maximum one.
->      We will calculate the prefix sum i.e. x-k, of the remaining subarray.
->      If that sum of the remaining part i.e. x-k exists in the map, we will calculate the length i.e. i-preSumMap[x-k], and consider the maximum one comparing it with the existing length we have achieved until now.
->      If the sum, we got after step 3.1, does not exist in the map we will add that with the current index into the map. We are checking the map before insertion because we want the index to be as minimum as possible an

   Complexity Analysis:- 
  # Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N^2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
  # Space Complexity: O(N) as we are using a map data structure.
*/
int getLongestSubarray3(vector<int> &ar3, long long k3) {
    int n3 = ar3.size();// size of the array.

    map<long long, int> preSumMap;
    long long sum3 = 0;
    int maxLen3 = 0;
    for(int i=0; i<n3; i++) { 
    //calculate the prefix sum till index i:
        sum3 += ar3[i];
    // if the sum = k, update the maxLen:
        if (sum3 == k3) {
            maxLen3 = max(maxLen3, i+1); 
        }

    // calculate the sum of remaining part i.e. x-k
        long long rem3 = sum3 - k3;

    //Calculate the length and update maxLen
        if(preSumMap.find(rem3) != preSumMap.end() ) {
            int len3 = i - preSumMap[rem3];//length of subarray
            maxLen3 = max(maxLen3, len3);
        }

    //Finally, update the map checking the conditions
        if (preSumMap.find(sum3) == preSumMap.end() ) {
            preSumMap[sum3] = i;
        }
    }
    return maxLen3;
//Remeber this is paritailly Correct for Positives & zeros
//But, this code is Optimal for both +ve & -ve, zeros
}







int main() {

// Soln 1.1: Brute Force
    vector<int> ar1 = {2, 3, 5, 1, 9};
    long long k1 = 10;
    int len1 = getLongestSubarray1(ar1, k1);
    cout<<"Length of the Longest Subarray is "<<len1<<endl;



// Soln 2: Better Approach
    vector<int> ar2 = {2, 3, 5, 1, 9};
    long long k2 = 10;
    int len2 = getLongestSubarray2(ar2, k2);
    cout << "Length of the Longest Subarray is " <<len2<<endl;



// Soln 2: Optimal Approach
    vector<int> ar3 = {2, 3, 5, 1, 9};
    long long k3 = 10;
    int len3 = getLongestSubarray3(ar3, k3);
    cout <<"Length of the Longest Subarray is "<<len3<<endl;



    return 0;
}





