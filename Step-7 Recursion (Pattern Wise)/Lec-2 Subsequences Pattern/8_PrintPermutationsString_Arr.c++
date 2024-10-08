// Permutations of a String or Array | Recursion    



/*// Permutations of a String (Coding Ninjas)-> https://shorturl.at/FzzQ8   

#include<bits/stdc++.h>

void solve(string str, vector<string>& ans, int index) {
    //Base Case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index+1);

        //Backtrack, for maintaining consistency of given string
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end());
    return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;


//1. Permutations of a String
void solveStrPermute(string str, int index, vector<string>& ans) {
    // Base Case
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solveStrPermute(str, index+1, ans);

        // Backtrack, for maintaining consistency of given string
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str) {
    vector<string> ans;
    int index = 0;
    solveStrPermute(str, index, ans);
    // sort(ans.begin(), ans.end()); //if asked to sort 
    return ans;
}





//2. Permutations of a Array
void solveArrPermute(vector<int> nums, vector<vector<int>>& ans, int index) {
    // Base Case
    if (index >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int j = index; j < nums.size(); j++) {
        swap(nums[index], nums[j]);
        solveArrPermute(nums, ans, index+1);

        // Backtrack, for maintaining consistency of given string
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> arrPermutations(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solveArrPermute(nums, ans, index);
    return ans;
}






int main() {

// Permutations of a String
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Generate permutations
    vector<string> permutations = generatePermutations(str);

    // Print the permutations
    cout << "Permutations of the string are:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }




// Permutations of a Array
    vector<int> nums = {1, 2, 3}; // Example input
    vector<vector<int>> permutations = arrPermutations(nums);

    // Print the permutations
    cout << "Permutations of the array: " << endl;
    for (const auto& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }




    return 0;
}


