// Partition Equal Subset Sum


/*// Problem-Link-> https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980


bool canPartition(vector<int> &arr, int n) {
	// Write your code here.
	int totalSum = 0;
	for(int i = 0; i < n; i++) totalSum += arr[i];

	if(totalSum % 2 == 1) return false;
	else {
		int k = totalSum / 2;
		vector<bool> prev(k+1 ,false), cur(k+1, false);
		prev[0] = cur[0] = true;

		if(arr[0] <= k) prev[arr[0]]  =true;

		for(int ind = 1; ind < n; ind++) {
			for(int target = 1; target <= k; target++) {
				bool notTake = prev[target];
				bool take = false;
				if(arr[ind] <= target) take = prev[target - arr[ind]];

				cur[target] = take || notTake;
			}
			prev = cur;
		}
		return prev[k];
	}
}


*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
bool memoHelp(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    bool notTake = memoHelp(index-1, target, arr, dp);
    bool take = false;
    if(arr[index] <= target) take = memoHelp(index-1, target-arr[index], arr, dp);

    return dp[index][target] = take || notTake;
}

bool canPartition1(int n, vector<int>& arr) {
    int totalSum = 0;

    for(int i=0; i < n; i++) totalSum += arr[i];

    if(totalSum % 2 == 1) {
        return false;
    }
    else {
        int k = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return memoHelp(n-1, k, arr, dp);
    }
}






// Soln-2 TABULATION Approach
bool canPartition2(int n, vector<int>& arr) {
    int totalSum = 0;
    for(int i=0; i < n; i++) totalSum += arr[i];

    if(totalSum % 2 == 1) return false;
    else {
        int k = totalSum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));

        for(int i=0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;

        for(int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= k; target++) {
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];

                dp[ind][target] = notTake || take;
            }
        }

        return dp[n-1][k];
    }
}






// Soln-3 SPACE OPTIMIZATION Approach
bool canPartition3(int n, vector<int>& arr) {
    int totalSum = 0;
    for(int i=0; i < n; i++) totalSum += arr[i];

    if(totalSum % 2 == 1) return false;
    else {
        int k = totalSum / 2;

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
        return prev[k];
    }
}




int main() {

    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    if (canPartition1(n, arr)) cout << "The Array can be partitioned into two equal subsets";
    else cout << "The Array cannot be partitioned into two equal subsets";
cout << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    if (canPartition2(n, arr)) cout << "The Array can be partitioned into two equal subsets";
    else cout << "The Array cannot be partitioned into two equal subsets";
cout << endl << endl;



// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    if (canPartition3(n, arr)) cout << "The Array can be partitioned into two equal subsets";
    else cout << "The Array cannot be partitioned into two equal subsets";
cout << endl << endl;




    return 0;
}
