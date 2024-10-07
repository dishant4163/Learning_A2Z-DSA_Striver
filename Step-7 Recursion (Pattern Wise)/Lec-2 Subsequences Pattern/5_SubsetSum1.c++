// Subset Sum : Sum of all Subsets | Recurssion


/* Subset Sum-1 -> https://shorturl.at/k2Ek8   



*/


#include<bits/stdc++.h>
using namespace std;

void solveSubsetSum(int ind, int sum, vector<int>& ar, int n, vector<int>& ansSet) {
    // Base Case
    if (ind == n) {
        ansSet.push_back(sum);
        return;
    }

    // Pickup the Element 
    solveSubsetSum(ind + 1, sum + ar[ind], ar, n, ansSet);

    // Not-Pick the Element
    solveSubsetSum(ind + 1, sum, ar, n, ansSet);
}

vector<int> subsetSums(vector<int>& arr, int n) {
    vector<int> ansSetSum;
    solveSubsetSum(0, 0, arr, n, ansSetSum);
    sort(ansSetSum.begin(), ansSetSum.end());
    return ansSetSum;
}

int main() {

    vector<int> arr{3,1,2};
    vector<int> ans = subsetSums(arr, arr.size());
    sort(ans.begin(), ans.end());
    cout<<"The sum of each subset is "<<endl;
    for (auto sum: ans) {
        cout << sum << " ";
    }
    cout << endl;



    return 0;
}

