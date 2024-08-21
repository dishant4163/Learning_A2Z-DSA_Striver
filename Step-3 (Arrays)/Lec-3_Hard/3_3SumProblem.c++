/*// (3-Sum Problem_Coding Ninja)-> https://bit.ly/3X34JSI    

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        // remove duplicates
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        // Moving 2 pointers
        int j = i + 1;
        int k = n - 1;

        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }


    return ans;
}


*/



/* Problem Statement(3Sum: Find triplets that add up to a zero):- 
Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute(using 3-Pointers)
   Intuition:- This approach is pretty straightforward. Here, we will check all possible triplets using 3 loops and among them, we will consider the ones whose sum is equal to the given target i.e. 0. And before considering them as our answer we need to sort the triplets in ascending order so that we can consider only the unique ones.

   Algorithm:- The steps are as follows:
  #  First, we will declare a set data structure as we want unique triplets.
  #  Then we will use the first loop(say i) that will run from 0 to n-1.
  #  Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
  #  Then there will be the third loop(say k) that runs from j+1 to n-1.
  #  Now, inside these 3 nested loops, we will check the sum i.e. arr[i]+arr[j]+arr[k], and if it is equal to the target i.e. 0 we will sort this triplet and insert it in the set data structure.
  #  Finally, we will return the list of triplets stored in the set data structure.

   Complexity Analysis:-
  # Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
    Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
  # Space Complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
*/
vector<vector<int>>triplet_1(int n1, vector<int> &ar1) {
    set<vector<int>> st1;

    // Check all possible Triplets
    for (int i = 0; i < n1; i++) {
        for (int j = i + 1; j < n1; j++) {
            for (int k = j + 1; k < n1; k++) {
                if (ar1[i] + ar1[j] + ar1[k] == 0) {
                    vector<int> temp = {ar1[i], ar1[j], ar1[k]};
                    sort(temp.begin(), temp.end());
                    st1.insert(temp);
                }
            }
        }
    }

    //Store the set elements in the answer
    vector<vector<int>> ans1(st1.begin(), st1.end());
    return ans1;
}






/*// Soln 2: Better(using Hashing)
   Algorithm:- The steps are as follows:
  #  First, we will declare a set data structure as we want unique triplets.
  #  Then we will use the first loop(say i) that will run from 0 to n-1.
  #  Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
  #  Before the second loop, we will declare another HashSet to store the array elements as we intend to search for the third element using this HashSet.
  #  Inside the second loop, we will calculate the value of the third element i.e. -(arr[i]+arr[j]).
  #  If the third element exists in the HashSet, we will sort these 3 values i.e. arr[i], arr[j], and the third element, and insert it in the set data structure declared in step 1.
  #  After that, we will insert the j-th element i.e. arr[j] in the HashSet as we only want to insert those array elements that are in between indices i and j.
  #  Finally, we will return a list of triplets stored in the set data structure.

   Complexity Analysis:-
  # Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
>    Reason: Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
   # Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
*/
vector<vector<int>>triplet_2(int n2, vector<int> &ar2) {
    set<vector<int>> st2; //set of list(4 storing unique triplets)

    for (int i = 0; i < n2; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n2; j++) {
            // calculate the 3rd element
            int third = -(ar2[i] + ar2[j]);

            //Find the element in the set
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp2 = {ar2[i], ar2[j], third};
                sort(temp2.begin(), temp2.end());
                st2.insert(temp2);
            }

            hashset.insert(ar2[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans2(st2.begin(), st2.end());
    return ans2;
}






/*// Soln 3: Optimal(using 2-Pointers)
   Approach:- The steps are as follows:
  #  First, we will sort the entire array.
  #  We will use a loop(say i) that will run from 0 to n-1. This i will represent the fixed pointer. In each iteration, this value will be fixed for all different values of the rest of the 2 pointers. Inside the loop, we will first check if the current and the previous element is the same and if it is we will do nothing and continue to the next value of i.
  #  After that, there will be 2 moving pointers i.e. j(starts from i+1) and k(starts from the last index). The pointer j will move forward and the pointer k will move backward until they cross each other while the value of i will be fixed.
>    Now we will check the sum i.e. arr[i]+arr[j]+arr[k].
>    If the sum is greater, then we need lesser elements and so we will decrease the value of k(i.e. k--). 
>    If the sum is lesser than the target, we need a bigger value and so we will increase the value of j (i.e. j++). 
>    If the sum is equal to the target, we will simply insert the triplet i.e. arr[i], arr[j], arr[k] into our answer and move the pointers j and k skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers).
  #  Finally, we will have a list of unique triplets.

   Complexity Analysis:-
  # Time Complexity:- O(NlogN)+O(N2), where N = size of the array.
>    Reason: The pointer i, is running for approximately N times. And both the pointers j and k combined can run for approximately N times including the operation of skipping duplicates. So the total time complexity will be O(N2). 
  # Space Complexity: O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
vector<vector<int>> triplet_3(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i=0; i < n; i++) {
        // remove duplicates
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        // Moving 2 pointers
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k  && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    return ans;
}






int main() {

// Soln 1: Brute Force(using 3-Pointers)
    vector<int> ar1 = { -1, 0, 1, 2, -1, -4};
    int n1 = ar1.size();
    vector<vector<int>>ans1 = triplet_1(n1, ar1);
    for (auto it: ans1) {
        cout << "[";
        for (auto i: it) {
            cout << i << " ";
        }
        cout<<"]";
    }
    cout<<endl;



// Soln 2: Better(using Hashing)
    vector<int> ar2 = { -1, 0, 1, 2, -1, -4};
    int n2 = ar2.size();
    vector<vector<int>>ans2 = triplet_2(n2, ar2);
    for (auto it: ans2) {
        cout << "[";
        for (auto i: it) {
            cout << i << " ";
        }
        cout<<"]";
    }
    cout<<endl;



// Soln 3: Optimal(using 2-Pointer)
    vector<int> arr = {-2, 2, 0, 0, -1, -1, -2, 2, 0, -1, 2, -2, 2};
    int n = arr.size();
    vector<vector<int>> ans = triplet_3(n, arr);
    for (auto it: ans) {
        cout << "[";
        for (auto i: it) {
            cout << i <<" ";
        }
        cout << "]";
    }
    cout << endl;



    return 0;
}
