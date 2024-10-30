// Prefix To Infix


/* Prefix To Infix_Coding Ninjas -> (  https://shorturl.at/ogmF8  )

string prefixToInfixConversion(string &s){
	// Write your code here.
	stack<string> st;

	for(int i = s.size()-1; i >= 0; i--) {
		if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ){
			st.push(string(1, s[i]));
		}
		else {
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();

			string newExp = "(" + op1 + s[i] + op2 + ")";
			st.push(newExp);
		}
	}

	return st.top();
}

*/


#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    int len = s.size();
    stack<string> st;
    for(int i = len-1; i >= 0; i--) {
        if( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') ) {
            st.push(string(1, s[i])); //Correct way to push a char as a string
        }
        else { // If the character is an operator
            // Pop two operands from the stack
            string op1 = st.top(); st.pop(); // First operand
            string op2 = st.top(); st.pop(); // Second operand

            //Create a new string in the format "(op1 operator op2)"
            string newExp = "(" + op1 + s[i] + op2 + ")";
            // Push the new expression back onto the stack
            st.push(newExp);
        }
    }

    //Final expression is only left element in the stack
    return st.top();
}



int main() {

    string exp = "*-A/BC-/AKL";
    cout << "Infix : " << prefixToInfix(exp);


    return 0;
}


