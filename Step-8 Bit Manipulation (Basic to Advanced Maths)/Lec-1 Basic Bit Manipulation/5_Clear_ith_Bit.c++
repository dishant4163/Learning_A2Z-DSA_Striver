// Clear the ith Bit 


#include <bits/stdc++.h>
using namespace std;

// Function to clear the kth bit of n
int clearBit(int n, int k) {
    // Creating the mask by shifting
    // 1 to the left by k positions
    // This creates a mask where the kth
    // bit is 0 and all other bits are 1.

    int mask = ~(1 << k); 
    
    // Clearing the kth bit of n using
    // bitwise AND with the mask
    // This clears the kth bit of n by
    // performing a bitwise AND
    // operation with the mask.

    return (n & mask);
}



int main() {
    int n = 13;
    int k = 2;


    int result = clearBit(n, k);
    
    cout << "Original number: " << n << endl;
    cout << "After clearing the " << k << "th bit to 1: " << result << endl;
    
    return 0;
}

