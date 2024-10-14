// Check If ith  Bit is Set or Not

/* Check whether K-th bit is set or not (Coding Ninjas ->  https://shorturl.at/VWE8o  )

bool isKthBitSet(int n, int k) {
    // Write your code here.
    if (n >> (k-1) & 1 != 0) return true; //1 based index
    else return false;
}

*/


#include<bits/stdc++.h>
using namespace std;


bool isKthBitSet(int n, int k) {
    //1 based index
    if (n >> (k-1) & 1 != 0) return true;
    else return false;
}


int main() {

    int n, k;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Enter the bit position to check (1-based index): ";
    cin >> k;

    if (isKthBitSet(n, k)) {
        cout << "The " << k << "th bit of " << n << " is set." << endl;
    } else {
        cout << "The " << k << "th bit of " << n << " is not set." << endl;
    }



    return 0;
}


