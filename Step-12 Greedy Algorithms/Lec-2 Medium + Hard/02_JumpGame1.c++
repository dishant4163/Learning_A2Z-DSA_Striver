// Jump Game-i



#include<bits/stdc++.h>
using namespace std;

//TC:- O(N),  SC:- O(1)
bool canJump(vector<int>& nums) {
    int n = nums.size(), maxIndex = 0;

    for(int i = 0; i < n; i++) {
        if (i > maxIndex) return false;

        //update maxIndex
        maxIndex = max(maxIndex, i + nums[i]);
    }

    return true;
}



int main() {

    vector<int> nums = {3, 2, 1, 0, 4};
    cout << "Array representing maximum jump from each index: ";
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    bool ans = canJump(nums);
    if (ans) {
        cout << "It is possible to reach the last index." << endl;
    } else {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}
