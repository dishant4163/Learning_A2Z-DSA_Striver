/*(Koko Eating Bananas_Coding Ninja)-> https://bit.ly/3CmCKVI   

#include <bits/stdc++.h>

int findMax(vector<int>&v) {
  int maxi = INT_MIN;
  int n = v.size();

  for(int i = 0; i < n; i++){
    maxi = max(maxi, v[i]);
  }
  return maxi;
}


int calculateTotalHours(vector<int> & v, int hourly, int h){
  int n = v.size();
  int totalH = 0;

  for(int i = 0; i < n; i++){
    totalH += ceil( (double) v[i] / (double) hourly );
    //to avoid overflow
    if(totalH > h) break;
  }
  return totalH;
}


int minimumRateToEatBananas(vector<int> v, int h) {
  int low = 1, high = findMax(v);
  while( low <= high ){
    int mid = low + (high - low) / 2;
    int totalH = calculateTotalHours(v, mid, h);
    if( totalH <= h  ){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return low;
}

*/


/* Problem Statement: 
 A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
 Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.

   Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

   Examples
Example 1:
Input Format:
 N = 4, a[] = {7, 15, 6, 3}, h = 8
Result:
 5
Explanation:
 If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.  

Example 2:

Input Format:
 N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Result:
 25
Explanation:
 If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.


Before moving on to the solution, let’s understand how Koko will eat the bananas. Assume, the given array is {3, 6, 7, 11} and the given time i.e. h is 8. 

    First of all, Koko cannot eat bananas from different piles. He should complete the pile he has chosen and then he can go for another pile.
    Now, Koko decides to eat 2 bananas/hour. So, in order to complete the first he will take
    3 / 2 = 2 hours. Though mathematically, he should take 1.5 hrs but it is clearly stated in the question that after completing a pile Koko will not consume more bananas in that hour. So, for the first pile, Koko will eat 2 bananas in the first hour and then he will consume 1 banana in another hour. 


From here we can conclude that we have to take ceil of (3/2). Similarly, we will calculate the times for other piles.

    1st pile: ceil(3/2) = 2 hrs
    2nd pile: ceil(6/2) = 3 hrs
    3rd pile: ceil(7/2) = 4 hrs
    4th pile: ceil(11/2) = 6 hrs


Koko will take 15 hrs in total to consume all the bananas from all the piles. 

Observation: Upon observation, it becomes evident that the maximum number of bananas (represented by 'k') that Koko can consume in an hour is obtained from the pile that contains the largest quantity of bananas. Therefore, the maximum value of 'k' corresponds to the maximum element present in the given array.

So, our answer i.e. the minimum value of ‘k’ lies between 1 and the maximum element in the array i.e. max(a[]).

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
int findMax1(vector<int>&ar) {
    int maxi = INT_MIN;
    int n1 = ar.size();
    // find the maximum:
    for (int i=0; i<n1; i++) {
        maxi = max(maxi, ar[i]);
    }
    return maxi;
}

int calculateTotalHours1(vector<int>&ar, int hourly1, int h) {
    int totalH1 = 0;
    int n1 = ar.size();
    // find total hours:
    for (int i=0; i<n1; i++) {
        totalH1 += ceil((double)(ar[i]) / (double)(hourly1));
        // avoid overflow 
        if(totalH1 > h)
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
int findMax(vector<int>&a) {
    int n = a.size();
    int maxi = INT_MIN;
    for (int i=0; i < n; i++) {
        maxi = max(maxi, a[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int>&a, int mid, int h) {
    //Note:- here mid = time spent in hoursly
    int n = a.size();
    int totalH = 0;
    for (int i=0; i < n; i++) {
        totalH += ceil((double)(a[i]) / (double)(mid));
        //to avoid overflow
        if(totalH > h) break;
    }
    return totalH;
}


int minimumRateToEatBananas(vector<int> a, int h) {
    int low = 1, high=findMax(a);

    while(low <= high) {
        int mid = low + (high - low);
        int totalH = calculateTotalHours(a, mid, h);
        if (totalH <= h) {
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
    vector<int> ar = {7, 15, 6, 3};
    int H = 8;
    int sol = minimumRateToEatBananas_1(ar, H);
    cout<<"Koko should eat atleast " << sol << " bananas/hr."<< endl;



// Soln 2: Optimal
    vector<int> a = {3, 6, 7, 11};
    int h = 8;
    int ans = minimumRateToEatBananas(a, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr." << endl;




    return 0;
}