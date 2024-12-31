// Binary subarray with Sum (based on Count SubArrays Sum Equal to K)


/* GFG__Binary subarray with Sum->( https://shorturl.at/8QK6P )


class Solution {
    public:
    int lessEqualToGoal(vector<int>& ar, int goal) {
        int n=ar.size(), l=0, r=0, sum=0, cnt=0;

        //EDGE case
        if(goal < 0) return 0;

        while(r < n) {
            sum = sum + ar[r];

            while(sum > goal) {
                sum = sum - ar[l];
                l++;
            }

            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        return lessEqualToGoal(arr, target) - lessEqualToGoal(arr, target-1);
    }
};


*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(N^2), SC:- O(1)
    int countNumOfBinarySubArray(vector<int>& nums, int target) {
        int s = nums.size(), count = 0;

        //Edges Case
        if(target < 0) return 0;

        for(int i=0; i < s; i++) {
            int Sum = 0;
            for(int j=i; j < s; j++) {
                Sum += nums[j];

                if(Sum == target) {
                    count++;
                }
            }
        }
        return count;
    }
*/




//Soln-2 Better Soln (using hashmap & prefix Sum) 
// TC:O(N)    SC(N)
int cntNumOfBinarySubArray(vector<int>& arr, int tar) {
    int m= arr.size(), Cnt = 0, currSum = 0;
    unordered_map<int, int> prefixSumCnt;

//Initially, we add 0 to the map to handle cases where the subarray itself equals the goal
    prefixSumCnt[0] = 1;

    for(int i=0; i < m; i++) {
        //Update the running sum (prefix sum)
        currSum = currSum + arr[i];

        //Check if the (currentSum - goal) exists in the map
        if (prefixSumCnt.find(currSum - tar) != prefixSumCnt.end()) {
            //Add the frequency of the corresponding prefixsum
            Cnt += prefixSumCnt[currSum - tar];
        }

        // Update the map with the current prefix sum
        prefixSumCnt[currSum]++;
    }
    return Cnt;
}





//Soln-3 OPTimal Soln (using 2-Ptr & Sliding Window )
// TC:- O(4N), SC:- O(1)
int lessEqualToGoal(vector<int>&ar, int goal) {
    //Edge Case
    if(goal < 0) return 0;

    int n = ar.size(), l=0, r=0, sum=0, cnt=0;

    while(r < n) {
        sum += ar[r];

        while(sum > goal) {
            sum = sum - ar[l]; //shrinks Lptr
            l++;
        }

        cnt = cnt + (r-l+1);

        r++;
    }

    return cnt;
}

int countNumOfBinarySubArrays(vector<int>& nums, int goal) {
    return lessEqualToGoal(nums, goal) - lessEqualToGoal(nums, goal-1);
}





int main() {

/*//Soln-1 Brute Force
    vector<int> nums = {1, 0, 1, 0, 1};
    int target = 2;
    int result = countNumOfBinarySubArray(nums, target);
    cout << "Number of subarrays with sum " << target << " is: " << result << endl;
*/


//Soln-2 Better Soln
    vector<int> arr = {1, 0, 1, 0, 1};
    int tar = 2;
    cout << "Number of subarrays with sum " << tar << " is: " << cntNumOfBinarySubArray(arr, tar) << endl;


//Soln-3 OPtimal (using 2-Ptr & Sliding Window )
    vector<int> ar = {1, 0, 0, 1, 1, 0};
    int goal = 2;
    cout << "Number of binary subarrays with sum 'GOAL': " << countNumOfBinarySubArrays(ar, goal) << endl;




    return 0;
}

