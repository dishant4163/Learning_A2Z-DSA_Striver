// Jump Game Part-2



#include<bits/stdc++.h>
using namespace std;


//Soln-1 Brute Force(using recursion)
// TC: O(N^N) exponential TC,   SC:- O(N), auxiliary stack space
/*int solveJump(vector<int>& jumps, int index) {
    int n = jumps.size(), miniJumps = INT_MAX;

    // If the current index is the last position or beyond, no more jumps needed
    if(index >= n-1) return 0;

    // Try all possible jumps from the current index
    for(int i = 1; i <= jumps[index]; i++) { //start iteration from i = 1
        miniJumps = min(miniJumps, ( solveJump(jumps, index + i) + 1) );// +1 for the current jump
    }

    return miniJumps;
}


int jumpii(vector<int>& nums) { //main code
    if (nums.size() == 1) return 0;

    return solveJump(nums, 0);
}
*/





//Soln-2 OPtimal (greedily)
int jump2(vector<int>& arr) {
    int cntJumps = 0, l = 0, r = 0 , N = arr.size();

    while(r < N-1) {
        int farthest = 0;

        for(int i = l; i <= r; i++) {
            farthest = max(farthest, i + arr[i]);
        }

        //if(farthest <= r) return -1; //if not reach last index

        l = r + 1;
        r = farthest;
        cntJumps++;
    }

    return cntJumps;
}






int main() {

/*//Soln-1 Brute Force(using recursion)
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum number of jumps: " << jumpii(nums) << endl;
*/


//Soln-2 OPtimal (greedily)
    vector<int> ar = {2, 3, 1, 1, 4};
    cout << "Minimum number of jumps: " << jump2(ar) << endl;





    return 0;
}

