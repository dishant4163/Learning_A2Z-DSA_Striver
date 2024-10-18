// Divide two integers without using multiplication, division and mod operator 


/* Divide Two Integers (Coding Ninjas ->  https://shorturl.at/Yjsda  )

#include<bits/stdc++.h>

int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.

	if(dividend == divisor) return 1;

	bool sign = true;
	if(dividend >= 0 && divisor < 0) sign = false;
	else if(dividend <= 0 && divisor > 0) sign = false;

	long n = abs(dividend);
	long d = abs(divisor);
	divisor = abs(divisor);

	long quotient = 0;

	while(n >= d) {
		int cnt = 0;

		while(n >= (d << (cnt+1) )) {
			cnt++;
		}

		quotient += (1 << cnt);
		n -= (d << cnt);
	}

	if(quotient == (1 << 31) && sign) return INT_MAX;
	if(quotient == (1 << 31) && !sign) return INT_MIN;

	return sign ? quotient : -quotient;

} 


*/




#include<bits/stdc++.h>
using namespace std;


/*//Soln-1 Brute Force
  Intuition:- We can simulate division by repeated addition of the divisor until the sum exceeds the dividend. The quotient is then determined by the number of times the divisor was added to reach or slightly exceed the dividend.

    Note: This approach will not handle certain edge cases like negative integers and overflow.


  Algorithm:

 Step 1:Initialise two integer variables sum and cnt to 0.
    sum represents the current accumulated sum.
    cnt represents the quotient

 Step 2: Enter a loop that continues as long as sum + divisor is less than or equal to dividend.
    At each iteration of the loop, increment cnt by 1.
    Add divisor to sum.

Step 3:Return the quotient cnt as a result.


   Complexity Analysis

 # Time Complexity:O(dividend) as in the worst case scenario, divisor is very small compared to dividend, the loop iterates a dividend number of times leading to a linear time complexity. In a balanced case the time complexity will be O(Quotient) as it depends on how many iterations it takes to reach the condition where sum + divisor exceeds dividend.

 # Space Complexity : O(1) as the space complexity remains constant and independent of the input size. Only a fixed amount of memory is required to store the integer variables.
*/
int divide2Int(int Dividend, int Divisor) {
    int Sum = 0; //Initialize a variable to keep track of the current sum.

    int Cnt = 0; //Initialize a variable to count the number of times the divisor is added to the sum.

// Continue looping until the sum plus the divisor is greater than the dividend.
    while(Sum + Divisor <= Dividend) {
        // Increment the counter representing the quotient.
        Cnt++;
        // Add the divisor to the current sum.
        Sum += Divisor;
    }

    return Cnt; // Return the quotient.
}





/*//Soln-2 OPtimal Approach

  Intuition:- Repeated Subtraction is the approach for integer division where we break down the division process by repeatedly subtracting multiples of the divisor from the dividend until the dividend becomes smaller than the divisor.

  Algorithm

 Step 1: Check for Special Cases:
    If N % 4 == 0, the XOR result is N If the divisor is 0, return INT_MAX to handle division by zero.
    If the divisor is 1, return the dividend itself as dividing any number by 1 results in the number itself.
    Check if the dividend is INT_MIN and the divisor is -1, in this case return INT_MAX to prevent overflow.
    Check if the divisor is equal to the dividend, return 1.

 Step 2: Determine Sign of the Result:
        Initialise a boolean to determine the sign of the answer to True.
    If the dividend is positive and the divisor is negative or vice versa, set the sign of the result to negative.

 Step 3: Initialise Result and Take Absolute Value:

    Initialise the result ‘ans’ to 0.
    Take the absolute values of dividend and divisor as numerator ‘n’ and denominator ‘d’.

 Step 4: Perform Division using Repeated Subtraction:

    Use repeated subtraction to perform division. While the numerator is greater than or equal to the denominator, continue on the loop.

 Step 5: Count Doublings of the Divisor:

    Inside the loop, count how many times the denominator can be doubled before exceeding the dividend.
    Add the value corresponding to the current doubling to the result ans.
    Subtract the product of the divisor and the doubled value from the dividend.

 Step 6: Return the result ans with the correct sign based on Step 2.


   Complexity Analysis
  # Time Complexity: O(N/M * log(d))where N is the number of bits required to represent the dividend and M is the number of bits required to represent the divisor. Inside each iteration, there’s a nested loop to find how many times the divisor can be doubled before exceeding the dividend. This nested loop iterates log(divisor) times.

  # Space Complexity : O(1)because it uses only a constant amount of extra space regardless of the size of the input. 

*/
int divideTwoInteger(int dividend, int divisor) {

    // Check if dividend and divisor
    // are equal, return 1 if true
    if(dividend == divisor){
        return 1;
    }

    // Determine the sign of the result,
    // true for positive, false for negative
    bool sign = true;

    // If dividend is positive and
    // divisor is negative, set sign to negative
    if(dividend >= 0 && divisor < 0){
        sign = false;
    }
    // If dividend is negative and divisor
    // is positive, set sign to negative
    else if(dividend <= 0 && divisor > 0){
        sign = false;
    }

    // Take absolute values
    // of dividend and divisor
    long n = abs(dividend);
    long d = abs(divisor);

    // Store original divisor absolute
    // value in divisor variable
    divisor = abs(divisor);

    // Initialize quotient to 0
    long quotient = 0;

    // Perform division using
    // repeated subtraction
    while(n >= d){
        // Count how many times divisor can
        // be doubled before exceeding dividend
        int cnt = 0;
        while(n >= (d << (cnt+1))){
            cnt += 1;
        }

        // Add the value corresponding to the current doubling to the quotient
        quotient += 1 << cnt;// (1<<cnt) means 2 ki pow cnt

        // Subtract the product of divisor & the doubled value from dividend
        n -= (d << cnt); //denominator ki power cnt
    }

// Handle overflow cases
    //If quotient equals (2^31) and the result is supposed to be positive, return INT_MAX
    if(quotient == (1<<31)&&sign){ // (1 << 31) means (2 ki 31)
        return INT_MAX;
    }

    //If quotient equals (2^31) and the result is supposed to be negative, return INT_MIN
    if(quotient == (1 << 31)&& !sign){
        return INT_MIN;
    }
    // Return the quotient with correct sign
    return sign ? quotient: -quotient;



}







int main() {

//Soln-1 BRUTE FORCE
    int Dividend = 45;
    int Divisor = 7;
    cout << "Dividend: " << Dividend << " Divisor: " << Divisor << endl;
    int result = divide2Int(Dividend, Divisor);
    
    cout << "Result of division: " << result << endl;




// SOln-2 Most OPtimal Soln
    int dividend = 45;
    int divisor = 7;
    cout << "Dividend: " << dividend << " Divisor: " << divisor << endl;
    int result = divideTwoInteger(dividend, divisor);
    
    cout << "Result of division: " << result << endl;




    return 0;
}


