// Sum of Subarray Maximums


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
//TC:- O(N^2)     SC:- O(1)
int sumSubarrayMaxi(vector<int>&arr) {
    int s = arr.size();
    int sum = 0;

    for(int i=0; i < s; i++) {
        int maxiEl = arr[i];
        for(int j = i; j < s; j++) {
            maxiEl = max(maxiEl, arr[j]);
            sum += maxiEl;
        }
    }
    return sum;
}
*/




//Soln-2 OPtimal Sum of Subarray Maximums
vector<int> findNGEE(vector<int>& a){
    int s = a.size();
    vector<int> ngee(s);
    stack<int> st;

    for(int i = s-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }

        ngee[i] = st.empty() ? s : st.top();
        st.push(i);
    }
    return ngee;
}

vector<int> findPGE(vector<int>& a) {
    int s = a.size();
    vector<int> pge(s);
    stack<int> st;

    for(int i=0; i < s; i++) {
        while(!st.empty() && a[st.top()] <= a[i]){
            st.pop();
        }

        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}

int sumSubArrayMaxis(vector<int>& ar) {
    int n = ar.size();
    vector<int> ngee = findNGEE(ar);
    vector<int> pge = findPGE(ar);
    int sumMaxis = 0;

    for(int i=0; i < n; i++) {
        int left = i - pge[i];
        int right = ngee[i] - i;

        sumMaxis += left * right * ar[i];
    }
    return sumMaxis;
}





int main() {

/*//Soln-1 Brute Force
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarrays Maximums is: " << sumSubarrayMaxi(arr) << endl;
*/


//Soln-2 OPtimal Soln
    vector<int> ar = {3, 1, 2, 4};
    cout << "Sum of Subarrays Maximums is: " << sumSubArrayMaxis(ar) << endl;


    return 0;
}

