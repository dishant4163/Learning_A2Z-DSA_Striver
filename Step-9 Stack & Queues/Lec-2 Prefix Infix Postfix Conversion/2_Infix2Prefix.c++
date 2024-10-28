// Convert Infix to Prefix 


#include<bits/stdc++.h>
using namespace std;

//Soln Approach ->  https://shorturl.at/r8cVu  

int getPriority(char C) {
    if (C == '-' || C == '+') return 1;
    else if (C == '*' || C == '/') return 2;
    else if (C == '^') return 3;

    return 0;
}

/* // Using 2 functions

bool isOPerator(char c) {
    return (!isalpha(c) && !isdigit(c));
}


string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int len = infix.size();
    stack<char> chSt;
    string ans;

    for(int i=0; i < len; i++) {
    //If scanned character is an operand, add it to output.
        if(isalpha(infix[i]) || isdigit(infix[i])) {
            ans += infix[i];
        }

    //If scanned character is an ‘(‘, push it to the stack.
        else if(infix[i] == '(') chSt.push('(');

    //If scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while(!chSt.empty() && chSt.top() != '(') {
                ans += chSt.top();
                chSt.pop();
            }
            //Remove '(' from the Stack
            chSt.pop();
        }

    // OPerator found
        else {
            if(isOPerator(chSt.top())) {
                if(infix[i] == '^') {
                    while(getPriority(infix[i]) <= getPriority(chSt.top())) {
                        ans += chSt.top();
                        chSt.pop();
                    }

                } else {
                    while(getPriority(infix[i]) < getPriority(chSt.top())) {
                        ans += chSt.top();
                        chSt.pop();
                    }
                }

                chSt.push(infix[i]);
            }
        }
    }

    while(!chSt.empty()) {
        ans += chSt.top();
        chSt.pop();
    }

    return ans;
}


// Main function to convert infix 2 postfix
string infixToPrefix(string infix) {
//-> Reverse String
//-> Replace ( with ) and vice versa
//-> Get Postfix
//-> Reverse Postfix
    int len = infix.size();
    // Reverse infix
    reverse(infix.begin(), infix.end());

    //Replace '(' with ')' & vice-versa
    for(int i=0; i < len; i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);
    //Reverse postfix for Prefix as answer
    reverse(prefix.begin(), prefix.end());

    return prefix;
}
*/


//Solve using only 1 functions
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    int len = s.size();
    //Replace '(' with ')' & vice-versa
    for(int i=0; i < len; i++) {
        if(s[i] == '(') {
            s[i] = ')';
            i++;
        } else if (s[i] == ')') {
            s[i] = '(';
            i++;
        }
    }

    stack<char> st;
    string ans = "";

    for(int i=0; i < len; i++) {

    //If scanned character is an operand, add it to ans string.
        if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ) {
            ans += s[i];
        }

    //If scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(') { 
            st.push(s[i]);
        }

    //If scanned character is an ‘)’, pop and to ans string from the stack until an ‘(‘ is encountered.
        else if(s[i] == ')') {
        while(!st.empty() && st.top() != '(' ) {
            ans += st.top();
            st.pop();
        }
        st.pop();
    }

    //Now some modification for infix 2 prefix

        else {
            if(s[i] == '^') { //if it is power operator
                while(!st.empty() && getPriority(s[i]) <= getPriority(st.top()) ) {
                    ans += st.top();
                    st.pop();
                }
            } else { //if it is not power operator
                while(!st.empty() && getPriority(s[i]) < getPriority(st.top()) ) {
                    ans += st.top();
                    st.pop();
                }
            }

            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}



int main() {

    string s = "(p+q)*(c-d)";
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << infixToPrefix(s) << endl;




    return 0;
}


