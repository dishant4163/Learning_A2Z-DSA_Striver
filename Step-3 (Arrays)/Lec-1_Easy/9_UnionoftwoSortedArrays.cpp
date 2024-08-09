/* (9_Union of Two Sorted Arrays_Coding Ninja)-> https://bit.ly/42SxAfe

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here.
    int n = a.size();
    int m = b.size();
    // Pointer i & j
    int i=0; 
    int j=0; 
    vector<int> unionArr; //List which will have ans as Union Array

    while(i < n && j < m) {
        if(a[i] <= b[j]) {
            if(unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(j < m) {
        if(unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while(i < n) {
        if(unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    

    return unionArr;
}

*/

/*(10_Intersection of two sorted arrays_Coding Ninja)-> https://bit.ly/3KSSx3Z

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i=0, j=0;
	vector<int> soln;

	while(i < n && j < m) {
		if(arr1[i] < arr2[j]) {
			i++;
		}
		else if (arr2[j] < arr1[i]) {
			j++;
		}
		else {
			soln.push_back(arr1[i]);
			i++;
			j++;
		}
	}

	return soln;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Union of Two Sorted Arrays
// Brute Force
/* Soln 1: Using Set/(same can be done via Map)
Suppose we consider arr1 and arr2 as a single array say arr, then the union of arr1 and arr2 is the distinct elements in arr.

  Example:
    arr1[] = {1,2,3,4,5,6,7,8,9,10}
    arr2[] = {2,3,4,4,5,11,12} 
    arr = arr1 + arr2 = {1,2,3,4,5,67,8,9,
        10,2,3,4,4,5,11,12}

Distinct element in 
    arr = {1,2,3,4,5,6,7,8,9,10,11,12} 
        = Union of arr1 ,arr2.

So using a set we can find the distinct elements because the set does not hold any duplicates. Hence we can find the union of arr1 and arr2.
  #  Why not unordered_set?
    In unordered_set the elements are stored in random order, while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.

    We can also use unordered_set, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.

  Complexity Analysis:-
  # Time Complexity: O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.

Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

  # Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}
*/


vector<int> findUnion1(int arr1[], int arr2[], int n1, int n2) {
    set<int> st;
    vector<int> Union1;
    for (int i=0; i<n1; i++) {
        st.insert(arr1[i]);
    }
    for (int i=0; i<n2; i++) {
        st.insert(arr2[i]);
    }
    for (auto &it : st) {
        Union1.push_back(it);
    }
    return Union1;
}




/*// Soln 2: Optimal  (2 Pointer)
  Approach:
  #  Take two pointers let’s say i,j pointing to the 0th index of arr1 and arr2.
  #  Create an empty vector for storing the union of arr1 and arr2.
  #  From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2 
  #  Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the union vector.

    While traversing we may encounter three cases.

  # arr1[ i ] == arr2[ j ] 
    Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i.

  #  NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we are inserting duplicates which is not desired. So while inserting always check whether the last element in the union vector is equal or not to the element to be inserted. If equal we are trying to insert duplicates, so don’t insert the element, else insert the element in the union. This makes sure that we are not inserting any duplicates in the union because we are inserting elements in sorted order.

  # arr1[ i ]  < arr2[ j ]
    arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
  # arr1[ i ] > arr2[ j ]
    arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.

  Complexity Analysis:-
  # Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

  # Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

-> O(1) {If Space of union ArrayList is not considered}
*/


vector<int> findUnion2(int ar1[], int ar2[], int m1, int m2) {
    int i = 0, j = 0; // pointers
    vector<int> Union2; // Uninon vector
        while (i < m1 && j < m2) {
            if (ar1[i] <= ar2[j]) { // Case 1 and 2
                if (Union2.size() == 0 || Union2.back() != ar1[i])
                Union2.push_back(ar1[i]);
                i++;
            } else { // case 3
                    if (Union2.size() == 0 || Union2.back() != ar2[j])
                    Union2.push_back(ar2[j]);
                    j++;
                }
        }
        // IF any element left in arr1
        while (i < m1) {
            if (Union2.back() != ar1[i])
            Union2.push_back(ar1[i]);
            i++;
        }
        // If any elements left in arr2
        while (j < m2) {
            if (Union2.back() != ar2[j])
            Union2.push_back(ar2[j]);
            j++;
        }
    return Union2;
}




int main() {

// Soln 1. Brute Force Approach
    int n1 = 10, n2 = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int  arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union1 = findUnion1(arr1, arr2, n1, n2);
    cout << "Union of arr1 & arr2 is " << endl;
    for (auto &value: Union1) {
        cout << value <<" ";
    }



// Soln 2. Optimal Approach
    int m1 = 10, m2 = 7;
    int ar1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ar2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union2 = findUnion2(ar1, ar2, m1, m2);
    cout << "Union of arr1 and arr2 is "<<endl;
    for (auto &ans: Union2) {
        cout << ans <<" ";
    }



    return 0;
}