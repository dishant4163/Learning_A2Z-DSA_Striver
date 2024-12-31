// K'th Smallest Element in Unsorted Array


/*// Kth Smallest Element -> ( https://shorturl.at/mNTqn )

int kthSmallest(int n,int k,vector<int> Arr) {
    // Write your code here.
    priority_queue<int> pq;
    for(int i=0; i < k; i++) {
        pq.push(Arr[i]);
    }

    for(int i=k; i < n; i++) {
        if(Arr[i] < pq.top()){
            pq.pop();
            pq.push(Arr[i]);
        }
    }

    return pq.top();
}

*/

#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC: O(N log(N)) bcz of sorting, SC:- O(1)
int kthSmallestEl(int arr[], int N, int K) {
    //int arr[] is not a dynamically allocated array. It is statically allocated array
    // arr.size() don't work
    // int s = sizeof(arr) / sizeof(arr[0]); //this will work too but 
    // giving argumental error so rather to pass here, pass int main() & also give wrong ans

    sort(arr, arr + N);

    return arr[K-1];
}
*/



//Soln-2 OPtimal Soln
int kthSmallestEle(int ar[], int n, int k) {
    priority_queue<int> pq;

    //Step-1 Create Max-Heap for 1st K element
    for(int i=0; i < k; i++) {
        pq.push(ar[i]);
    }

    //Step-2 For remaining elements 
    // if ele < heap.top ele
    for(int i = k; i < n; i++) {
        if(ar[i] < pq.top()) {
            pq.pop();
            pq.push(ar[i]);
        }
    }

    // return ans as heap.top
    return pq.top();
} 






int main() {

/*//Soln-1 Brute Force
    int arr[] = {10, 7, 20, 4, 3, 15};
    int N = sizeof(arr) / sizeof(arr[0]), K = 3;
    cout << "K'th smallest element is: " << kthSmallestEl(arr, N, K) << endl;
*/


//Soln-2 OPtimal
    int n = 5;
    int ar[] = {7, 10, 4, 20 ,15}, k = 4;
    cout << "K'th smallest element is: " << kthSmallestEle(ar, n, k) << endl;



    return 0;
}

