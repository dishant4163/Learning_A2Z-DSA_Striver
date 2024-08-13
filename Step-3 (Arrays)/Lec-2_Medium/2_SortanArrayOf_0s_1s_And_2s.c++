/*// (Sort an array of 0s, 1s and 2s_Coding Ninja)-> https://bit.ly/3CsgYAa

#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{   // Write your code here
    // 3-Pointers (Dutch National Flag Algo)
    int low = 0, mid = 0, high = n3 - 1;

    while(mid <= high) {
        if (ar3[mid] == 0) {
            swap(ar3[low], ar3[mid]);
            low++;
            mid++;
        }
        else if(ar3[mid] == 1) {
            mid++;
        }
        else {
            swap(ar3[mid], ar3[high]);
            high--;
        }
    }
}

*/

/* Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

*/


#include<bits/stdc++.h>
using namespace std;


/*//Soln 1:Brute Force(use any Sort Algo like Merge)
  Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches). Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the array would arrange the elements in increasing order. 

   Complexity Analysis:-
  # Time Complexity: O(N*logN) {this 4 using MERGE Sort Algo}
  # Space Complexity: O(1)
*/
void mergeAlgo(vector<int> &Arr, int Low, int Mid, int High) {
    vector<int> temp;//Temporary Array
    int left = Low;// starting index of left half of Array
    int right = Mid+1;//starting index of right half of Arr

    //sorting elements in the temporary array in a sorted way

    while(left <= Mid && right <= High) {
        if (Arr[left] <= Arr[right]) {
            temp.push_back(Arr[left]);
            left++;
        }
        else {
            temp.push_back(Arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //
    while(left <= Mid) {
        temp.push_back(Arr[left]);
        left++;
    }

    // if elements on the right half are still left //
    while(right <= High) {
        temp.push_back(Arr[right]);
        right++;
    }

    // Putting all elements from Temporary to Array
    for (int i=Low; i<=High; i++) {
        Arr[i] = temp[i - Low];
    }

}

void mergeSortArray(vector<int> &Arr, int Low, int High) {
    if (Low >= High) return;
    int Mid = Low + (High - Low)/2;
    mergeSortArray(Arr, Low, Mid);//Left Half array
    mergeSortArray(Arr, Mid+1, High);//Right Half array
    mergeAlgo(Arr, Low, Mid, High);// Merging sorted halves
}






/*// Soln 2: Better Approach
   Keeping count of values

   Intuition:- Since in this case there are only 3 distinct values in the array so it's easy to maintain the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values.

   Approach:-
  #  Take 3 variables to maintain the count of 0, 1 and 2.
  #  Travel the array once and increment the corresponding counting variables

   ( let's consider count_0 = a, count_1 = b, count_2 = c )

  #  In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.

   Complexity Analysis:-
  # Time Complxity:- O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
  # Space Complexity: O(1) as we are not using any extra space.
*/
void sortArray2(vector<int> &ar2, int n2) {

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i=0; i < n2; i++) {
        if (ar2[i] == 0) cnt0++;
        else if (ar2[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array
    for (int i=0; i < cnt0; i++) ar2[i] = 0;//Replacing 0's

    for(int i=cnt0; i < cnt0 + cnt1; i++) ar2[i] = 1;//Replacing 1's

    for(int i=cnt0+cnt1; i < n2; i++) ar2[i] = 2;//Replacing 2's
}






/*// Soln 3: Optimal(Dutch National Flag Algo)
  This problem is a variation of the popular DUTCH NATIONAL FLAG ALGORITHM

   Approach:-

        Note: Here in this tutorial we will work based on the value of the mid pointer.

   The steps will be the following:

  #  First, we will run a loop that will continue until mid <= high.
  #  There can be three different values of mid pointer i.e. arr[mid]
    #    If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
    #    If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
    #    If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
    #    In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
  #  Finally, our array should be sorted.

   Complexity Analysis:-
  # Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
void sortArray3(vector<int> &ar3, int n3) {
    // 3-Pointers (Dutch National Flag Algo)
    int low = 0, mid = 0, high = n3 - 1;

    while(mid <= high) {
        if (ar3[mid] == 0) {
            swap(ar3[low], ar3[mid]);
            low++;
            mid++;
        }
        else if(ar3[mid] == 1) {
            mid++;
        }
        else {
            swap(ar3[mid], ar3[high]);
            high--;
        }
    }
}




int main() {

// Soln 1: Brute Force(Merge Sort Algo)
    vector<int> Arr = {0, 2, 1, 2, 0, 1};
    int n1 = 6;
    mergeSortArray(Arr, 0, n1 - 1);
    cout<<"After sorting Array: "<<endl;
    for(int i=0; i < n1; i++) {
        cout << Arr[i]<<" ";
    }
    cout << endl;



// Soln 2: Better
    int n2 = 6;
    vector<int> ar2 = {0, 2, 1, 2, 0, 1};
    sortArray2(ar2, n2);
    cout<<"After sorting: ";
    for (int i=0; i < n2; i++) {
        cout << ar2[i]<<" ";
    }
    cout<<endl;



// Soln 3: Optimal(Dutch National Flag Algo)
    int n3 = 6;
    vector<int> ar3 = {0, 2, 1, 2, 0, 1};
    sortArray3(ar3, n3);
    cout<<"After sorting: ";
    for (int i=0; i < n3; i++) {
        cout << ar3[i]<<" ";
    }
    cout<<endl;



    return 0;
}