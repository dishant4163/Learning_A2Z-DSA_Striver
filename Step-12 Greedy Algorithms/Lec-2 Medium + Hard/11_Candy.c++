// Candy -> Leetcode-135

/*//Coding Ninjas - Problem Link
// https://www.naukri.com/code360/problems/candies_893290?leftPanelTabValue=PROBLEM


int requiredCandies(vector < int > &students) {
    // Write your code here.
    int n = students.size(), sum = 1, i = 1;

    while(i < n) {
        if(students[i] == students[i-1]) {
            sum += 1;
            i++;
            continue;
        }

        int peak = 1;
        while(i < n && students[i] > students[i-1]) {
            peak += 1;
            sum += peak;
            i++;
        }

        int down = 0;
        while(i < n &&students[i] < students[i-1]) {
            down += 1;
            sum += down;
            i++;
        }
        down++;

        if(down > peak) {
            sum += down - peak;
        }
    }

    return sum;
}

*/



#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(3N), SC:- O(2N)
int Candy(vector<int>& ar) {
    int s = ar.size();

    int leftAr[s], rightAr[s];
    leftAr[0] = 1;
    rightAr[s-1] = 1;

    for(int i = 1; i < s; i++) {
        if(ar[i] > ar[i-1]) {
            leftAr[i] = leftAr[i-1] + 1;
        }
        else {
            leftAr[i] = 1;
        }
    }

    for(int i = s-2; i >= 0; i--) {
        if(ar[i] > ar[i+1]) {
            rightAr[i] = rightAr[i+1] + 1;
        }
        else {
            rightAr[i] = 1;
        }
    }

    int totalSum = 0;
    for(int i = 0; i < s; i++) {
        totalSum += max(leftAr[i], rightAr[i]);
    }

    return totalSum;
}
*/





/*//Soln-2 Better Soln
// TC:- O(2N),  Sc:- O(N)
int candies(vector<int>& arr) {
    int N = arr.size();
    int leftArr[N];
    leftArr[0] = 1;

    for(int i = 1; i < N; i++) {
        if(arr[i] > arr[i-1]) {
            leftArr[i] = leftArr[i-1] + 1;
        }
        else {
            leftArr[i] = 1;
        }
    }

    int curr = 1, rightArr = 1, sum = max(1, leftArr[N-1]);
    for(int i = N-2; i >= 0; i--) {
        if(arr[i] > arr[i+1]) {
            curr = rightArr + 1;
            rightArr = curr;
        }
        else {
            curr = 1;
        }

        sum += max(leftArr[i], curr);
    }

    return sum;
}
*/





//Soln-3 OPtimal Soln
// TC:- O(N), SC:- O(1)
int candy(vector<int>& ratings) {
    int n = ratings.size(), totalsum = 1, i = 1;

    while(i < n) {
        // it might be flat-surface
        if(ratings[i] == ratings[i-1]) {
            totalsum += 1;
            i++;
            continue;
        }

        int peak = 1;
        while(i < n && ratings[i] > ratings[i-1]) {
            peak++;
            totalsum += peak;
            i++;
        }

        int down = 0;
        while(i < n && ratings[i] < ratings[i-1]) {
            down++;
            totalsum += down;
            i++;
        }
        down++;

        if(down > peak) {
            totalsum += down - peak;
        }
    }

    return totalsum;
}








int main() {

/*//SOln-1 Brute Force
    vector<int> ar = {1, 0, 2};
    cout << "Minimum candies required: " << Candy(ar) << endl;
*/


/*//Soln-2 Better Soln
vector<int> arr = {1, 3, 2, 1};  
cout << "Total candies: " << candies(arr) << endl;
*/


//Soln-3 OPtimal
vector<int> ratings = {1, 3, 2, 1};
cout<< "Total candies: " << candy(ratings) << endl;



    return 0;
}

