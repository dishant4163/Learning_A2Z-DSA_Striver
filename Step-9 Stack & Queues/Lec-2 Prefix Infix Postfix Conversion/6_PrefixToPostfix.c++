// Prefix To Postfix


/* Prefix To Postfix_Coding Ninjas -> (  https://shorturl.at/OhHuD  )



*/



#include<bits/stdc++.h>
using namespace std;

string prefixToPostfix(string s) {
    stack<string> st;

    for(int i=s.size()-1; i >= 0; i--) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string exp = t1 + t2 + s[i];

            st.push(exp);
        }
    }

    return st.top();
}



int main() {

    string exp = "/-AB*+DEF";
    cout << "Postfix : " << prefixToPostfix(exp);



    return 0;
}


