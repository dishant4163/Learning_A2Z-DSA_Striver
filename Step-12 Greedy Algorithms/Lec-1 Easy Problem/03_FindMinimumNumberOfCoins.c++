// Find minimum number of coins


/*Find minimum number of coins->( https://shorturl.at/RyJG3 )


*/



#include<bits/stdc++.h>
using namespace std;


vector<int> MinimumCoins(int n){
    // Denominations we have (you can modify this list as per your problem)
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};  // Coins available in descending order
    vector<int> ans;

    for(int i = denominations.size() - 1; i >= 0; i--) {
        while(n >= denominations[i]) {
            ans.push_back(denominations[i]);
            n -= denominations[i];
        }
    }

    return ans;
}




int main() {

    int n;
    cout << "Enter the amount: ";
    cin >> n;

    vector<int> result = MinimumCoins(n);
    
    cout << "Minimum coins needed: " << result.size() << endl;
    cout << "Coins used: ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;




    return 0;
}
