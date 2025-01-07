/*// N meetings in one room
// https://www.naukri.com/code360/problems/maximum-meetings_1062658

class meeting {
public:
    int startTime, endTime;
};

bool compare(meeting m1, meeting m2) {
    return m1.endTime < m2.endTime;  // Sort by end time
}

int maximumMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();

    // Create a vector of meetings
    vector<meeting> meets(n);
    for (int i = 0; i < n; i++) {
        meets[i].startTime = start[i];
        meets[i].endTime = end[i];
    }

    // Sort meetings by their end time
    sort(meets.begin(), meets.end(), compare);

    // Greedily select meetings
    int count = 1;  // First meeting is always selected
    int freeTime = meets[0].endTime;  // End time of the first selected meeting

    for (int i = 1; i < n; i++) {
        if (meets[i].startTime > freeTime) {
            count++;  // Increment count if meeting can be selected
            freeTime = meets[i].endTime;  // Update last_end_time to the current meeting's end time
        }
    }

    return count;  // Return the maximum number of meetings that can be attended
}

*/


#include<bits/stdc++.h>
using namespace std;

struct meeting {
public:
    int startTime;
    int endTime;
    int pos;
};

bool compare(meeting m1, meeting m2) {
    return m1.endTime < m2.endTime;
}


int maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();

    vector<meeting> meets(n);
    for(int i = 0; i < n; i++) {
        meets[i].startTime = start[i];
        meets[i].endTime = end[i];
    }

    sort(meets.begin(), meets.end(), compare);

    int cnt = 1, freeTime = meets[0].endTime;

    for(int i = 1; i < n; i++) {
        if(meets[i].startTime > freeTime) {
            cnt++;
            freeTime = meets[i].endTime;
        }
    }

    return cnt;
}


int main() {

    vector<int> start = { 0, 3, 1, 5, 5, 8 };
    vector<int> end = { 5, 4, 2, 9, 7, 9 };

    int res = maximumMeetings(start, end);
    cout << "Maximum meeting can be held is " << res << endl;

    return 0;
}
