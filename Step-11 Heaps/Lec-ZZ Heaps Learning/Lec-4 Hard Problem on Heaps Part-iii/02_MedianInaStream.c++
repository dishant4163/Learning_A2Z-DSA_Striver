// Median from Running Data Stream/Median in a Stresam




#include<bits/stdc++.h>
using namespace std;

vector<int> findMedian(vector<int> &arr, int n) {
    vector<int> result;
    
    // Max-heap (to store the smaller half of the numbers)
    priority_queue<int> maxHeap;
    
    // Min-heap (to store the larger half of the numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        
        // Add the number to one of the heaps
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps: maxHeap can only have at most one more element than minHeap
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Find the median
        if(maxHeap.size() > minHeap.size()) {
            result.push_back(maxHeap.top());  // Odd number of elements
        } else {
            result.push_back((maxHeap.top() + minHeap.top()) / 2);  // Even number of elements
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {5, 15, 10, 20, 30};
    int n = arr.size();
    
    vector<int> medians = findMedian(arr, n);
    
    for(int median : medians) {
        cout << median << " ";
    }
    cout << endl;

    return 0;
}




