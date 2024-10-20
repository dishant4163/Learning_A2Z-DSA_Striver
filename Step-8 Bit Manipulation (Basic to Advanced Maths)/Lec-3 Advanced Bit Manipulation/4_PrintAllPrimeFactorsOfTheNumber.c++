// Print all Prime Factors of the given Number


/* // Count Primes(based on Sieve of Erathosthenes) (Coding Ninjas ->   https://tinyurl.com/dh8wahv6 )



vector<int> countPrimes(int n) {
    // Write your code here.
    vector<int> pr(n+1, 1); //sieve of Eratosthenes is better 99.16

    pr[0] = pr[1] = 0;

    for(int i = 2; i*i <= n; i++) {
        if(pr[i] == 1) {
            for(int j = i*i; j <= n; j += i) {
                pr[j] = 0;
            }
        }
    }

    vector<int> cnt;
    for(int i=2; i <= n; i++) {
        if(n%i == 0 && pr[i] == 1) cnt.push_back(i);
    }

    return cnt;



    // vector<int> ans; // this is 46.27 better

    // for(int i = 2; i*i <= n; i++) {
    //     if(n%i == 0) {
    //         ans.push_back(i);
    //     }

    //     while(n%i == 0) {
    //         n = n/i;
    //     }
    // }

    // if(n != 1) ans.push_back(n);

    // return ans;
    
}


*/



#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force

  Intuition
 First of all, let's understand what the Prime Factor of a number is. Factors are the numbers that can be multiplied to get a new number. The factors of a number that are prime are called Prime Factors. For example: If N=12, 12=2x2x3 here 2 and 3 are prime factors of the 12 and 2^2 x 3 makes up to 12.
 A straightforward approach would be to iterate from 2 to the given number and each step check if that number is a factor of n. As we learnt in the article, Check if a Number if Prime or not, we can determine if a number is prime or not. If a number is both a factor and prime we can print it.


   Algorithm

 Step 1:Initialise an empty vector to store the prime factors of n.

 Step 2: Start a loop from 2 to n and iterate through each number i. At each step:
    Check if n is divisible by i without any remainder.
    If n is divisible by i, call the checkPrime function to determine if i is prime.
    If i is prime, add it to the vector to store the prime factors.

 Step 3: After iterating through all numbers from 2 to n, return the vector containing prime factors


   Complexity Analysis:-
 # Time Complexity: O(N*sqrt(N)) where N is the input number. We iterate through numbers from 2 to n and inside the loop, we check if a number's factor is prime or not. To check that, we iterate up to the square root of it giving it a complexity of sqrt(N).

 # Space Complexity : O(sqrt(N))as the space used by the algorithm depends upon the size of the list to store the prime factors of N. In the worst case, the number of factors if N can be the square root of N.

*/
bool checkPrime1(int x) {
    int cnt = 0;
    for(int i= 1; i*i <= x; i++) {
        // If n is divisible by i without any remainder.
        if(x % i == 0) {
            cnt++;

        // If n is not a perfect square, count its reciprocal factor.
        if(x/i != i) {
            cnt++;
            }
        }
    }
    //If the number of factors is exactly 2.
    if(cnt == 2) return true;
    //Return false, indicating that the number is not prime.
    else return false;
}

vector<int> getPrimeFactors1(int a) {
    vector<int> ans; //for stroing all prime factors

    for(int i = 2; i <= a; i++) {
        if(a%i == 0) {
            if(checkPrime1(i)) {
                ans.push_back(i);
            }
        }
    }

    return ans;
}





/*//Soln-2 Better Approach
   Intuition:- We can optimise the algorithm by only iterating up to the square root of n when checking for prime factors. This is because if n has a factor greater than its square root, it must also have a factor smaller than its square root.
 This property is symmetric about the square root of n by traversing just the first half we can avoid redundant iteration and computations improving the efficiency of the algorithm. Discusses in detail here:Print All Divisiors


  Algorithm

 Step 1: Initialise an empty vector to store the prime factors of n.

 Step 2: Start a loop from 1 to the square root of n and iterate through each number i. At each step:
    Check if n is divisible by i without any remainder. If i is a factor of n then n/i is also a factor.
    If n is divisible by i, call the checkPrime function to determine if i is prime. If i is prime, add it to the array to store the prime factors.
    Check if i is not equal to n/i as i is not a perfect square. If not, check if n/i is prime or not, if it is prime, add it to the array storing prime factors.

 Step 3: After iterating through potential factors of n from 1 to the square root of n, return the array containing the prime factors of n.


   Complexity Analysis

 # Time Complexity: O(2*N)where N is the input number. The loop iterates up to the square root of n check if the factor is prime or not.
    This complexity arises from the loop iterating up to the square root of N and performing operations to check if each factor and its divisor are prime. Within each iteration, two operations with a complexity of O(sqrt(N)) are performed.
    Overall time complexity: O(sqrt(N)*2*sqrt(N)) = O(2*N).


 # Space Complexity : O(sqrt(N)) as the space used by the algorithm depends upon the size of the list to store the prime factors of N. In the worst case, the number of factors if N can be the square root of N.

*/
bool checkPrime2(int b) {
    int cnT = 0;
    for(int i=1; i*i <= b; i++) {
        if(b%i == 0) {
            cnT++;

            if(b/i != i) {
                cnT++;
            }
        }
    }

    if(cnT == 2) { 
        return true; 
    } else { 
        return false; 
    }
}

vector<int> getPrimeFactors2(int b) {
    vector<int> anS;

    for(int i = 1; i*i <= b; i++) {
        if(b%i == 0) {
            if(checkPrime2(i)){
                anS.push_back(i);
            }

            if(b/i != i){
                if(checkPrime2(b/i)) {
                    anS.push_back(b/i);
                }
            }
        }
    }

    return anS;
}





/*//Soln-3 OPtimal 
  Intuition:- A more efficient approach to finding prime factors of a number would be to continuously divide the number by its smallest prime factor until it becomes a prime number itself.


  Algorithm:-

 Step 1: Initialise an empty array to store the prime factors of n.

 Step 2: Start a loop from 1 to the square root of n and iterate through each number i. At each step:
    Check if n is divisible by i without any remainder. If it is divisible, push it into the array to store the prime factors of n.
    Enter a while loop to continuously divide n by i until its no longer divisible. This eliminates repeat factors and ensures each prime factor is included only once.
 Step 3: After iterating through potential factors of n, return the array containing all the unique prime factors of n.


   Complexity Analysis:-

 # Time Complexity: O(sqrt(N)) where N is the input number. This loop runs from 2 up to the square root of n, which means it runs approximately sqrt(n) times. Inside the loop, the operations are basic arithmetic operations and pushing elements into the vector, all of which are constant time operations.

 # Space Complexity: O(sqrt(N)) as the space used by the algorithm depends upon the size of the list to store the prime factors of N. In the worst case, the number of factors if N can be the square root of N.
*/
// Function to get prime factors of a number
vector<int> getPrimeFactors(int num) {
    vector<int> soln; // Vector to store the prime factors

    // Loop from 2 to the square root of num
    for(int i=2; i*i <= num; i++) {
        // Check if i is a factor of num
        if(num % i == 0) {
            soln.push_back(i); // Add i to the list of prime factors
        }

        // Divide num by i until it's no longer divisible
        while(num % i == 0) {
            num = num / i; // Remove the factor i from num
        }
    }

    // If there's any prime factor left in num (greater than 1), add it
    if(num != 1) soln.push_back(num);

    return soln; // Return the list of prime factors
}






int main() {

//Soln-1 Brute Force
    int a;
    cout << "Enter the Number: ";
    cin >> a;
    vector<int> ans = getPrimeFactors1(a);
    cout << "Prime Factors for " << a << ": ";
    for(auto factor: ans){
        cout << factor << " ";
    }
    cout << endl;



//Soln-2 Better Approach
    int b;
    cout << "Enter the Number: ";
    cin >> b;
    vector<int> anS = getPrimeFactors2(b);
    cout << "Prime Factors for " << b << ": ";
    for(auto factoR: anS){
        cout << factoR << " ";
    }
    cout << endl;



//Soln-3 OPtimal Soln
    int num;
    cout << "Enter the number: ";
    cin >> num;
    vector<int> Ans = getPrimeFactors(num);
    cout << "Prime Factors for " << num << ": ";
    for(auto it: Ans) {
        cout << it << " ";
    }
    cout << endl;




    return 0;
}

