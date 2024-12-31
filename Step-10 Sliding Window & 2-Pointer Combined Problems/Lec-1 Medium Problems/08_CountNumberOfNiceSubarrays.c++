// Count Number of Nice Subarrays (it based on previous problem
// Binary subarray with Sum)
// Nice Subarrays means Count of Odd Integers in Subarray is Equal to given Target(k)


/* Count Distinct Subarrays With At Most K Odd Elements -> ( https://shorturl.at/3z7hG )

int cntNumOfBinarySubAr(vector<int>& nums, int goal) {
	int n=nums.size(), l=0, r=0, cnt=0, sum=0;

	//Edge Case
	if(goal < 0) return 0;

	while(r < n) {
		sum += nums[r] % 2; // if it is odd num gives 1 & for even gives 0

        while(sum > goal) {
			sum -= nums[l] % 2; // if it is odd num gives 1 & for even gives 0
			l++;
		}

		cnt += (r-l+1);
		r++;
	}
	return cnt;
}

int distinctSubKOdds(vector<int> &arr, int k) {
	// Write your code here
	return cntNumOfBinarySubAr(arr, k) - cntNumOfBinarySubAr(arr, k-1);
}

*/


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
// TC:- O(N^2), SC:- O(1)
    int countDistinctSubArKOdds(vector<int>& nums, int target) {
        int s = nums.size(), count = 0;

        //Edges Case
        if(target < 0) return 0;

        for(int i=0; i < s; i++) {
            int Sum = 0;
            for(int j=i; j < s; j++) {
                Sum += nums[j] % 2; //if it is odd num gives 1 & for even gives 0

                if(Sum == target) {
                    count++;
                }
            }
        }
        return count;
    }
*/




/*//Soln-2 Better Soln (using hashmap & prefix Sum) 
// TC:O(N)    SC(N)
int cntDistinctSubArKOdds(vector<int>& arr, int goal) {
    int m= arr.size(), Cnt = 0, currSum = 0;
    unordered_map<int, int> prefixSumCnt;

//Initially, we add 0 to the map to handle cases where the subarray itself equals the goal
    prefixSumCnt[0] = 1;

    for(int i=0; i < m; i++) {
        //Update the running sum (prefix sum)
        currSum = currSum + arr[i] %2; // if it is odd num gives 1 & for even gives 0

        //Check if the (currentSum - goal) exists in the map
        if (prefixSumCnt.find(currSum - goal) != prefixSumCnt.end()) {
            //Add the frequency of the corresponding prefixsum
            Cnt += prefixSumCnt[currSum - goal];
        }

        // Update the map with the current prefix sum
        prefixSumCnt[currSum]++;
    }
    return Cnt;
}
*/




//Soln-3 OPTimal Soln (using 2-Ptr & Sliding Window )
// TC:- O(4N), SC:- O(1)
int cntNumOfBinarySubAr(vector<int>& ar, int k) {
	int n=ar.size(), l=0, r=0, cnt=0, sum=0;

	//Edge Case
	if(k < 0) return 0;

	while(r < n) {
		sum += ar[r] % 2; // if it is odd num gives 1 & for even gives 0

        while(sum > k) {
			sum -= ar[l] % 2; // if it is odd num gives 1 & for even gives 0
			l++;
		}

		cnt += (r-l+1);
		r++;
	}
	return cnt;
}

int distinctSubArKOdds(vector<int> &ar, int k) {
	return cntNumOfBinarySubAr(ar, k) - cntNumOfBinarySubAr(ar, k-1);
}






int main() {

/*//Soln-1 Brute Force
    vector<int> nums = {1, 5, 2, 1, 1};
    int target = 3;
    cout << "Number of Nice Subarrays is: " << countDistinctSubArKOdds(nums, target) << endl;
*/


/*//Soln-2 Better Soln
    vector<int> arr = {1, 5, 2, 1, 1};
    int goal = 3;
    cout << "Number of Nice Subarrays is: " << cntDistinctSubArKOdds(arr, goal) << endl;
*/


//Soln-3 OPtimal (using 2-Ptr & Sliding Window )
    vector<int> ar = {1, 5, 2, 1, 1};
    int k = 3;
    cout << "Number of Nice Subarrays is: " << distinctSubArKOdds(ar, k) << endl;




    return 0;
}

