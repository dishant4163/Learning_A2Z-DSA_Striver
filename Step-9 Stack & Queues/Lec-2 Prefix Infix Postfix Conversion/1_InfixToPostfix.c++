// Convert Infix to Postfix  


/*  Infix to Postfix__Coding Ninjas -> (  https://shorturl.at/7w6MJ  ) 



*/


#include<bits/stdc++.h>
using namespace std;

//Soln approach-> https://shorturl.at/1tWSZ  

//Function to return precedence of operators
int precOrder(char c) {
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

//Main function to convert infix to postfix expression
void infix2Postfix(string s) {
    stack<char> st;//Stack for storing operators
    string ans;

    for(int i=0; i < s.length(); i++) {

    //If scanned character is an operand, add it to ans string.
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }

    //If scanned character is an ‘(‘, push it to the stack.
    else if(s[i] == '(') st.push(s[i]);

    //If scanned character is an ‘)’, pop and to ans string from the stack until an ‘(‘ is encountered.
    else if(s[i] == ')') {
        while(!st.empty() && st.top() != '(' ) {
            ans += st.top();
            st.pop();
        }
        st.pop();
    }

    //If an operator is scanned
    else {
        while(!st.empty() && precOrder(s[i]) <= precOrder(st.top()) ) {
            ans += st.top();
            st.pop();
        }
        st.push(s[i]);
        }
    }

    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << "Prefix expression: " << ans << endl;

}



int main() {

    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infix2Postfix(exp);



    return 0;
}


