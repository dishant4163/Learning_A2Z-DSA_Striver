/*(Left Rotate an Array by D Places_Coding Ninja)->

*/

#include <bits/stdc++.h>
using namespace std;

// Left Rotate an Array by D Places
// Approach:- Using a temp array
/* Soln 1. >>>   For Rotating the Elements to right   <<<
  # Step 1: Copy the last k elements into the temp array.
  # Step 2: Shift n-k elements from the beginning by k position to the right
  # Step 3: Copy the elements into the main array from the temp array.

  Time Complexity: O(n)
  Space Complexity: O(k) since k array element needs to be stored in temp array
*/
void Rotatetoright(int arr1[], int n1, int k1)
{
    if (n1 == 0)
        return;
    k1 = k1 % n1;
    if (k1 > n1)
        return;
    int temp1[k1];
    for (int i = n1 - k1; i < n1; i++)
    {
        temp1[i - n1 + k1] = arr1[i];
    }
    for (int i = n1 - k1 - 1; i >= 0; i--)
    {
        arr1[i + k1] = arr1[i];
    }
    for (int i = 0; i < k1; i++)
    {
        arr1[i] = temp1[i];
    }
}

/* Soln 2. >>>   For Rotating Elements to Left
  Step 1: Copy the first k elements into the temp array.
  Step 2: Shift n-k elements from last by k position to the left
  Step 3: Copy the elements into the main array from the temp array.

  Time Complexity: O(n)
  Space Complexity: O(k) since k array element needs to be stored in temp array
*/
void Rotatetoleft(int arr2[], int n2, int k2)
{
    if (n2 == 0)
        return;
    k2 = k2 % n2;
    if (k2 > n2)
        return;
    int temp2[k2];
    for (int i = 0; i < k2; i++)
    {
        temp2[i] = arr2[i];
    }
    for (int i = 0; i < n2 - k2; i++)
    {
        arr2[i] = arr2[i + k2];
    }
    for (int i = n2 - k2; i < n2; i++)
    {
        arr2[i] = temp2[i - n2 + k2];
    }
}

// Approach:- Using "Reversal Algorithm"
/* Soln 3. >>> For Rotating Elements to Right <<<
  # Step 1: Reverse the last k elements of the array
  # Step 2: Reverse the first n-k elements of the array.
  # Step 3: Reverse the whole array.
*/
// Function to Reverse the array
void Reverse(int arr3[], int start1, int end1)
{
    while (start1 <= end1)
    {
        int temp3 = arr3[start1];
        arr3[start1] = arr3[end1];
        arr3[end1] = temp3;
        start1++;
        end1--;
    }
}
// Function to Rotate k elements to right
void Rotateeletoright(int arr3[], int n3, int k3)
{
    // Reverse first n-k elements
    Reverse(arr3, 0, n3 - k3 - 1);
    // Reverse last k elements
    Reverse(arr3, n3 - k3, n3 - 1);
    // Reverse whole array
    Reverse(arr3, 0, n3 - 1);
}

/* Soln 4. >>> For Rotating Elements to left <<<
  # Step 1: Reverse the first k elements of the array
  # Step 2: Reverse the last n-k elements of the array.
  # Step 3: Reverse the whole array.
*/
// Function to Reverse the array
void Reverse(int arr4[], int start2, int end2)
{
    while (start2 <= end2)
    {
        int temp4 = arr4[start2];
        arr4[start2] = arr4[end2];
        arr4[end2] = temp4;
        start2++;
        end2--;
    }
}
// Function to Rotate k elements to left
void Rotateeletoleft(int arr4[], int n4, int k4)
{
    // Reverse first k elements
    Reverse(arr4, 0, k4 - 1);
    // Reverse last n-k elements
    Reverse(arr4, k4, n4 - 1);
    // Reverse whole array
    Reverse(arr4, 0, n4 - 1);
}

int main()
{
    // Soln-> 1 For Rotating the Elements to Right
    int n1 = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 2;
    Rotatetoright(arr1, n1, k1);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }

    // Soln-> 2 For Rotating the Elements to Left
    int n2 = 7;
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int k2 = 2;
    Rotatetoleft(arr2, n2, k2);
    cout << "After Rotating the elements to left " << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }

    // Soln-> 3 For Rotating Elements to Right
    int arr3[] = {1, 2, 3, 4, 5, 6, 7};
    int n3 = 7;
    int k3 = 2;
    Rotateeletoright(arr3, n3, k3);
    cout << "After Rotating the k elements to right ";
    for (int i = 0; i < n3; i++)
        cout << arr3[i] << " ";
    cout << endl;

    // Soln-> 4  For Rotating Elements to Left
    int arr4[] = {1, 2, 3, 4, 5, 6, 7};
    int n4 = 7;
    int k4 = 2;
    Rotateeletoleft(arr4, n4, k4);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n4; i++)
        cout << arr4[i] << " ";
    cout << endl;

    return 0;
}
