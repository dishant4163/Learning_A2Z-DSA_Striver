/*(Aggressive Cows_Coding Ninja)-> https://bit.ly/3J9ab1B   

bool canWePlace(vector<int>&stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1, lastCowPlaced = stalls[0];

    for (int i=1; i < n; i++) {
        if (stalls[i] - lastCowPlaced >= dist) {
            cntCows++;
            lastCowPlaced = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low =1, high = stalls[n-1] - stalls[0];

    while(low <= high) {
        int mid = low + (high - low)/2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

*/



/* Problem Statement: 
 You are given an array 'arr' of size 'n' which denotes the position of stalls.
 You are also given an integer 'k' which denotes the number of aggressive cows.
 You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
 Find the maximum possible minimum distance.


   Examples:=
Example 1:
 Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
 Result: 3
 Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:

 Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
 Result: 5
 Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force  
   Intuition:- The extremely naive approach is to check all possible distances from 1 to max(stalls[])-min(stalls[]). The maximum distance for which the function canWePlace() returns true, will be our answer.

   Algorithm:-
  #  First, we will sort the given stalls[] array.
  #  We will use a loop(say i) to check all possible distances.
  #  Next, inside the loop, we will send each distance, i, to the function canWePlace() function to check if it is possible to place the cows.
        We will return (i-1), where i is the minimum distance for which the function canWePlace() returns false. Because (i-1) is the maximum distance for which we can place all the cows and for the distances >= i, it becomes impossible.
  #  Finally, if we are outside the loop, we can conclude the minimum possible distance should be max(stalls[])-min(stalls[]). And we will return this value.


   Complexity Analysis:-
  # Time Complexity: O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
    Reason: O(NlogN) for sorting the array. We are using a loop from 1 to max(stalls[])-min(stalls[]) to check all possible distances. Inside the loop, we are calling canWePlace() function for each distance. Now, inside the canWePlace() function, we are using a loop that runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
bool canWePlace1(vector<int> &stalls1, int dist1, int cows1) {
    int n1 = stalls1.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last1 = stalls1[0]; //position of last placed cow.
    for (int i = 1; i < n1; i++) {
        if (stalls1[i] - last1 >= dist1) {
            cntCows++; //place next cow.
            last1 = stalls1[i]; //update the last location.
        }
        if (cntCows >= cows1) return true;
    }
    return false;
}

int aggressiveCows1(vector<int> &stalls1, int k1) {
    int n1 = stalls1.size(); //size of array
    //sort the stalls[]:
    sort(stalls1.begin(), stalls1.end());

    int limit1 = stalls1[n1 - 1] - stalls1[0];
    for (int i = 1; i <= limit1; i++) {
        if (canWePlace1(stalls1, i, k1) == false) {
            return (i - 1);
        }
    }
    return limit1;
}





/*// Soln 2: Optimal(BS)   
   Intuition: 
 We are going to use the Binary Search algorithm to optimize the approach.
 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Upon closer observation, we can recognize that our answer space, represented as [1, (max(stalls[])-min(stalls[]))], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

   Algorithm:-
  #  First, we will sort the given stalls[] array.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to (stalls[n-1]-stalls[0]). As the ‘stalls[]’ is sorted, ‘stalls[n-1]’ refers to the maximum, and ‘stalls[0]’ is the minimum element.
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the boolean value returned by canWePlace():
  #  We will pass the potential distance, represented by the variable 'mid', to the ‘canWePlace()' function. This function will return true if it is possible to place all the cows with a minimum distance of ‘mid’.
        If the returned value is true: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the maximum number. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is greater than the distance we want. This means the numbers greater than ‘mid’ should not be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, outside the loop, we will return the value of high as the pointer will be pointing to the answer.
 The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.

   Note: It is always the opposite polarity. Initially the pointer ‘high’ was in the ‘not-possible’ half and so it ends up in the ‘possible’ half. Similarly, ‘low’ was initially in the ‘possible’ part and it ends up in the ‘not-possible’ part.

   Complexity Analysis:-
  # Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
    Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. Now, inside the canWePlace() function, we are using a loop that runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/ 
bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}








int main() {

// Soln 1: Brute Force
    vector<int> stalls1 = {0, 3, 4, 7, 10, 9};
    int k1 = 4;
    int ans1 = aggressiveCows1(stalls1, k1);
    cout << "The maximum possible minimum distance is: " << ans1 << endl;



// Soln 2: Optimal(BS)
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << endl;




    return 0;
}
