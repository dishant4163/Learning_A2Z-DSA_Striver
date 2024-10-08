// Combination Sum-I_Coding Ninja | Recursion


/* // Combination Sum-1 (Coding Ninja):- https://shorturl.at/g9aZO   

void findCombo(int ind, vector<int>& arr, int target, 
    vector<vector<int>>& ans, vector<int>& output) {
        //Base Case
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(output);
            }
            return;
        }

    // pick the element
    if(arr[ind] <= target) {
        output.push_back(arr[ind]);
        findCombo(ind, arr, target - arr[ind], ans, output);
        output.pop_back();
    }

    // not pick the element & move to next index
    findCombo(ind + 1, arr, target, ans, output);
}


vector<vector<int>> combSum(vector<int>& arr, int target)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> output;
    sort(arr.begin(), arr.end()); // asked in question
    findCombo(0, arr, target, ans, output);
    return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;

void findCombo(int ind, int target, vector<int>& ar, vector<vector<int>>& ans, vector<int>& ds) {
    // Base Case
    if(ind == ar.size()) {
        if(target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    //pickup the element
    if(ar[ind] <= target) {
        ds.push_back(ar[ind]);
        findCombo(ind, target - ar[ind], ar, ans, ds);
        ds.pop_back();
    }

    //not pick the element & move to next ind
    findCombo(ind + 1, target, ar, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombo(0, target, candidates, ans, ds);
    return ans;
}


int main() {

    vector<int> ar{2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(ar, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
        cout << ans[i][j] << " ";
    cout << endl;
    }



    return 0;
}
