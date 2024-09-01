/*(K-th Element of 2 Sorted Arrays_Coding Ninja)-> https://bit.ly/3MD3mHK  

#include<bits/stdc++.h>

int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){
    // Write your code here.
    if (n > m) return kthElement(b, a, m, n, k);

    int left = k;

    int low = max(0, k-m), high = min(k, n);
    while(low <= high) {
        int mid1 = low + (high - low)/2;
        int mid2 = left - mid1;

        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;

        if (mid1 < n) r1 = a[mid1];
        if (mid2 < m) r2 = b[mid2];
        if (mid1-1 >= 0) l1 = a[mid1-1];
        if (mid2-1 >= 0) l2 = b[mid2-1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0;
}

*/



/* Problem Statement:-
 Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array. 

 Pre-requisite: Median of 2 sorted arrays
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force   
   Intuition:- 
 The extremely naive approach is to merge the two sorted arrays and then find the K-th element in that merged array.

  How to merge two sorted arrays:
 The word “merge” suggests applying the merge step of the merge sort algorithm . In that step, we essentially perform the same actions as required by this solution. By using two pointers on two given arrays, we fill up the elements into a third array.


   Algorithm/Approach:
  #  We will use a third array i.e. arr3[] of size (m+n) to store the elements of the two sorted arrays.
  #  Now, we will take two pointers i and j, where i points to the first element of arr1[] and j points to the first element of arr2[].
  #  Next, using a while loop( while(i < m && j < n)), we will select two elements i.e. arr1[i] and arr2[j], and consider the smallest one among the two. Then, we will insert the smallest element in the third array and increase that specific pointer by 1.
        If arr1[i] < arr2[j] : Insert arr1[i] into the third array and increase i by 1.
        Otherwise : Insert arr2[j] into the third array and increase j by 1.
  #  After that, the left-out elements from both arrays will be copied as it is into the third array.
  #  Now, the third array i.e. arr3[] will be the sorted merged array. Now the k-th will be the arr3[k-1].
  #  Finally, we will return the value of arr3[k-1].


   Complexity Analysis:-
  # Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
    Reason: We traverse through both arrays linearly.
  # Space Complexity: O(m+n), where m and n are the sizes of the given arrays.
    Reason: We are using an extra array of size (m+n) to solve this problem. 
*/
int kthElement_1(vector<int> &a, vector<int>& b, int m, int n, int k) {
    vector<int> arr3;
            
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
            
    //copy the left-out elements:
    while (i < m) arr3.push_back(a[i++]);
    while (j < n) arr3.push_back(b[j++]);
    return arr3[k - 1];
}





/*// Soln 2: Better(optimized SearchSpace in Brute soln)   
   Intuition:-
 To optimize the space used in the previous approach, we can eliminate the third array used to store the final merged result. After closer examination, we realize that we only need the k-th element at index (k-1), rather than the entire merged array, to solve the problem effectively.

 We will stick to the same basic approach, but instead of storing elements in a separate array, we will use a counter called 'cnt' to represent the imaginary third array's index. As we traverse through the arrays, when 'cnt' reaches the index (k-1), we will store that particular element. This way, we can achieve the same goal without using any extra space.


   Algorithm/Approach:-
  #  We will declare the counter called ‘cnt’ and initialize it with 0.
  #  Now, as usual, we will take two pointers i and j, where i points to the first element of arr1[] and j points to the first element of arr2[].
  #  Next, using a while loop( while(i < m && j < n)), we will select two elements i.e. arr1[i] and arr2[j], and consider the smallest one among the two. Then, we will increase that specific pointer by 1. In addition to that, in each iteration, we will check if the counter ‘cnt’ hits the indicex (k-1). when 'cnt' reaches that index, we will store that particular element. We will also increase the ‘cnt’ by 1 every time regardless of matching the conditions.
        If arr1[i] < arr2[j] : Check ‘cnt’ to perform necessary operations and increase i and ‘cnt’ by 1
        Otherwise : Check ‘cnt’ to perform necessary operations and increase j and ‘cnt’ by 1.
  #  After that, the left-out elements from both arrays will be copied as it is into the third array. While copying we will again check the above-said conditions for the counter, ‘cnt’ and increase it by 1.
  #  Finally, we will return the value of the k-th element stored in the variable.


   Complexity Analysis:-
  # Time Complexity: O(m+n), where m and n are the sizes of the given arrays.
    Reason: We traverse through both arrays linearly.
  # Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
int kthElement_2(vector<int> &a, vector<int>& b, int m, int n, int k) {
    int ele = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < m) {
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }
    while (j < n) {
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
}





/*// Soln 3: Optimal(using BS) 
   Intuition:
 We are going to use the Binary Search algorithm to optimize the approach.
 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

    Note: Please refer to the article Median of 2 sorted arrays to get a detailed overview of this optimal approach.

   Algorithm:
  #  First, we have to make sure that the arr1[] is the smaller array. If not by default, we will just swap the arrays. Our main goal is to consider the smaller array as arr1[].
  #  Calculate the length of the left half: left = k.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(0, k-n2), and the high will point to min(k, n1) (i.e. n1 = The size of the smaller array, n2 = the size of the bigger array).

  #  Calculate the ‘mid1’ i.e. x and ‘mid2’ i.e. left-x: Now, inside the loop, we will calculate the value of ‘mid1’ using the following formula:

    mid1 = (low+high) // 2 ( ‘//’ refers to integer division)

    mid2 = left-mid1

  #  Calculate l1, l2, r1, and r2: Generally,
        l1 = arr1[mid1-1]
        l2 = arr1[mid2-1]
        r1 = arr1[mid1]
        r1 = arr1[mid2]

        The possible values of ‘mid1’ and ‘mid2’ might be 0 and n1 and n2 respectively. So, to handle these cases, we need to store some default values for these four variables. The default value for l1 and l2 will be INT_MIN and for r1 and r2, it will be INT_MAX.

  #  Eliminate the halves based on the following conditions:
        If l1 <= r2 && l2 <=r1: We have found the answer. Return max(l1, l2).
        If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. So, we have to take less elements from arr1[] and more from arr2[]. In such a scenario, we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid1-1).
        If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. So, we have to take less elements from arr2[] and more from arr1[]. In such a scenario, we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid1+1).
  #  Finally, outside the loop, we will include a dummy return statement just to avoid warnings or errors.
 The steps from 4-6 will be inside a loop and the loop will continue until low crosses high. 


   Complexity Analysis:
  # Time Complexity: O(log(min(m, n))), where m and n are the sizes of two given arrays.
    Reason: We are applying binary search on the range [max(0, k-n2), min(k, n1)]. The range length <= min(m, n).
  # Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
int kthElement_3(vector<int> &a, vector<int>& b, int m, int n, int k) {
    if (m > n) return kthElement_3(b, a, n, m, k);

    int left = k; //length of left half

    //apply binary search:
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m) r1 = a[mid1];
        if (mid2 < n) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}







int main() {

// Soln 1: Brute Force 
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<kthElement_1(a, b, a.size(), b.size(), 5) << '\n';



// Soln 2: Better 
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<kthElement_2(a, b, a.size(), b.size(), 5) << '\n';



// Soln 3: Optimal
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " <<kthElement_3(a, b, a.size(), b.size(), 5) << '\n';






    return 0;
}
