/*//(Next Permutation : Find Next Lexicographically Greater Permutation_Coding Ninja)-> https://bit.ly/3qoj5iQ 

#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int ind = -1;
    for (int i = n-2; i >=0; i--) {
        if(permutation[i] < permutation[i+1]) {
            ind = i;
            break;
        }
    }
    if(ind == -1) {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    for (int i = n-1; i>ind; i--) {
        if(permutation[i] > permutation[ind]) {
            swap(permutation[i], permutation[ind]);
            break;
        }
    }

    reverse(permutation.begin() + ind + 1, permutation.end());    

    return permutation;
}

*/


/*Problem Statement:-
Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force via Recursion(Finding all possible permutations)
   Approach :

Step 1: Find all possible permutations of elements present and store them in sorted manner.
Step 2: Search input from all possible permutations.
Step 3: Print the next permutation present right after it.

   Complexity Analysis:-
  # Time Complexity:- For finding, all possible permutations, it is taking N!xN. N represents the number of elements present in the input array. Also for searching input arrays from all possible permutations will take N!. Therefore, it has a Time complexity of O(N!xN).

  # Space Complexity :- Since we are not using any extra spaces except stack spaces for recursion calls. So, it has a space complexity of O(1).
*/
void printArray(const vector<int>& arr) { // Function to print the array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Recursive function to generate all permutations
void permute(vector<int>& arr, int l, int r, vector<vector<int>>& permutations) {
    if (l == r) {
        permutations.push_back(arr);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(arr[l], arr[i]);
        permute(arr, l + 1, r, permutations);
        swap(arr[l], arr[i]); // backtrack
    }
}

// Function to find the next permutation in lexicographical order
vector<int> findNextPermutation(const vector<int>& arr, const vector<vector<int>>& permutations) {
    int n = permutations.size();
    // Find the position of the current permutation
    for (int i = 0; i < n; i++) {
        if (permutations[i] == arr) {
            // If we are at the last permutation, return the smallest permutation
            if (i == n - 1) {
                return permutations[0];
            } else {
                return permutations[i + 1];
            }
        }
    }
    // This part should never be reached if the permutations are generated correctly
    return {};
}






/*// Soln 3: Optimal 
   Approach:- The steps are the following:

  #  Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
  #  For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
  #  To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
  #  If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
    So, in this case, we will reverse the whole array and will return it as our answer.
  #  If a break-point exists:
->      Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
->      Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.

   Complexity Analysis:-
  # Time Complexity: O(3N), where N = size of the given array
Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).

  # Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).
*/
vector<int> nextGreaterPermutation(vector<int> &Ar) {
    int N = Ar.size(); // size of the array

    //Step-1: Find the Break point
    int ind = -1;// Break Point
    for (int i = N-2; i >= 0; i--) {
        if (Ar[i] < Ar[i+1]) {
            ind = i; // Index i is the Break point
            break;
        }
    }

    //If break point does not exits
    if (ind == -1) {
        //reverse the whole array
        reverse(Ar.begin(), Ar.end());
        return Ar;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]
    for(int i = N-1; i > ind; i--) {
        if (Ar[i] > Ar[ind]) {
            swap(Ar[i], Ar[ind]);
            break;
        }
    }

    // Step 3: Reverse the right half
    reverse(Ar.begin() + ind + 1, Ar.end());

    return Ar;
}






int main() {

// Soln 1: Brute Force(using Recursion)
vector<int> arr = {1, 3, 2};
    vector<vector<int>> permutations;

    // Generate all permutations of arr
    permute(arr, 0, arr.size() - 1, permutations);

    // Sort permutations lexicographically
    sort(permutations.begin(), permutations.end());

    // Find the next permutation
    vector<int> nextPerm = findNextPermutation(arr, permutations);

    // Print the next permutation
    printArray(nextPerm);





/*// Soln 2: Better Using in-built function
  # C++ provides an in-built function called next_permutation() which directly returns the lexicographically next greater permutation of the input.

   Complexity Analysis(for mention code/stl function):-
  # Time Complexity:- O(N)
  # Space Complexity:- O(1)
*/
int Pr[] = {1,3,2};
    
    next_permutation(Pr, Pr + 3);//using in-built function of C++
    cout<<Pr[0]<<" "<<Pr[1]<<" "<<Pr[2];





// Soln 3: OPtimal Approach
    vector<int> Ar = {2, 1, 5, 4, 3, 0, 0};
    vector<int> soln = nextGreaterPermutation(Ar);

    cout<<"The next Permutation is : [";
    for (auto it: soln) {
        cout << it << " ";
    }
    cout<< "]";




    return 0;
}

