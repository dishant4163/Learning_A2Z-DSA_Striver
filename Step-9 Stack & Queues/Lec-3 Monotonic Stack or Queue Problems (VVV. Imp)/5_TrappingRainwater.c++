// Trapping Rainwater

/* Trapping Rain Water _Coding Ninjas -> (  https://shorturl.at/tiDjz  )

long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    long long Lptr = 0, Rptr = n-1;
    long long maxL = 0, maxR = 0, waterTrap = 0;

    while(Lptr <= Rptr) {
        if(arr[Lptr] <= arr[Rptr]) {
            if(arr[Lptr] >= maxL) {
                maxL = arr[Lptr];
            } else {
                waterTrap += maxL - arr[Lptr];
            }
            Lptr++;
        }
        else {
            if(arr[Rptr] >= maxR) {
                maxR = arr[Rptr];
            } else {
                waterTrap += maxR - arr[Rptr];
            }
            Rptr--;
        }
    }
    return waterTrap;
}

*/


#include<bits/stdc++.h>
using namespace std;


/*//SOln-1.1 Brute Force
// TC:- O(N^2) SC:- O(N)
int trapWater(vector<int>& ar) {
    int res = 0;

    for(int i=0; i < ar.size(); i++) {

        //Find the maxi element on its left
        int l = ar[i];
        for(int j = 0; j < i; j++)
            l = max(l, ar[j]);

        //Find the maxi element on its right
        int r = ar[i];
        for(int j =i+1; j < ar.size(); j++)
            r = max(r, ar[j]);

        //update the maximum water
        res += min(l, r) - ar[i];
    }

    return res;
}
*/




/*//SOln-2 Better Approach(using PrefixMax & SuffixMax)
// TC:- O(3N) SC:- O(N) + O(N) = O(2N)
int trapW(vector<int>& arr) {
    int s = arr.size();
    int prefix[s], suffix[s];

    prefix[0] = arr[0];
    for(int i=1; i < s; i++) {
        prefix[i] = max(prefix[i-1], arr[i]);
    }

    suffix[s-1] = arr[s-1];
    for(int i = s-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], arr[i]);
    }

    int collectWater = 0;
    for(int i = 0; i < s; i++) {
        collectWater += min(prefix[i], suffix[i]) - arr[i];
    }

    return collectWater;
}
*/




//SOln-3.1 OPtimal Approach(using stack)
//TC:- O(N) SC:- O(N)
int getTrapWater(vector<int>& v) {
    int m = v.size();
    stack<int> st;
    int totalWater = 0;

    for(int i = 0; i < m; i++) {
        while(!st.empty() && v[st.top()] < v[i]) {
    //NOTE: inThis we are playing with indexes not elements
            int newContainer = st.top();
            st.pop();

            if(st.empty()) break;
            int distance = i - st.top() - 1;
            totalWater += (min(v[st.top()], v[i]) - v[newContainer]) * distance;
        }

        st.push(i);
    }

    return totalWater;
}






//SOln-3.2 More OPtimized Soln(using 2 Pointer)
//TC:- O(N) SC:- O(1)
int trappedWater(vector<int>& a){
    int n = a.size();
    int lptr = 0, rptr = n-1;
    int maxL = 0, maxR = 0, waterTrap = 0;

    while(lptr <= rptr) {
        if(a[lptr] <= a[rptr]) {
            if(a[lptr] >= maxL){
                maxL = a[lptr];
            } else {
                waterTrap += maxL - a[lptr];
            }
            lptr++;
        }

        else {
            if(a[rptr] >= maxR) {
                maxR = a[rptr];
            } else {
                waterTrap += maxR - a[rptr];
            }
            rptr--;
        }
    }

    return waterTrap;
}






int main() {

/*//SOln-1.1 Brute Force
    vector<int> ar = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trapWater(ar);
*/


/*//Soln-2 Better Approch(using PrefixMax & SuffixMax)
    vector<int> arr = {10, 9, 0, 4};
    cout << trapW(arr);
*/


//Soln-3.1 OPtimal Approach(using Stack)
    vector<int> v = {3, 1, 0, 2, 0, 4};
    cout << "The water that can be trapped is " << getTrapWater(v)  << " units" << endl;



//Soln-3.2 OPtimal Approach(using 2 Pointers approach)
// MOst Optimized soln in compare of stack
    vector<int> a = {3, 0, 0, 2, 0, 4};
    cout << "The water that can be trapped is " << trappedWater(a)  << " units" << endl;




    return 0;
}
