// Non-overlapping Intervals



#include<bits/stdc++.h>
using namespace std;


// comparator function
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1] ;
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), compare);

    int n = intervals.size();
    int cnt = 1, lastEndTime = intervals[0][1];

    for(int i = 1; i < n; i++) {
        if(intervals[i][0] >= lastEndTime) {
            cnt++;
            lastEndTime = intervals[i][1];
        }
    }

    //Return the minimum number of intervals to remove
    return n - cnt;
}


int main() {

    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << eraseOverlapIntervals(intervals) << endl;


    return 0;
}

