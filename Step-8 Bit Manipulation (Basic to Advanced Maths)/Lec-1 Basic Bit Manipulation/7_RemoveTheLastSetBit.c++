// Remove the Last Set Bit (RightMost)


/*//Reset All Bits   (Coding Ninjas ->  https://shorturl.at/FivQF  )
// reset the MSB(1st set bit position from left)
int resetAllExceptMSB(int n) {
    int cnt = 0;
    while(n != 0) {
        cnt++;
        n = n >> 1;
    }
    return (1 <<(cnt-1));
}

*/



#include<bits/stdc++.h>
using namespace std;


// Problem-1
// unsets the rightmost set bit 
// of n and returns the result 
int unsetLSB(int n) {
    //remove Last Set Bit means unset LSB
    return (n & (n-1));
}





/*// Problem-2

int resetAllExceptMSB(int n) {
    // If n is 0, return 0 since there are no set bits
    if (n == 0) return 0;

    // Find the position of the most significant bit (MSB) 
    // i.e, from to 1st set bit position to the left
    int msb = 0;
    for (int i = 31; i >= 0; --i) {
        if (n & (1 << i)) {
            msb = i;
            break;
        }
    }

    // Create a number with only the MSB set
    return (1 << msb);
}

*/







int main() {

// Remove Last Set Bit Or Unset LSB
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = unsetLSB(n);
    cout << "Number after removing the last set bit: " << result << endl;







    return 0;
}


