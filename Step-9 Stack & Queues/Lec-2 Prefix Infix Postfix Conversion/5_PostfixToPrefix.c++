// Postfix To Prefix

/* PostFix To Prefix_Coding Ninjas -> (  https://tinyurl.com/5n9be2f3  )



*/


#include<bits/stdc++.h>
using namespace std;


// Function to convert postfix to prefix
string postfixToPrefix(string& s) {
    stack<string> st;

    for(int i=0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] <= '0' && s[i] >= '9')) {
            st.push(string(1, s[i]));
        }
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string exp = s[i] + t2 + t1;
            st.push(exp);
        }
    }

    return st.top();
}



int main() {

    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);
    cout << "The prefix expression is: " << prefix << endl;



    return 0;
}

