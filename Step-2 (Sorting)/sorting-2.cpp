// Sorting-II_A2Z DSA Striver


#include<bits/stdc++.h>
using namespace std;

// TC of Merge Sort Algo is O(nlogn)
// SC of Merge Sort Algo is O(N)
// 1. MERGE SORT (Divide & Conquer)
//####APPROACH-1_Dividing array into 2 arrays(LOVE BABBAR Soln)

//Merge func 4 merging both parts
void merge(int *arr1, int start, int end) {

    int mid = start + (end-start)/2;

    int len1 = mid - start+1;//declaring len of left array
    int len2 = end - mid;// declaring len of right array

    int *first = new int[len1];//declare left arr with len
    int *second = new int[len2];//declare rigth arr with len

    // copy values from original array new divided arrays
    // for 1st array
    int mainArrIndex= start;
    for (int i=0; i<len1; i++){
        first[i] = arr1[mainArrIndex++];
    }

    //for 2nd array
    mainArrIndex = mid+1;
    for (int i=0; i<len2; i++) {
        second[i] = arr1[mainArrIndex++];
    }

    //Merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrIndex = start;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr1[mainArrIndex++] = first[index1++];
        }
        else {
            arr1[mainArrIndex++] = second[index2++];
        }
    }

    while(index1 < len1 ) {
        arr1[mainArrIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr1[mainArrIndex++] = second[index2++];
    }



}


void mergeSort(int *arr1, int start, int end) {

    //base case
    if(start >= end) {
        return ;
    }

    int mid = start + (end-start)/2;

    //Left part sort karna h
    mergeSort(arr1, start, mid);

    //Right part sort karna h
    mergeSort(arr1, mid+1, end);

    //Merge kardo dono part
    merge(arr1, start, end);

}







//####APPROACH-2_ Using Indexes 4 Merge Sort(STRIVER SOLN)
// Function for merging 2 Arrays

// Coding Ninja (MERGE SORT) Link-> https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbTRKODJMUW51QWhfWVFFOWQzQi1ZZ0lhMm5UQXxBQ3Jtc0tuV2Q3NFdoRnkxMlRIaTVTcDdnRklObTMtSWljeWFCcUZYMGhPRVBJWEgxVVNGZ0t2dXRmVkd1bllQRGtydUh2RjJEZktEbkx2dDRVcXEwV281MXotdjdTY2hJQi1qYnBnc25LbzdYd2NHWU1XdG9PZw&q=https%3A%2F%2Fbit.ly%2F3DN7ccC&v=ogjf7ORKfd8

void merge(vector<int> &arr2, int low, int mid2, int high) {
    vector<int> temp;
    int left = low; // [low to mid] in 1st array
    int right = mid2+1; // [mid+1 to high] in 2nd array
    while(left <= mid2 && right <= high) {
        if(arr2[left] <= arr2[right]) {
            temp.push_back(arr2[left]);
            left++;
        }
        else {
            temp.push_back(arr2[right]);
            right++;
        }
    }


    //If above 'WHILE Loop false then this below 1 happens
    while(left <= mid2) { //on the Left side array
        temp.push_back(arr2[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr2[right]);
        right++;
    }

    // Put them into array & Printing the SORTED array
    for (int i=low; i<=high; i++) {
        arr2[i] = temp[i - low];
    }

}


// Function for Merge Sorting of 2 arrays with sorting
void mergeSol(vector<int> &arr, int low, int high )
// Pass by refernce
{
    if(low == high) return;
    int mid2 = low + (high-low)/2;
    mergeSol(arr2, low, mid2);
    mergeSol(arr2, mid2+1, high);
    merge(arr2, low, mid2, high);

}

//Calling mergeSort func & sorting the array with mering
void mergeSort(vector < int > & arr2, int n2) {
    // Write your code here.
    mergeSol(arr2, 0, n2-1);
}









// 2. QUICK SORT ALGO (Divide & CONQUER)
// BABBAR SOLN
// DECLARING PARTITION Function
    int partition(int arr3[], int s3, int e3) {

    // Find PIVOT
    int pivot = arr3[s3];

    // count no. of elements less than pivot
    int cnt = 0;
    for(int i = s3+1; i<=e3; i++) {
        if(arr3[i] <= pivot) {
            cnt++;
        }
    }

    // Place pivot at right place
    int pivotIndex = s3 + cnt;
    swap(arr3[pivotIndex], arr3[s3]);

    //Left & Right wala part sambhal lete h
    int i = s3, j = e3;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr3[i] <= pivot)
        {
            i++;
        }

        while(arr3[j] > pivot)
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr3[i++], arr3[j--]);
        }
    }

    return pivotIndex;

}


// DECLARING QUICKSORT Function
void quickSort1(int arr3[], int s3, int e3) {

    // BASE CASE
    if(s3 >= e3)
        return;
    // PARTITION Karnege
    int p = partition(arr3, s3, e3);
    // LEFT part sort karnege
    quickSort1(arr3, s3, p-1);
    // RIGHT Part sort karenge
    quickSort1(arr3, p+1, e3);

}








// STRIVER SOLN 
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i=low, j=high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while(arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if(i<j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickS(vector<int> &arr, int low,  int high) {
    if(low < high) {
        int pIndex = partition(arr, low, high);
        quickS(arr, low, pIndex - 1);
        quickS(arr, pIndex+1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{

    quickS(arr, 0, arr.size()-1);//Striver
    return arr;

}











int main () {

// Merge Sort (via creating 2 arrays)
// Method using dividing into 2 arrays (Love Babbar)
    int n1 = 5;
    int arr1[5] = {2, 5, 1, 6, 9};
    // calling mergeSort func
    mergeSort(arr1, 0, n1-1);
    //printing sorted array
    for (int i=0; i<n1; i++) {
        cout << arr1[i] << " ";
    }






// Quick Sort
// Babbar Method
    int arr3[5] = {2, 4, 1, 6, 9};
    int n3 = 5;
    // Calling Quick Sort Function
    quickSort1(arr3, 0, n3-1);
    // printing sorted array
    for (int i=0; i<n3; i++)
    {
        cout << arr3[i] << " ";
    } cout << endl;




    



    return 0;
}

