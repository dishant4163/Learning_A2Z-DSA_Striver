// Valid Parenthesis String | Multiple Approches


#include<bits/stdc++.h>
using namespace std;


/*//Soln- 1 Brute Force (solving recursively)
// TC:- O(3^N) i.e, expontential in nature   SC:- O(N), taking auxiliary stack space due to recursion
bool validParenthesisString(string str, int ind, int cnt) {
    // If cnt goes negative, it's invalid
    if(cnt < 0) return false;

    // If we've reached the end of the string, the count must be zero (balanced parentheses)
    if(ind == str.size()) return (cnt == 0);

    // If the current character is '(', we increase the open count
    if(str[ind] == '(') return validParenthesisString(str, ind+1, cnt+1);

    // If the current character is ')', we decrease the open count
    if(str[ind] == ')') return validParenthesisString(str, ind+1, cnt-1);

    // If the current character is '*', it can be treated as '(', ')' or empty
    return (validParenthesisString(str, ind+1, cnt+1) || // Treat '*' as '('
        validParenthesisString(str, ind+1, cnt-1) ||     // Treat '*' as ')'
        validParenthesisString(str, ind+1, cnt) );       // Treat '*' as empty
}
*/





bool checkValidParenthesisString(string s){
    int n = s.size(), minRange=0, maxRange=0;

    for(int i=0; i < n; i++) {
        if(s[i] == '(') {
            minRange += 1;
            maxRange += 1;
        }
        else if(s[i] == ')') {
            minRange -= 1;
            maxRange += 1;
        }
        else { // '*' can act as either '(' or ')'
            minRange -= 1;
            maxRange += 1;
        }

        // Ensure minRange doesn't go negative
        if(minRange < 0) {
            minRange = 0;
        }

        // If maxRange goes negative, we know it's invalid
        if(maxRange < 0) {
            return false;
        }
    }

    //At the end, minRange must be 0 for valid parentheses
    return (minRange == 0);
}




int main() {

/*//Soln- 1 Brute Force (solving recursively)
    string str = "(*()";
    // Check if the input string is a valid parenthesis string
    if(validParenthesisString(str, 0, 0)) {
        cout << "Valid Parenthesis String" << endl;
    } else {
        cout << "Invalid Parenthesis String" << endl;
    }
*/


//Soln-2 
    string s = "(*))";
    // cout << "Enter the string: ";
    // cin >> s ;

    if (checkValidParenthesisString(s)) {
        cout << "Valid Parenthesis String" << endl;
    } else {
        cout << "Invalid Parenthesis String" << endl;
    }



    return 0;
}
