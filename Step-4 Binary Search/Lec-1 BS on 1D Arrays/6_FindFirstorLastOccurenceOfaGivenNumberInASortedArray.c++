/*(First or Last Occurrences Of a Given Number in a Sorted Array_Coding Ninja)-> https://bit.ly/3Mdw2FX  

int lowerBound(vector<int> arr, int n, int x) {
    int low=0, high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        // maybe answer
        if(arr[mid] >= x) {
            ans = mid;
            //Look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>&arr, int n, int x) {
    int low=0, high=n-1;
    int ans = n;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        //maybe an answer
        if(arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here.
    int lb = lowerBound(arr, n, k);
    int ub = upperBound(arr, n, k);
    if ((lb == n) || (arr[lb] != k)) return {-1, -1};
    return {lb, ub - 1};
}


*/


/*NOTE:problem solve on coding ninja has diff. soln but have same approach*/

#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(using Naive) 
   Naive solution 
    As the array is already sorted, start traversing the array from the back using a for loop and check whether the element is present or not.
    If the target element is present, break out of the loop and print the resulting index.
    If the target element is not present inside the array, then print -1

   Complexity Analysis:-
  # Time Complexity: O(n) 
  # Space Complexity: O(1) not considering the given array
*/
int solve(vector<int>&arr, int n1, int key) {
    int sol = -1;
    for (int i = n1-1; i >=0; i--) {
        if (arr[i] == key) {
            sol = i;
            break;
        }
    }
    return sol;
}





/*// Soln 2: Optimal(using Binary Search) 
   Approach:

Whenever the word “sorted” or other similar terminologies are used in an array question, BINARY SEARCH can be one of the approaches.
Initially consider the start=0 and the end=n-1 pointers and the result as -1.
Till start does not crossover end pointer compare the mid element 
  #  If the mid element is equal to the key value, store the mid-value in the result and move the start pointer to mid+1(move leftward)
  #  Else if the key value is less than the mid element then end= mid-1(move leftward)
  #  Else do start = mid+1 (move rightwards)

   Complexity Analysis:-
  # Time Complexity: O(log n)
  # Space Complexity: O(1)
*/
int solution(vector<int>&ar, int n, int k) {
    int start = 0, end = n-1;
    int ans = -1;

    while(start <= end) {
        int mid = start + (end - start) / 2;
        if (ar[mid] == k) {
            ans = mid;
            start = mid+1;
        }
        else if (k < ar[mid]){
            end = mid - 1;
        }
        else {
            start = mid+1;
        }
    }
    return ans;
}






int main() {

// Soln 1: Brute Force(using Naive)
    int n1=7, key = 13;
    vector<int> arr = {3,4,13,13,13,20,40};
    // returning the last occurrence index if the element is present otherwise -1
    cout<<"The last Occurrence of "<<key<<" is at " <<solve(arr, n1, key)<<"th index." << endl;



// Soln 2: Optimal(Binary search)
    int n = 7, k=13;
    vector<int> ar = {3,4,13,13,13,20,40};

    // returning the last occurrence index if the element is present otherwise -1
    cout<<"The last Occurrence of "<<k<<" is at " <<solution(ar, n, k)<<"th index." << endl;




    return 0;
}