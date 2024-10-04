//Recusrion Day-5 Challenge | Merge Sort using Recursion 



#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e- mid;

    int *first = new int[len1]; // here we allocate dynaic memory, so in last we have delete it.
    int *second = new int[len2]; // here we allocate dynaic memory, so in last we have delete it.

    // copy values
    int mainArrIndex = s;
    for (int i=0; i < len1; i++) {
        first[i] = arr[mainArrIndex++];
    }

    mainArrIndex = mid + 1;
    for (int i=0; i < len2; i++) {
        second[i] = arr[mainArrIndex++];
    }

    //merge 2 sorted arrays
    int index1 = 0, index2 = 0;
    mainArrIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrIndex++] = first[index1++];
        }
        else {
            arr[mainArrIndex++] = second[index2++];
        }
    }

    while(index1 < len1) {
        arr[mainArrIndex++] = first[index1++];
    }

    while(index2 < len2) {
        arr[mainArrIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}


void mergeSort(int *arr, int s, int e) {
    // Base case
    if (s >= e) return;

    int mid = s + (e-s)/2;

    // left part sort karna h
    mergeSort(arr, s, mid);

    //right part sort karna h
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);
}



int main() {

    int arr[5] = {2, 7, 9, 21, 8};
    int n = 5;

    mergeSort(arr, 0, n-1);

    //printing the sorted array
    for(int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;





    return 0;
}


