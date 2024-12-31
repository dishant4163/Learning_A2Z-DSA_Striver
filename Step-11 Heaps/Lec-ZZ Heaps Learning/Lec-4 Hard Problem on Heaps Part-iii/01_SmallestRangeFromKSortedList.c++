// Smallest Range From K Sorted List 




#include<iostream>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;


//OPtimal SOln
// TC:-O(N x k log k)    SC:- O(K)
class node {
public:
    int data;
    int row;
    int col;

    node(int DATA, int ROW, int COl) {
        data = DATA;
        row = ROW;
        col = COl;
    }
};

class compare {
public:
    bool operator() (node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &ar, int k, int n) {
    int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare> minHp; 

    //Step-1 create a minheap for starting element of each list &
    //tracking mini/maxi ki value
    for(int i=0; i < k; i++) {
        int element = ar[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHp.push(new node(element, i, 0));
    }

    int start = mini, end = maxi;

    //Step-2 Process Ranges
    while(!minHp.empty()){

        // mini fetch
        node* temp = minHp.top();
        minHp.pop();

        mini = temp->data;

        // range or answer updation
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // next element exists
        if( (temp->col + 1) < n) {
            maxi = max(maxi, ar[temp->row][temp->col + 1]);
            minHp.push(new node(ar[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else { // next element does not exists
            break;
        }
    }

    return (end - start + 1);
}






int main() {

    vector<vector<int>> ar = {
        {1, 10, 11},
        {2, 3, 20},
        {5, 6, 12}
    };

    int k = ar.size(); // Number of lists
    int n = ar[0].size(); // Size of each list

    int ans = kSorted(ar, k, n);
    cout << "The smallest range is: " << ans << endl;


    return 0;
}