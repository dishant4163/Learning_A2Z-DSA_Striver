// Merge OverLapping Intervals



#include<bits/stdc++.h>
using namespace std;


/*// Brute Force
// TC:- O(N logN + N^2),    SC:- O(N)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < n; i++) {
        int start = intervals[i][0], end = intervals[i][1];

        //skip all the merged intervals
        if(!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        for(int j = i+1; j < n; j++) {
            if(intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
            }
            else break;
        }

        ans.push_back({start, end});
    }

    return ans;
}
*/




//OPtimal Soln
// TC:- O(N logN) + O(N),   SC:- O(N)
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr) {
    int s = arr.size();
    vector<vector<int>> ans;

    //Edge case
    if(s == 0) return ans;

    sort(arr.begin(), arr.end());

    for(int i=0; i < s; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval lies in the last interval
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}





int main() {


/*//Brute Force
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = merge(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
*/


// OPtimal SOln
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;



    return 0;
}

