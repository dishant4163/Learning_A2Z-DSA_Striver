//Next Smaller Element/NSE (in right side in an array)




#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
void printNSE(int arr[], int N) {
    int NSE;
    for(int i=0; i < N; i++) {
        NSE = -1;
        for(int j=i+1; j<N; j++) {
            if(arr[j] < arr[i]) {
                NSE = arr[j];
                break;
            }
        }
        cout <<arr[i] << " ---> " << NSE << endl;
    }
}
*/




//SOLn-2 OPtimal
vector<int> nextSmallerEl(vector<int>& ar, int n) {
    stack<int> st;
    vector<int> nse(n, -1);

    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && st.top() >= ar[i]) {
            st.pop();
        }

        if(!st.empty()) nse[i] = st.top();
        else nse[i] = -1;

        st.push(ar[i]);
    }

    return nse;
}






int main() {

/*//SOLn-1 Brute Force
    int arr[] = {11, 13, 21, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, N);
    cout << endl;
*/


//Soln-2 OPtimal Soln
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input elements of the array
    vector<int> ar(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    // Get the next greater elements
    vector<int> result = nextSmallerEl(ar, n);

    // Output the results
    cout << "Next Smaller Elements: ";
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;



    return 0;
}
