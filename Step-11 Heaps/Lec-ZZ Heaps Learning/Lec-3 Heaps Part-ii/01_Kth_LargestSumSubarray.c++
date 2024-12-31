// Kth Largest Sum Subarray



#include<bits/stdc++.h>
using namespace std;

/*//Brute Force
int kthLargestSumSubAr(int ar[], int N, int K) {
    vector<int> ans;

    for(int i=0; i < N; i++) {
        int sum = 0;
        for(int j=i; j < N; j++){
            sum += ar[j];
            ans.push_back(sum);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[ans.size() - K]; //return the Kth largest sum
}
*/




//OPtimal (using minHeap)
int kthLargestSumSubArr(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i < n; i++) {
        int SUM = 0;
        for(int j=i; j < n; j++) {
            SUM += arr[j];
            if(pq.size() < k) {
                pq.push(SUM);
            }
            else {
                if(SUM > pq.top()) {
                    pq.pop();
                    pq.push(SUM);
                }
            }
        }
    }

    return pq.top();
}








int main() {

/*//Brute Force
    int ar[] = {20, -5, 1, 2, -1};
    int N = sizeof(ar) / sizeof(ar[0]);
    int K = 3;
    cout << kthLargestSumSubAr(ar, N, K) << endl;
*/



//OPtimal 
    int arr[] = {20, -5, 1, 2, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k= 3;
    cout << kthLargestSumSubArr(arr, n, k) << endl;




    return 0;
}

