/*//(4 Sum: Find Quads that add up to a target value_Coding Ninja)-> https://bit.ly/3Bsovy2   

vector<vector<int>> fourSum(vector<int> &nums, int target) {
  // Write your code here
  int n = nums.size();
  vector<vector<int>> sol;

  // sort the given array
  sort(nums.begin(), nums.end());

  // calculate the quadruplets
  for (int i = 0; i < n; i++) {

    // Avoid the duplicates while moving i
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n; j++) {

      // avoid the duplicates while moving j
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      // 2 Pointers
      int k = j + 1;
      int l = n - 1;

      while (k < l) {
        long long sum = nums[i];
        sum += nums[j];
        sum += nums[k];
        sum += nums[l];
        if (sum == target) {
          vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
          sol.push_back(temp);
          k++;
          l--;

          // Skip the duplicates
          while (k < l && nums[k] == nums[k - 1])
            k++;
          while (k < l && nums[l] == nums[l + 1])
            l--;
        } else if (sum < target)
          k++;
        else
          l--;
      }
    }
  }

  return sol;
}

*/


/*Problem Statement(4 Sum | Find Quads that add up to a target value):-
Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute(Naive Approach)
   Approach: The steps are as follows:
  #  First, we will declare a set data structure as we want unique quadruplets.
  #  Then we will use the first loop(say i) that will run from 0 to n-1.
  #  Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
  #  Then there will be the third loop(say k) that runs from j+1 to n-1.
  #  Inside loop k, the fourth loop(say l) will run from k+1 to n-1.
  #  Now, inside these four nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k]+arr[l], and if it is equal to the target we will sort this quadruplet and insert it in the set data structure.
  #  Finally, we will return a list of stored quadruplets.

   Intuition: This approach is pretty straightforward. Here, we will check all possible quadruplets using 4 loops(as we did in the 3-sum problem) and among them, we will consider the ones whose sum is equal to the given target. And before considering them as our answer we need to sort the quadruplets in ascending order.

   Complexity Analysis:-
  # Time Complexity:- Time Complexity: O(N4), where N = size of the array.
    Reason: Here, we are mainly using 4 nested loops. But we not considering the time complexity of sorting as we are just sorting 4 elements every time.
  # Space Complexity: O(2 * no. of the quadruplets) as we are using a set data structure and a list to store the quads.
*/
vector<vector<int>>fourSum1(vector<int>& ar1, int target1) {
  int n1 = ar1.size();
  set<vector<int>> st1;

  // checking all possible quadruplets
  for (int i=0; i<n1; i++) {
    for (int j=i+1; j<n1; j++) {
      for (int k=j+1; k<n1; k++) {
        for (int l=k+1; l<n1; l++) {
          // taking bigger data type
          // to avoid integer overflow
          long long sum = ar1[i] + ar1[j];
          sum += ar1[k];
          sum += ar1[l];

          if (sum == target1) {
            vector<int> temp1 = {ar1[i], ar1[j],  ar1[k], ar1[l]};
            sort(temp1.begin(), temp1.end());
            st1.insert(temp1);
          }
        }
      }
    }
  }

  vector<vector<int>> ans1(st1.begin(), st1.end());
  return ans1;
}






/*// Soln 2: Better(Using 3 loops & set data structure)
   Approach:The steps are as follows:
  #  First, we will declare a set data structure as we want unique quadruplets.
  #  Then we will use the first loop(say i) that will run from 0 to n-1.
  #  Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
  #  Before the third loop, we will declare a HashSet to store the specific array elements as we intend to search the fourth element in that HashSet.
  #  Then there will be the third loop(say k) that runs from j+1 to n-1.
  #  Inside the third loop, we will calculate the value of the fourth element i.e. target - (nums[i]+nums[j]+nums[k]).
  #  If the fourth element exists in the HashSet, we will sort these four values i.e. nums[i], nums[j], nums[k], and the fourth element, and insert it in the set data structure declared in step 1.
  #  After that, we will insert the k-th element i.e. nums[k] in the HashSet as we only want to insert those array elements that are in between indices j and k.
  #  Finally, we will return a list of stored quadruplets stored in the set data structure.

   Complexity Analysis:-
  # Time Complexity:- O(N3*log(M)), where N = size of the array, M = no. of elements in the set.
    Reason: Here, we are mainly using 3 nested loops, and inside the loops there are some operations on the set data structure which take log(M) time complexity.
  # Space Complexity: O(2 * no. of the quadruplets)+O(N)
    Reason: we are using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).
*/
vector<vector<int>>fourSum2(vector<int>& ar2, int target2) {
  int n2 = ar2.size();
  set<vector<int>> st2;

  // checking all possible quadruplets
  for (int i=0; i<n2; i++) {
    for (int j=i+1; j<n2; j++) {
      set<long long> hashset2;
      for (int k=j+1; k<n2; k++) {
        // taking bigger data type
        // to avoid integer overflow
        long long sum2 = ar2[i] + ar2[j];
        sum2 += ar2[k];
        long long fourth = target2 - sum2;
        if (hashset2.find(fourth) != hashset2.end()) {
          vector<int> temp2 = {ar2[i], ar2[j], ar2[k], (int)(fourth)};
          sort(temp2.begin(), temp2.end());
          st2.insert(temp2);
        }

        // put the kth element into the hashset
        hashset2.insert(ar2[k]);
      }
    }
  }

  vector<vector<int>> ans2(st2.begin(), st2.end());
  return ans2;
}






/*// Soln 3: OPtimal
   Approach:The steps are as follows:
  #  First, we will sort the entire array.
  #  We will use a loop(say i) that will run from 0 to n-1. This i will represent one of the fixed pointers. In each iteration, this value will be fixed for all different values of the rest of the 3 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
  #  After checking inside the loop, we will introduce another fixed pointer j(runs from i+1 to n-1) using another loop. Inside this second loop, we will again check for duplicate elements and only perform any further operation if the elements are different.
  #  Inside the second loop, there will be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index). The pointer k will move forward and the pointer l will move backward until they cross each other while the value of i and j will be fixed.
>       Now we will check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l].
>       If the sum is greater, then we need lesser elements and so we will decrease the value of l.
>       If the sum is lesser than the target, we need a bigger value and so we will increase the value of k. 
>       If the sum is equal to the target, we will simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into our answer and move the pointers k and l skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
  #  Finally, we will have a list of unique quadruplets.

   Complexity Analysis:-
  # Time Complexity:- Time Complexity: O(N3), where N = size of the array.
    Reason: Each of the pointers i and j, is running for approximately N times. And both the pointers k and l combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N3). 
  # Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
vector<vector<int>>fourSum3(vector<int>& arr, int target) {
  int n = arr.size();
  vector<vector<int>> sol;

  // sort the given array
  sort(arr.begin(), arr.end());

  // calculate the quadruplets
  for(int i=0; i<n; i++) {

    //Avoid the duplicates while moving i
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    for (int j = i + 1; j < n; j++) {

      // avoid the duplicates while moving j
      if (j > i + 1 && arr[j] == arr[j-1]) continue;

      // 2 Pointers
      int k = j+1;
      int l = n-1;

      while(k < l) {
        long long sum = arr[i];
        sum += arr[j];
        sum += arr[k];
        sum += arr[l];
        if (sum == target) {
          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          sol.push_back(temp);
          k++;
          l--;

          // Skip the duplicates
          while(k < l && arr[k] == arr[k - 1]) k++;
          while(k < l && arr[l] == arr[l + 1]) l--;
        }
        else if (sum < target) k++;
        else l--;
      }
    }
  }


  return sol;
}








int main() {

// Soln 1: Brute(Naive Approach(using 4 loops))
  vector<int> ar1 = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target1 = 9;
    vector<vector<int>> ans1 = fourSum1(ar1, target1);
    cout << "The quadruplets are: \n";
    for (auto it : ans1) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << endl;



// Soln 2: Better(using 3 loops with set & hashset)
    vector<int> ar2 = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target2 = 9;
    vector<vector<int>> ans2 = fourSum2(ar2, target2);
    cout << "The quadruplets are: \n";
    for (auto it : ans2) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << endl;



// Soln 3: Optimal(using 2 Pointers)
    vector<int> arr = {1, 4, 3, 3, 2, 5, 4, 2, 1, 2, 1, 3, 4, 5};
    int target = 8;
    vector<vector<int>> sol = fourSum3(arr, target);
    cout << "The quadruplets are: \n";
    for (auto it : sol) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout<<endl;



    return 0;
}
