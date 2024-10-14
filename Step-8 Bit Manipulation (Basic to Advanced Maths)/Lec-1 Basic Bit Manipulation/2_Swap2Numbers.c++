// Swap Two Numbers


/*// Swap Two Numbers (Coding Ninjas ->  https://shorturl.at/JObmj  )

void swapNumber(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

*/


#include<bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


int main() {

    int x, y;
    cout << "Enter two numbers to swap: ";
    cin >> x >> y;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapNumber(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;



    return 0;
}

