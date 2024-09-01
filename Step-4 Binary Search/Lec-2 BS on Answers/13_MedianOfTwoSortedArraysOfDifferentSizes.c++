/*(Median of Two Sorted Arrays of different sizes_Coding Ninja)-> https://bit.ly/3BtvLJS  

double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1 = a.size();
	int n2 = b.size();
	if (n1 > n2) return median(b, a);

	int n = n1 + n2;
	int left = (n1 + n2 + 1) / 2;
	int low = 0, high = n1;
	while(low <= high) {
		int mid1 = low + (high - low) / 2;
		int mid2 = left - mid1;
		int l1 = INT_MIN, l2 = INT_MIN;
		int r1 = INT_MAX, r2 = INT_MAX;
		if(mid1 < n1) r1 = a[mid1];
		if(mid2 < n2) r2 = b[mid2];
		if(mid1-1 >= 0) l1 = a[mid1 - 1];
		if(mid2-1 >= 0) l2 = b[mid2 - 1];

		if(l1 <= r2 && l2 <= r1) {
			if (n%2 == 1) {
				return max(l1, l2);
			}
			else return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
		}
		else if (l1 > r2) high = mid1 - 1;
		else low = mid1 + 1;
	}
	return 0;
}

*/


/* Problem Statement:-
 Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.


   Examples:-
Example 1:
 Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
 Result: 3.5

Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
 Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
 Result: 3

Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
 Intuition:- The extremely naive approach is to merge the two sorted arrays and then find the median in that merged array.

   How to merge two sorted arrays:
 The word “merge” suggests applying the merge step of the merge sort algorithm. In that step, we essentially perform the same actions as required by this solution. By using two pointers on two given arrays, we fill up the elements into a third array.

   How to find the median:
  #  If the length of the merged array (n1+n2) is even: The median is the average of the two middle elements. index = (n1+n2) / 2, median = (arr3[index] + arr3[index-1]) / 2.0.
  #  If the length of the merged array (n1+n2) is odd: index = (n1+n2) / 2, median = arr3[index].

   Algorithm:-
  #  We will use a third array i.e. arr3[] of size (n1+n2) to store the elements of the two sorted arrays. 
  #  Now, we will take two pointers i and j, where i points to the first element of arr1[] and j points to the first element of arr2[].
  #  Next, using a while loop( while(i < n1 && j < n2)), we will select two elements i.e. arr1[i] and arr2[j], and consider the smallest one among the two. Then, we will insert the smallest element in the third array and increase that specific pointer by 1.
        If arr1[i] < arr2[j]: Insert arr1[i] into the third array and increase i by 1.
        Otherwise: Insert arr2[j] into the third array and increase j by 1.
  #  After that, the left-out elements from both arrays will be copied as it is into the third array.
  #  Now, the third array i.e. arr3[] will be the sorted merged array. Now the median will be the following:
        If the length of arr3[] i.e. (n1+n2) is even: The median is the average of the two middle elements. index = (n1+n2) / 2, median = (arr3[index] + arr3[index-1]) / 2.0.
        If the length of arr3[] i.e. (n1+n2) is odd: index = (n1+n2) / 2,
        median = arr3[index].
  #  Finally, we will return the value of the median.


   Complexity Analysis:-
  # Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
    Reason: We traverse through both arrays linearly.
  # Space Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
    Reason: We are using an extra array of size (n1+n2) to solve this problem.
*/
double median1(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}





/*// Soln 2: Better 
 Intuition:- To optimize the space used in the previous approach, we can eliminate the third array used to store the final merged result. After closer examination, we realize that we only need the two middle elements at indices (n1+n2)/2 and ((n1+n2)/2)-1, rather than the entire merged array, to solve the problem effectively.

 We will stick to the same basic approach, but instead of storing elements in a separate array, we will use a counter called 'cnt' to represent the imaginary third array's index. As we traverse through the arrays, when 'cnt' reaches either index (n1+n2)/2 or ((n1+n2)/2)-1, we will store that particular element. This way, we can achieve the same goal without using any extra space.


   Algorithm:
  #  We will call the required indices as ind2 = (n1+n2)/2 and ind1 = ((n1+n2)/2)-1. Now we will declare the counter called ‘cnt’ and initialize it with 0.
  #  Now, as usual, we will take two pointers i and j, where i points to the first element of arr1[] and j points to the first element of arr2[].
  #  Next, using a while loop( while(i < n1 && j < n2)), we will select two elements i.e. arr1[i] and arr2[j], and consider the smallest one among the two. Then, we will increase that specific pointer by 1.
  #  In addition to that, in each iteration, we will check if the counter ‘cnt’ hits the indices ind1 or ind2. when 'cnt' reaches either index ind1 or ind2, we will store that particular element. We will also increase the ‘cnt’ by 1 every time regardless of matching the conditions.
        If arr1[i] < arr2[j]: Check ‘cnt’ to perform necessary operations and increase i and ‘cnt’ by 1.
        Otherwise: Check ‘cnt’ to perform necessary operations and increase j and ‘cnt’ by 1.
  #  After that, the left-out elements from both arrays will be copied as it is into the third array. While copying we will again check the above-said conditions for the counter, ‘cnt’ and increase it by 1.
  #  Now, let’s call the elements at the required indices as ind1el(at ind1) and ind2el(at ind2):
        If the total length i.e. (n1+n2) is even: The median is the average of the two middle elements. median = (ind1el + ind2el) / 2.0.
        If the total length i.e. (n1+n2) is odd: median = ind2el.
  #  Finally, we will return the value of the median.


   Complexity Analysis:-
  # Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
    Reason: We traverse through both arrays linearly.
  # Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
double median2(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}





/*// Soln 3: Optimal  
   Algorithm:
  #  First, we have to make sure that the arr1[] is the smaller array. If not by default, we will just swap the arrays. Our main goal is to consider the smaller array as arr1[].
  #  Calculate the length of the left half: left = (n1+n2+1) / 2.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 0 and the high will point to n1(i.e. The size of arr1[]).
  #  Calculate the ‘mid1’ i.e. x and ‘mid2’ i.e. left-x: Now, inside the loop, we will calculate the value of ‘mid1’ using the following formula:
    mid1 = (low+high) // 2 ( ‘//’ refers to integer division)
    mid2 = left-mid1
  #  Calculate l1, l2, r1, and r2: Generally,
        l1 = arr1[mid1-1]
        l2 = arr2[mid2-1]
        r1 = arr1[mid1]
        r2 = arr2[mid2]
        The possible values of ‘mid1’ and ‘mid2’ might be 0 and n1 and n2 respectively. So, to handle these cases, we need to store some default values for these four variables. The default value for l1 and l2 will be INT_MIN and for r1 and r2, it will be INT_MAX.
    Eliminate the halves based on the following conditions:
        If l1 <= r2 && l2 <= r1: We have found the answer.
            If (n1+n2) is odd: Return the median = max(l1, l2).
            Otherwise: Return median = (max(l1, l2)+min(r1, r2)) / 2.0
        If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. So, we have to take less elements from arr1[] and more from arr2[]. In such a scenario, we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid1-1).
        If l2 > r1: This implies that we have considered more elements from arr2[] than necessary. So, we have to take less elements from arr2[] and more from arr1[]. In such a scenario, we should try bigger values of x. To achieve this, we will eliminate the left half (low = mid1+1).
  #  Finally, outside the loop, we will include a dummy return statement just to avoid warnings or errors.

 The steps from 4-6 will be inside a loop and the loop will continue until low crosses high.


   Complexity Analysis:-
  # Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
    Reason: We are applying binary search on the range [0, min(n1, n2)].
  # Space Complexity: O(1) as no extra space is used.
*/
double median3(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}







int main() {

// Soln 1: Brute Force
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << median1(a, b) << '\n';



// Soln 2: Better 
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << median2(a, b) << '\n';



// Soln 3: Optimal   
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << median3(a, b) << '\n';






    return 0;
}
