// Fractional Knapsack Problem


/* Fractional Knapsack ( https://shorturl.at/07xZk )

*/



#include<bits/stdc++.h>
using namespace std;

// Structure to store an item along with its value-to-weight ratio
struct Item {
public:
    int val;
    int wt;

// Constructor to initialize the value and weight of an item
    Item (int VAL, int Wt) {
        val = VAL;
        wt = Wt;
    }
};

// writing own designed comparator
//Comparison function to sort Item acc to profit/weight ratio
static bool compare(struct Item a, struct Item b) {
    double x = (double)a.val / (double)a.wt;
    double y = (double)b.val / (double)b.wt;
    return x > y;
}



// solving with using vector pair-values
// TC:- O(N logN + N),   SC:- O(N)
double maximumValue(vector<pair<int, int>>& items, int n, int w) {
    // Step 1: Create a list of items
    vector<Item> itemList;
    for (int i = 0; i < n; i++) {
        itemList.push_back(Item(items[i].first, items[i].second));
    }

    // Step 2: Sort items based on value-to-weight ratio using the custom comparator
    sort(itemList.begin(), itemList.end(), compare);
    
    // Step 3: Start taking items to maximize the value
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (w == 0) {
            break;  // If the knapsack is full, stop.
        }

        // If item fits completely into the knapsack
        if (itemList[i].wt <= w) {
            totalValue += itemList[i].val;
            w -= itemList[i].wt;
        }
        // If the item doesn't fit completely, take the fraction of it
        else {
            totalValue += itemList[i].val * ((double)w / itemList[i].wt);
            //w = 0;  // Knapsack is full
            break;
        }
    }

    return totalValue;
}








// solving without using vector pairs
//TC: O(N+ N logN), SC:- O(1)
double maxiValue(struct Item ar[], int N, int W) {
    double maxiVal = 0.0;

    sort(ar, ar + N, compare);

    for(int i=0; i < N; i++) {
        if(ar[i].wt <= W){
            maxiVal += ar[i].val;
            W -= ar[i].wt;
        }
        else {
            maxiVal += ar[i].val * ((double) W / (double) ar[i].wt);
            break;
        }
    }

    return maxiVal;
}




int main() {

    // solving with pair values

int n, w;
    cout << "Enter the value of n ";
    cin >> n ;
    cout << "Enter the weight of the bag w ";
    cin >> w;  // Input number of items and capacity of knapsack
    vector<pair<int, int>> items = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};

    // Call the function to calculate the maximum value we can get
    cout << "The maximum value is " << fixed << setprecision(2) << maximumValue(items, n, w) << endl;





// solving without using vector pairs
    int W = 90;
    Item ar[] = {{100, 20}, {60, 10}, {100, 50}, {200, 50}};
    int N = sizeof(ar) / sizeof(ar[0]);

    // function call
    cout << endl << "The maximum value is " << fixed << setprecision(2) << maxiValue(ar, N, W);



    return 0;
}

