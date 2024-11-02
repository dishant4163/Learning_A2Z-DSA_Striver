// Previous/Nearest Smaller ELement/PSE (on LEFT side in an array)



#include<bits/stdc++.h>
using namespace std;

// SOln-1 Brute Force
// TC:- O(n^2)  SC:- O(n)
vector<int> findPrevSmallerEL(vector<int>& arr) {
    vector<int> PSE(arr.size(), -1); //To store the result &
    //Initialize with -1, to indicates no smaller ele found

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i-1; j >= 0; j--) {  // Check all elements to the left
            if(arr[j] < arr[i]) {
                PSE[i] = arr[j]; //Found the previous smaller element
                break; //No need to check further left
            }
        }
    }

    return PSE;
}





//SOln-2 OPTimal
vector<int> PrevSmallerEl(vector<int>& ar) {
    int n = ar.size();
    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {
    // Pop elements from the stack while the stack is not empty
    // and the top element is greater than or equal to the current element
        while(!st.empty() && st.top() >= ar[i]) {
            st.pop();
        }

     // If the stack is empty, it means there is no smaller element to the left
        if(st.empty()) pse[i] = -1; //Indicate no smaller element
        else pse[i] = st.top(); // The top of the stack is the previous smaller element

        st.push(ar[i]); // Push the current element onto the stack
    }

    return pse;
}






int main() {

// SOln-1 Brute Force
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    // Input elements of the array
    vector<int> arr(N);
    cout << "Enter the elements: ";
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Get the next greater elements
    vector<int> result = findPrevSmallerEL(arr);

    // Output the results
    cout << "Next Greater Elements: ";
    for(int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;




//Soln-2 OPtimal 
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
    vector<int> res = PrevSmallerEl(ar);

    // Output the results
    cout << "Next Greater Elements: ";
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;



    return 0;
}

