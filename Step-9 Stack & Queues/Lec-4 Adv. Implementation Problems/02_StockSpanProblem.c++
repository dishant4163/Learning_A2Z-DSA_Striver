// Stock Span Problem


/*//Stock Span_Coding Ninjas -> ( https://shorturl.at/yPIrd )

vector<int> findPGEE(vector<int>& prices) {
    stack<int> st;
    vector<int> pgee(prices.size(), 1);

    for(int i=0; i < prices.size(); i++) {
        while(!st.empty() && prices[st.top()] < prices[i]) {
            st.pop();
        }

        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}

vector<int> findStockSpans(vector<int>& prices) {
    // Write your code here.
    int n = prices.size();
    vector<int> pgee = findPGEE(prices);
    vector<int> ans(n, 1);

    for(int i=1; i < n; i++) {
        ans[i] = i - pgee[i];
    }

    return ans;
}



*/


#include<bits/stdc++.h>
using namespace std;


/*//Soln-1 Brute Force
vector<int> findStockSpans(vector<int>& Prices) {
    int s = Prices.size();
    //Span value of first day is always 1
    vector<int> span(s, 1);

    for(int i = 1; i < s; i++) {
        //Check previous days for the span
        for(int j = i-1; j >= 0; j--) {
            if (Prices[i] >= Prices[j]) {
                span[i]++;
            } 
            else break;
        }
    }

    return span;
}
*/






//Soln-2 OPtimal Soln
vector<int> stockSpans(vector<int>& prices) {
    // Write your code here.
    int n = prices.size();
    vector<int> span(n, 1);
    stack<int> st;
    st.push(0);

    for(int i=1; i < n; i++) {
        while(!st.empty() && prices[i] >= prices[st.top()])
            st.pop();

        span[i] = st.empty() ? (i+1) : (i - st.top());

        st.push(i);
    }
    return span;
}





int main() {

/*//Soln-1 Brute Force
    vector<int> prices = {7, 2, 1, 3, 3, 1, 8};
    vector<int> spans = findStockSpans(prices);

    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;
*/



//Soln-2 OPtimal Soln 
    vector<int> Prices = { 10, 4, 5, 90, 120, 80 };
    vector<int> Spans = stockSpans(Prices);

    for (int it : Spans) {
        cout << it << " ";
    }
    cout << endl;



    return 0;
}
