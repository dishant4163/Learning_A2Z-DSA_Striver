// Find xor of numbers from L to R


/* (Coding Ninjas ->  https://shorturl.at/cTHaS  )

int xorTill(int n) {
    if(n%4 == 1){
        return 1;
    }
    else if (n%4 == 2) {
        return n+1;
    }
    else if (n%4 == 3) {
        return 0;
    }
    else {
        return n;
    }
}

int findXOR(int L, int R){
    // Write your code here.
    int findXorL = xorTill(L-1);
    int findXorR = xorTill(R);

    return findXorL ^ findXorR;
}

*/



#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force Approach

   Intuition:- A brute force approach would be to calculate the XOR of all numbers from L to R iteratively using a for loop.


  Algorithm:

 Step 1:Initialise a variable ans to store the result of the XOR operations.

 Step 2: Iterate from 1 to n ie. the input number. At each step: Perform XOR operation of the current value of i with the current value of ans and store the result back in ans.

 Step 3:After iterating through all numbers from L to R and return the final value of ans.


   Complexity Analysis

 # Time Complexity:O(R - L + 1 )where R and L are the input range parameters as the algorithm iterates through the entire range from L to R performing constant time XOR operation for each element in the range.

 # Space Complexity : O(1) as only a constant amount of additional memory regardless of size of the input number.
*/
int xOrInRange(int l, int r) {
    int ans = 0;

    for(int i = L; i <= R; i++) {
        ans ^= i;
    }

    return ans;
}






/*//Soln-2 Optimal Approach

   Intuition:- We can use a more optimised approach using bitwise where we find the XOR in range 1 to L-1 and XOR in range 1 to R. We XOR these to results add cancel out all the common XORs before L, leaving us with the XOR of numbers within the range [L, R].


  Algorithm

 Step 1: Define a function that takes an integer n as input and calculates the XOR of numbers from 1 to n based on the pattern:
    If N % 4 == 0, the XOR result is N itself.
    If N % 4 == 1, the XOR result is 1.
    If N % 4 == 2, the XOR result is N + 1.
    If N % 4 == 3, the XOR result is 0.

 Step 2: For the given range [L, R], calculate the XOR of numbers from 1 to L-1 and 1 to R using the function defined in the previous step.

 Step 3: Return the XOR of the range [L, R] by XORing the results of 1 to L-1 and 1 to R.


   Complexity Analysis

 # Time Complexity: O(1)as this approach does not depend on the size of the input number and only performs a series of constant time modulo operations once for L-1 and once for R.

 # Space Complexity : O(1)as only a constant amount of additional memory regardless of size of the input number.
*/
int xorTill(int n) {
    if(n%4 == 1) { 
        return 1;
    }

    else if(n%4 == 2) { 
        return n+1;
    }

    else if(n%4 == 3) { 
        return 0;
    }

    else {
        return n;
    }
}

int xorInRange(int L, int R) {
    int xorTillL = xorTill(L-1);
    int xorTiilR = xorTill(R);

    return xorTillL ^ xorTiilR;
}






int main() {

//Soln-1 Brute Force
    int l = 3;
    int r = 19;
    int anS = xOrInRange(l, r);
    cout << "XOR of of Numbers from " << l;
    cout << " to " << r << ": "<< anS << endl;




//Soln-2 OPtimal Soln
    int L = 3;
    int R = 19;
    int soln = xorInRange(L, R);
    cout << "XOR of of Numbers from " << L;
    cout << " to " << R << ": "<< soln << endl;





    return 0;
}


