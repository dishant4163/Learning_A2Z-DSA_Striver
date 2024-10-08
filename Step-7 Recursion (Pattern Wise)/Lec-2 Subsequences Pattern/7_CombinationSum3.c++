// Combination Sum-3 | Recursion

/* Combination Sum III_(Coding Ninjas):- https://shorturl.at/0zOHP      

void solve(int ind, int sum, int k, int n, vector<vector<int>>& ans, vector<int>& output) {
    //Base Cases
    if (sum == n && k == 0) {
        ans.push_back(output);
        return;
    }
    if (sum > n || k < 0) return;

    for(int i = ind; i <= 9; i++) {
        if (i > n) break;

        output.push_back(i);
        solve(i+1, sum+i, k-1, n, ans, output);
        output.pop_back();
    }
}

vector<vector<int>> combinationSum(int k, int n) {
    // Write Your Code Here
    vector<vector<int>> ans;
    vector<int> output;
    solve(1, 0, k, n, ans, output);
    //sort(ans.begin(), ans.end()); //if asked in problem
    return ans;
}

*/


/* //216. Combination Sum III (Leetcode)

   Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

  # Only numbers 1 through 9 are used.
  # Each number is used at most once.

   Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.


 Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.



 Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.



 Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.


  Constraints:
 # 2 <= k <= 9
 # 1 <= n <= 60

*/


#include<bits/stdc++.h>
using namespace std;

void solveComboS3(int sum, int ind, int k, int n, vector<vector<int>>& ans, vector<int>& output) {
    // Base Cases
    if (sum == n && k == 0) {
        ans.push_back(output);
        return;
    }
    if (sum > n || k < 0) return;

    for(int i=ind; i <= 9; i++) {
        if (i > n) break;
        output.push_back(i);
        solveComboS3(sum + i, i + 1, k - 1, n, ans, output);
        output.pop_back();
    }
}


vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> output;
    solveComboS3(0, 1, k, n, ans, output);
    return ans;
}


int main() {

    int k, n;
    cout << "Enter the values of k and n: ";
    cin >> k >> n;

    vector<vector<int>> result = combinationSum3(k, n);

    cout << "Combinations are:\n";
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }



    return 0;
}



