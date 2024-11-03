// Sum Of Subarray Minimums

/*  Sum of Subarray Minimums_Coding Ninjas -> (  https://shorturl.at/Nbmzi  )


int mod = 1e9 + 7;
vector<int> findNSE(vector<int>& a) {
    int s = a.size();
    vector<int> nse(s);
        stack<int> st;
        for(int i=s-1 ; i>=0 ; i--) {
            while(!st.empty() && a[st.top()]>= a[i]) {
                st.pop();
            }
            nse[i] = st.empty()? s: st.top();
            st.push(i);
        }
        return nse;
}

vector<int> findPSEE(vector<int>& a) {
    int s = a.size();
    vector<int> psee(s);
        stack<int> st;
        for(int i=0 ; i<s ; i++) {
            while(!st.empty() && a[st.top()]> a[i]) { // don't take >= as we have to consider for smaller equal element also eg [1,1,1]
                st.pop();
            }
            psee[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return psee;
}


int sumSubarrayMins(vector<int>&arr) {
    // Write your code here.
    int n = arr.size();
    vector<int> Nse = findNSE(arr); //nextSmallerEl
    vector<int> Pse = findPSEE(arr); //PrevSmallerElorEqaul
    int totalSum = 0;

    

    for(int i=0; i < n; i++) {
        int left = i - Pse[i];
        int right = Nse[i] - i;

        //if ans is too big to store then do % of mod
        totalSum = (totalSum + (right * left * arr[i])%mod) %mod;

    }

    return totalSum;
}


*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
//TC:- O(N^2)     SC:- O(1)
int sumSubarrayMins(vector<int>&arr) {
    int s = arr.size();
    int sum = 0;
    for(int i=0; i < s; i++) {
        int miniEl = arr[i];
        for(int j = i; j < s; j++) {
            miniEl = min(miniEl, arr[j]);
            sum += miniEl;
        }
    }
    return sum;
}
*/






//Soln-2 OPtimal Soln(using Stack)
//TC:- O(5N)     SC:- O(5N)

// int mod = 1e9 + 7;
vector<int> findNSE(vector<int>& a) {
    int s = a.size();
    vector<int> nse(s);
        stack<int> st;
        for(int i=s-1 ; i>=0 ; i--) {
            while(!st.empty() && a[st.top()]>= a[i]) {
                st.pop();
            }
            nse[i] = st.empty()? s: st.top();
            st.push(i);
        }
        return nse;
}

vector<int> findPSEE(vector<int>& a) {
    int s = a.size();
    vector<int> psee(s);
        stack<int> st;
        for(int i=0 ; i<s ; i++) {
            while(!st.empty() && a[st.top()]> a[i]) { // don't take >= as we have to consider for smaller equal element also eg [1,1,1]
                st.pop();
            }
            psee[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return psee;
}


int sumSubarrayMinimums(vector<int>& ar) {
    int n = ar.size();
    vector<int> Nse = findNSE(ar); //nextSmallerEl
    vector<int> Pse = findPSEE(ar); //PrevSmallerElorEqaul
    int totalSum = 0;

    

    for(int i=0; i < n; i++) {
        int left = i - Pse[i];
        int right = Nse[i] - i;

        totalSum += (right * left * ar[i]);

        //if ans is too big to store then do % of mod
        //totalSum = (totalSum + (right * left * ar[i])%mod) %mod;

    }

    return totalSum;
}






int main() {

/*//SOln-1 Brute Force
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarrays minimums is: " << sumSubarrayMins(arr) << endl;
*/


//Soln-2 OPtimal Soln
    vector<int> ar = {1, 4, 6, 7, 3, 7, 8, 1};
    cout << "Sum of Subarrays minimums is: " << sumSubarrayMinimums(ar) << endl;




    return 0;
}
