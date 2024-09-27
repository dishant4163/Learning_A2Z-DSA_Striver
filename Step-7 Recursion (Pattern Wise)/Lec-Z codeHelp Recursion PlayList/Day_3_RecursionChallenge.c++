//Recusrion Day-3 Challenge |  Recursion & Binary Search



#include<bits/stdc++.h>
using namespace std;

//1. Is Array Sorted using Recursion
bool isArrSorted(int arr[], int size) {
    // Base Case
    if(size == 0 || size == 1) return true;

    if (arr[0] > arr[1]) { // array is not sorted
        return false;
    }
    else {
        bool remainingPart = isArrSorted(arr + 1, size - 1);
        return remainingPart;
    }
}






int main() {

//Is Array Sorted using Recursion
    int arr[5] = {2, 4, 6, 9, 9};
    int size = 5;

    int ans = isArrSorted(arr, size);

    if(ans) {
        cout << "Array is Sorted" << endl;
    } else {
        cout << "Array is not Sorted" << endl;
    }







    return 0;
}
