/*//(2 Sum Problem_Coding Ninja)-> https://bit.ly/3Iu7zMu

#include<bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    map<int,int> mpp;//Or We can use "unordered_map" too.
    for (int i=0; i<n; i++) {
        int a = book[i];
        int moreNeeded = target - a;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
*/


/*Problem Statement: Given an array of integers arr[] and an integer target.

 #  1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

 #  2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

 Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1:Brute Force(Naive Approach)
 Intuition: For each element of the given array, we will try to search for another element such that its sum is equal to the target. If such two numbers exist, we will return the indices or “YES” accordingly.

 Approach:
  #  First, we will use a loop(say i) to select the indices of the array one by one.
  #  For every index i, we will traverse through the remaining array using another loop(say j) to find the other number such that the sum is equal to the target (i.e. arr[i] + arr[j] = target).

   Observation: In every iteration, if the inner loop starts from index 0, we will be checking the same pair of numbers multiple times. For example, in iteration 1, for i = 0, we will check for the pair arr[0] and arr[1]. Again in iteration 2, for i = 1, we will check arr[1] and arr[0]. So, to eliminate these same pairs, we will start the inner loop from i+1.

   Complexity Analysis:
  # Time Complexity: O(N2), where N = size of the array.
->   Reason: There are two loops(i.e. nested) each running for approximately N times.
  # Space Complexity: O(1) as we are not using any extra space.
*/
// CODE Variant 1
string twoSum1(int n1, vector<int> &ar1, int target1) {
    for (int i=0; i < n1; i++) {
        for (int j = i+1; j < n1; j++) {
            if (ar1[i] + ar1[j] == target1) {
                return "YES";
            }
        }
    }
    return "NO";
}


// CODE Variant 2
vector<int> twoSum2(int n2, vector<int> &ar2, int target2) {
    vector<int> ans2;// declare VECTOR as Answer
    for (int i=0; i < n2; i++) {
        for (int j = i+1; j < n2; j++) {
            if (ar2[i] + ar2[j] == target2) {
                ans2.push_back(i);
                ans2.push_back(j);
                return ans2;
            }
        }
    }
    return { -1, -1};
}






/*// Soln 2:Better(Using Hashing) 
  Intuition: Basically, in the previous approach we selected one element and then searched for the other one using a loop. Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists. Thus we can trim down the time complexity of the problem.

And for the second variant, we will store the element along will its index in the HashMap. Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.

 Approach:- The steps are as follows:

  #  We will select the element of the array one by one using a loop(say i).
  #  Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
->       If that element exists, then we will return “YES” for the first variant or we will return the current index i.e. i, and the index of the element found using map i.e. mp[target-arr[i]].
->       If that element does not exist, then we will just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
  #  Finally, if we are out of the loop, that means there is no such pair whose sum is equal to the target. In this case, we will return either “NO” or {-1, -1} as per the variant of the question.
*/
// CODE Variant 1
string twoSum3(int n3, vector<int> &ar3, int target3) {
    unordered_map<int, int> mpp3;
    for (int i=0; i < n3; i++) {
        int num3 = ar3[i];
        int moreNeeded3 = target3 - num3;
        if (mpp3.find(moreNeeded3) != mpp3.end()) {
            return "YES";
        }
        mpp3[num3] = i;
    }
    return "NO";
}
// CODE Variant 2
vector<int> twoSum4(int n4, vector<int> &ar4, int target4) {
    unordered_map<int, int> mpp4;
    for (int i=0; i<n4; i++) {
        int num4 = ar4[i];
        int moreNeeded4 = target4 - num4;
        if (mpp4.find(moreNeeded4) != mpp4.end()) {
            // return indexes
            return {mpp4[moreNeeded4], i}; 
        }
        mpp4[num4] = i;
    }
    return {-1, -1};
}






/*// Soln 3: Optimal Approach(Using 2-Pointer)
 Intuition:- 
 _____In this approach, we will first sort the array and will try to choose the numbers in a greedy way._____

  # We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer. 

  # If sum == target we will return either “YES” or the indices as per the question.
But if the left crosses the right pointer, we will return “NO” or {-1, -1}.

   Approach:- The steps are the following:
  #  We will sort the given array first.
  #  Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
  #  Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
->      If arr[left] + arr[right] > sum, we will decrement the right pointer.
->      If arr[left] + arr[right] < sum, we will increment the left pointer.
->      If arr[left] + arr[right] == sum, we will return the result.
  #  Finally, if no results are found we will return “No” or {-1, -1}.

    Note: For variant 2, we can store the elements of the array along with its index in a new array. Then the rest of the code will be similar. And while returning, we need to return the stored indices instead of returning “YES”. But for this variant, the recommended approach is approach 2 i.e. hashing approach.

   Complexity Analysis:-
  # Time Complexity: O(N) + O(N*logN), where N = size of the array.
->  Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.

  # Space Complexity: O(1) as we are not using any extra space.

*** Note: Here we are distorting the given array. So, if we need to consider this change, the space complexity will be O(N).
*/
// CODE Variant 1
string twoSum5 (int n5, vector<int> &ar5, int target5) {
    //First, sort the array
    sort(ar5.begin(), ar5.end()); // O(N*logN)
    // 2-Ppinters
    int left = 0, right = n5 - 1; // from 0 to n-1

    while (left < right) {
        int sum5 = ar5[left] + ar5[right];
        if (sum5 == target5) {
            return "YES";
        }
        else if ( sum5 < target5 ) {
            left++;//move left pointer forward
        }
        else {
            right--;// move right pinter backward
        }
    }
    return "NO";
}






int main() {
// Soln 1: Brute Force ( Variant 1 )
    int n1 = 5;
    vector<int> ar1 = {2, 6, 5, 8, 11};
    int target1 = 14;
    string ans1 = twoSum1(n1, ar1, target1);
    cout << "This is the soln for Variant 1 via Brute Force: " << ans1 << endl;


// Soln 1: Brute Force ( Variant 2 )
    int n2 = 5;
    vector<int> ar2 = {2, 6, 5, 8, 11};
    int target2 = 14;
    vector<int> ans2 = twoSum2(n2, ar2, target2);
    cout <<"This is the soln for Variant 2 via Brute Force: ["<<ans2[0] << ", "<<ans2[1] <<"]"<< endl;




// Soln 2: Better ( Variant 1 )
    int n3 = 5; 
    vector<int> ar3 = {2, 6, 5, 8, 11};
    int target3 = 14;
    string ans3 = twoSum3(n3, ar3, target3);
    cout << "This is the soln for Variant  via Better Approach: "<<ans3<<endl;


// Soln 2: Better ( Variant 2 )
    int n4 = 5;
    vector<int> ar4 = {2, 6, 5, 8, 11};
    int target4 = 14;
    vector<int> ans4 = twoSum4(n4, ar4, target4);
    cout<<"This is the Soln for Variant 2 via Better Approach: [" << ans4[0] <<", "<<ans4[1]<<"]"<<endl;



// Soln 3: Optimal Approach ( Variant 1 )
    int n5 = 5;
    vector<int> ar5 = {2, 6, 5, 8, 11};
    int target5 = 14;
    string ans5 = twoSum5(n5, ar5, target5);
    cout<<"This is the Soln for Variant 1 via Opitmal Approach: "<<ans5<<endl;
// *** NOTE(Optimal Approach):-
// (i). THIS not OPTIMAL SOLN for solving this kind of Problem
// (ii). I'm Provinding this soln bcz if not asked to use HASHING(i.e., maps) then we can go this approach
// (iii). And also this Approach is hard to use for Variant-2.



    return 0;
}