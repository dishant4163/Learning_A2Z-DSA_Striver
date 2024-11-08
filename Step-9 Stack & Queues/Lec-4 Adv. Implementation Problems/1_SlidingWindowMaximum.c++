// Sliding Window Maximum






#include <bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force

  Intuition: We want to look for a window of size k at a time and then shift to the next window.
So why not do exactly what we are asked to! We fix our window of size k at first and then calculate the maximum element in it.
We then shift our window to the next position and do the same process until we exhaust all possibilities i.e we reach the end of the array.

  Approach: We initially keep a left and right pointer to fix our window to a size of k.
We compute the maximum element present in this window using the GetMax function. Further, update the left and right pointer by left++ and right++ every
time to get to a new window of size k using a while loop. For every new window we encounter, we add the maximum element using the GetMax function to our data structure.

   Complexity Analysis:
    # TC:- O(N-k) * O(k)
    # SC:- O(N-k)

*/
vector<int> maxSlidingWindow(vector<int>& nums, int K) {
    int s = nums.size();
    vector<int> res;

    for(int i=0; i <= (s-K); i++) {
        int maxiAns = nums[i];
        for(int j=i; j < (i+K); j++) {
            maxiAns = max(maxiAns, nums[j]);
        }
        res.push_back(maxiAns);
    }
    return res;
}







/*//Soln-2 Optimal Soln
  Intuition : Can we do something better?
 # To understand this, we would first need to check whether we are doing any repetitions. 
 To understand this, consider the following scenario:

   Window : [1,2,3]  and the next incoming value is 2

 # For this state, we get a maximum of 3. However, when our state changes to, [2,3,2] we again check what is the largest element even though 
 we know that the outgoing element is not the largest one. Hence, the point of concern lies only when the outgoing element was the largest. 


  Approach:- We address this problem with the help of a data structure that keeps checking whether 
  the incoming element is larger than the already present elements. This could be implemented with the help of a de-queue. 
  When shifting our window, we push the new element in from the rear of our de-queue.

  Every time before entering a new element, we first need to check whether the element present at the front is out of bounds of our present window size. 
  If so, we need to pop that out. Also, we need to check from the rear that the element present is smaller than the incoming element. 
  If yes, there’s no point storing them and hence we pop them out. Finally, the element present at the front would be our largest element.

   Complexity Analysis:-
  # TC:- : O(N)
  # Space Complexity: O(K)
*/
    vector<int> maxSlidingWindowK(vector<int>& ar, int k) {
    int n = ar.size();
    vector<int> ans;
    deque<int> dq;

    for(int i=0; i < n; i++) {
    // Remove indices that are out of the current window
        if(!dq.empty() && dq.front() == (i-k)) {
            dq.pop_front();
        }

    // Remove elements from the back of the deque if they are smaller than the current element
        while(!dq.empty() && ar[dq.back()] < ar[i]) {
            dq.pop_back();
        }

        // Add the current element's index to the deque
        dq.push_back(i);

        // Add the maximum for the current window to the result (starting from the K-1 index)
        if (i >= (k-1)) {
            ans.push_back(ar[dq.front()]);
        }

    }

    return ans;
}








int main() {

//SOln-1 Brute Force
    vector<int> nums = {12, 1, 78, 90, 57, 89, 56}; // Sample input
    int K = 3; // Window size
    vector<int> result = maxSlidingWindow(nums, K);
    cout << "Maximums in each sliding window: " ;
    for (int maxNum : result) {
        cout << maxNum << " ";
    }
    cout << endl;




//Soln-2 Optimal Soln
    vector<int> arr = {4,0,-1,3,5,3,6,8}; 
    int k = 3; // Window size
    vector<int> res = maxSlidingWindowK(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (int it : res) {
        cout << it << " ";
    }
    cout << endl;





    return 0;
}

