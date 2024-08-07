/*(Remove Duplicates from Sorted Array_Coding Ninja)-> https://bit.ly/41GRxEK
int removeDuplicates(vector<int> &arr, int n) {
    int i = 0;
    for (int j = 1; j<n; j++) {
    if(arr[i] != arr[j]) {
        arr[i+1] = arr[i];
        i++;
    }
    }
    return i+1;
}
*/

#include <bits/stdc++.h>
using namespace std;

// Remove Duplicates in-place from Sorted Array
/* Soln 1. Brute Force
  Intuition:- We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.

  Approach:-
  # Declare a HashSet.
  # Run a for loop from starting to the end.
  # Put every element of the array in the set.
  # Store size of the set in a variable K.
  # Now put all elements of the set in the array from the starting of the array.
  # Return K.

  Complexity Analysis:-
  # Time Complexity: O(n*log(n))+O(n)
  # Space Complexity: O(n)
*/
int removeDuplicates(int arr1[], int n1)
{
    set<int> set;
    for (int i = 0; i < n1; i++)
    {
        set.insert(arr1[i]);
    }
    int k = set.size();
    int j = 0;
    for (int x : set)
    {
        arr1[j++] = x;
    }
    return k;
}

/* Soln 2. Optimal Approach (Two pointers)
  Intuition:- We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don't get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j].

  Approach:-
  # Take a variable i as 0;
  # Use a for loop by using a variable ‘j’ from 1 to length of the array.
  # If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
  # After completion of the loop return i+1, i.e size of the array of unique elements.

  Complexity Analysis:-
  # Time Complexity: O(N)
  # Space Complexity: O(1)
*/
int removeDup(int arr1[], int n1)
{
    int i = 0;
    for (int j = 1; j < n1; j++)
    {
        if (arr1[i] != arr1[j])
        {
            i++;
            arr1[i] = arr1[j];
        }
    }
    return i + 1;
}

int main()
{
    // Remove Duplicates in-place from Sorted Array
    // Soln->1 Brute Force
    int arr1[] = {1, 1, 2, 2, 2, 3, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k = removeDuplicates(arr1, n1);
    cout << "Array after removing duplicate element is ";
    for (int i = 0; i < k; i++)
    {
        cout << arr1[i] << " ";
    }

    // Soln->2 Optimal Approach
    int arr2[] = {1, 1, 2, 2, 2, 3, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = removeDup(arr2, n2);
    cout << "Array after removing duplicate element is ";
    for (int i = 0; i < k2; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}
