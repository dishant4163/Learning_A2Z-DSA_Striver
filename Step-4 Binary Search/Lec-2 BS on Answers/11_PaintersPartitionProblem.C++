/*(Painter's Partition Problem_Coding Ninja)-> https://bit.ly/3XM8oFS   

int countPainters(vector<int>&boards, int time) {
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;
    for (int i=0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    // Apply Binary Search
    while(low <= high) {
        int mid = low + (high - low) /2;
        int Painters = countPainters(boards, mid);
        if (Painters > k) {
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
 Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

 Pre-requisite: BS-18. Allocate Books or Book Allocation | Hard Binary Search

   Examples:

Example 1:
 Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
 Result: 10
 Explanation: We can divide the boards into 2 equal-sized partitions, so each painter gets 10 units of the board and the total time taken is 10.

Example 2:
 Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
 Result: 60
 Explanation: We can divide the first 3 boards for one painter and the last board for the second painter.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(using Naive)   
 Intuition:- The extremely naive approach is to check all possible answers from max(arr[]) to sum(arr[]). The minimum time for which we can paint all the boards will be our answer.


   Algorithm:-
  # First, we will find the maximum element and the summation of the given array.
  #  We will use a loop(say time) to check all possible answers from max(arr[]) to sum(arr[]).
  #  Next, inside the loop, we will send ‘time’, to the function countPainters() function to get the number of painters to whom we can allocate the boards.
        The first value of ‘time’, for which the number of painters will be lesser or equal to ‘k’, will be our answer. So, we will return that particular value of ‘time’.
  #  Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.


   Complexity Analysis:
  # Time Complexity: O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPainters() function for each number. Now, inside the countPainters() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
int countPainters1(vector<int> &boards1, int time1) {
    int n1 = boards1.size(); //size of array.
    int painters1 = 1;
    long long boardsPainter1 = 0;
    for (int i = 0; i < n1; i++) {
        if (boardsPainter1 + boards1[i] <= time1) {
            //allocate board to current painter
            boardsPainter1 += boards1[i];
        }
        else {
            //allocate board to next painter
            painters1++;
            boardsPainter1 = boards1[i];
        }
    }
    return painters1;
}

int findLargestMinDistance1(vector<int> &boards1, int k1) {
    int low1 = *max_element(boards1.begin(), boards1.end());
    int high1 = accumulate(boards1.begin(), boards1.end(), 0);

    //Apply Brute Force(linear iteration)
    for (int time = low1; time <= high1; time++) {
      if ((countPainters1(boards1, time)) <= k1) {
        return time;
      }
    }
    return low1;
} 






/*// Soln 2: Optimal(BS)
 Intuition- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Upon closer observation, we can recognize that our answer space, represented as [max(arr[]), sum(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

   Algorithm:-
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(arr[]) and the high will point to sum(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the number of painters returned by countPainters():
  #  We will pass the potential value of time, represented by the variable 'mid', to the ‘countPainters()' function. This function will return the number of painters we need to paint all the boards.
        If painters > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
 The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.

   Complexity Analysis:
  # Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPainters() function for the value of ‘mid’. Now, inside the countPainters() function, we are using a loop that runs for N times.
  # Space Complexity:  O(1) as we are not using any extra space to solve this problem.
*/
int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}







int main() {

// Soln 1: Brute Force
    vector<int> boards1 = {10, 20, 30, 40};
    int k1 = 2;
    int ans1 = findLargestMinDistance1(boards1, k1);
    cout << "The answer is: " << ans1 << endl;



// Soln 2: Optimal
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << endl;





    return 0;
}
