// Subset - II | Print all the Unique Subsets | Recurssion


/* Subset-2 (Coding Ninjas) -> https://shorturl.at/YYc8q        



*/


#include<bits/stdc++.h>
using namespace std;

void findSubsets(int ind, vector<int>& arr, vector<vector<int>>& ans, vector<int>& output) {
    // Add the current subset to the result
    ans.push_back(output); // No BASE CASE in this problem

    for (int i=ind; i < arr.size(); i++) {
        // Skip duplicates: we only want to include the first occurrence of each element
        if(i > ind && arr[i] == arr[i-1]) continue; // or we can use (i != ind) && arr[i] == arr[i-1]

        // Include the current element
        output.push_back(arr[i]);
        // Recursion for the next index
        findSubsets(i + 1, arr, ans, output);
        // Backtrack
        output.pop_back();
    }
}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    sort(nums.begin(), nums.end()); // Sort the array to manage duplicates
    findSubsets(0, nums, ans, output);  // Generate subsets starting from index 0
    return ans;
}

int main() {

    vector<int > nums = {1,2,2};
    vector<vector<int>> subsets = subsetsWithDup(nums);
    // Print the Results
    for(auto it: subsets) {
        cout <<"[ ";
        for(int num : it) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << "\n";



    return 0;
}


