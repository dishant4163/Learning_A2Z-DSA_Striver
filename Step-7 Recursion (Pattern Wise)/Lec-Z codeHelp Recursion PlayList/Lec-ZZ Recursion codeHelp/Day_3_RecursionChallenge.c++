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




//3. Linear Search in Array using Recursion
bool LinearSearch(int ar3[], int size3, int key) {
    // Base Case
    if (size3 == 0) return false;

    if(ar3[0] == key) {
        return true;
    }
    else {
        bool remainingArPart = LinearSearch(ar3 + 1, size3 - 1, key);
        return remainingArPart;
    }
}




//4. Binary Search using Recursion
bool binarySearch(int arr4[], int start, int end, int keyEl) {
    //Base Case-1, if Element not found
    if(start > end) return false;

    //Find Mid
    int mid = start + (end - start) / 2;

    //Base Case-2, if Element Found
    if(arr4[mid] == keyEl) return true;

    if(arr4[mid] < keyEl) { // right wala part, i.e start = mid+1
        return binarySearch(arr4, mid + 1, end, keyEl);
    }
    else { // left wala part, i.e, end = mid - 1
        return binarySearch(arr4, start, mid - 1, keyEl);
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




//Find the Sum of the Elemnents in the Given Array
    int ar[4] = {1, 2, 1, 4};
    int Size = 4;

    int Sum = getArSum(ar, Sum);
    cout << "Sum of the elements in the given Array is " <<Sum << endl;



// Linear Search in Array using Recursion
    int ar3[5] = {3, 5, 1, 2, 6};
    int size3 = 5;
    int key = 1;
    bool ans = LinearSearch(ar3, size3, key);
    if (ans) {
        cout << "Key element is Present " << endl;
    } else {
        cout << "Key element is Absent "<< endl;
    }



// Binary Search using Recursion
    int arr4[5] = {2, 4, 6, 10, 16};
    int size4 = 5;
    int keyEl = 10;

    cout << "Present or not " << binarySearch(arr4, 0, size4 - 1, keyEl) << endl;





    return 0;
}
