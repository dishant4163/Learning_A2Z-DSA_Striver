// Check If a Number is Power of 2 or not

/* Power of 2 or Not (Coding Ninjas ->  https://shorturl.at/7q2ES  )

bool isPowerOfTwo(int n) {
    //write your code here:
    return (n > 0) && ((n & (n - 1)) == 0);
}

*/

#include<bits/stdc++.h>
using namespace std;

/* Explanation:

  # Check if (n>0): This ensures that the input number is positive.
  # Check (n & (n−1) == 0): This checks if nn has only one bit set.

Examples:

   For N=4:
 #      Binary of 4 is 100, and 4 - 1 is 011.
 #      100 & 011 = 000 (which is 0), so it returns true.
   For N=5:
 #      Binary of 5 is 101, and 5 - 1 is 100.
 #      101 & 100 = 100 (which is not 0), so it returns false.

*/

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is not a power of two." << endl;
    }



    return 0;
}



