// Count Set Bits in 1 to N numbers


/* Problem Statement_Coding Ninjas

Problem statement
You are given a positive integer ‘N’. Your task is to find the total number of ‘1’ in the binary representation of all the numbers from 1 to N.

Since the count of ‘1’ can be huge, you are required to return it modulo 1e9+7.

Note:
Do not print anything, just return the number of set bits in the binary representation of all integers between 1 and ‘N’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 10^9

Time limit: 1 second
Sample Input 1:
2
5
3
Sample Output 1:
7
4
Explanation For Sample Input 1 :
In the first test case,

DECIMAL    BINARY      SET BIT COUNT
1            01                  1
2            10                  1
3            11                  2
4            100                 1
5            101                 2
1 + 1 + 2 + 1 + 2 = 7 
Answer = 7 % 1000000007 = 7


In the second test case,

DECIMAL    BINARY      SET BIT COUNT
1            01                  1 
2            10                  1
3            11                  2
1 + 1 + 2 = 4 
Answer = 4 % 1000000007 = 4
Sample Input 2:
2
6
10
Sample Output 2:
9
17


*/



/*  Count Set Bits(hard)_Coding Ninjas -> https://shorturl.at/3luSZ     


const int MOD = 1e9 + 7;

int countSetBits(int n) {
    // Write your code here
    int count = 0;

    // Iterate through each bit position
    for (int i = 0; (1 << i) <= n; ++i) {
        // Full cycles of (1 << (i + 1))
        int total_pairs = n + 1;
        int complete_cycles = total_pairs / (1 << (i + 1));
        int total_set_bits = complete_cycles * (1 << i);

        // Add bits from the remainder part
        int remainder = total_pairs % (1 << (i + 1));
        if (remainder > (1 << i)) {
            total_set_bits += remainder - (1 << i);
        }

        // Ensure to take modulo at each step to prevent overflow
        count = (count + total_set_bits) % MOD;
    }

    return count;
}



*/





#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countSetBits(int n) {
    int count = 0;

    // Iterate through each bit position
    for (int i = 0; (1 << i) <= n; ++i) {
        // Calculate the total pairs of bits in cycles
        int total_pairs = n + 1; // Total numbers from 1 to N inclusive
        int complete_cycles = total_pairs / (1 << (i + 1)); // Number of complete cycles of 0..(1 << (i+1)) - 1
        int total_set_bits = complete_cycles * (1 << i); // Total set bits contributed by complete cycles

        // Add bits from the remainder part
        int remainder = total_pairs % (1 << (i + 1));
        if (remainder > (1 << i)) {
            total_set_bits += remainder - (1 << i); // Count additional set bits in the incomplete cycle
        }

        // Ensure to take modulo at each step to prevent overflow
        count = (count + total_set_bits) % MOD;
    }

    return count;
}




int main() {

    int N;
    cin >> N; // Read each value of N
    cout << countSetBits(N) << endl; // Output the result


    return 0;
}

