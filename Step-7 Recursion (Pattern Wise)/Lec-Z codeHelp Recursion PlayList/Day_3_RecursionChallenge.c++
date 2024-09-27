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




//2. Find the Sum of the Elemnents in the Given Array
int getArSum(int ar[], int Size) {
    // Base Case
    if(Size == 0) return 0;
    if(Size == 1) return 1;

    int remainingArSum = getArSum(ar + 1, Size - 1);
    int Sum = ar[0] + remainingArSum;
    return Sum;
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



//Find the Sum of the Elemnents in the Given Array
    int ar[4] = {1, 2, 1, 4};
    int Size = 4;

    int Sum = getArSum(ar, Sum);
    cout << "Sum of the elements in the given Array is " <<Sum << endl;







    return 0;
}
