/*// (Count the number of subarrays with given xor K_Coding Ninja)-> https://bit.ly/3jLfElm  

#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int xr=0;

    //Declaring the map
    map<int, int> mp;
    mp[xr]++; //setting the value of 0
    int cnt = 0;

    for (int i=0; i<n; i++) {
        // prefix XOR till index i
        xr = xr^a[i];

        //By formula: x = xr^k:
        int x = xr^b;

        // add the occurrence of xr^k to the count
        cnt += mp[x];

        // Insert prefix XOR till index 'i' into the map
        mp[xr]++;
    }

    return cnt;
}

*/


/*// Problem Statement: 
Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.

   Example:
 # Input Format: A = [4, 2, 2, 6, 4] , k = 6
 #Result: 4
   Explanation:The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute(Naive)
 > How to generate all possible subarrays?
 > We will select all possible starting indices(say i) and all possible ending indices(say j) to generate all possible subarrays. The possible starting indices i.e. i can vary from index 0 to index n-1(i.e. The last index). For every index i, the possible ending index j can vary from i to n-1.

   Intuition:- We will check the XOR of every possible subarray and count how many of them are equal to k. To get every possible subarray sum, we will be using three nested loops. The first two loops(say i and j) will iterate over every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be from index i to index j. Using another loop we will get the XOR of the elements of the subarray [i…..j]. Among all values of the XOR calculated, we will only consider those that are equal to k.

*** Note: We are selecting every possible subarray using two nested loops and for each of the subarrays, we are calculating the XOR of all its elements using another loop.

   Approach:- The steps are as follows:
Generate Subarrays: 
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Calculate XOR of the subarray: After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the XOR of all the elements(of that particular subarray).
  #  Check the XOR and modify the count: If the XOR is equal to k, we will increase the count by 1.

   Complexity Analysis:-
  # Time Complexity: O(N^3) approx., where N = size of the array.
    Reason: We are using three nested loops, each running approximately N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int subarrayWithXorK_1(vector<int> ar1, int k1) {
    int n1 = ar1.size();
    int cnt1 = 0;

    //Step-1: Generating Subarrays
    for (int i=0; i<n1; i++) {
        for (int j=i; j<n1; j++) {
            //Step-2: Calculate XOR of all elements
            int XR1=0;
            for (int K=i; K <= j; K++) {
                XR1 = XR1 ^ ar1[K];
            }
            //Step-3: Check XOR & count
            if (XR1 == k1) cnt1++;
        }
    }

    return cnt1;
}





/*// Soln 2: Better 
   Approach:- The steps are as follows:
Generate Subarrays: 
  #  First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
  #  Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
  #  Calculate XOR of the subarray: Inside loop j, we will XOR the current element to the XOR of the previous subarray i.e. xorr = XOR(a[i….j-1]) ^ arr[j]. 
  #  Check the XOR and modify the count: After calculating the XOR, we will check if the sum is equal to the given k. If it is, we will increase the value of the count.

   Intuition: If we carefully observe, we can notice that to get the XOR of the current subarray we just need to XOR the current element(i.e. arr[j]) to the XOR of the previous subarray i.e. arr[i….j-1].

>   Assume previous subarray = arr[i……j-1]
>   current subarray = arr[i…..j]
>   XOR of arr[i….j] = (XOR of arr[i….j-1]) ^ arr[j]

 This is how we can remove the third loop and while moving j pointer, we can calculate the XOR.

   Complexity Analysis:-
  # Time Complexity: O(N^2), where N = size of the array.
    Reason: We are using two nested loops here. As each of them is running for N times, the time complexity will be approximately O(N^2).
  # Space Complexity: O(1) as we are not using any extra space.
*/
int subarrayWithXorK_2(vector<int> ar2, int k2) {
    int n2 = ar2.size();
    int cnt2=0;

    //Step-1: Generate Subarrays
    for (int i=0; i<n2; i++) {
        int XR2=0;
        for (int j=i; j<n2; j++) {
            //Step-2: Calculate XOR of all Elements
            XR2 = XR2 ^ ar2[j];

        // Step-3: check XOR & count 
        if (XR2==k2) cnt2++;
        }
    }

    return cnt2;
}





/*// Soln 3: Optimal(using Hashing) 
   Approach:- The steps are as follows:
  #  First, we will declare a map to store the prefix XORs and their counts.
  #  Then, we will set the value of 0 as 1 on the map.
  #  Then we will run a loop(say i) from index 0 to n-1(n = size of the array).
  #  For each index i, we will do the following:
>       We will XOR the current element i.e. arr[i] to the existing prefix XOR.
>       Then we will calculate the prefix XOR i.e. xr^k, for which we need the occurrence.
>       We will add the occurrence of the prefix XOR xr^k i.e. mpp[xr^k] to our answer.
>       Then we will store the current prefix XOR, xr in the map increasing its occurrence by 1.


 Question: Why do we need to set the value of 0 beforehand?
 Let’s understand this using an example. Assume the given array is [3, 3, 1, 1, 1] and k is 3. Now, for index 0, we get the total prefix XOR as 3, and k is also 3. So, the prefix XOR xr^k will be = 3^3 = 0. Now, if the value is not previously set for the key 0 in the map, we will get the default value 0 and we will add 0 to our answer. This will mean that we have not found any subarray with XOR 3 till now. But this should not be the case as index 0 itself is a subarray with XOR k i.e. 3.
So, in order to avoid this situation we need to set the value of 0 as 1 on the map beforehand.

   Complexity Analysis:-
  # Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
    Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2). 
  # Space Complexity: O(N) as we are using a map data structure.
*/
int subarraysWithXorK_3(vector<int> arr, int k3) {
    int n3=arr.size();
    int xr=0;

    //Declaring the map
    map<int, int> mp;
    mp[xr]++; //setting the value of 0
    int cnt3 = 0;

    for (int i=0; i<n3; i++) {
        // prefix XOR till index i
        xr = xr^arr[i];

        //By formula: x = xr^k:
        int x = xr^k3;

        // add the occurrence of xr^k to the count
        cnt3 += mp[x];

        // Insert prefix XOR till index 'i' into the map
        mp[xr]++;
    }

    return cnt3;
}





int main() {

// Soln 1: Brute Force(Naive)
    vector<int> ar1 = {4, 2, 2, 6, 4};
    int k1 = 6;
    int ans1 = subarrayWithXorK_1(ar1, k1);
    cout<<"The number of subarrays with XOR k is: "<<ans1<<endl;



// Soln 2: Better
    vector<int> ar2 = {4, 2, 2, 6, 4};
    int k2=6;
    int ans2 = subarrayWithXorK_2(ar2, k2);
    cout<<"The number of subarrays with XOR k is: "<<ans2<<endl;



// Soln 3: Optimal(using Hashing)
    vector<int> arr = {4, 2, 2, 6, 4};
    int k3=6;
    int ans3 = subarraysWithXorK_3(arr, k3);
    cout<<"The number of subarrays with XOR k is: "<<ans3<<endl;



    return 0;
}
