// Arrays_DS->Type-: EASY

/*(Largest Element in an Array_Coding Ninja)-> https://bit.ly/3W6bmUF
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = arr[0];

    for(int i=0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}
*/


/*(Find Second Smallest and Second Largest Element in an array)-> https://bit.ly/3OaPohF
// Second Largest Algo
int secondLargest(vector<int> &a, int n) {
    int largest = a[0];
    int seclargest = INT_MIN;

    for(int i=1; i<n; i++) {
        if(a[i] > largest) {
            seclargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > seclargest) {
            seclargest = a[i];
        }
    }
    return seclargest;
}

// Second Smallest Algo
int secondSmallest(vector<int> &a, int n) {
    int smallest = a[0];
    int secsmallest = INT_MAX;

    for(int i=1; i<n; i++) {
        if(a[i] < smallest) {
            secsmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] != smallest && a[i] < secsmallest) {
            secsmallest = a[i];
        }
    }
    return secsmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int seclargest = secondLargest(a, n);
    int secsmallest = secondSmallest(a,n);
    return {seclargest, secsmallest};
}
*/





#include<bits/stdc++.h>
using namespace std;

// I. Find the Largest Element in an Array
/*1. Brute Force Approach (i.e, Sorting Soln & Not Optimal Soln)

  Intuition:-We can sort the array in ascending order, hence the largest element will be at the last index of the array. 

  Approach: 
  #  Sort the array in ascending order.
  #  Print the (size of the array -1)th index.

  Complexity Analysis:
  # TC: O(N*logN) 
  # SC: O(N)
*/
int sortArr(vector<int> &arr1) {
    sort(arr1.begin(), arr1.end());//1st Sort the Array
    return arr1[arr1.size()-1];// & then direct return largest element
}

/*2. Using Max Variable(i.e, Recursive & Optimal Soln)

  Intuition:-We can maintain a max variable that will update whenever the current value is greater than the value in the max variable.  

  Approach: 
  # Create a max variable and initialize it with arr[0].
  # Use a for loop and compare it with other elements of the array
  # If any element is greater than the max value, update max value with the element’s value
  # Print the max variable.

  Complexity Analysis:
  # TC: O(N) 
  # SC: O(1)
*/
int findLargestArr(int arr2[], int n2) {

    int largest = arr2[0];
    for(int i=0; i<n2; i++) {
        if(largest < arr2[i]) {// Or if(a[i] > largest)
            largest = arr2[i];
        }
    }
    return largest;
}





// II. Find Second Smallest and Second Largest Element in an array
/* Soln 1. Brute Force (This approach only works if there are no duplicates)
  Intuition:- What do we do to find the largest or the smallest element present in an array? We ideally sort them and the first element would be the smallest of all while the last element would be the largest. Can we find the second-smallest and second-largest using a similar approach?

  Approach:
  # Sort the array in ascending order
  # The element present at the second index is the second smallest element
  # The element present at the second index from the end is the second largest element

Complexity Analysis:-
  # Time Complexity: O(N*LogN), 4 sorting the array
  # Space Complexity: O(1)
*/
void getElements(int arr3[], int n3) {
    if(n3==0 || n3==1){
        cout<<-1<<" "<<-1<<endl;//edge case when only one element is present in array
    }
    sort(arr3, arr3+n3);
    int small=arr3[1], large=arr3[n3-2];
    cout<<"Second Smallest is "<<small<<endl;
    cout<<"Second Largest is "<<large<<endl;
}

/* Soln 2. Better Approach
  Intuition:- Even though we want to have just the second smallest and largest elements, we are still sorting the entire array for that and thus increasing the time complexity. Can we somehow try to not sort the array and still get our answer?

  Approach:
  # Find the smallest and largest element in the array in a single traversal
  # After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
  # Similarly, we would find the largest element which is just smaller than the largest element we just found
  # Indeed, this is our second smallest and second largest element.

  Complexity Analysis:-
  # Time Complexity: O(N), We do two linear traversals in our array (i.e, O(n)+O(N)=O(2N) & so on...)
  # Space Complexity: O(1)
*/
void getElements(int arr4[], int n4) {
    if(n4==0 || n4==1) {
        cout <<-1<<" "<<-1<<endl; // edge case when only one element is present in array
    }
        int smallEl=INT_MAX, second_small=INT_MAX;
        int largeEl=INT_MIN, second_large=INT_MIN;

        for(int i=0; i<n4; i++) {
            smallEl=min(smallEl, arr4[i]);
            largeEl=max(largeEl, arr4[i]);
        }
        for(int i=0; i<n4; i++) {
            if(arr4[i] < second_small && arr4[i] != smallEl){
                second_small = arr4[i];
            }
            if(arr4[i] > second_large && arr4[i] != largeEl){
                second_large = arr4[i];
            }
        }
        cout<<"Second smallest is " << second_small<<" & "<<"Second largest is "<<second_large<<endl;
    }

/* Soln 3. Optimal Approach(Best Soln)
  Intuition:- In the previous solution, even though we were able to bring down the time complexity to O(N), we still needed to do two traversals to find our answer. Can we do this in a single traversal by using smart comparisons on the go?

  Approach:-
  We would require four variables: small,second_small, large, and second_large. Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

  Second Smallest Algo:-

  #  If the current element is smaller than ‘small’, then we update second_small and small variables
  #  Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
  #  Once we traverse the entire array, we would find the second smallest element in the variable second_small.
  #  Here’s a quick demonstration of the same.

Second Largest Algo:

  #  If the current element is larger than ‘large’ then update second_large and large variables
  #  Else if the current element is larger than ‘second_large’ then we update the variable second_large.
  #  Once we traverse the entire array, we would find the second largest element in the variable second_large.
  #  Here’s a quick demonstration of the same.

  Complexity Analysis:-
  # Time Complexity: O(N), Single-pass solution
  #Space Complexity: O(1)
*/

    // Second Smallest Algo:
int secSmallest(int arr5[], int n5){
    if (n5 < 2){
        return -1;
    }
    int smallEle = INT_MAX, sec_small = INT_MAX;
    for(int i=0; i < n5; i++) {
        if (arr5[i] < smallEle){
            sec_small = smallEle;
            smallEle = arr5[i];
        }
        else if (arr5[i] < sec_small && arr5[i] != smallEle) {
            sec_small = arr5[i];
        }
    }
    return sec_small;
}

    // Second Largest Algo:
int secLargest(int arr5[], int n5) {
    if(n5 < 2){
        return -1;
    }
    int largeEle = INT_MIN, sec_large = INT_MIN;
    for (int i = 0; i < n5; i++) {
        if (arr5[i] > largeEle) {
            sec_large = largeEle;
            largeEle = arr5[i];
        }

        else if (arr5[i] > sec_large && arr5[i] != largeEle) {
            sec_large = arr5[i];
        }
    }
    return sec_large;
}








int main() {
// Soln->1.1_Largest Element(Brute Force)
    vector<int> arr1 = {11, 33, 77, 44};
    cout<<"The largest element in the array is "<<sortArr(arr1)<<endl;

// Soln->1.2_Largest Element(Recursive)
    int arr2[] = {12, 96, 60, 36, 84};
    int n2=5;
    int largest = findLargestArr(arr2, n2);
    cout<<"The Largest element in the Array is "<<largest<<endl;




// II. Find Second Smallest and Second Largest Element in an array SOLN
// Soln->2.1 Brute Force Approach
    int arr3[] = {73, 22, 46, 11, 90};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    getElements(arr3, n3);

// Soln->2.2 Better Approach
int arr4[]={11, 17, 22, 9, 36};
int n4 = sizeof(arr4)/sizeof(arr4[0]);
getElements(arr4, n4);

// Soln->2.3 Optimal Approach
int arr5[] = {17, 21, 49, 8, 72};
int n5 = sizeof(arr5)/sizeof(arr5[0]);
    int secS = secSmallest(arr5, n5), secL = secLargest(arr5, n5);
cout<<"Second smallest is "<<secS<<" & "<<"Second largest is "<<secL<<endl;




    return 0;
