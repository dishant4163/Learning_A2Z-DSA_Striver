// Shortest Job First (or SJF) CPU Scheduling



#include<bits/stdc++.h>
using namespace std;


// TC:- O(N) + O(N logN), SC:- O(1)
// Function to calculate average waiting time using Shortest Job First algorithm
float shortestJobFirst(vector<int> jobs) {
    sort(jobs.begin(), jobs.end());

    int n = jobs.size(), totalTime = 0;
    float waitTime = 0;

    for(int i = 0; i < n; i++) {
        waitTime += totalTime; // Add current total time to waiting time
        totalTime += jobs[i]; //Add current job's time to total time
    }

    //Return the average waiting time
    return (waitTime / n);
}




int main() {

    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;

    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;



    return 0;
}


