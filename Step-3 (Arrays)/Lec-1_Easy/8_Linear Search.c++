/*(Linear Search_Coding Ninja)-> https://www.naukri.com/code360/problems/linear-search_6922070?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i=0; i<n; i++){
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}
*/



// Linear Search in C
/*Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:
# Example 1:
  Input: arr[]= 1 2 3 4 5, num = 3
    Output: 2
  Explanation: 3 is present in the 2nd index

# Example 2:
  Input: arr[]= 5 4 3 2 1, num = 5
    Output: 0
  Explanation: 5 is present in the 0th index
*/

/* Solution:-
  # Approach:

-> Given an array
-> We will traverse the whole array and see if the element is present in the array or not
-> If found we will print the index of the element
-> Otherwise, we will print -1.

  # Complexity Analysis:-
  Time Complexity: O(n), where n is the length of the array.
  Space Complexity: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int num) {
    for (int i=0; i<n; i++) {
        if (arr[i] == num) {
            return i;
        }
        else {
            return -1;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int num = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int value = search(arr, n, num);
    cout<< value <<" ";

    return 0;
}
