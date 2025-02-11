// 2D-DP | Ninja's Trainig



/*// Problem-Link-> https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003 

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Write your code here.
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
        temp[last] = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
            temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}


*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    // Base Case
    if(day == 0) {
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task < 3; task++) {
        if(task != last) {
            int point = points[day][task] + memoHelp(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// Function to find the maximum points for ninja training
int ninjatraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return memoHelp(n-1, 3, points, dp);
}








//Soln-2 TABULATION Approach
int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    //start traversing from day 1 to n
    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n-1][3]; 
}








//Soln-3 SPACE OPTIMIZATION Approach
int ninjasTraining(int n, vector<vector<int>>& points) {
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++) {
            temp[last] = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}






int main() {

    // Define the points matrix
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size(); // get number of days


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach & output is: " << ninjatraining(n, points) << endl << endl; 


//Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach & output is: " << ninjaTraining(n, points) << endl << endl;


//Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach & output is: " << ninjasTraining(n, points) << endl << endl;






    return 0;
}
