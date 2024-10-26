// Check for Balanced Paranthesis

/* Balanced Parentheses_Coding Ninjas-> (  https://shorturl.at/mCQ7G  )

bool isBalanced(string S){
    // Write your code here.
    stack<char> st;
    for(auto it : S) {
        if(it == '(' || it == '[' || it == '{') {
            st.push(it);
        } else {
            if (st.size() == 0) return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == ']' && ch == '[') ||
                (it == '}' && ch == '{')) continue;
            else return false;
        }
    }

    return st.empty();
}

*/


#include<bits/stdc++.h>
using namespace std;


bool isValid(string s) {
    stack<char> st;
    for(auto it: s) {
        if (it == '(' || it == '[' || it == '{' ) {
            st.push(it);
        } else {
            if (st.size() == 0) return false;
            char ch = st.top();
            st.pop();
            if (( it == ')' && ch == '(') || ( it == ']' && ch == '[') || ( it == '}' && ch == '{') ) continue;
            else return false;
        }
    }

    return st.empty();
}



int main() {

    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;



    return 0;
}

