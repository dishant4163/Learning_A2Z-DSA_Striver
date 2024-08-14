/*//(Stock Buy & Sell_Coding Ninja)-> https://bit.ly/3GsANaD

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minPrice = INT_MAX;
    int n = prices.size();
    int maxPro = 0;

    for (int i=0; i<n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}

*/


/*Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/




#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force
   Intuition: We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

   Approach: 
  #  Use a for loop of ‘i’ from 0 to n.
  #  Use another for loop of j from ‘i+1’ to n.
  #  If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
  #  Return maxPro.

   Complexity Analysis:-
  # Time complexity: O(n^2)
  # Space Complexity: O(1)
*/
int maximumProfit1(vector<int> &ar1) {
    int maxProfit1 = 0;
    int n1 = ar1.size();

    for (int i = 0; i < n1; i++) {
        for (int j = i+1; j < n1; j++ ) {
            if (ar1[j] > ar1[i]) {
                maxProfit1 = max(maxProfit1, ar1[j] - ar1[i]);
            }
        }
    }
    return maxProfit1;
}






/*//Soln 2: Optimal
   Intuition: We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

   Approach:
  #  Create a variable maxPro and store 0 initially.
  #  Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
  #  Run a for loop from 0 to n.
  #  Update the minPrice if it is greater than the current element of the array
  #  Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
  #  Return the maxPro.

   Complexity Analysis:-
  # Time complexity: O(n)
  # Space Complexity: O(1)
*/
int maximumProfit2(vector<int> &ar2) {
    int maxProfit2 = 0;
    int n2 = ar2.size();
    int minPrice = INT_MAX;

    for (int i=0; i < n2; i++) {
        minPrice = min(minPrice, ar2[i]);
        maxProfit2 = max(maxProfit2, ar2[i] - minPrice);
    }
    return maxProfit2;
}




int main() {

//Soln 1: Brute Force
    vector<int> ar1 = {7,1,5,3,6,4};
    int maxProfit1 = maximumProfit1(ar1);
    cout << "Max profit is: " << maxProfit1 << endl;



//Soln 2: Optimal Approach
    vector<int> ar2 = {7,1,5,3,6,4};
    int maxProfit2 = maximumProfit2(ar2);
    cout <<"Max profit is: "<<maxProfit2<<endl;



return 0;

}