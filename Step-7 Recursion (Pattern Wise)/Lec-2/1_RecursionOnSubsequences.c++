//(Recursion on Subsequences | Printing Subsequences)


// Another way to Solve this Problem is using Power Set


#include<bits/stdc++.h>
using namespace std;

void printSubsequence(int ind, vector<int> &listt, int arr[], int n) {
    if (ind == n) {
        for(auto it : listt) {
            cout << it << " ";
        }
        // if the none element is present, i.e, 
        if(listt.size() == 0) {
            cout << "{}";
        }
        cout<< endl;
        return;
    }
    // not pick, or not take condition, this element is not added to your subsequence
    printSubsequence(ind+1, listt, arr, n);

    // take or pick the particular index into the subsequence
    listt.push_back(arr[ind]);
    printSubsequence(ind+1, listt, arr, n);
    listt.pop_back();
}





int main() {

int arr[] = {3, 1, 2};
int n = 3;
vector<int> listt;
printSubsequence(0, listt, arr, n);





    return 0;
}


