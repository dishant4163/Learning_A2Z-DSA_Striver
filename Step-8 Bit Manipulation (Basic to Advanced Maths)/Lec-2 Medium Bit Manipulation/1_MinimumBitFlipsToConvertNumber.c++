// Minimum Bit Flips to Convert Number/Count number of bits to be flipped to convert A to B 


/* Flip Bits | (Coding Ninjas ->  https://shorturl.at/sxVOQ  )

int flipBits(int A, int B){
    // Write your code here.
    int xorAns = A ^ B;
    int cnt = 0;

    for (int i=0; i < 32; i++) {
        if(xorAns & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

*/



#include<bits/stdc++.h>
using namespace std;

int numberOfFlips(int start, int goal) {
    // XOR of start and goal numbers
    int xorResult = start ^ goal;

    //count to track the num of set bits
    int cnt = 0;

    for(int i=0; i<32; i++) {
        // Check if the i-th bit of xorResult is set
        if(xorResult & (1 << i))
        cnt++; // Increment the count if the bit is set
    }

    return cnt;
}


int main() {

    int start, goal;
    cout << "Enter the value of start: ";
    cin >> start;
    cout << "Enter the value of goal: " ;
    cin >> goal;

    cout << "Number of flips needed to convert "<< start <<" to " << goal << ": " << numberOfFlips(start, goal) << endl;


    return 0;
}

