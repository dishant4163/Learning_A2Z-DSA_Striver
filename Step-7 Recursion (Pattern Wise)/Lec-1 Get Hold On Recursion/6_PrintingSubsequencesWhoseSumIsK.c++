// Problems on Printing Subsequences 



#include<bits/stdc++.h>
using namespace std;


// Problem-1 Printing Subsequences whose sum is K
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






// Print any SubSequences whose Sum is givenSum
// i.e, technique to print 1 answer
 //Problem-2 Print any SubSequences whose Sum is givenSum
bool printSubsequenceSumK2(int indx, vector<int> &listAr, int givensum, int Sum, int ar[], int N) {
    if(indx == N) {
        // if condition satisfiesd
        if (givensum == Sum) {
            for (auto it : listAr ) cout << it << " ";
            cout <<endl;
            return true;
        }
        // condition not satisfiesd
        else return false;
    }

    listAr.push_back(ar[indx]);
    givensum += ar[indx];

    if (printSubsequenceSumK2(indx+1, listAr, givensum, Sum, ar, N) == true) {
        return true;
    }

    givensum -= ar[indx];
    listAr.pop_back();

    // not pick
    if (printSubsequenceSumK2(indx+1, listAr, givensum, Sum, ar, N) == true) return true;

    return false;
}






// Problem-3 Count the Subsequence with Sum = K










int main() {

// Problem-1
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> listArr;
    printSubsequenceSumK(0, listArr, 0, sum, arr, n);




// Problem-2 Print any SubSequences whose Sum is givenSum
int arr2[] = {1, 2, 1};
    int n2 = 3;
    int sum2 = 2;
    vector<int> listArr2;
    printSubsequenceSumK2(0, listArr2, 0, sum2, arr2, n2);




// Problem-3 Count the Subsequence with Sum = K







    return 0;
}



