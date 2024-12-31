// Minimum Cost of Ropes

/* Minimum Cost of Ropes->(https://shorturl.at/9djiD)


long long connectRopes(int* arr, int n) {
    // Your code goes here
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    long long cost = 0;

    for(int i=0; i < n; i++) {
        pq.push(arr[i]);
    }

    while(pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}


*/

/* Connect n ropes with minimum cost-> (https://shorturl.at/4yGvb)

int minCost(int arr[], int n) {
	//  *Write your code here. 
	//  *Don't write main().
	//  *Don't take input, it is passed as function argument.
	//  *Don't print output.
	//  *Taking input and printing output is handled automatically.


	priority_queue<int, vector<int>, greater<int> > pq;
	int cost = 0;

	for(int i=0; i < n; i++) pq.push(arr[i]);

	while(pq.size() > 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		int sum = a+b;
		cost += sum;

		pq.push(sum);
	}
	return cost;
}


*/


#include<bits/stdc++.h>
using namespace std;

//OPtimal
// TC:- O(N logN), SC:- O(N)
int minCost(int ar[], int n) {
// using Min_heap for solving
    priority_queue<int, vector<int>, greater<int> > pq;
    int cost = 0;

    //push all elements into minheap
    for(int i=0; i < n; i++) {
        pq.push(ar[i]);
    }

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a+b;
        cost += sum;

        pq.push(sum);
    }
    return cost;
}


int main() {

//OPtimal 
    int len[] = { 4, 3, 2, 6 };
    int n = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "<< minCost(len, n);





    return 0;
}

