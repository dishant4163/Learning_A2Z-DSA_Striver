// Lec-1 of Sorting-I_A2Z DSA Striver


#include<bits/stdc++.h>
using namespace std;


// I. SELECTION SORT (simple It select the minimum & Swap)
// TC of Selection Sort id O(N^2)-> Avg & W TC
void selection_sort(int arr1[], int n1) {
    for (int i=0; i <= n1-2; i++) {
        int mini = i;// i.e initially 0th index is mini
        for (int j=i; j<=n1-1; j++) {
            if(arr1[j] < arr1[mini]) {
                mini = j;
            }
        }
        int temp = arr1[mini];
        arr1[mini] = arr1[i];
        arr1[i] = temp;
    }
}



// II. BUBBLE SORT (simple push the Max. to the last by adjusting swapping)
// TC of Bubble Sort is O(N^2)-> Avg & W TC
    void bubble_sort(int arr2[], int n2) {
        for (int i = n2-1; i >= 0; i--) {
            for(int j=0; j <= i-1; j++) {
                if(arr2[j] > arr2[j+1]) {
                    int temp2 = arr2[j+1];
                    arr2[j+1] = arr2[j];
                    arr2[j] = temp2;
                }
            }
        }
    }



// III. INSERTION SORT (simple takes an element & places it in its correct order)
// TC of Insertion Sort is O(N^2)-> Avg & W TC
void insertion_sort(int arr3[], int n3) {
    for (int i=0; i<=n3; i++) {
        int j=i;
        while(j > 0 && arr3[j-1] > arr3[j] ) {
            int temp = arr3[j-1];
            arr3[j-1] = arr3[j];
            arr3[j] = temp;

            j--;
        }
    }
}


int main() {

// SELECTION SORT
    int n1;
    cin >> n1;
    int arr1[n1];
    for(int i=0; i<n1; i++) {
        cin >> arr1[i];
    }
    selection_sort(arr1, n1);
    // Printing the SORTED Array
    for(int i=0; i<n1; i++) {
        cout << arr1[i] << " ";
    }



// BUBBLE SORT
    int n2;
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++) {
        cin >> arr2[i];
    }
    bubble_sort(arr2, n2);
    for (int i=0; i<n2; i++) {
        cout << arr2[i] << " ";
    }



// INSERTION SORT
    int n3;
    cin >> n3;
    int arr3[n3];
    for (int i=0; i<n3; i++) {
        cin >> arr3[i];
    }
    insertion_sort(arr3, n3);
    for(int i=0; i<n3; i++) {
        cout << arr3[i] << " ";
    }


    return 0;
}

