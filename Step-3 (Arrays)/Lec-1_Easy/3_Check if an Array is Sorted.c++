/*(Check Sorted Array_Coding Ninja)-> https://bit.ly/3Mpo6Tk
int isSorted(int n, vector<int> a) {
    // Write your code here.
    for(int i=1; i<n; i++) {
        if(a[i] >= a[i-1]){

        }
        else {
            return false;
        }
    }
    return true;
}
*/

#include <bits/stdc++.h>
using namespace std;

// Check if an Array is Sorted
/* Soln 1. Brute Force
  Approach:-
  # The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its future elements that are present in the array.
  # If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element until the whole array is traversed.
  # If any of the picked elements is greater than its future elements, Then simply we will return False.
  # If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully then we will simply return True.

  Complexity Analysis:-
  # Time Complexity: O(N^2)
  # Space Complexity: O(1)
*/
bool isSorted(int arr1[], int n1)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = i + 1; j < n1; j++)
        {
            if (arr1[j] < arr1[i])
                ;
            return false;
        }
    }
    return true;
}

/* Soln 2. Optimal Approach: Efficient (Single traversal)
  Approach:-
  # As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
  # So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
  # We will check every element with its previous element if the previous element is smaller than or equal to the current element then we will move to the next index.
  # If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). Then we will return True else return False.

  Complexity Analysis:-
  # Time Complexity: O(N)
  # Space Complexity: O(1)
*/
bool isSorted2(int arr2[], int n2)
{
    for (int i = 1; i < n2; i++)
    {
        if (arr2[i] < arr2[i - 1])
            return false;
    }
    return true;
}

int main() {
// Check if an Array is Sorted
// Soln->1 Brute Force
int arr1[] = {1, 2, 3, 4, 5}, n6=5;
bool ans = isSorted(arr1, n1);
if (ans) {
    cout << "True" << endl;
}
else {
    cout << "False" << endl;
}


// Soln->2 Optimal Approach
int arr7[] = {1, 2, 3, 4, 5}, n7 = 5;
bool ans2 = isSorted2(arr7, n7);
if (ans2) {
    cout << "True"<<endl;
}
else{
    cout<<"False"<<endl;
}



    return 0;
}