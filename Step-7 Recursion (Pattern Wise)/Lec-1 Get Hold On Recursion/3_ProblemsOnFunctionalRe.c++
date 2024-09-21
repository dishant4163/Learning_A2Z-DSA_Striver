//Problems on Functional Recursion



#include<bits/stdc++.h>
using namespace std;



/*  Recursive method
   Approach: The recursive method has an approach almost similar to the iterative one. The approach has been broken down into some steps for simplicity.
  -> Create a function that takes an array, start index, and end index of the array as parameters.
  -> Swap the elements present  at the start and end index,
  -> The portion of the array left to be reversed is arr[start+1,end-1]. Make a recursive call to reverse the rest of the array. While calling recursion pass start +1  and ends - 1 as parameters for the shrunk array. Repeat step 2.
  -> Continue recursion as long as the ‘start < end’ condition is satisfied. This is the base case for our recursion.
*/
// Using 2 pointer
/*// Function to print array
void printAr(int ar[], int n) {
    cout << "Reverse array is: " << endl;
    for (int i=0; i < n; i++) {
        cout << ar[i] <<" ";
    }
}

// Reverse an Array uisng 2 ptr
void reverse1Arr(int arr[], int start, int end) {
    if (start > end) return;

    swap(arr[start], arr[end]);
    reverse1Arr(arr, start+1, end-1);
}
*/


// Reverse an Array uisng 1 ptr
void reverse2Arr(int i, int arrr[], int m) {
    if (i >= m/2) return;
    swap(arrr[i], arrr[m-i-1]);
    reverse2Arr(i+1, arrr, m);
}







int main() {

/*// Reverse an Array using 2 pointer
    int n;
    cin >> n;
    int arr[] = {11, 22, 33, 44, 55};
    reverse1Arr(arr, 0, n-1);
    printAr(arr, n);
*/


/*// Reverse an Array using 1 pointer
    int m;
    cin >> m;
    int arr[m];
    for(int i=0; i < m; i++) {
        cin >> arr[i];
    }

    reverse2Arr(0, arr, m);
    //print the Reverse Array
    for(int i=0; i < m; i++) {
        cout <<arr[i] <<" ";
    }
*/






    return 0;
}


