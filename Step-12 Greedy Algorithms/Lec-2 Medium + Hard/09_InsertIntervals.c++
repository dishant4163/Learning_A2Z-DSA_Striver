// Insert Intervals



#include<bits/stdc++.h>
using namespace std;

//Soln_OPtimal Soln
// TC:- O(N),   SC:- O(N)
vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //define 2-D array to store answer
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

//LEFT-Portion
    //Add all intervals that come before the new interval
    while(i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

//MIDDLE-Portion
    // Merge all overlapping intervals with the new interval
    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);

//RIGHT-Portion
    // Add all the remaining intervals in right portion
    while(i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}



int main() {

    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {5, 8};

    vector<vector<int>> result = insertInterval(intervals, newInterval);
    cout << "The output is: " << endl;
    for(vector<int> it: result) {
        cout << it[0] << " " << it[1] << endl;
    }



    return 0;
}

