/*(Find the Smallest Divisor Given a Threshold_Coding Ninja)-> https://bit.ly/3Cl6KB6   

#include<bits/stdc++.h>

int sumByDiv(vector<int>&arr, int div){
	int sum = 0;
	for (int i=0; i<arr.size(); i++) {
		sum += ceil((double)(arr[i]) / (double)(div)); //here div is mid
	}
	return sum;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
    int n = arr.size();
	// whatIf it cannot have divisor 
	// if (n > limit) return -1; //then uncomment this

	int low=1, high = *max_element(arr.begin(), arr.end());

	while(low <= high) {
		int mid = low + (high - low)/2;
		if(sumByDiv(arr, mid) <= limit) {
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
 You are given an array of integers 'arr' and an integer i.e. a threshold value 'limit'. Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.

   Examples:
 Example 1:
 Input Format: N = 5, arr[] = {1,2,3,4,5}, limit = 8
 Result: 3
 Explanation: We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
 The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor. Upon dividing all the elements of the array by 3, we get 1,1,1,2,2 respectively. Now, their sum is equal to 7 <= 8 i.e. the threshold value. So, 3 is the minimum possible answer.


Example 2:
 Input Format: N = 4, arr[] = {8,4,2,3}, limit = 10
 Result: 2
 Explanation: If we choose 1, we get 17 as the sum. If we choose 2, we get 9(4+2+1+2) <= 10 as the answer. So, 2 is the answer.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
   Intuition:- The extremely naive approach is to check all possible divisors from 1 to max(arr[]). The minimum number for which the result <= threshold value, will be our answer.


   Algorithm:
  #  We will run a loop(say d) from 1 to max(arr[]) to check all possible divisors.
  #  To calculate the result, we will iterate over the given array using a loop. Within this loop, we will divide each element in the array by the current divisor, d, and sum up the obtained ceiling values.
  #  Inside the outer loop, If result <= threshold: We will return d as our answer.
  #  Finally, if we are outside the nested loops, we will return -1.


   Complexity Analysis:
  # Time Complexity: O(max(arr[])*N), where max(arr[]) = maximum element in the array, N = size of the array.
    Reason: We are using nested loops. The outer loop runs from 1 to max(arr[]) and the inner loop runs for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/  
int smallestDivisor1(vector<int>&ar1, int limit1) {
    int n1 = ar1.size();
    //Find the maximum element:
    int maxi = *max_element(ar1.begin(), ar1.end());

    //Find the smallest divisor:
    for(int d=1; d<= maxi; d++) {
        //Find the summation result:
        int sum1 = 0;
        for (int i=0; i<n1; i++) {
            sum1 += ceil((double)(ar1[i])/(double)(d));
        }
        if (sum1 <= limit1) return d;
    }
    return -1;//dummy statement
}





/*// Soln 2: Optimal(BS)      
   Intuition:- The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Now, we are not given any sorted array on which we can apply binary search. Upon closer observation, we can recognize that our answer space, represented as [1, max(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.


   Algorithm:
  #  If n > threshold: If the minimum summation i.e. n > threshold value, the answer does not exist. In this case, we will return -1.
  #  Next, we will find the maximum element i.e. max(arr[]) in the given array.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to max(arr[]).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves based on the summation of division results:
  #  We will pass the potential divisor, represented by the variable 'mid', to the 'sumByD()' function. This function will return the summation result of the division values.
        If result <= threshold: On satisfying this condition, we can conclude that the number ‘mid’ is one of our possible answers. But we want the minimum number. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
        Otherwise, the value mid is smaller than the number we want. This means the numbers greater than ‘mid’ should be considered and the right half of ‘mid’ consists of such numbers. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
  #  Finally, outside the loop, we will return the value of low as the pointer will be pointing to the answer.

 The steps from 3-4 will be inside a loop and the loop will continue until low crosses high.

    The algorithm for sumByD() is given below:
 sumByD(arr[], div):
 arr[] -> the given array, div -> the divisor.
  #  We will run a loop to iterate over the array.
  #  We will divide each element by ‘div’, and consider the ceiling value.
  #  With that, we will sum up the ceiling values as well.
  #  Finally, we will return the summation. 


   Complexity Analysis:-
  # Time Complexity: O(log(max(arr[]))*N), where max(arr[]) = maximum element in the array, N = size of the array.
    Reason: We are applying binary search on our answers that are in the range of [1, max(arr[])]. For every possible divisor ‘mid’, we call the sumByD() function. Inside that function, we are traversing the entire array, which results in O(N).
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int sumByDiv(vector<int>&ar, int div) {
    int n = ar.size();
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += ceil((double)(ar[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>&ar, int limit) {
    int n = ar.size();

    // if there is no divisor
    if (n > limit) return -1;

    int low=1, high= *max_element(ar.begin(), ar.end());
    while(low <= high) {
        int mid = low + (high-low)/2;
        if (sumByDiv(ar, mid) <= limit) {
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
    vector<int> ar1 = {1, 2, 3, 4, 5};
    int limit1 = 8;
    int ans1 = smallestDivisor1(ar1, limit1);
    cout << "The minimum divisor is: " << ans1 << endl;



// Soln 2: Optimal
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << endl;



    return 0;
}

