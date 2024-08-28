/*(Finding Sqrt of a number using Binary Search_Coding Ninja)-> https://bit.ly/41AJb1p  



*/

/* Problem Statement: 
 You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.


   Note: 
 The question explicitly states that if the given number, n, is not a perfect square, our objective is to find the maximum number, x, such that x squared is less than or equal to n (x*x <= n). In other words, we need to determine the floor value of the square root of n.

   Examples 
Example 1: Input Format: n = 36
 Result: 6
 Explanation: 6 is the square root of 36.

 Example 2: Input Format: n = 28
 Result: 5
 Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.
*/



#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force(using Linear Search)   
   Intuition:- We can guarantee that our answer will lie between the range from 1 to n i.e. the given number. So, we will perform a linear search on this range and we will find the maximum number x, such that x*x <= n.  

   Algorithm:
  #  We will first declare a variable called ‘ans’.
  #  Then, we will first run a loop(say i) from 1 to n.
  #  Until the value i*i <= n, we will update the variable ‘ans’, with i.
  #  Once, the value i*i becomes greater than n, we will break out from the loop as the current number i, or the numbers greater than i, cannot be our answers. 
  #  Finally, our answer should have been stored in ‘ans’.

   Complexity Analysis:-
  # Time Complexity: O(N), N = the given number.
    Reason: Since we are using linear search, we traverse the entire answer space.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int floorSqrt_1(int n1) {
    int ans1 = 0;
    //Linear Search o the answer space:
    for (int i=0; i<=n1; i++) {
        long long val = i * i;
        if (val <= n1 * 1ll) {
            ans1 = i; 
        } else {
            break;
        }
    }
    return ans1;
}





/*//Soln 2.1:Optimal{Using In-built sqrt() funct} O(logN)}   

   Intuition(Using in-built sqrt() function): 
 A straightforward solution to this problem is to utilize the built-in sqrt() function. This approach doesn't require any code implementation but serves as one of the possible solutions.

   Complexity Analysis:-
  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using the Binary Search algorithm.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int floorSqrt_2(int n2) {
    int ans2 = sqrt(n2);
    return ans2;
}





/*// Soln 2.2: Optimal(using Binary Search)  
   Intuition: We are going to use the Binary Search algorithm to optimize the approach.
 The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.
 Now, we are not given any sorted array on which we can apply binary search. But, if we observe closely, we can notice that our answer space i.e. [1, n] is sorted. So, we will apply binary search on the answer space.

   Algorithm:The steps are as follows:
 We will declare a variable called ‘ans’.
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 1 and the high will point to n.
  #  Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) // 2 ( ‘//’ refers to integer division)
  #  Eliminate the halves accordingly: 
        If mid*mid <= n: On satisfying this condition, we can conclude that the number ‘mid’ is one of the possible answers. So, we will store ‘mid’ in the variable ‘ans’. But we want the maximum number that holds this condition. So, we will eliminate the left half and consider the right half(i.e. low = mid+1).
        Otherwise, the value mid is larger than the number we want. This means the numbers greater than ‘mid’ will not be our answers and the right half of ‘mid’ consists of such numbers. So, we will eliminate the right half and consider the left half(i.e. high = mid-1).
  #  Finally, the ‘ans’ variable will be storing our answer. In addition to that, the high pointer will also point to the same number i.e. our answer. So, we can return either of the ‘ans’ or ‘high’.

 NOTE:- The steps from 2-3 will be inside a loop and the loop will continue until low crosses high.

   Complexity Analysis:-
  # Time Complexity: O(logN), N = size of the given array.
    Reason: We are basically using the Binary Search algorithm.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int floorSqrt(int n) {
    int low =0, high = n;
    //Binary search on the answers:
    while(low <= high) {
        long long mid = low + (high - low)/2;
        long long ans = mid * mid;
        if (ans <= (long long)(n) ) { // typecast int into long long
            //Eliminate the left half:
            low = mid + 1;
        }
        else {
            // Eliminate the right half:
            high = mid - 1;
        }
    }

    return high;
}






int main() {


// Soln 1: Brute Force
    int n1 = 28;
    int ans1 = floorSqrt_1(n1);
    cout << "The floor of square root of " << n1 << " is: " << ans1 << endl;



// Soln 2.1: Optimal{using In-built sqrt() funct}
    int n2 = 28;
    int ans2 = floorSqrt_2(n2);
    cout << "The floor of square root of "<< n2 << " is: "<< ans2 << endl;



// Soln 2.2: Optimal(using Binary Search)
    int n = 28;
    int result = floorSqrt(n);
    cout << "The floor of Square root of " << n << " is: "<<result<<endl;





    return 0;
}
