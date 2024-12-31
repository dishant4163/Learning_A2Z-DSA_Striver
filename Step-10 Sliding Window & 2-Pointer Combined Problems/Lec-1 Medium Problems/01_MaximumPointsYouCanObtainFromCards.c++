//  Maximum Points You Can Obtain from Cards


/* Maximum Points From Cards-> https://shorturl.at/goWJo     


int maxPoints(vector<int>&arr , int K){
    // Write your code here.
    int n = arr.size(), lsum = 0, rsum = 0, maxSum = 0;

    for(int i=0; i < K; i++) {
        lsum = lsum + arr[i];
    }

    maxSum = lsum;

    int rightInd = n-1;
    for(int i = K-1; i >= 0; i--) {
        lsum = lsum - arr[i];
        rsum = rsum + arr[rightInd];
        rightInd--;

        maxSum = max(maxSum, (lsum + rsum));
    }

    return maxSum;
}

*/


#include<bits/stdc++.h>
using namespace std;

// OPtimal Soln (using sliding Wind & 2-ptr)
// TC: O(2k) , SC:- O(1)
int maxCardsPoints(vector<int>&ar , int k){
    int n = ar.size();
    int lSum = 0, rSum = 0, maxSum = 0;

    for(int i=0; i < k; i++) { // this will take O(k)
        lSum = lSum + ar[i];
        maxSum = lSum;
    }


    int rInd = n-1;
    for(int i = k-1; i >= 0; i--) { //this loop, also take O(k)
        lSum = lSum - ar[i];
        rSum = rSum + ar[rInd];
        rInd--;

        maxSum = max(maxSum, (lSum + rSum));
    }

    return maxSum;
}


int main() {

    vector<int> num = {9, 7, 5, 3, 2, 1, 8};
    int k = 4;  // Number of cards we can pick
    cout << maxCardsPoints(num, k) << endl;  // Output the result



    return 0;
}

