/*(Koko Eating Bananas_Coding Ninja)-> https://bit.ly/3CmCKVI   

#include <bits/stdc++.h>

int findMax(vector<int>&v) {
    int maxi = INT_MIN;
    int n = v.size();
    // find the maximum element in the given array
    for (int i=0; i<n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}


int calculateTotalHours(vector<int>&v, int hourly) {
    int totalH = 0;
    int n = v.size();

    for (int i=0; i<n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}


int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int low = 1, high = findMax(v);

    while(low <= high) {
        int mid = low + (high - low) /2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid -1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;// bcz we req mini. no. of bananas
}

*/






#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive):
   Intuition:-
 The extremely naive approach is to check all possible answers from 1 to max(a[]). The minimum number for which the required time <= h, is our answer.

   Algorithm:-
  #  First, we will find the maximum value i.e. max(a[]) in the given array.
  #  We will run a loop(say i) from 1 to max(a[]), to check all possible answers.
  #  For each number i, we will calculate the hours required to consume all the bananas from the pile. We will do this using the function calculateTotalHours(), discussed below.
  #  The first i, for which the required hours <= h, we will return that value of i.


    CalculateTotalHours(a[], hourly):
  #  a[] -> the given array
  #  Hourly -> the possible number of bananas, Koko will eat in an hour.

  #  We will iterate every pile of the given array using a loop(say i).
  #  For every pile i, we will calculate the hour i.e. ceil(v[i] / hourly), and add it to the total hours.
  #  Finally, we will return the total hours.


   Complexity Analysis
  # Time Complexity: O(max(a[]) * N), where max(a[]) is the maximum element in the array and N = size of the array.
    Reason: We are running nested loops. The outer loop runs for max(a[]) times in the worst case and the inner loop runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
/*int findMax1(vector<int>&ar) {
    int maxi = INT_MIN;
    int n1 = ar.size();
    // find the maximum:
    for (int i=0; i<n1; i++) {
        maxi = max(maxi, ar[i]);
    }
    return maxi;
}

int calculateTotalHours1(vector<int>&ar, int hourly1) {
    int totalH1 = 0;
    int n1 = ar.size();
    // find total hours:
    for (int i=0; i<n1; i++) {
        totalH1 += ceil((double)(ar[i]) / (double)(hourly1));
    }
    return totalH1;
}

int minimumRateToEatBananas_1(vector<int> ar, int H) {
    //Find the maximum number:
    int maxi = findMax1(ar);

    //Find the minimum value of k:
    for (int i=1; i <= maxi; i++) {
        int reqTime1 = calculateTotalHours1(ar, i);
        if (reqTime1 <= H) {
            return i;
        }
    }

    //Dummy return statement
    return maxi;
}
*/




/*// Soln 2: Optimal   
   Intuition:
 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Now, we are not given any sorted array on which we can apply binary search. But, if we observe closely, we can notice that our answer space i.e. [1, max(a[])] is sorted. So, we will apply binary search on the answer space.

   Algorithm:
  #  First, we will find the maximum element in the given array i.e. max(a[]).
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to max(a[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the time required if Koko eats ‘mid’ bananas/hr:
  #  We will first calculate the total time(required to consume all the bananas in the array) i.e. totalH using the function calculateTotalHours(a[], mid):
        If totalH <= h: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
        Otherwise, the value mid is smaller than the number we want(as the totalH > h). This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

 The steps from 2-4 will be inside a loop and the loop will continue until low crosses high.

   CalculateTotalHours(a[], hourly):
  #  a[] -> the given array
  #  Hourly -> the possible number of bananas, Koko will eat in an hour.
  #  We will iterate every pile of the given array using a loop(say i).
  #  For every pile i, we will calculate the hour i.e. ceil(v[i] / hourly), and add it to the total hours.
  #  Finally, we will return the total hours.

   Complexity Analysis:-
  # Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
    Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().

  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/








int main() {

/*// Soln 1: Brute Force
    vector<int> ar = {7, 15, 6, 3};
    int H = 8;
    int sol = minimumRateToEatBananas_1(ar, H);
    cout<<"Koko should eat atleast " << sol << " bananas/hr."<< endl;
*/


// Soln 2: Optimal
    vector<int> arr = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(arr, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr." << endl;




    return 0;
}