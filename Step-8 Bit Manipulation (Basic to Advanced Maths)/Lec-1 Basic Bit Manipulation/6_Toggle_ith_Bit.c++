// Toogle ith Bit | Toogle K Bits | Coding Ninjas

/* Toogle K Bits (Coding Ninjas ->  https://shorturl.at/HF6kx  )


int toggleKBits(int n, int k) {
    // Write your code here.
    int mask = (1 << k) - 1;

    return n ^ mask; 
}

*/



#include <bits/stdc++.h> 
using namespace std;

// Problem-1
int toggle_ith_Bit(int n, int i) {
    // Write your code here.
    int Mask = (1 << i);

    return n ^ Mask;
}






/* Problem-2 (Toggle K Bits_Coding Ninjas)

  Problem statement:- You are given a 32-bit integer ‘N’. Your task is to toggle the rightmost ‘K’ bits in the given integer and return the new integer.

  For Example :
 If ‘N’ = 12 and ‘K’ = 2:
   The binary representation of 12 is ‘1100’, after toggling rightmost 2 bits, it becomes ‘1111’ i.e. 15. Hence, the answer is 15. 


  Sample Input 1:
2
21 3
40 4

 Sample Output 1:

18
39

  Explanation For Sample Input 1:
In example 1, the binary representation of 21 is '10101'. After toggling rightmost 3 bits, it becomes ‘10010’ which is equal to 18.
In example 2, the binary representation of 40 is ‘101000’. After toggling rightmost 4 bits, it becomes ‘100111’ which is equal to 39.

*/

int toggle_K_Bits(int N, int K) {
    // Write your code here.
    int mask = (1 << K) - 1;

    return N ^ mask;
}







int main() {

// Problem-1
    int n, i;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter the bit position to toggle (i): ";
    cin >> i;
    // Call the function
    int result = toggle_ith_Bit(n, i);
    // Output the result
    cout << "The number after toggling the " << i << "th bit is: " << result << endl;





// Problem-2
    int N, K;
    cin >> N >> K; // Read N and K for each test case
    int Result = toggle_K_Bits(N, K); // Toggle K bits of N
    cout << Result << endl; // Output the result




    return 0;
}





