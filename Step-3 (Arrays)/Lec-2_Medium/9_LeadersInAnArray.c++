/*//(Leaders in an Array_Coding Ninja)-> https://bit.ly/3I6VADy    

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.

    vector<int> ans;//declare ans array as answer
    int maxi = INT_MIN;//as small as maximum element
    int  n = a.size();//Size of the array

    for (int i = n-1; i >= 0; i--) { //back traversing
        if (a[i] > maxi) { // & then check arr[i] is >than the maximum element
            ans.push_back(a[i]);// if found put in the ans array
        }
        //Update maxi & Keep a track of right maxi
        maxi = max(maxi, a[i]);
    }
    //for sorting the ans array 
    sort(ans.begin(), ans.end());
    return ans;

}
*/


//A Leader is an element that is greater than all of the elements on its right side in the array.


#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array, print all the elements which are leaders. 


/*// Soln 1: Brute Force
   Intuition:- There is no special intuition needed here. Just a common fact that we need to compare elements in order to find the greatest is more than enough.

   Approach:- 
  #  In this brute force approach, we start checking all the elements from the start of the array to the end to see if an element is greater than all the elements on its right (i.e, the leader).
  #  For this, we will use nested loops where the outer loop will check for each element in the array whether it is a leader or not.
  #  The inner loop checks if there is any element to the right that is greater than the element currently traversed by the outer loop.
  #  We start by initializing the outer loop pointer to the start element and setting it as the current leader.
  #  If any element traversed is found greater than the element currently set as a leader, it will not go to the ans array and we increment the outer loop pointer by 1 and set the next element as the current leader.
  #  If we don’t find any other element to the right greater than the current element, then we push the current element to the ans array stating that is it the leader element.

   Complexity Analysis:-
  # Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.
  # Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }
*/
vector<int> printLeadersBruteForce(int Ar[], int N) {
    //declare vector ans as array for storing answer
    vector<int> Ans;

    for (int i=0; i < N; i++) {
        bool Leader = true;

        //Checks whether ar[i] is greater than all
        //the elements in its right side
        for(int j=i+1; j < N; j++) {
            if (Ar[j] > Ar[i]) {
            //If any element found is >than current leader
            // current element is not the leader   
            Leader = false;
            break;
            }
        }

        // Push all the Leaders in ans array
        if(Leader == true){
            Ans.push_back(Ar[i]);
        }
    }
    return Ans;
}






/*// Soln 2: Optimal 
   Approach:-
  #     In the above approach, we do a fresh traversal for each candidate. If we think carefully, we only want to compare the elements on the right side. So, what if we start from the last element?
  #  That is, we'll try to remember the greatest element encountered so far and we'll use that to decide whether a candidate is a leader or not.
  #  First, we'll start the traversal from the right. Then, we move toward the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
  #  If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.
  #  Else, we proceed with the further elements on the left. This method prints the leaders in the reverse direction of their occurrences. If we are concerned about the order, we can use an extra array or a string to order.

   Complexity Analysis:-
  # Time Complexity: O(N) { Since the array is traversed single time back to front, it will consume O(N) of time where N = size of the array }.
  # Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
*/
vector<int> printLeadersOptimal(int ar[], int n) {
    //declare vector ans array as answer
    vector<int> ans;

    // Last element of array is alawys a Leader
    // push into ans array
    int maxi = ar[n-1];
    ans.push_back(ar[n-1]);

    //Start checking from the End whether a number is 
    //greater than max no. from right, hence a Leader
    for (int i = n-2; i >= 0; i--) {
        if (ar[i] > maxi) {
            ans.push_back(ar[i]);
            maxi = ar[i];
        }
    }

    return ans;
}





int main() {

// Soln 1: Brute Force Approach
    //Array Initialization
    int N = 6;
    int Ar[N] = {10, 22, 12, 3, 0, 6};
    vector<int> Ans = printLeadersBruteForce(Ar, N);
    for (int i=0; i < Ans.size(); i++) {
        cout<<Ans[i]<<" ";
    }
    cout<<endl;



// Soln 2: OPtimal 
    int n = 6;
    int ar[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeadersOptimal(ar, n);

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] <<" ";
    }
    cout << endl;




    return 0;
}

