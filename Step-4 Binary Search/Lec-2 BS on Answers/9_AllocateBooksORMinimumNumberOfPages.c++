/*(Allocate Minimum Number of Pages_Coding Ninja)-> https://bit.ly/43ekSb1    

int countStudents(vector<int>&arr, int pages) {
    int n = arr.size();
    int cntstudents = 1;
    long long pagesStudent = 0;
    for (int i=0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else {
            cntstudents++;
            pagesStudent = arr[i];
        }
    }
    return cntstudents;
}


int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    // Write your code here.
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low)/2;
        int cntStu = countStudents(arr, mid);

        if (cntStu > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

*/


/* Problem Statement: 
 Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
 Allocate books in such a way that:
  #  Each student gets at least one book.
  #  Each book should be allocated to only one student.
  #  Book allocation should be in a contiguous manner.
 You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

   Examples:-
 Example 1: 
 Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
 Result: 113
 Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

 Example 2:
 Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
 Result: 71
 Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force   
   Intuition:- The extremely naive approach is to check all possible pages from max(arr[]) to sum(arr[]). The minimum pages for which we can allocate all the books to M students will be our answer.

   Algorithm:
  #  If m > n: In this case, book allocation is not possible and so, we will return -1.
  #  Next, we will find the maximum element and the summation of the given array.
  #  We will use a loop(say pages) to check all possible pages from max(arr[]) to sum(arr[]).
  #  Next, inside the loop, we will send each ‘pages’, to the function countStudents() function to get the number of students to whom we can allocate the books.
        The first number of pages, ‘pages’, for which the number of students will be equal to ‘m’, will be our answer. So, we will return that particular ‘pages’.
  #  Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.


   Complexity Analysis:-
  # Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible numbers of pages. Inside the loop, we are calling the countStudents() function for each number. Now, inside the countStudents() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
int countStudents1(vector<int> &arr1, int pages1) {
    int n1 = arr1.size(); //size of array.
    int students1 = 1;
    long long pagesStudent1 = 0;
    for (int i = 0; i < n1; i++) {
        if (pagesStudent1 + arr1[i] <= pages1) {
            //add pages to current student
            pagesStudent1 += arr1[i];
        }
        else {
            //add pages to next student
            students1++;
            pagesStudent1 = arr1[i];
        }
    }
    return students1;
}

int findPages1(vector<int>& arr1, int n1, int m1) {
    //book allocation impossible:
    if (m1 > n1) return -1;

    int low1 = *max_element(arr1.begin(), arr1.end());
    int high1 = accumulate(arr1.begin(), arr1.end(), 0);

    for (int pages1 = low1; pages1 <= high1; pages1++) {
        if (countStudents1(arr1, pages1) == m1) {
            return pages1;
        }
    }
    return low1;
}





/*// Soln 2: Optimal(BS)   
   Intuition:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Upon closer observation, we can recognize that our answer space, represented as [max(arr[]), sum(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

   Algorithm:
  #  If m > n: In this case, book allocation is not possible and so, we will return -1.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the number of students returned by countStudents():
  #  We will pass the potential number of pages, represented by the variable 'mid', to the ‘countStudents()' function. This function will return the number of students to whom we can allocate the books.
        If students > m: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.


   Complexity Analysis:-
  # Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
int countStudents(vector<int>&arr, int pages) {
  int n = arr.size();
  int cntStudents = 1;
  long long pagesStudents = 0;

  for (int i=0; i<n; i++) {
    if (pagesStudents + arr[i] <= pages) {
    //add pages to current student
      pagesStudents += arr[i];
    }
    else {
    //add pages to next student
      cntStudents++;
      pagesStudents = arr[i];
    }
  }
  return cntStudents;
}


int findPages(vector<int>& arr, int n, int m) {
  //if books allocation is impossible
  if (m > n) return -1;
// low = max(arr):
  int low = *max_element(arr.begin(), arr.end());
// high = sum(arr):
  int high = accumulate(arr.begin(), arr.end(), 0);

  while(low <= high) {
    int mid = low + (high - low) /2;
    int cntStu = countStudents(arr, mid);

    if (cntStu > m) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return low;
}







int main() {

// Soln 1:
    vector<int> ar1 = {25, 46, 28, 49, 24};
    int n1 = 5;
    int m1 = 4;
    int ans1 = findPages(ar1, n1, m1);
    cout << "The answer is: " << ans1 << endl;



// Soln 2:
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << endl;




    return 0;
}