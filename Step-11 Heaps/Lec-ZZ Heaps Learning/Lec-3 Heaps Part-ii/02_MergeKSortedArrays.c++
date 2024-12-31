// Merge K Sorted Arrays


#include<bits/stdc++.h>
using namespace std;

//Brute Force
vector<int> mergekSortedArr(vector<vector<int>>& arr) {
    vector<int> res;

    // Append all arrays into res
    for (auto it : arr) {
        for (int i: it)
            res.push_back(i);
    }

    sort(res.begin(), res.end());
    return res;
} 






//OPtimal Soln (using minheap)
class Node {
public:
    int data;
    int row;
    int col;

    Node(int DATA, int ROW, int COL) {
        this->data = DATA;
        row = ROW;
        col = COL;
    }


};

class compare { // defining khud ka comparator
public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>>& ar) {
    priority_queue<Node*, vector<Node*>, compare> pq; //minheap me graeter nhi aaye ga or apna comparator laga na hoga
    vector<int> ans;

    //Step-1 saare arrays k first element insert karne h
    for(int i=0; i < ar.size(); i++) {
        Node* temp = new Node(ar[i][0], i, 0);
        pq.push(temp);
    }

    //Step-2
    while(!pq.empty()) {
        Node* temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();

        int i = temp->row;
        int j = temp->col;

        if( (j+1) < ar[i].size()) {
            Node* newNode = new Node(ar[i][j+1], i, j+1);
            pq.push(newNode);
        }
    }

    return ans;
}



int main() {

//Brute
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> soln = mergekSortedArr(arr);
    //output
    cout << "Merged array: ";
    for(int it : soln) {
        cout << it << " ";
    }
    cout << endl;




//OPtimal
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    
    // Merge k sorted arrays
    vector<int> result = mergeKSortedArrays(arrays);
    
    // Output the result
    cout << "Merged array: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;



    return 0;
}
