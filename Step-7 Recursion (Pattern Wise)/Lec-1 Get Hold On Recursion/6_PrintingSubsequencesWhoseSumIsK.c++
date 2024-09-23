// Printing Subsequences whose sum is K



#include<bits/stdc++.h>
using namespace std;


void printSubsequenceSumK(int ind, vector<int> &listArr, int givenSum, int sum, int arr[], int n) {
    if(ind == n) {
        if (givenSum == sum) {
            for (auto it : listArr ) cout << it << " ";
            cout <<endl;
        }
        return;
    }

    listArr.push_back(arr[ind]);
    givenSum += arr[ind];

    printSubsequenceSumK(ind+1, listArr, givenSum, sum, arr, n);

    givenSum -= arr[ind];
    listArr.pop_back();

    // not pick
    printSubsequenceSumK(ind+1, listArr, givenSum, sum, arr, n);
}





int main() {

    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> listArr;
    printSubsequenceSumK(0, listArr, 0, sum, arr, n);



    return 0;
}



