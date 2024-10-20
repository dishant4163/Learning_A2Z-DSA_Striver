// Sieve of Eratosthenes : Find all Prime Numbers


/* All prime numbers(based on Sieve of Eratosthenes) (Coding Ninjas ->  https://tinyurl.com/mrycznsk  )


#include<iostream>
#include<vector>
using namespace std;

// bool checkPrime(int n) {
// 	if (n <= 1) return false; //0 & 1 are not prime numbers
// 	if (n == 2 || n == 3) return true; // 2 & 3 are prime numbers

// 	for(int i = 2; i*i <= n; i++) {
// 		if (n%i == 0) return false; //if divisible by i then not prime
// 	}
// 	return true;
// }

vector<int> checkPrime(int n) {
	//declare arr with size (n+1) & initialize with 1(assume all numbers are prime initially)
    vector<int> primeAr(n+1, 1);

    // 0 & 1 are not prime
    primeAr[0] = primeAr[1] = 0;

    // Apply Sieve of Erathosthenes
    for (int i = 2; i*i <= n; i++) {
        if(primeAr[i] == 1) {
            for (int j = i*i; j <= n; j = j+i){
                // Mark multiples of prime numbers as not prime
                primeAr[j] = 0;
            }
        }
    }

    vector<int> ans;
    //collect prime numbers
    for (int i = 2; i <= n; i++) {
        if(primeAr[i] == 1) ans.push_back(i);
    }

    return ans;
}


int main(){

// Read input as specified in the question.
// Print output as specified in the question.

	int n;
	cin >> n;
    vector<int> primes = checkPrime(n);

    for (int it : primes) {
        cout << it << " \n";
    }
    cout << endl;

}


*/




#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
   Intuition:- A brute force approach would be to just iterate over all numbers from 2 to n and for each number check if it is prime or not.

 Algorithm:
 Step 1: Initialise an empty array to store the prime numbers found.

 Step 2:Iterate over numbers from 2 to n (inclusive). For each number i in range:
    Check if i is prime using the methods discussed in Check for Prime. If it is prime, add it to the answer vector.

 Step 3:After iterating over all numbers from 2 to n, return the array containing all prime numbers found.


   Complexity Analysis

 # Time Complexity: O(N*sqrt(N)) where N is the exponent. This is because iterate over numbers from 2 to N and at each iteration we check if the current number is prime.
    To check if a number is prime, we iterate up to its square root, giving a time complexity of O(sqrt(N)).
    Therefore, the overall time complexity of the function is O(N*sqrt(N)).

 # Space Complexity : O(1) as only a constant amount of space is required. The function does not increase with the size of the input and only uses a few variables to store the intermediate values regardless of the size of the exponent. 

*/
bool checkPrime(int N) {
    int cnt = 0;
    for(int i=1; i*i <= N; i++) {
        if(N%i == 0) {
            cnt++;

            if((N/i) != i) {
                cnt++;
            }
        }
    }

// Check if the number of divisors is exactly 2
    if(cnt == 2) {
        return true; // If there are exactly 2 divisors, return true (prime)
    }

    return false; //If the number of divisors is not 2, return false (not prime)

}

vector<int> findAllPrimes1(int x) {
    vector<int> anS;

    for(int i=2; i <= x; i++) {
        if(checkPrime(i) ) {
            anS.push_back(i);
        }
    }

    return anS;
}






/*//Soln-2 OPtimal Soln
  Intuition:-
 Based on the previous approach, the complexity of checking if a number is prime can be optimised using Sieve of Eratosthenes. We can create a list of consecutive integers from 2 to ‘n’.
 Start with the prime number which is 2. Mark all of its multiple greater than 2 as composite (ie. 4, 6, 8, 10 and so on). Find the next number in the list that is not marked as composite. This is the next prime number. Repeat until all numbers up to ‘n’ have to be processed.
 This algorithm efficiently identifies primes because it eliminates composite numbers early in the process. It basically works like a sieve, we just filter the numbers in each iteration, to make our search space smaller and smaller, which makes this more efficient.


  Algorithm:-
 Step 1: Initialise a vector of size n+1 with all elements equal to 1. This vector stores the status of all numbers from 2 to n, whether they are prime or not. Initially, we assume all numbers are prime.

 Step 2: We iterate through all numbers from 2 to the square root of n. For each prime number found, we marks its multiples as not prime starting from i*i up to n.
    We mark multiples of prime numbers as not prime, effectively sieving out composite numbers.

 Step 3: We iterate through numbers 2 to n. For each number i that is prime, we add it to the result vector ans.
    We collect all numbers marked as prime in the answer vector to return as the final result.


   Complexity Analysis:-

 # Time Complexity: O(N + N*log(log(N)))where N is the input number. The outer loop iterates from 2 to the square root of n which is O(sqrt(n)) iterations.
    The inner loop iterates over multiples of each prime number found, marking them as not prime.
    In total, the number of operations performed is: O(n/2 + n/3 + n/5 + ….) = O(n log(log(N))

 # Space Complexity : O(N) where N is the input number as additional space proportional to the input size is needed to store a vector of size ‘n+1’ to store whether each number up to n is prime.
 
*/
vector<int> findAllPrimes(int n) {

//declare arr with size (n+1) & initialize with 1(assume all numbers are prime initially)
    vector<int> primeAr(n+1, 1);

    // 0 & 1 are not prime
    primeAr[0] = primeAr[1] = 0;

    // Apply Sieve of Erathosthenes
    for (int i = 2; i*i <= n; i++) {
        if(primeAr[i] == 1) {
            for (int j = i*i; j <= n; j = j+i){
                // Mark multiples of prime numbers as not prime
                primeAr[j] = 0;
            }
        }
    }

    vector<int> ans;
    //collect prime numbers
    for (int i = 2; i <= n; i++) {
        if(primeAr[i] == 1) ans.push_back(i);
    }

    return ans;
}





int main() {


//Soln-1 Brute Force
    int N;
    cout << "Enter the number: ";
    cin >> N;
    vector<int> primeS = findAllPrimes1(N);

    cout << "Prime numbers less than or equal to " << N << ":" << endl;
    for (int Prime : primeS) {
        cout << Prime << " ";
    }
    cout << endl;




//Soln-2 OPtimal Soln
    int n;
    cout<< "Enter the number: ";
    cin >> n;
    vector<int> primes = findAllPrimes(n);

    cout << "Prime numbers less than or equal to " << n << ":" << endl;
    for (int it : primes) {
        cout << it << " ";
    }
    cout << endl;





    return 0;
}


