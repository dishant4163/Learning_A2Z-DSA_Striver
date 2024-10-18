// Two Numbers with Odd Occurrences/Single Number-iii | Bit Manipulation

/* Two Numbers with Odd Occurrences (Coding Ninjas =>  https://shorturl.at/Ar7DG  )

vector<int> twoOddNum(vector<int> arr){
    // Write your code here.
    int xorr = 0;

    for(int i=0; i<arr.size(); i++) {
        xorr = xorr ^arr[i];
    }

    int rightmostbit ;

    if(xorr == INT_MIN) {
        rightmostbit = INT_MIN;
    } else {
        rightmostbit = (xorr & ~(xorr-1));
    }

    int bucket1 = 0, bucket2 = 0;

    for (int i=0; i < arr.size(); i++) {
        if (arr[i] & rightmostbit) {
            bucket1 = bucket1 ^ arr[i];
        }
        else {
            bucket2 = bucket2 ^ arr[i];
        }
    }

    if(bucket1 > bucket2) return {bucket1, bucket2};
    else return {bucket2, bucket1};
}

*/


#include<bits/stdc++.h>
using namespace std;


/*//Soln-1 Brute Force(using HashMap)

  Intuition:- This approach involves using a hashmap to store the frequency of each element in the input array. After traversing the input array and storing the frequency of each element in the hashmap, we iterate through it to find the two elements with a frequency of 1 and return them.


  Algorithm:
 Step 1:Initialise an empty hashmap to store the frequency of each element.

 Step 2: Populate the hashmap by iterating through the input array. For each element in the array, if it is already present in the hashmap, increment its frequency. Otherwise, add it to the hashmap with a frequency of 1.

 Step 3:Initialise an array ans to store the elements that appear once.

 Step 4: Iterate through the hashmap to find the elements with a frequency of 1. For each key-value pair in the hashmap if the value (frequency) is 1, add the corresponding key to the ans array.

 Step 5: Return the ans vector.


   Complexity Analysis

 # Time Complexity:O(N x log2M + M) where N is the number of elements in the input array and M = (N/2 + 2):-
    Inserting into the hashmap with the frequency of each element in the input array requires iterating through the entire array once ie. O(N). At each element, we search if it is already present in the map or not.
    In the worst case scenario, this adds a complexity of O(log2M) for each insertion. Here M is the maximum size of the map, which can be N/2 + 2 at max as all elements are present twice except one.
    After populating the hashmap, we iterate over it to find the element with a frequency of 1. This operation's time complexity is O(M), where M = N/2 + 2 represents the number of unique elements.

 # Space Complexity : O(M) where M = N/2 + 1, representing the number of unique elements stored in the hashmap. This is because each element in the input array appears twice except one, therefore after the last scenarios the space complexity taken up is N/2 + 2.
*/
vector<int> twoOddNum_1(vector<int> arr){
    unordered_map<int, int> mp;
    for(int i=0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    //Initialize ans vector for storing multiple single nos
    vector<int> ans;

    for(auto it: mp) {
        if(it.second == 1) {
            ans.push_back(it.first);
        }
    }

    return ans;
}






/*//Soln-2 OPtimal Soln(using Bitwise Operator i.e, Concepts of Buckets)

  Algorithm:-
 Step 1: Take the XOR of all numbers in the array. Since XOR of two identical numbers is 0, and XOR of a number with 0 is the number itself, the XOR operation will result in the XOR of the two numbers that appear only once in the array.

 Step 2: The XOR operation of all numbers in the array will yield a result with at least one bit set to 1.

    This is because if the two unique numbers were identical, their XOR would be 0.
    Conversely, if they were different, there would be at least one bit position where they differ, and the XOR operation of different bits results in 1.
    Hence, the XOR result will have at least one bit set to 1.

 Step 3: Take the rightmost set bit of the XOR result.

    To isolate this bit, create a mask equal to num-1 and use the bitwise AND operation with (num & (num-1)).
    XOR this result with the original XOR result to isolate the rightmost bit. 

 Step 4: Using the rightmost bit set number, we can create two buckets based on whether the corresponding bit in each element of the array is set or unset. 

    Since the corresponding rightmost bit is set differently in the two unique single numbers, they will fall into separate buckets.
    Based on the check of whether the bit is set or not, we XOR the number into one of the two buckets.

 Step 5:The two buckets are divided in such a way that both the buckets will only have one number appearing once. By taking a XOR of all numbers appearing in a bucket, all numbers appearing twice will cancel out each other and only the single unique number will remain.


   Complexity Analysis:-
 Time Complexity: O(2N) where N is the number of elements in the input array. This is because we iterate through the array twice: once to compute the XOR of all elements and once to place each number in its corresponding bucket.

 Space Complexity : O(1) as we are only using a constant amount of extra space regardless of the size of the input array. The algorithm uses only a few extra variables to store intermediate results and these variables do not depend on the size of the input array.
*/
vector<int> twoOddNum(vector<int> ar) {
    int xorr = 0;
    for(int i=0; i < ar.size(); i++) {
        xorr = xorr ^ ar[i];
    }

    int rightMostSetBit;

    if(xorr == INT_MIN) rightMostSetBit = INT_MIN;
    else rightMostSetBit = (xorr & (xorr-1)) ^ xorr;

    int bucket1 = 0, bucket2 = 0;
    for(int i=0; i < ar.size(); i++) {
        if(ar[i] & rightMostSetBit) bucket1 ^= ar[i];
        else bucket2 ^= ar[i];
    }

    return {bucket1, bucket2};

}







int main() {

/*//Soln-1 Brute Force(using HashMap)
    vector<int> nums = {2, 3, 2, 6, 3, 7, 7, 3, 4};
    cout << "Initial vector: ";
    for (auto it: nums){
        cout << it << " ";
    }
    cout << endl;
    vector<int> ans = twoOddNum_1(nums);
    cout << "Elements that appear only once: ";
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;
*/
    vector<int> ar = {2, 4, 2, 14, 3, 7, 7, 3};
    cout << "Input Array: ";
    for(int it: ar){
        cout << it << " ";
    }
    cout << endl;
    cout << "Unique Numbers: ";
    vector<int> soln = twoOddNum_1(ar);
    for (int it : soln) {
        cout << it << " ";
    }
    cout <<endl;



//Soln-2 OPtimal Soln(using Bitwise Operator)
    vector<int> arr = {1, 2, 1, 5, 2, 7};
    cout << "Input Array: ";
    for(int iT: arr){
        cout << iT << " ";
    }
    cout << endl;
    cout << "Unique Numbers: ";
    vector<int> result = twoOddNum(arr);
    for (int iT : result) {
        cout << iT << " ";
    }





    return 0;
}

