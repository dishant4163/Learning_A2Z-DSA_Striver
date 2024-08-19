/*//(Count All Subarrays with given Sum/Sum Equals K_Coding Ninja) -> https://bit.ly/3Kn10eZ

int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
    map<int, int> mpp;// OR unordered_map can be used
    int n = arr.size(); // size of the given array

    mpp[0] = 1; // Setting 0 in the map

    int prefixSum = 0, cnt = 0;
    for (int i=0; i<n; i++) {
        // add current element to prefix Sum
        prefixSum += arr[i];
        // Calculate x-k
        int remove = prefix - k;

        // Add the number of subarrays to be removed
        cnt += mpp[remove];
        
        // Update the count of prefix sum in the map
        mpp[prefixSum] += 1;
    }


    return cnt;
}
*/


//Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k.


#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force (Naive Approach)
 Algorithm:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
  #  After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

   Intuition: We will check the sum of every possible subarray and count how many of them are equal to k. To get every possible subarray sum, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values of the sum calculated, we will only consider those that are equal to k.

*** Note: We are selecting every possible subarray using two nested loops and for each of them, we add all its elements using another loop.

   Complexity Analysis:-
  # Time Complexity:- O(N^3), where N = size of the array.
> Reason: We are using three nested loops here. Though all are not running for exactly N times, the time complexity will be approximately O(N^3).
  # Space Complexity: O(1) as we are not using any extra space.
*/
int findAllSubarraysWithGivenSum1 (vector<int> &ar1, int k1) {
    int n1 = ar1.size(); // size of the given array
    int cnt1 = 0; // Number of SubArray

    for (int i=0; i < n1; i++) { // starting index i
        for (int j=i; j < n1; j++) { // ending index j
        // Calculate the sum of Subarray [i...j]
        int sum1 = 0;
        for (int K = i; K <= j; K++) 
            sum1 += ar1[K];

            // Increase the Count if sum == k
            if (sum1 == k1) {
                cnt1++;
            }
        }
    }
    return cnt1;
}






/*//Soln 2: Better (using 2 Loops) 
 Algorithm:- The steps are as follows:
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. 
  #  After calculating the sum, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

   Intuition: If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

> Assume previous subarray = arr[i……j-1]
> current subarray = arr[i…..j]
> Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

   Complexity Analysis:-
  # Time Complexity:- O(N^2), where N = size of the array.
 >  Reason: We are using two nested loops here. As each of them is running for exactly N times, the time complexity will be approximately O(N^2).

  # Space Complexity:- O(1) as we are not using any extra space.
*/
int findAllSubarraysWithGivenSum2(vector<int> &ar2, int k2) {
    int n2 = ar2.size(); // size of the given array
    int cnt2 = 0; // Number of Subarrays

    for (int i=0; i < n2; i++) { // staring index i
        int sum2 = 0;
        for (int j=i; j < n2; j++) { // ending index j
          // calculate the sum of subarray [i...j]
          // sum of [i...j-1] + arr[j]
            sum2 += ar2[j];

            // Increase the count if sum == k
            if (sum2 == k2) {
                cnt2++;
            }
        }
    }

    return cnt2;
}






/*//Soln 3: Optimal 
 In this approach, we are going to use the concept of the prefix sum to solve this problem. Here, the prefix sum of a subarray ending at index i simply means the sum of all the elements of that subarray.

Observation:- Assume, the prefix sum of a subarray ending at index i is x. In that subarray, we will search for another subarray ending at index i, whose sum equals k. Here, we need to observe that if there exists another subarray ending at index i with sum k, then the prefix sum of the rest of the subarray will be x-k.

Now, for a subarray ending at index i with the prefix sum x, if we remove the part with the prefix sum x-k, we will be left with the part whose sum is equal to k. And that is what we want.

Now, there may exist multiple subarrays with the prefix sum x-k. So, the number of subarrays with sum k that we can generate from the entire subarray ending at index i, is exactly equal to the number of subarrays with the prefix sum x-k, that we can remove from the entire subarray.

That is why, instead of searching the subarrays with sum k, we will keep the occurrence of the prefix sum of the subarrays using a map data structure. 

In the map, we will store every prefix sum calculated, with its occurrence in a <key, value> pair. Now, at index i, we just need to check the map data structure to get the number of times that the subarrays with the prefix sum x-k occur. Then we will simply add that number to our answer.

We will apply the above process for all possible indices of the given array. The possible values of the index i can be from 0 to n-1(where n = size of the array).

   Approach:- The steps are as follows:

  #  First, we will declare a map to store the prefix sums and their counts.
  #  Then, we will set the value of 0 as 1 on the map.
  #  Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
  #  For each index i, we will do the following:
>       We will add the current element i.e. arr[i] to the prefix sum.
>       We will calculate the prefix sum i.e. x-k, for which we need the occurrence.
>       We will add the occurrence of the prefix sum x-k i.e. mpp[x-k] to our answer.
>       Then we will store the current prefix sum in the map increasing its occurrence by 1.

*** Question: Why do we need to set the value of 0?
    Let’s understand this using an example. Assume the given array is [3, -3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix sum as 3, and k is also 3. So, the prefix sum of the remove-part should be x-k = 3-3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 for the key 0 and we will add 0 to our answer. This will mean that we have not found any subarray with sum 3 till now. But this should not be the case as index 0 itself is a subarray with sum k i.e. 3.
   So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.

*/
/*Complexity Analysis
  # Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
> Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.
  # Space Complexity: O(N) as we are using a map data structure.
*/
int findAllSubarraysWithGivenSum3(vector<int> &ar3, int k3) {
    int n3=ar3.size(); // size of the given array
    map<int, int> mp; //  OR unordered_map can be used
    int preSum = 0, cnt3 = 0;//set prefixSum & count as 0 

    //Setting 0 in the map i.e., (0, 1)
    mp[0]=1; // preSum as key-> 0, cnt as value-> 1 
    for (int i=0; i < n3; i++) {
        // add current element to prefix Sum
        preSum += ar3[i];

        //Calculate x-k
        int remove = preSum - k3;

        // add the number of Subarrays to be removed
        cnt3 += mp[remove];

        // Update the count of prefix sum in the map
        mp[preSum] += 1;
    }

    return cnt3;
}





int main() {

// Soln 1: Brute Force (Naive)
    vector<int> ar1 = {3, 1, 2, 4};
    int k1 = 6;
    int cnt1 = findAllSubarraysWithGivenSum1(ar1, k1);
    cout << "The number of subarrays whose sum euals to "<< k1 << " is " << cnt1 << "\n";



// Soln 2: Better(using 2 loops)
    vector<int> ar2 = {3, 1, 2, 4};
    int k2 = 7;
    int cnt2 = findAllSubarraysWithGivenSum2(ar2, k2);
    cout << "The number of subarrays whose sum euals to "<< k2 << " is " << cnt2 << "\n";



// Soln 3: Optimal(using hashing either order/Un_map)
    vector<int> ar3 = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int k3 = 3;
    int cnt3 = findAllSubarraysWithGivenSum3(ar3, k3);
    cout << "The number of subarrays whose sum euals to "<< k3 << " is " << cnt3 << "\n";



    return 0;
}

