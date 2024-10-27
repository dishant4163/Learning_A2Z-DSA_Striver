// Modular Exponentiation 


/* Modular Exponentiation_Coding Ninjas-> ( https://shorturl.at/IHLgn )


#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long ans = 1;  // Use long long to handle large values
    long long base = x % m; // Take base modulo m

    while (n > 0) {
        if (n % 2 == 1) { // If n is odd
            ans = (ans * base) % m; // Multiply result with the base
        }
        base = (base * base) % m; // Square the base
        n /= 2; // Divide n by 2
    }
    return ans;
}

*/ 

#include<bits/stdc++.h>
using namespace std;

int modularExponentiation(int x, int n, int m) {
    long long ans = 1;  // Use long long to handle large values
    long long base = x % m; // Take base modulo m

    while (n > 0) {
        if (n % 2 == 1) { // If n is odd
            ans = (ans * base) % m; // Multiply result with the base
        }
        base = (base * base) % m; // Square the base
        n /= 2; // Divide n by 2
    }
    return ans;
}



int main() {

    int x = 2, n = 10, m = 1000;
    cout << "Modular Exponentiation: " << modularExponentiation(x, n, m) << endl; 
    // Output should be 24 (2^10 % 1000)



    return 0;
}


