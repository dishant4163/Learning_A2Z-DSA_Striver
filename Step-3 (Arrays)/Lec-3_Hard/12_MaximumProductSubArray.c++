/*(Maximum Product Subarray in an Array_Coding Ninja)-> https://bit.ly/3I7SrmM  

#include<bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int n = arr.size();

	int pre = 1, suff = 1;
	int ans = INT_MIN;
	for (int i=0; i < n; i++) {
		if (pre == 0) pre = 1;
		if (suff == 0) suff = 1;
		pre *= arr[i];
		suff *= arr[n-i-1];
		ans = max(ans, max(pre, suff));
	}
	return ans;
}

*/


// Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.



#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force(using 3 loops 4 finding subarray)  
   Approach:- Find all possible subarrays of the given array. Find the product of each subarray. Return the maximum of all them.

Following are the steps for the approach:-
  #  Run a loop on the array to choose the start point for each subarray.
  #  Run a nested loop to get the end point for each subarray.
  #  Multiply elements present in the chosen range.

   Complexity Analysis:-
  # Time Complexity: O(N3)
Reason: We are using 3 nested loops for finding all possible subarrays and their product.
  # Space Complexity: O(1)
Reason: No extra data structure was used
*/
int maxProductSubArray_1(vector<int>&nums1) {
    int n1 = nums1.size();
    int ans1 = INT_MIN;
    for (int i=0; i < n1; i++) {
        for (int j=i+1; j<n1; j++) {
            int prod1 = 1;
            for (int k=i; k<=j; k++) {
                prod1 *= nums1[k];
                ans1 = max(ans1, prod1);
            }
        }
    }
    return ans1;
}





/*// Soln 2: Better    
   Approach:- We can optimize the brute force by making 3 nested iterations to 2 nested iterations

Following are the steps for the approach:
  #  Run a loop to find the start of the subarrays.
  #  Run another nested loop
  #  Multiply each element and store the maximum value of all the subarray.

   Complexity Analysis:-
  # Time Complexity: O(N2)
Reason: We are using two nested loops
  # Space Complexity: O(1)
Reason: No extra data structures are used for computation
*/
int maxProductSubArray_2(vector<int>&nums2) {
    // OR INT_MIN i.e storing maxi. as answer
    int ans2 = nums2[0];

    for(int i=0; i <nums2.size(); i++) {
        int prod2 = nums2[i];
        for (int j=i+1; j<nums2.size(); j++) {
            ans2 = max(ans2, prod2);
            prod2 *= nums2[j];
        }

        ans2 = max(ans2, prod2); //Manages (n-1)th term
    
    }
    return ans2;
}





/*// Soln 3.1: Optimal(Observations Method)  
   Algorithm: 
  #  We will first declare 2 variables i.e. ‘pre’(stores the product of the prefix subarray) and ‘suff’(stores the product of the suffix subarray). They both will be initialized with 1(as we want to store the product).
  #  Now, we will use a loop(say i) that will run from 0 to n-1.
  #  We have to check 2 cases to handle the presence of 0:
>    If pre = 0: This means the previous element was 0. So, we will consider the current element as a part of the new subarray. So, we will set ‘pre’ to 1.
>    If suff = 0: This means the previous element was 0 in the suffix. So, we will consider the current element as a part of the new suffix subarray. So, we will set ‘suff’ to 1.
  #  Next, we will multiply the elements from the starting index with ‘pre’ and the elements from the end with ‘suff’. To incorporate both cases inside a single loop, we will do the following:
>    We will multiply arr[i] with ‘pre’ i.e. pre *= arr[i].
>    We will multiply arr[n-i-1] with ‘suff’ i.e. suff *= arr[n-i-1].
  #  After each iteration, we will consider the maximum among the previous answer, ‘pre’ and ‘suff’ i.e. max(previous_answer, pre, suff).
  #  Finally, we will return the maximum product.

   Complexity Analysis:-
  # Time Complexity: O(N), N = size of the given array.
Reason: We are using a single loop that runs for N times.
  # Space Complexity: O(1) as No extra data structures are used for computation.
*/
int maxProductSubArray_3(vector<int> &ar) {
    int n3 = ar.size();
    int pre = 1, suff = 1;
    int ans3 = INT_MIN;
    for (int i=0; i<n3; i++) {
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= ar[i];
        suff *= ar[n3 - i - 1];
        ans3 = max(ans3 , max(pre, suff));
    }
    return ans3;
}





/*// Soln 3.2: Optimal(Modify Kadene's Algo & not intutive so don't use this in interview)  
   Approach:
The following approach is motivated by Kandane’s algorithm. 
The pick point for this problem is that we can get the maximum product from the product of two negative numbers too.

Following are the steps for the approach:
  #  Initially store 0th index value in prod1, prod2 and result.
  #  Traverse the array from 1st index. 
  #  For each element, update prod1 and prod2.
  #  Prod1 is maximum of current element, product of current element and prod1, product of current element and prod2
  #  Prod2 is minimum of current element, product of current element and prod1, product of current element and prod2
  #  Return maximum of result and prod1

   Complexity Analysis:-
  # Time Complexity: O(N)
Reason: A single iteration is used.
  # Space Complexity: O(1)
Reason: No extra data structure is used for computation
*/

/*int maxProductsubarray(vector<int> &prodArr) {
    int pro1=prodArr[0], pro2 = prodArr[0], sol=prodArr[0];

    for (int i=1; i < prodArr.size(); i++) {
        int temp = max({prodArr[i], pro1*prodArr[i], pro2*prodArr[i]});
        pro2 = min({prodArr[i], pro1*prodArr[i], pro2*prodArr[i]});
        pro1 = temp;

        sol = max(sol, pro1);
    }
    return sol;
}
*/







int main() {

// Soln 1: Brute Froce(using 3 loops 4 finding subarray)
    vector<int> nums1 = {1, 2, -3, 0, -4, -5};
    cout<<"The maximum product subarray is: "<< maxProductSubArray_1(nums1);



// Soln 2: Better(Optimized the Brute soln)
    vector<int> nums2 = {1, 2, -3, 0, -4, -5};
    cout<<"The maximum product subarray is "<< maxProductSubArray_2(nums2);



// Soln 3.1: Optimal(Observations Method)
    vector<int> ar = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "<<maxProductSubArray_3(ar)<<endl;



/*// Soln 3.2: Optimal(Modify Kadene's Algo & not intutive so don't use this in interview)
    vector<int> prodArr = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductsubarray(prodArr);
*/



    return 0;
}
