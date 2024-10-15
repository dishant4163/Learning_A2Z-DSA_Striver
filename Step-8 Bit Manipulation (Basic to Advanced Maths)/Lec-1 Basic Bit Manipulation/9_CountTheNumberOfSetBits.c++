// Count The Number of Set Bits



#include<bits/stdc++.h>
using namespace std;

//Approach-1
int countSetBits_1(int n) {
    int cnt = 0;

    while(n > 0) {
        cnt += n & 1;
        n = n >> 1;
    }
    if(n == 1) cnt += 1;

    return cnt;
}





//Approach-2
int countSetBits_2(int N) {
    int Cnt = 0;
    while(N != 0) {
        Cnt += N & 1; // Increment count if the last bit is set
        N = N >> 1;   // Right shift to process the next bit
    }

    return Cnt;
}








int main() {

//Approach-1
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int setBitsCount1 = countSetBits_1(n);
    cout << "Number of set bits in " << n << " is: " << setBitsCount1 << endl;



//Approach-2
    int x;
    cout << "Enter a number: ";
    cin >> x;

    int setBitsCount2 = countSetBits_2(x);
    cout << "Number of set bits in " << x << " is: " << setBitsCount2 << endl;






// Approach - 3 Using inBuilt C++ function

    int N = 7;
    cout << __builtin_popcount(N);





    return 0;
}


