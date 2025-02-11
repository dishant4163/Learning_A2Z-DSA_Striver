// 1D-DP | DP on Subsequences | House Robber-2


/* // PRoblem-Link->  https://www.naukri.com/code360/problems/house-robber_839733

#include <bits/stdc++.h> 

long long int maxNonAdjHouses(vector<int>& arr) {
    int n = arr.size();
    long long int prev2 = 0;
    long long int prev = arr[0];

    for(int i = 1; i < n; i++) {
        long long int pick = arr[i];
        if(i > 1) pick += prev2;

        long long int notPick = 0 + prev;

        long long int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}



long long int houseRobber(vector<int>& valueInHouse) {
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    vector<int> temp1, temp2;

    for(int i = 0; i < n; i++) {
        //Leave 1st array element
        if(i != 0) temp1.push_back(valueInHouse[i]);

        //Leave Last array element
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }

    return max(maxNonAdjHouses(temp1), maxNonAdjHouses(temp2));
}

*/



#include<bits/stdc++.h>
using namespace std;

// Soln->  SPACE OPTIMIZATION Approch
long long int maxNonAdjHouses(vector<int>& arr) {
    int n = arr.size();
    long long int prev2 = 0;
    long long int prev = arr[0];

    for(int i = 1; i < n; i++) {
        long long int pick = arr[i];
        if(i > 1) pick += prev2;

        long long int notPick = 0 + prev;

        long long int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}


long long int robStreet(int n, vector<int> &valuesInHouse) {
    //Edge Case
    if(n == 1) return valuesInHouse[0];

    vector<int> temp1, temp2;

    for(int i = 0; i < n; i++) {
        //Leave 1st array element
        if(i != 0) temp1.push_back(valuesInHouse[i]);

        //Leave Last array element
        if(i != n-1) temp2.push_back(valuesInHouse[i]);
    }

    return max(maxNonAdjHouses(temp1), maxNonAdjHouses(temp2));
}






int main() {

// Soln->  SPACE OPTIMIZATION Approch
    vector<int> arr{1,5,1,2,6};
    int n=arr.size();
    cout << "The output is: " << robStreet(n,arr);


    return 0; 
}

