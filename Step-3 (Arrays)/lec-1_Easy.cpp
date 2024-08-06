// Arrays_DS->Type-: EASY

/*(Largest Element in an Array_Coding Ninja)-> https://bit.ly/3W6bmUF
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = arr[0];

    for(int i=0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}
*/


#include<bits/stdc++.h>
using namespace std;

// I. Find the Largest Element in an Array
/*1. Brute Force Approach (i.e, Sorting Soln & Not Optimal Soln)

  Intuition:-We can sort the array in ascending order, hence the largest element will be at the last index of the array. 

  Approach: 
  #  Sort the array in ascending order.
  #  Print the (size of the array -1)th index.

  Complexity Analysis:
  # TC: O(N*logN) 
  # SC: O(N)
*/
int sortArr(vector<int> &arr1) {
    sort(arr1.begin(), arr1.end());//1st Sort the Array
    return arr1[arr1.size()-1];// & then direct return largest element
}




/*2. Using Max Variable(i.e, Recursive & Optimal Soln)

  Intuition:-We can maintain a max variable that will update whenever the current value is greater than the value in the max variable.  

  Approach: 
  # Create a max variable and initialize it with arr[0].
  # Use a for loop and compare it with other elements of the array
  # If any element is greater than the max value, update max value with the element’s value
  # Print the max variable.

  Complexity Analysis:
  # TC: O(N) 
  # SC: O(1)
*/
int findLargestArr(int arr2[], int n2) {

    int largest = arr2[0];
    for(int i=0; i<n2; i++) {
        if(largest < arr2[i]) {// Or if(a[i] > largest)
            largest = arr2[i];
        }
    }
    return largest;
}





int main() {
// Soln->1.1_Largest Element(Brute Force)
    vector<int> arr1 = {11, 33, 77, 44};
    cout<<"The largest element in the array is "<<sortArr(arr1)<<endl;


// Soln->1.2_Largest Element(Recursive)
    int arr2[] = {12, 96, 60, 36, 84};
    int n2=5;
    int largest = findLargestArr(arr2, n2);
    cout<<"The Largest element in the Array is "<<largest<<endl;




    return 0;
