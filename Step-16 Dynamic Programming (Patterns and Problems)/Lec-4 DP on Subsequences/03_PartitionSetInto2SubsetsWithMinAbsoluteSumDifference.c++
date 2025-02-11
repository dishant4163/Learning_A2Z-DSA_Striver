// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference



/*// Problem-Link-> https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494  

int minSubsetSumDifference(vector<int>& arr, int n) {
	// Write your code here.
	int totalSum = 0;
	for(int i=0; i < n; i++) totalSum += arr[i];

	int k = totalSum;
	vector<bool> prev(k+1, false), cur(k+1, false);
	//base case-1
	prev[0] = cur[0] = true;
	//base case-2
	if(arr[0] <= k) prev[arr[0]] = true;

	for(int ind = 1; ind < n; ind++) {
		for(int target = 1; target <= k; target++) {
			bool notTake = prev[target];
			bool take = false;
			if(arr[ind] <= target) take = prev[target - arr[ind]];

			cur[target] = take || notTake;
		}
		prev = cur;
	}

	int mini = 1e9;
	for(int i=0; i <= totalSum; i++) {
		if(prev[i] == true) {
			mini = min(mini, abs(i - (totalSum - i)));
		}
	}

	return mini;
}


*/


#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
bool memoHelp(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = memoHelp(ind-1, target, arr, dp);
    bool take = false;
    if(arr[ind] <= target) take = memoHelp(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = take || notTake;
}

int minsubsetsumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for(int i=0; i < n; i++) totalSum += arr[i]; // Calculate the total sum of the array

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    // Calculate the subset sum for each possible sum from 0 to the total sum
    for(int i = 0; i <= totalSum; i++) {
        bool dummy = memoHelp(n-1, i, arr, dp);// Populate the DP table.
    }

    int mini = 1e9;

    // Find the minimum difference between two subset sums.
    for(int i=0; i <= totalSum; i++) {
        if(dp[n-1][i] == true) {
            // Calculate the absolute difference
            int diff  = abs(i - (totalSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}





// Soln-2 TABULATION Approach
int minsubSetSumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += arr[i];

    int k = totalSum;
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i=0; i < n; i++) dp[i][0] = true;
    if(arr[0] <= k) dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];

            dp[ind][target] = take || notTake;
        }
    }

    //  dp[n-1][col-> 0....totSum]
    int mini = 1e9;
    for(int s1=0; s1 <= totalSum/2; s1++) {
        if(dp[n-1][s1] == true) {
            mini = min(mini, abs((totalSum - s1) - s1));
        }
    }

    return mini;
}





// Soln-3 SPACE OPTIMIZATION Approach
int minSubSetSumDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for(int i=0; i < n; i++) totalSum += arr[i];

    int k = totalSum;
    vector<bool> prev(k+1, false), cur(k+1, false);
    prev[0] = cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;

    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target - arr[ind]];

            cur[target] = take || notTake;
        }
        prev = cur;
    }

    int mini = 1e9;
    for(int i=0; i <= totalSum; i++) {
        if(prev[i] == true) {
            mini = min(mini, abs(i- (totalSum - i)));
        }
    }

    return mini;
}






int main() {

    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The minimum absolute difference is: " << minsubsetsumDifference(arr, n) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The minimum absolute difference is: " << minsubSetSumDifference(arr, n) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "The minimum absolute difference is: " << minSubSetSumDifference(arr, n) << endl << endl;


    return 0;
}
