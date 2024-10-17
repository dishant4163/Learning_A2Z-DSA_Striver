// Single Number-ii | Bit Manipulation

/* // Single Number-ii (Coding Ninjas ->  https://shorturl.at/X5kxW  )

int elementThatAppearsOnce(vector<int> arr) {
	// Write your code here.

//MOST OPtimal Soln->Using Concepts of Buckets(Based on bitwise operator) Better than 99.5%

    int ones = 0, twos = 0;
    for(int i=0; i<arr.size(); i++) {
	    ones = (ones ^ arr[i]) & (~twos);
	    twos = (twos ^ arr[i]) & (~ones);
    }
    return ones;




//Test this Soln too. bcz of TC: O(N x 32) Better than 75.57%
	// int ans = 0;

	// for(int bitIndex = 0; bitIndex < 32; bitIndex++) {
	// 	int cntSetBits = 0;

	// 	for(int i=0; i < arr.size(); i++) {
	// 		//check ith bit is set
	// 		if(arr[i] & (1 << bitIndex)) cntSetBits++;
	// 	}

	// 	if(cntSetBits % 3 == 1) {
	// 		ans = ans | (1 << bitIndex);
	// 	}
	// }

	// return ans;
	



//OPtimal Soln --> TC:- O(nlogn +n/3) SC:- O(1) Better than 79.08%
	// sort(arr.begin(), arr.end());
    // //the indexing on Array is 0-based but start traversing from 1-index
	// for(int i = 1; i < arr.size(); i = i+3) {
	// 	if(arr[i] != arr[i-1]) {
	// 		return arr[i-1];
	// 	}
	// }

	// // if above return arr[i-1] statement never executed then ans is 
	// return arr[arr.size() - 1];



}

*/


#include<bits/stdc++.h>
using namespace std;


/* //Soln-1 Brute Force(Using HashMap)

  Algorithm / Intuition:- A straightforward approach involves using a hashmap to store the frequency of each element in the input array. After traversing the input array and storing the frequency of each element in the hashmap, we iterate through it to find the element with a frequency of 1. Return this element as it appears only once in the input array.


  Algorithm:-
 Step 1: Initialise an empty hashmap to store the frequency of each element.

 Step 2: Populate the hashmap by iterating through the input array.
  For each element in the array, if it is already present in the hashmap, increment its frequency. Otherwise, add it to the hashmap with a frequency of 1.

 Step 3: Iterate through the hashmap to find the element with a frequency of 1.
  For each key-value pair in the hashmap if the value (frequency) is 1, return the corresponding key (element) as it appears only once in the input array.


   Complexity Analysis:-

 Time Complexity: O(N x log2M + M) where N is the number of elements in the input array and M = (N/3 + 1).
  # Inserting into the hashmap with the frequency of each element in the input array requires iterating through the entire array once ie. O(N). At each element, we search if it is already present in the map or not.
  # In the worst case scenario, this adds a complexity of O(log2M) for each insertion. Here M is the maximum size of the map, which can be N//3 + 1 at max as all elements are present thrice except one.
  # After populating the hashmap, we iterate over it to find the element with a frequency of 1. This operation's time complexity is O(M), where M = N/3 + 1 represents the number of unique elements.


  Space Complexity: O(M)where M = N/3 + 1, representing the number of unique elements stored in the hashmap. This is because each element in the input array appears thrice except one, therefore after the last scenarios the space complexity taken up is N/3 + 1.

*/
int findSingleNumber_1(vector<int>& nums) {
    unordered_map<int, int> mp;

    for(int i=0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    for(auto it: mp) {
        if(it. second == 1) return it.first;
    }

    return -1;
}





/*//Soln-2 Better Approach (Bitwise)
   Algorithm / Intuition:- 
 The previous hashmap based approach requires a lot of space complexity to store the frequencies. We also iterate over the input array and the frequency map leading to high time complexity as well. To overcome this, we can use bitwise operations to solve this problem.

 We iterate through each bit position of the binary representation of the numbers in the input array. For each bit position, we calculate the sum of all numbers in the input array that have a set bit at that position and check if this sum is divisible by 3.

 If the sum is divisible by 3, it means that the number that appears only once on that bit position has a bit value of 0. Otherwise, it has a bit value of 1. This is because if a number appears thrice in the input array, the sum of its bits at any position will be divisible by 3.

   Algorithm:-

 Step 1: Initialise a variable `ans` to store the result.

 Step 2: Iterate through each bit position from 0 to 31. Inside the loop:
    Initialise a counter `cnt` to count the number of set bits at the current bit position.

 Step 3: Inside the loop, iterate through each element in the input array. Inside this nested loop:
    Check if the bit at the current position is set in the current element using bitwise AND with a mask for that current bit position from 0 to 31 ie. nums[i] & 1 << bitIndex.
    If the bit is set, increment the counter `cnt`.

 Step 4: After iterating through all elements, check if the count of set bits at the current bit position is not divisible by 3. If the condition is true, set the corresponding bit in the answer variable `ans` using the bitwise OR operation ie. ( ans |= 1 << bitIndex ).

 Step 5: After iterating through all bit positions, return the decimal representation of the answer stored in ans.


   Complexity Analysis

 Time Complexity: O(32*N) where N is the number of elements in the input array. This is because we iterate through each of the 32 bits of all N numbers in the input array.

 Space Complexity: O(1) as we are only using a constant amount of extra space regardless of the size of the input array.
*/ 
int findSingleNumber_2(vector<int>& ar) {
    int ans = 0;

    for(int bitIndex = 0; bitIndex < 32; bitIndex++) {
        int cntSetBits = 0;

        for(int i=0; i < ar.size(); i++) {
            //check ith bit is set or not
            if(ar[i] & (1 << bitIndex)) 
            cntSetBits++;
        }

        if(cntSetBits % 3 == 1) {
            ans= ans | (1 << bitIndex);
        }
    }

    return ans;
}





/*//Soln-3 OPtimal Approach (for-loop with iterating -> i = i+3)

 The previous approach uses nested loops to iterate over each bit of every element of the input array and can be optimised. Every element in the input array except one element is present three times.

 By sorting the array, the identical elements are grouped together. We iterate through the sorted array, skipping elements in groups of three. For each iteration we compare the current element with its preceding element.

 If the current element is different from its preceding element, it means that the preceding element appears only once in the array as all other elements appear three times. Therefore, we return the preceding element as the unique element.

  Algorithm:

 Step 1:Sort the input array using a sorting algorithm.

 Step 2: Traverse through the sorted array, starting from the second element (index 1):
    Since the array has been sorted, there will be consecutive triplets of each unique number except one single number out of order.
    Increment the loop variable by 3 in each iteration to skip elements in groups of three.

 Step 3: In each iteration, compare the current element with its preceding element. If the current element is not equal to its preceding element, return the preceding element as its unique element.

 Step 4: If the loop ends without returning the out of place element. Return the end element as that is the only unchecked element. Return it.


   Complexity Analysis

 # Time Complexity: O(N log2N) where N is the number of elements in the input array. Sorting the array has a time complexity of log2N and traversing the sorted array to find the unique element takes linear time.

 # Space Complexity: O(1) as we are only using a constant amount of extra space regardless of the size of the input array. The sorting operation is performed in-place, and no additional space is used beyond the input array. 
*/
int findSingleNumber(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    //the indexing on Array is 0-based but start traversing from 1-index
	for(int i = 1; i < arr.size(); i = i+3) {
		if(arr[i] != arr[i-1]) {
			return arr[i-1];
		}
	}

	// if above return arr[i-1] statement never executed then ans is 
	return arr[arr.size() - 1];
}










/* //4 MOST OPtimal Soln(using Concepts of Buckets(based on bitwise operator))


   Key Concepts
  # Bit Manipulation: The code uses bitwise operations to keep track of the counts of bits at each position across the integers in the vector.

  # Two Variables: It uses two variables, ones and twos, to keep track of the numbers that have appeared once and twice, respectively.


   How It Works

 1. Initialization:
   # ones: Keeps track of bits that have appeared once.
   # twos: Keeps track of bits that have appeared twice.

 2. Loop Through Each Number:
   # For each number in the array:
    > Update ones:
        Calculate the new value of ones using the formula:
        ones = (ones ^ a[i]) & (∼twos)

        This means: take the current ones, XOR it with the current number, and then clear any bits that are also in twos.

    > Update twos:
        Calculate the new value of twos using the formula:
        twos = (twos ^ a[i]) & (∼ones)

        This means: take the current twos, XOR it with the current number, and then clear any bits that are also in ones.

 3. Final Result:
   # After processing all numbers, ones will contain the bits of the number that appears only once, while twos will only track the numbers that have appeared twice.


    Summary:- In simpler terms, this code efficiently keeps track of how many times each bit has appeared across the array and uses that information to identify the unique number that only appears once.



   Complexity Analysis:
 TC:- O(N), n is array size
 SC:- O(1)

*/
int singleNumber_ii (vector<int>& a) {
    int ones = 0;
    int twos = 0;

    for(int i=0; i < a.size(); i++) {
        ones = (ones ^ a[i]) & (~twos);
        twos = (twos ^ a[i]) & (~ones);
    }

    return ones;
}













int main() {

//Soln-1 Brute Force(Using HashMap)
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Initial vector: ";
    for (auto num: nums){
        cout << num << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << findSingleNumber_1(nums) << endl;



//Soln-2 Better Approach (Bitwise)
    vector<int> ar = {4, 4, 4, 2, 5, 5, 5};
    cout << "Input Array: ";
    for (auto nuM: ar){
        cout << nuM << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << findSingleNumber_2(ar) << endl;



//Soln-3 Optimal Approach
    vector<int> arr = {4, 4, 4, 6, 5, 5, 5};
    cout << "Input Array: ";
    for (auto iT: arr){
        cout << iT << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << findSingleNumber(arr) << endl;






//Soln-4 MOST OPtimal Soln(using Concepts of Buckets(based on bitwise operator))
    vector<int> a = {4, 4, 4, 7, 5, 5, 5};
    cout << "Input Array: ";
    for (auto ar: a){
        cout << ar << " ";
    }
    cout << endl;
    cout << "Element that appears only once: " << singleNumber_ii(a) << endl;






    return 0;
}

