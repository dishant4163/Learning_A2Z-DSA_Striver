// Count Prime in a range L-R



#include<bits/stdc++.h>
using namespace std;


/*//Soln-1 Brute Force
 Intuition:-A straightforward brute-force approach would be to iterate over each query in the range of its minimum (left) and maximum (right) endpoint. For each number in the range, check if it is prime or not and increment a counter. Store these counts for each query in an ans vector and return it.


  Algorithm:

 Step 1: Initialise an empty vector ans to store the counts of primes for each query.

 Step 2: Process each query in the queries array. For each query extract the minimum and maximum endpoints.

 Step 3: For each query, Initialise a counter cnt to count the number of primes between the left and right endpoints. Loop through each number in the range left (inclusive) to right and check if it is prime or not.

    To efficiently check is a number is prime or not use the method explained here:Check for Prime

 Step 4: If a number is prime, increment the counter cnt.

 Step 5: Push the count of primes for the current query into the answer vector.

 Step 6: After iterating over all queries, return the ans vector.


   Complexity Analysis

 Time Complexity: O(Q*(R-L+1)*sqrt(N)) where Q is the number of queries, R and L are the endpoints of the range in each query and N is the maximum value in range:-
    The outer loop iterates through each query so it executes Q times.
    For each query, there is a loop that iterates through each number in the range [L, R) hence the number of iterations is R-L+1.
    Inside the inner loop, for each number we iterate up to its square root to check for divisors hence determine if it is prime or not. 

 Space Complexity: O(Q)where Q is the number of queries. For each query, we save a count of prime numbers in the ans vector. Apart from this, only constant additional space is required to store the intermediate variables in checking if a number is prime or not.

*/
bool isPrime(int n) {
    int cnt = 0;

    for(int i=1; i*i <= n; i++) {
        if(n%i == 0) {
            cnt++;

            if(n/i != i) {
                cnt++;
            }
        }
    }

    if(cnt == 2) {
        return true;
    }

    return false;
}

vector<int> countPrimes1(vector<vector<int>>& queries1) {
    vector<int> res;

    for(int i=0; i < queries1.size(); i++) {

        int l = queries1[i][0];
        int r = queries1[i][1];
        int cnt = 0;

        for(int j = l; j < r; j++) {
            if(isPrime(j)) {
                cnt++;
            } 
        }

        res.push_back(cnt);
    }

    return res;
}





/*//Soln-2 Better Soln 

 Intuition:- The time complexity of the previous algorithm approaches very high values as the input scales. The number of queries can be of the magnitude 106 and the difference between the range of each query approaches 105 this leads to a complexity of 1011sqrt(N).

  Using the Sieve of Eratosthenes, we can precompute all prime numbers up to a given limit (such as 106). This eliminates the need to check for each number individually. Once the Sieve is created, checking whether a number is prime or not becomes a constant time operation.
Algorithm:

Step 1: Create a Sieve of Eratosthenes up to the maximum range ie. 106 (or as given in the problem). Read more about creatingSieve of Eratosthenes

Step 2: Initialise an empty vector ans to store the counts of primes of each query.

Step 3: Process each query in the queries input vector.

    Extract the left and right range points of the current query.
    Calculate the number of primes between the left and right endpoints using another loop from left to right index counting the true values.
    Add this count to the answer vector.

Step 4: Return the ans vector containing counts of primes for each query.



   Complexity Analysis

  Time Complexity: O(Q*(R-L+1)) where Q is the number of queries and R and L are the endpoints of the range in each query:
    The outer loop iterates through each query so it executes Q times.
    For each query, there is a loop that iterates through each number in the range [L, R) hence the number of iterations is R-L+1.
    Inside the inner loop, for each number check the Sieve of Eratosthenes to check if a number is prime or not. This is a constant time operation.
    To create the Sieve of Eratosthenes, we require a time complexity of (n*log(log(n)) but since we are creating a Sieve of size 106 for each problem, this complexity remains constant and does not scale with the number of queries or their range.


  Space Complexity:O(Q + N) where Q is the number of queries and N is the maximum possible range (given 105):
    For each query, we save a count of prime numbers in the ans vector.
    Apart from this, only constant additional space is required to store the Sieve which is a boolean array of size N+1 where each element represents whether the corresponding index is prime or not.

*/
vector<int> getSieve2(int n) {
    vector<int> prime(n+1, 1);
    prime[0] = prime[1] = 1;

    for(int i=2; i*i <= n; i++) {
        if(prime[i] == 1) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    return prime;
}

vector<int> countPrimes2(vector<vector<int>>& queries2) {
    vector<int> prime = getSieve2(1000000);
    vector<int> res;

    for(int i=0; i < queries2.size(); i++) {

        int l = queries2[i][0];
        int r = queries2[i][1];
        int cnt = 0;

        for(int j = l; j < r; j++) {
            if(prime[j] == 1) {
                cnt++;
            } 
        }

        res.push_back(cnt);
    }

    return res;
}







/*//Soln-3 OPtimal Soln  (Preffix Sum)
 Intuition:- We can further reduce the time complexity of the previous algorithm by avoiding redundant counting of primes for each index. For each query, we need to continuously count the number of primes between the left and right endpoints. If we pre calculate the count of primes up to each index we can answer each query in constant time complexity.

 Algorithm

Step 1:Create a Sieve of Eratosthenes up to the maximum range ie. 106 (or as given in the problem). Read more about creating a Sieve of Eratosthenes here:

Step 2: Initialise an empty vector ans to store the counts of primes of each query.

Step 3: After generating the Sieve, count the number of primes up to each index. Iterate through the Sieve and count the number of primes encountered so far.

    The Sieve now stores the number of prime numbers up to ‘n’ at that index.

Step 4: Process each query in the queries input vector.

    Extract the left and right range points of the current query.
    Calculate the number of primes between the left and right endpoints by substracting the count of primes at index right from the count of primes at index l-1.
    Add this count to the answer vector.

Step 5: Return the ans vector containing counts of primes for each query.


   Complexity Analysis:-

  Time Complexity: O(Q) where Q is the number of queries and R and L are the endpoints of the range in each query:
    The outer loop iterates through each query so it executes Q times.
    For each query, we extract the primes up to the left and right endpoint which is also constant time.
    Inside the inner loop, for each number check the Sieve of Eratosthenes to check if a number is prime or not. This is a constant time operation.
    To create the Sieve of Eratosthenes, we require a time complexity of (n*log(log(n)) but since we are creating a Sieve of size 106 for each problem, this complexity remains constant and does not scale with the number of queries or their range.


  Space Complexity: O(Q + N) where Q is the number of queries and N is the maximum possible range (given 105):
    For each query, we save a count of prime numbers in the ans vector.
    Apart from this, only constant additional space is required to store the Sieve which is a boolean array of size N+1 where each element represents whether the corresponding index is prime or not.

*/
vector<int> getSieve(int m) {
    vector<int> prime(m+1, 1);
    prime[0] = prime[1] = 0;

    for(int i=2; i*i <= m; i++) {
        if(prime[i] == 1) {
            for(int j=i*i; j < m; j += i) {
                prime[j] = 0;
            }
        }
    }

    return prime;
}

vector<int> countPrimes(vector<vector<int>>& queries) {
    vector<int> prime = getSieve(1000000);
    vector<int> ans;
    int cnt = 0;

    for(int i = 2; i < prime.size(); i++) {
        cnt += prime[i];
        prime[i] = cnt;
    }

    for(int i=0; i < queries.size(); i++) {
        int l = queries[i][0], r = queries[i][1];

        ans.push_back(prime[r] - prime[l-1]);
    }

    return ans;
}





int main() {


//Soln-1 Brute Force
    int Q1 = 3;
    vector<vector<int>> queries1 = {{3, 10}, {8, 20}, {1, 5}};
    cout << "No. of Queries: "<< queries1.size() << endl;
    cout << "Queries: ";
    for(auto query: queries1){
        cout << "("<< query[0]<< ", " << query[1] << ")  ";
    }
    
    vector<int> result = countPrimes1(queries1);
    
    cout << endl<< "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;




//Soln-2 Better Soln
    int Q2 = 3;
    vector<vector<int>> queries2 = {{3, 10}, {8, 20}, {1, 5}};
    cout << "No. of Queries: "<< queries2.size() << endl;
    cout << "Queries: ";
    for(auto query2: queries2){
        cout << "("<< query2[0]<< ", " << query2[1] << ")  ";
    }
    
    vector<int> result2 = countPrimes2(queries2);
    
    cout << endl<< "Number of primes between the ranges: ";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;




//Soln-3 OPtimal Soln
    int Q = 3;
    vector<vector<int>> queries = {{3, 10}, {8, 20}, {1, 5}};
    cout << "No. of Queries: "<< queries.size() << endl;
    cout << "Queries: ";
    for(auto query: queries){
        cout << "("<< query[0]<< ", " << query[1] << ")  ";
    }
    
    vector<int> result = countPrimes(queries);
    
    cout << endl<< "Number of primes between the ranges: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;





    return 0;
}


