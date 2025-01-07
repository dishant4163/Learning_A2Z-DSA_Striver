// Job Sequencing Problem



#include<bits/stdc++.h>
using namespace std;

struct Job {
public:
    int id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit in descending order
bool static compare (Job j1, Job j2) {
    return j1.profit > j2.profit;
}



//main function to schedule jobs
pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compare);

    int maxDeadline = arr[0].deadline;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }

    int hashAr[maxDeadline + 1]; 
    for (int i = 0; i <= maxDeadline; i++) {
        hashAr[i] = -1;  // Initialize all slots as free (-1 means no job scheduled)
    }

    int maxProfit = 0, cntJobs = 0;

    // Iterate through jobs and try to schedule them
    for (int i = 0; i < n; i++) {
        // Try to schedule this job in the latest available slot before its deadline
        for (int j = arr[i].deadline; j > 0; j--) {
            if (hashAr[j] == -1) {  // Slot is free
                hashAr[j] = i;  // Assign job `i` to this slot
                cntJobs++;  // Increment the job count
                maxProfit += arr[i].profit;  // Add the profit of the job
                break;  // Stop once the job is scheduled
            }
        }
    }

    // Return the total number of jobs scheduled and the total profit
    return make_pair(cntJobs, maxProfit);
}
// TC:- O(N logN) + O(N*M),   SC:- O(N)



int main() {

    int n = 4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    //function call
    pair < int, int > ans = JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;


    return 0;
}


