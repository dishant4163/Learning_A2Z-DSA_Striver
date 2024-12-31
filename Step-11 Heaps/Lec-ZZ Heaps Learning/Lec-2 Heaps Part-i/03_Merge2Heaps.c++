// Merge Two Binary Max Heaps

/*Merge Two Binary Max Heaps ->(https://shorturl.at/rIaPp)

#include <bits/stdc++.h> 

void heapify(vector<int>& ar, int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && ar[largest] < ar[l]) largest = l;
    if(r < n && ar[largest] < ar[r]) largest = r;

    if(largest != i) {
        swap(ar[largest], ar[i]);
        heapify(ar, n, largest);
    }
}

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Write your code here
    vector<int> ans; // step-1 merge two heaps
    
    for(auto it: arr1) ans.push_back(it);
    for(auto it: arr2) ans.push_back(it);

    //step-2 apply heapify algo
    int s = ans.size();
    for(int i = (s/2 - 1); i >= 0; i--) { // s/2 - 1, bcz for 0-based indexing
        heapify(ans, s, i);
    }

    return ans;
}

*/

#include<bits/stdc++.h>
using namespace std;

//OPtimal Soln
void heapify(vector<int>&ar, int n, int i) {
// playing with 0-Based indexing
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && ar[largest] < ar[l]) largest = l;
    if(r < n && ar[largest] < ar[r]) largest = r;

    if(largest != i) {
        swap(ar[largest], ar[i]);
        heapify(ar, n, largest);
    }
}

vector<int> mergeTwoHeaps(vector<int>&a, vector<int>&b, int n, int m) {
    //step-1 mereg both arrays into one
    vector<int> ans;

    for(auto it: a) {
        ans.push_back(it);
    }
    for(auto it: b) {
        ans.push_back(it);
    }

    //step-2 build heap using merged array
    int s = ans.size();
    for(int i = (s/2 - 1); i >= 0; i--) { // non-leafNnodes from (n/2 - 1) to >= 0 in zero-based indexing
        heapify(ans, s, i);
    }

    return ans;
}






int main() {

//OPtimal Soln
    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };

    int n = a.size();
    int m = b.size();

    vector<int> res = mergeTwoHeaps(a, b, n, m);
    for(auto it : res) {
        cout << it << " ";
    }


    return 0;
}

