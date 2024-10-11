// Maximum Nesting Depth of the Parentheses | Leetcode 1614


/* Maximum Nesting Depth of the Parentheses (Coding Ninjas ->  https://shorturl.at/89Zxb  )



*/



#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int ans = 0, curDepth = 0;

    for(char& ch : s) {
        if (ch == '(') {
            curDepth++;
            ans = max(ans, curDepth);
        }
        if (ch == ')') {
            curDepth--;
        }
    }

    return ans;
}


int main() {

    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;

    int depth = maxDepth(input);
    cout << "Maximum depth of nested parentheses: " << depth << endl;


    return 0;
}


