/*(Left Rotate an Array by One_Coding Ninja)-> https://bit.ly/3W6eBeV
vector<int> rotateArray(vector<int>& arr, int n) {
    // Write your code here.
    int temp = arr[0];
    for(int i=1; i<n; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}
*/

#include <bits/stdc++.h>
using namespace std;

// Left Rotate an Array by One
/* Soln 1. Brute Force
  Intuition:- The rotated array has just a difference that its first element is present at the last index of the array. So if we can just store the element at the first index and then shift all the elements towards the left and at last put the stored element at the last index. We will get th rotated array.

  Approach:- We can take another dummy array of the same length and then shift all elements in the array toward the left and then at the last element store the index of 0th index of the array and print it.

  Complexity Analysis:-
  # Time Complexity: O(n), as we iterate through the array only once.
  # Space Complexity: O(n) as we are using another array of size, same as the given array.
*/
void solve1(int arr1[], int n1)
{
    int temp1[n1];
    for (int i = 1; i < n1; i++)
    {
        temp1[i - 1] = arr1[i];
    }
    temp1[n1 - 1] = arr1[0];
    for (int i = 0; i < n1; i++)
    {
        cout << temp1[i] << " ";
    }
    cout << endl;
}

/*// Soln 2. Optimal Approach
  Approach:- Here, in the given array :

    n = 5,
    arr[] = {1,2,3,4,5}

  At first, we have to shift the array towards the left so, we store the value of the first index in a variable (let it be x).

  Then we iterate the array from the 0th index to the n-1th index(why n-1 i will explain it below)

  And then store the value present in the next index to the current index like this :

    arr[i] = arr[i+1]

  And to prevent its segmentation fault we will iterate it till n-1.

  At last, put the value of variable x in the last index of the array.

  Complexity Analysis:-
  # Time Complexity: O(n), as we iterate through the array only once.
  # Space Complexity: O(1) as no extra space is used
*/
void solve2(int arr2[], int n2)
{
    int tempp2 = arr2[0]; // storing the first element of array in a variable
    for (int i = 0; i < n2 - 1; i++)
    {
        arr2[i] = arr2[i + 1];
    }
    arr2[n2 - 1] = tempp2; // assigned the value of variable at the last index
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
}

int main()
{
    // Left Rotate an Array by One
    // Soln-> 1 Brute Force
    int n1 = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    solve1(arr1, n1);

    // Soln-> 2 Optimal Approach
    int n2 = 5;
    int arr2[] = {1, 2, 3, 4, 5};
    solve2(arr2, n2);

    return 0;
}
