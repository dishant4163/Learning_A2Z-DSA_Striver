// Implement Atoi Recursively


#include<bits/stdc++.h>
using namespace std;


// Recursive Implementation of ATOI
int createAtoiHelper(const std::string& s, int& index, bool& isNegative) {
    // Skip leading whitespaces
    while (index < s.length() && s[index] == ' ') {
        index++;
    }

    // Determine the sign
    if (index < s.length() && (s[index] == '-' || s[index] == '+')) {
        isNegative = (s[index] == '-');
        index++;
    }

    // Read digits and accumulate the result recursively
    int result = 0;
    while (index < s.length() && isdigit(s[index])) {
        // Check for overflow before adding
        if (result > (INT_MAX - (s[index] - '0')) / 10) {
            return isNegative ? INT_MIN : INT_MAX; // Handle overflow
        }
        result = result * 10 + (s[index] - '0');
        index++;
    }

    return isNegative ? -result : result; // Apply sign
}

int createAtoi(const std::string& s) {
    int index = 0; // To track the current index in the string
    bool isNegative = false; // To track if the number is negative
    return createAtoiHelper(s, index, isNegative);
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



