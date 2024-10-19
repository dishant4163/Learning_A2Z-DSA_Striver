//Print all Divisors of a given Number

/* // Sum of all divisors 
(Coding Ninjas ->  https://www.naukri.com/code360/problems/sum-of-all-divisors_8360720?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf  )

int sumOfAllDivisors(int n){
	// Write your code here.
	int sum = 0;

	for(int i=1; i <= n; i++) {
		sum += (n/i) * i;
	}

	return sum;
}

*/



#include<bits/stdc++.h>
using namespace std;


//Soln-1 Brute Force
// Function to print all divisors of n and return the count
int printDivisors_1(int n) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) { // Loop from 1 to n
        if (n % i == 0) { // Check if i is a divisor
            ans.push_back(i); // Store the divisor
        }
    }
    
    // Print all divisors
    for (int div : ans) {
        cout << div << " "; // Print each divisor
    }
    cout << endl; // New line after printing all divisors
    
    return ans.size(); // Return the count of divisors
}















int main() {

//Soln-1 Brute Force
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printDivisors_1(n); // Call the function










return 0;
}
