// Convert Postfix To Infix


/* Postfix To Infix_Coding Ninjas -> (  https://shorturl.at/XMQNa  )

string postToInfix(string postfix) {
    // Write your code here.

    stack<string> st;
    for(auto s : postfix) {
        if( (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') ) {
            st.push(string(1, s)); //Correct way to push a char as a string
        }
        else { // If the character is an operator
            // Pop two operands from the stack
            string op2 = st.top(); st.pop(); // Second operand
            string op1 = st.top(); st.pop(); // First operand

            //Create a new string in the format "(op1 operator op2)"
            string newExp = "(" + op1 + s + op2 + ")";
            // Push the new expression back onto the stack
            st.push(newExp);
        }
    }

    //Final expression is only left element in the stack
    return st.top();
}

*/



#include<bits/stdc++.h>
using namespace std;


string postfixToInfix(string str) {

    stack<string> st; //stack storing string not characters 
    for(auto s : str) {
        if( (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') ) {
            st.push(string(1, s)); //Correct way to push a char as a string
        }
        else { // If the character is an operator
            // Pop two operands from the stack
            string op1 = st.top(); st.pop(); // First operand
            string op2 = st.top(); st.pop(); // Second operand

            //Create a new string in the format "(op1 operator op2)"
            string newExp = "(" + op2 + s + op1 + ")";
            // Push the new expression back onto the stack
            st.push(newExp);
        }
    }

    //Final expression is only left element in the stack
    return st.top();
}



int main() {

    string s = "pq+cd-*f^"; // Example postfix expression
    cout << "Postfix expression: " << s << endl;
    cout << "Infix Expression: " << postfixToInfix(s) << endl;


    return 0;
}

