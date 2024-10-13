// Basic & Intro to Bit Manipulation 



#include<bits/stdc++.h>
using namespace std;


//1. Convert Decimal to Binary
// TC:- O(log2 N) [log base 2]
// SC:- O(log2 N) [log base 2]
string convert2Binary(int a) {
    string ans = "";
    if (a == 0) return "0"; // Handle the case for 0
    while (a != 0) {
        if (a % 2 == 1) ans += '1'; // Add '1' for odd numbers
        else ans += '0'; // Add '0' for even numbers
        a = a / 2; // Divide by 2 to shift right
    }
    reverse(ans.begin(), ans.end()); // Reverse the string to get the correct binary order
    return ans;
}




//2. Convert Binary to Decimal
// TC:- O(length of string)
// SC:- O(1)
int convert2Decimal(string s) {
    int len = s.length();
    int powerOf2 = 1;
    int num = 0;

    for(int i=len-1; i >= 0; i--) {
        if(s[i] == '1')
            num += powerOf2;
        powerOf2 = powerOf2 * 2;
    }
    return num;
}










int main() {

//1. Convert Decimal to Binary
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    string binary = convert2Binary(number);
    cout << "Binary representation: " << binary << endl;



//2. Convert Binary to Decimal
    string binaryString;
    cout << "Enter a binary string: ";
    cin >> binaryString;

    // Validate the input to ensure it's a binary string
    for (char c : binaryString) {
        if (c != '0' && c != '1') {
            cout << "Invalid binary string!" << endl;
            return 1; // Exit with error code
        }
    }

    int decimalValue = convert2Decimal(binaryString);
    cout << "Decimal representation: " << decimalValue << endl;



//3. 



    return 0;
}


