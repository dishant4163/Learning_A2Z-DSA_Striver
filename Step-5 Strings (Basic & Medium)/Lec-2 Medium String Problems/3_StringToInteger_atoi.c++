// String to Integer atoi | Leetcode 8 | Coding Ninjas


/*//  Implement Atoi Function (Coding Ninjas ->  https://shorturl.at/qvcXX  )

int createAtoi(string s) {
    // Write your code here.
    if(s.length() == 0) return 0;//if string is empty

    int i=0;
    while(i<s.size() && s[i] == ' '){
        i++;
    }
    s.substr(i);

    int sign = +1;
    long ans = 0;

    if(s[0] == '-') sign = -1;

    int MAX = INT_MAX, MIN = INT_MIN;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    while(i < s.size()) {
        if(s[0] == ' ' || !isdigit(s[i])) break;

        ans = ans*10 + (s[i] - '0');
        if(sign == -1 && -1*ans < MIN) return MIN;
        if(sign == 1 && ans > MAX) return MAX;

        i++;
    }
    return (int)(sign*ans);// convert ans string to int & then return ans
}

*/

#include<bits/stdc++.h>
using namespace std;


int createAtoi(string s) {
    //check if string is empty
    if(s.length() == 0) return 0;

    int i=0;
    while(s.length() && s[i] == ' ') {
        i++;
    }
    s = s.substr(i); // i --> last of string

    int sign = +1;
    long ans = 0;

    if(s[0] == '-') sign = -1;

    int MAX = INT_MAX, MIN = INT_MIN;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    while(i < s.length()) {
        if(s[0] == ' ' || !isdigit(s[i])) break;

        ans = ans*10 + (s[i] - '0');
        if(sign == -1 && -1*ans < MIN) return MIN;
        if(sign == 1 && ans < MAX) return MAX;

        i++;
    }

    return (int)(sign*ans);
}







int main() {

    string input;
    // Prompt user for input
    cout << "Enter a number: ";
    getline(cin, input);  // Read the entire line

    // Convert string to integer
    int result = createAtoi(input);

    // Print the result
    cout << "Converted integer: " << result << endl;



    return 0;
}

