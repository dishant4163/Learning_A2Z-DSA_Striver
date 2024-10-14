// Set ith Bit


/* Set Bits(count the numbers of 1's in the binary representation of a int)
// Coding Ninjas ->  https://shorturl.at/MR0Io   


int countBits(int n) {
    int i = 1;
    int cnt = 0;
    while(i <= n) {
        if (n & i) cnt++;
        i = i << 1;
    }
    return cnt;
}

*/


#include<bits/stdc++.h>
using namespace std;


//Problem-1
// function to set the kth bit
int setKthBit(int n, int k) {
    // kth bit of n is being set by this operation
    return ((1 << k) | n);
}






// Problem-2 Set Bits(count the numbers of 1's in the binary representation of a int)
int countBits(int n) {
    int i = 1;
    int cnt = 0;
    while(i <= n) {
        if (n & i) cnt++;
        i = i << 1;
    }
    return cnt;
}









int main() {

// Problem-1
    int n, k;
    cout << "Enter the number: ";
    cin >> n;
    cout<< "Enter kth bit to set number: ";
    cin >> k;

    cout << "Kth bit set number = " << setKthBit(n, k);







// Problem-2
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout<<"Count the number of 1's in the binary representation of an int is: "<<countBits(n);





    return 0;
}


