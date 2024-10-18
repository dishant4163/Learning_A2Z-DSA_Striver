// Single Number-iii | Bit Manipulation


/* Single Number-iii (Coding Ninjas =>  https://shorturl.at/1zv6Z  )

#include <bits/stdc++.h> 
void twoNonRepeatingElements(int arr[], int n) {
    // Write your code here.

    int xorr = 0;

    for(int i=0; i<n; i++) {
        xorr = xorr ^ arr[i];
    }

    int rightmostBit = (xorr & -xorr); 

    int bucket1 = 0, bucket2 = 0;

    for(int i=0; i < n; i++) {
        if(arr[i] & rightmostBit) {
            bucket1 = bucket1 ^ arr[i];
        } else {
            bucket2 = bucket2 ^ arr[i];
        }
    }

    if (bucket1 < bucket2) {
        cout << bucket1 << " " << bucket2 << endl;
    } else {
        cout << bucket2 << " " << bucket1 << endl;
    }

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
void twoNonRepeatingElements_1(int ar[], int m) {
    unordered_map<int, int> mp;
    for(int i=0; i < m; i++) {
        mp[ar[i]]++;
    }

    vector<int> ans;
    for(auto it: mp) {
        if(it.second == 1) ans.push_back(it.first);
    }

    //sort(ans.begin(), ans.end()); //if asked to sort

//if not to exceeds more TC then avoid extra for loop
    // for(int i=0; i < ans.size(); i++) {
    //     cout << ans[i] <<" ";
    // }

    cout<<ans[0] << " "<<ans[1] << endl;//use this for not to exceeds more TC 
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
 Time Complexity: O(N) where N is the number of elements in the input array. This is because we iterate through the array twice: once to compute the XOR of all elements and once to place each number in its corresponding bucket.

 Space Complexity : O(1) as we are only using a constant amount of extra space regardless of the size of the input array. The algorithm uses only a few extra variables to store intermediate results and these variables do not depend on the size of the input array.
*/
/*Steps:
    XOR All Elements: First, compute the XOR of all elements in the array. The result will be the XOR of the two unique elements (let's call them x and y), since all paired elements will cancel out.

    Find a Set Bit: Find any set bit in the resulting XOR. This bit will be different between x and y. We can use this bit to divide the original array into two groups: one group with the set bit and another without.

    Separate and XOR Again: XOR the elements in each group separately. This will give us the two unique elements.

    Sort and Output: Finally, sort the two unique elements before outputting them.


   Explanation of the Code:
    Line 7-10: Compute the XOR of all elements in the array.
    Line 13: Determine the rightmost set bit in the XOR result.
    Line 16-23: Use this set bit to divide the elements into two groups and compute the XOR for each group, thus isolating the two unique elements.
    Line 26-29: Finally, sort and print the two unique numbers.

*/
void twoNonRepeatingElements(int arr[], int n) {
    int xorr = 0;
    
    // Step 1: XOR all elements
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    
    // Step 2: Find a set bit (rightmost set bit)
    int SetBit = xorr & -xorr; // Get the rightmost set bit
    
    int bucket1 = 0, bucket2 = 0;
    
    // Step 3: Divide elements into two groups and XOR separately
    for (int i = 0; i < n; i++) {
        if (arr[i] & SetBit) {
            bucket1 ^= arr[i]; // Group with the set bit
        } else {
            bucket2 ^= arr[i]; // Group without the set bit
        }
    }
    
    // Step 4: Output the results in sorted order
    if (bucket1 < bucket2) {
        cout << bucket1 << " " << bucket2 << endl;
    } else {
        cout << bucket2 << " " << bucket1 << endl;
    }
}





int main() {

//Soln-1 Brute Force Using HashMa
    int m;
    cout << "Enter the size of array: ";
    cin >> m; // Read the size of the array

    int ar[m]; // Declare the array
    for (int i = 0; i < m; i++) {
        cin >> ar[i]; // Read the array elements
    }

    // Call the function to find the two non-repeating elements
    twoNonRepeatingElements_1(ar, m);




//Soln-2 Optimal Soln
    int n;
    cout << "Enter the size of array: ";
    cin >> n; // Read the size of the array

    int arr[n]; // Declare the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read the array elements
    }

    // Call the function to find the two non-repeating elements
    twoNonRepeatingElements(arr, n);





    return 0;
}

