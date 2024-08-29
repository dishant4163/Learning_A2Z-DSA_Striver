/*(Capacity to Ship Packages within D Days_Coding Ninja)-> https://bit.ly/43QDpdG   

int findDays(vector<int>&weights, int capacity) {
    int n = weights.size();
    int days = 1; // first day of ship
    int load = 0;
    for (int i=0; i<n; i++) {
        if (load + weights[i] > capacity) {
            days += 1; // move to next day
            load = weights[i];
        }
        else { // load the weights in the same day till capacity
            load += weights[i];
        }
    }
    return days;
}


int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high) {
        int mid = low + (high - low)/2;
        int numOfDays = findDays(weights, mid); // here mid is the capacity of the ship
        if (numOfDays <= d) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

*/



/* Problem Statement: 
 You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.
 The weights of the packages are given in an array 'of weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
 Find out the least-weight capacity so that you can ship all the packages within 'd' days.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force   
   Intuition: The extremely naive approach is to check all possible capacities from max(weights[]) to sum(weights[]). The minimum number for which the required days <= d value, will be our answer.

   Algorithm:
  #  We will use a loop(say cap) to check all possible capacities.
  #  Next, inside the loop, we will send each capacity to the findDays() function to get the number of days required for that particular capacity.
  #  The minimum number, for which the number of days <= d, will be the answer.

   Complexity Analysis:
  # Time Complexity: O(N * (sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
    Reason: We are using a loop from max(weights[]) to sum(weights[]) to check all possible weights. Inside the loop, we are calling findDays() function for each weight. Now, inside the findDays() function, we are using a loop that runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int findDays(vector<int>&weights1, int cap1) {
    int days =1; // first day
    int load1 = 0;
    int n1 = weights1.size();
    for (int i=0; i<n1; i++) {
        if (load1 + weights1[i] > cap1) {
            days += 1; // move to next day
            load1 = weights1[i]; // load the weight
        }
        else {
            // load the weight on the same day
            load1 += weights1[i];
        }
    }
    return days;
}

int leastWeightCapacity1(vector<int> &weights1, int days1) {
    // find maximum & the summation:
    int maxi1 = *max_element(weights1.begin(), weights1.end());
    int sum1 = accumulate(weights1.begin(), weights1.end(), 0);

    for (int i=maxi1; i<=sum1; i++) {
        if (findDays(weights1, i) <= days1) {
            return i;
        }
    }
    return -1; // dummy statement
}





/*// Soln 2: Optimal(BS)   
   Intuition:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Now, we are not given any sorted array on which we can apply binary search. Upon closer observation, we can recognize that our answer space, represented as [max(weights[]), sum(weights[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

   Algorithm:
  #  First, we will find the maximum element i.e. max(weights[]), and the summation i.e. sum(weights[]) of the given array.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to max(weights[]) and the high will point to sum(weights[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the number of days required for the capacity ‘mid’:
    We will pass the potential capacity, represented by the variable 'mid', to the 'findDays()' function. This function will return the number of days required to ship all the weights for the particular capacity, ‘mid’.
        If munerOfDays <= d: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
        Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.
 The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.


   Complexity Analysis:-
  # Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.
    Reason: We are applying binary search on the range [max(weights[]), sum(weights[])]. For every possible answer ‘mid’, we are calling findDays() function. Now, inside the findDays() function, we are using a loop that runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int findDays(vector<int>&weights, int cap) {
    int days = 1;
    int load = 0;
    int n = weights.size();
    for (int i=0; i<n; i++) {
        if (load + weights[i] > cap) {
            days += 1;
            load = weights[i];
        }
        else {
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high) {
        int mid = low + (high - low)/2;
        int numOfDays = findDays(weights, mid);
        if (numOfDays <= days) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}








int main() {

// Soln 1: Brute Force
    vector<int> weights1 = {5, 4, 5, 2, 3, 4, 5, 6};
    int day1 = 5;
    int ans1 = leastWeightCapacity1(weights1, day1);
    cout<< "The minimum capacity should be: "<< ans1<<endl;



// Soln 2: Optimal(BS)
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    int ans = leastWeightCapacity(weights, days);
    cout<< "The minimum capacity should be: "<< ans<< endl;




    return 0;
}
