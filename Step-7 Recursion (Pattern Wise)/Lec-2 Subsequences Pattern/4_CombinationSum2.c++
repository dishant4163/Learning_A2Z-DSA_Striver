// Combination Sum II - Find all unique combinations | Recursion

/* // Combination Sum 2_Coding Ninjas -> https://shorturl.at/aRhDT

#include<bits/stdc++.h>

void findCombo2(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& output, int n) {
    //Base case
    if(target == 0) {
        ans.push_back(output);
        return;
    }

    for(int i=ind; i < n; i++) {
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        output.push_back(arr[i]);
        findCombo2(i + 1, target - arr[i], arr, ans, output, n);
        output.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	vector<int> output;
	findCombo2(0, target, arr, ans, output, n);
	return ans;
}


*/

#include <bits/stdc++.h>
using namespace std;

void findCombo2(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& output) {
    //Base case
    if(target == 0) {
        ans.push_back(output);
        return;
    }

    for(int i=ind; i < arr.size(); i++) {
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        output.push_back(arr[i]);
        findCombo2(i + 1, target - arr[i], arr, ans, output);
        output.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> output;
    sort(candidates.begin(), candidates.end());
    findCombo2(0, target, candidates, ans, output);
    return ans;
}


int main()
{

    vector<int> v{10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> comb = combinationSum2(v, 8);
    cout << "[ ";
    for (int i = 0; i < comb.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++) {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

    return 0;
}

