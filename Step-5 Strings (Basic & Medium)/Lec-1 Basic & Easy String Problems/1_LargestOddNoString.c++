// Largest Odd Number in String | Strings | Leetcode 1903


/* Largest Odd Number in String (Leetcode 1903  -> https://shorturl.at/th3kG   )

string largestOddNumber(string num) {
    for (int i = num.size()-1; i >= 0; i--) {
        if((num[i] - '0') %2 != 0) {
            return num.substr(0, i+1);
        }
    }
    // if odd num not found
    return "";
    }

*/



#include<bits/stdc++.h>
using namespace std;

string largestOddNoStr(string num) {
    for (int i = num.size()-1; i >= 0; i--) {
        if((num[i] - '0') %2 != 0) {
            return num.substr(0, i+1);
        }
    }
    // if odd num not found
    return "";
}


int main() {

    string num;
    cout << "Enter a number: ";
    cin >> num;

    string result = largestOddNoStr(num);

    if (result.empty()) {
        cout << "No odd number can be formed." << endl;
    } else {
        cout << "The largest odd number that can be formed is: " << result << endl;
    }



    return 0;
}


