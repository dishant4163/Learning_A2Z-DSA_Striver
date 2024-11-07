// Remove K Digits



/* Remove K Digits_Coding Ninjas -> (  https://shorturl.at/HOF3e  )



*/



#include<bits/stdc++.h>
using namespace std;


string remove_K_Digits(string s, int k) {
    int n = s.length();
    //If k is >= to the number of digits, return "0"
    if(k >= n) return "0";

    stack<int> st;

    for(int i=0; i < n; i++) {
        // While we can remove digits and the stack is not empty
        // and the current digit is less than the digit on top of the stack
        while(!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // if we still have left-over to remove
    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    //Build stack have some element
    string ans ="";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }


//Edge Case, if zeros are at start and back of number
    while(ans.size() != 0 && ans.back() == '0') ans.pop_back();

// Reverse the result since we constructed it from the top of the stack
reverse(ans.begin(), ans.end());

    // Return "0" if the result is empty
    return ans.empty() ? "0" : ans;

}




int main() {

    string numStr = "1432219"; // input
    int k = 3; // Number of digits to remove

    string result = remove_K_Digits(numStr, k);
    cout << "Result after removing " << k << " digits: " << result << endl; // Expected output: "1219"


    return 0;
}

