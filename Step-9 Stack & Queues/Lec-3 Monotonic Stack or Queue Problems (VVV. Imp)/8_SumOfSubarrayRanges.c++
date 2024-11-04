// Sum of Subarray Ranges

/* Subarray Range Sum _Coding Ninjas -> (  https://shorturl.at/vQgdJ  )


int rangeSum(vector<int>&nums){
    // Write your code here.
    int n = nums.size();
    vector<int> psee(n), nse(n), pge(n), ngee(n);
    stack<int> st;

    //find prev smaller or equal ele
    for(int i=0; i < n; i++) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    //clear the stack
    while(!st.empty()) st.pop();

    //find next smaller ele
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    //clear the stack
    while(!st.empty()) st.pop();

    //find prev greater ele
    for(int i=0; i < n; i++) {
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    //clear the stack
    while(!st.empty()) st.pop();

    //find next greater or eqaul ele
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        ngee[i] = st.empty() ? n : st.top();
        st.push(i);
    }


    //calculate Subarray Range Sum
    int sum = 0;
    for(int i=0; i < n; i++) {
        sum += (nums[i] * ((i - pge[i])*(ngee[i] - i))) - (nums[i] * ((i - psee[i])*(nse[i] - i)));
    }
    return sum;
}


*/

#include<bits/stdc++.h>
using namespace std;

//SOln-1 Brute Force
// TC:- O(N^2) SC:- O(1)
int sumSubArRange(vector<int>& arr) {
    int s = arr.size();
    int sum = 0;
    for(int i=0; i < s; i++) {
        int largest = arr[i], smallest = arr[i];
        for(int j = i+1; j < s; j++) {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);

            sum += (largest - smallest);
        }
    }
    return sum;
}





//Soln-2 OPtimal Soln(using Sum Of Subarray Minimums & Maximums)
// TC:- O(10N) approx= O(N)    SC:- O(10N) approx= O(N)

//Sum Of Subarray Minimums
vector<int> findNSE(vector<int>& a) {
    int s = a.size();
    vector<int> nse(s);
    stack<int> st;

    for(int i = s-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? s : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSEE(vector<int>& a) {
    int s = a.size();
    vector<int> psee(s);
    stack<int> st;

    for(int i=0; i < s; i++) {
        while(!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

int sumSubArMinis(vector<int>& ar) {
    int n = ar.size();
    vector<int> Nse = findNSE(ar);
    vector<int> Psee = findPSEE(ar);

    int minSubSum = 0;

    for(int i=0; i < n; i++) {
        int left = i - Psee[i];
        int right = Nse[i] - i;

        minSubSum += (left * right * ar[i]);
    }
    return minSubSum;
}


//Sum of Subarray Maximums
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

int sumSubArMaxis(vector<int>& ar) {
    vector<int> Ngee = findNGEE(ar);
    vector<int> Pge = findPGE(ar);

    int maxSubSum = 0;
    for(int i=0; i < ar.size(); i++) {
        int left = i - Pge[i];
        int right = Ngee[i] - i;

        maxSubSum += left * right * ar[i];
    }
    return maxSubSum;
}


// Main function to calculate sum of Subarray Ranges
int getSubArRangeSum(vector<int>& ar) {
    int maxSum = sumSubArMaxis(ar);
    int minSum = sumSubArMinis(ar);

    return maxSum - minSum;
}





//(same optimal soln but solve in only one function)
// TC:- O(10N) approx= O(N)    SC:- O(10N) approx= O(N)
int getSubArRangeSum2(vector<int>& ar) {
    int n = ar.size();

    vector<int> pse(n), nse(n), pge(n), nge(n);
    stack<int> st;
    //find previous smaller or equal elements
    for(int i = 0; i < n; i++){
        while(!st.empty() && ar[st.top()] >= ar[i]){
            st.pop();
        }
        if(st.empty()) pse[i] = -1;
        else pse[i] = st.top();
        st.push(i);
        }

        //clear the stack
        while(!st.empty()) st.pop();

        //find previous greater or equal elements
        for(int i = 0; i < n; i++){
            while(!st.empty() && ar[st.top()] <= ar[i]){
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();
            st.push(i);
        }

        //clear the stack
        while(!st.empty()) st.pop();

        //find next smaller elements
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && ar[st.top()] > ar[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }

        //clear the stack
        while(!st.empty()) st.pop();

        //find next greater elements
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && ar[st.top()] < ar[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = n;
            else nge[i] = st.top();
            st.push(i);
        }


    int sumSubArRange = 0;
    for(int i = 0; i < n; i++){
        sumSubArRange += (ar[i] * ((i-pge[i]) * (nge[i] - i))) - (ar[i] * ((i-pse[i]) * (nse[i] - i)));
    }

    return sumSubArRange;
}






int main() {

//Soln-1 Brute Force
    vector<int> arr = {1, 4, 3, 2};
    cout << "Sum of Subarray Ranges is " << sumSubArRange(arr) << endl;



//Soln-2 OPtimal
    vector<int> ar = {1, 4, 3, 2};
    cout << "Sum of Subarray Ranges is " << getSubArRangeSum(ar) << endl;



//Soln-2 OPtimal
    vector<int> ar = {1, 4, 3, 2};
    cout << "Sum of Subarray Ranges is " << getSubArRangeSum2(ar) << endl;



    return 0;
}


