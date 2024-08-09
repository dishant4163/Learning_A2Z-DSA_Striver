/* (Move all Zeros to the end of the array_Coding Ninja)-> https://bit.ly/3MrYBRa

vector<int> moveZeros(int n, vector<int> a) {
    // Write your code here.
    int j = -1;

    for(int i=0; i<n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //No Non-Zero Numbers
    if(j == -1) {
        return a;
    }

    for(int i=j+1; i<n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }

    return a;
}
*/



#include<bits/stdc++.h>
using namespace std;


// Move all Zeros to the End of the Array
/*// Soln 1. Brute Force Approach
  Algorithm:
  # Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array. 
  # Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array. 
  # The last N-X places of the original array will be then filled with zero. Now, our task is completed.

  Complexity Analysis:-
  # Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
X = no. of non-zero elements, and N-X = total no. of zeros.
Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).

  # Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.

*/

vector<int> moveZeros1(int n1, vector<int> arr1) {
    // temporary array:
    vector<int> temp1;
    // copy non-zero elements
    // from original -> Temp Array:
    for (int i=0; i<n1; i++) {
        if (arr1[i] != 0) {
            temp1.push_back(arr1[i]);
        }
    }

    // number of non-zero elements
    int nz1 = temp1.seize();

    //copy elements from temp
    //fill first nz fields of original array:
    for (int i=0; i<nz1; i++) {
        arr1[i] = temp1[i];
    }

    //fill rest of the cells with 0:
    for (int i=nz1; i<n1; i++) {
        arr1[i] = 0;
    }
    return arr1;
}





/*// Soln 2. Optimal Approach (2-Pointer)
  Algorithm:

  # First, using a loop, we will place the pointer j. If we don’t find any 0, we will not perform the following steps.
  # After that, we will point i to index j+1 and start moving the pointer using a loop.
  # While moving the pointer i, we will do the following:
    ->   If a[i] != 0 i.e. a[i] is a non-zero element: We will swap a[i] and a[j]. Now, the current j is pointing to the non-zero element a[i]. So, we will shift the pointer j by 1 so that it can again point to the first zero.
  # Finally, our array will be set in the right manner.

  Complexity Analysis:-
  # Time Complexity: O(N), N = size of the array.
Reason: We have used 2 loops and using those loops, we are basically traversing the array once.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

vector<int> moveZeros2(int n2, vector<int> arr2) {
    int j = -1;
    // place the j pointer
    for (int i=0; i<n2; i++) {
        if (arr2[i] == 0) {
            j = i;
            break;
        }
    }

    // no non-zero elements
    if (j == -1) {
        return arr2;
    }

    // Move the pointers i & j and swap accordingly
    for (int i = j + 1; i < n2; i++) {
        if (arr2[i] != 0) {
            swap(arr2[i], arr2[j]);
            j++;
        }
    }
    return arr2;
}



int main() {

// Soln 1. Brute Force Approach
    vector<int> arr1 = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n1 = 10;
    vector<int> ans = moveZeros1(n1, arr1);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';


// Soln 2. Optimal Approach
    vector<int> arr2 = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n2 = 10;
    vector<int> solve = moveZeros2(n2, arr2);
    for (auto &it : solve) {
        cout << it << " ";
    }
    cout << '\n';



    return 0;
}
