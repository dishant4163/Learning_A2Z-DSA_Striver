/*//(Longest Consecutive Sequence in an Array_Coding Ninja)-> https://bit.ly/3Ob0Zgn

int longestSuccessiveElemnets(vector<int> &a) {
    int n = a.size();//declare size of array
    // If size is Empty then there is no sequence
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;//declare Unordered Set
    //put all the array elements into set
    for(int i=0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence
    for (auto it: st) {
        //if 'it' is a starting number
        if(st.find(it - 1) == st.end()) {
            //find consecutive numbers
            int cnt = 1;
            int x = it;
            while (st.find(x+1) != st.end()) {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

*/



/*// Problem Statement:
   You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force
   Intitution:- A straightforward but basic solution is to examine consecutive sequences for each element in the given array. For every element x, we will try to find the consecutive elements, x+1, x+2, x+3, and so on using the linear search algorithm. Thus, we will check the length of the longest consecutive subsequence we can build for every element x. Among all the lengths we will consider the maximum one.

   Algorithm:
  #  To begin, we will utilize a loop to iterate through each element one by one.
  #  Next, for every element x, we will try to find the consecutive elements like x+1, x+2, x+3, and so on using the linear search algorithm in the given array.
        Within a loop, our objective is to locate the next consecutive element x+1. 
            If this element is found, we increment x by 1 and continue the search for x+2. 
            Furthermore, we increment the length of the current sequence (cnt) by 1. 

->  This process repeats until step 2.2 occurs.

  #  If a specific consecutive element, for example, x+i, is not found, we will halt the search for subsequent consecutive elements such as x+i+1, x+i+2, and so on. Instead, we will take into account the length of the current sequence (cnt).
  #  Among all the lengths we get for all the given array elements, the maximum one will be the answer.

   Complexity Analysis:-
  # Time Complexity: O(N2), N = size of the given array.
->  Reason: We are using nested loops each running for approximately N times.
  # Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
bool linearSearch(vector<int> &ar1, int num1) {
    for (int i=0; i < ar1.size(); i++) {
        if (ar1[i] == num1)
            return true;
    }
    return false;
}
int longestConsecutiveElement1(vector<int> &ar1) {
    int longest1 = 1;
    //pick a element & search for its
    //consecutive numbers
    for (int i=0; i < ar1.size(); i++) {
        int x = ar1[i];
        int cnt1 = 1;
        //search for consecutive numbers using linear search
        while(linearSearch(ar1, x+1) == true) {
            x += 1;
            cnt1 += 1;
        }

        longest1 = max(longest1, cnt1);
    }
    return longest1;
}






/*// Soln 2: Better Approach(using Sorting)
-> We can simply sort the array and run a for loop to find the longest consecutive sequence.

   Algorithm:

  #  We will consider 3 variables, 
>        ‘lastSmaller’ →(to store the last included element of the current sequence), 
>        ‘cnt’ → (to store the length of the current sequence), 
>        ‘longest’ → (to store the maximum length).
  #  Initialize ‘lastSmaller’ with ‘INT_MIN’, ‘cnt’ with 0, and ‘longest’ with 1(as the minimum length of the sequence is 1).

->  The steps are as follows:

  #  First, we will sort the entire array.
  #  To begin, we will utilize a loop(say i) to iterate through each element one by one.
  #  For every element, we will check if this can be a part of the current sequence like the following:
>        If arr[i]-1 == lastSmaller: The last element in our sequence is labeled as 'lastSmaller' and the current element 'arr[i]' is exactly 'lastSmaller'+1. It indicates that 'arr[i]' is the next consecutive element. To incorporate it into the sequence, we update 'lastSmaller' with the value of 'arr[i]' and increment the length of the current sequence, denoted as 'cnt', by 1.
>        If arr[i] == lastSmaller: If the current element, arr[i], matches the last element of the sequence (represented by 'lastSmaller'), we can skip it since we have already included it before.
>        Otherwise, if lastSmaller != arr[i]: On satisfying this condition, we can conclude that the current element, arr[i] > lastSmaller+1. It indicates that arr[i] cannot be a part of the current sequence. So, we will start a new sequence from arr[i] by updating ‘lastSmaller’ with the value of arr[i]. And we will set the length of the current sequence(cnt) to 1.
  #  Every time, inside the loop, we will compare ‘cnt’ and ‘longest’ and update ‘longest’ with the maximum value. longest = max(longest, cnt)
  #  Finally, once the iteration is complete, we will have the answer stored in the variable ‘longest’.

   Complexity Analysis:-
  # Time Complexity: O(NlogN) + O(N), N = size of the given array.
->   Reason: O(NlogN) for sorting the array. To find the longest sequence, we are using a loop that results in O(N).

   # Space Complexity: O(1), as we are not using any extra space to solve this problem.
*/
int longestConsecutiveElements2(vector<int> &ar2) {
    int n2 = ar2.size();
    if (n2 == 0)
    return 0;

    //Sort the Array
    sort(ar2.begin(), ar2.end());
    int lastSmaller = INT_MIN;
    int cnt2 = 0;
    int longest2 = 1;

    //Find Longest Sequence
    for (int i=0; i < n2; i++) {
        if (ar2[i]-1 == lastSmaller) {
            //a[i] is the next element of the
            //current sequence.
            cnt2 += 1;
            lastSmaller = ar2[i];
        }
        else if (ar2[i] != lastSmaller) {
            cnt2 = 1;
            lastSmaller = ar2[i];
        }
        longest2 = max(longest2, cnt2);
    }
    return longest2;
}






/*// Soln 3: Optimal(using Set Data Structure)
->  How to identify if a number can be the starting number for a sequence:
  #  First, we will put all the array elements into the et data structure.
  #  If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. :
>        If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
>        If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.

 How to search for consecutive elements for a number, x:
  #  Instead of using linear search, we will use the set data structure itself to search for the elements x+1, x+2, x+3, and so on.

->  Thus, using this method we can narrow down the search and optimize the approach.

   Algorithm:

  #  We will declare 2 variables, 

  #  ‘cnt’ → (to store the length of the current sequence), 
  #  ‘longest’ → (to store the maximum length).

  #  First, we will put all the array elements into the set data structure.
  #  For every element, x, that can be a starting number(i.e. x-1 does not exist in the set) we will do the following:
>        We will set the length of the current sequence(cnt) to 1.
>        Then, again using the set, we will search for the consecutive elements such as x+1, x+2, and so on, and find the maximum possible length of the current sequence. This length will be stored in the variable ‘cnt’.
>        After that, we will compare ‘cnt’ and ‘longest’ and update the variable ‘longest’ with the maximum value (i.e. longest = max(longest, cnt)).
  #  Finally, we will have the answer i.e. ‘longest’.

   Complexity Analysis:-
  # Time Complexity: O(N) + O(2*N) ~ O(3*N), where N = size of the array.
->   Reason: O(N) for putting all the elements into the set data structure. After that for every starting element, we are finding the consecutive elements. Though we are using nested loops, the set will be traversed at most twice in the worst case. So, the time complexity is O(2*N) instead of O(N2).

  # Space Complexity: O(N), as we are using the set data structure to solve this problem.

*** Note: The time complexity is computed under the assumption that we are using unordered_set and it is taking O(1) for the set operations. 

    If we consider the worst case the set operations will take O(N) in that case and the total time complexity will be approximately O(N2). 
    And if we use the set instead of unordered_set, the time complexity for the set operations will be O(logN) and the total time complexity will be O(NlogN).
*/
int longestConsecutiveElement3(vector<int> &ar3) {
    int n3 = ar3.size();
    if (n3 == 0)
    return 0;

    int longest3 = 1;
    unordered_set<int> st;
    //put all the array element into set
    for (int i=0; i < n3; i++) {
        st.insert(ar3[i]);
    }

    //Find the Longest Sequence
    for (auto it: st) {
        //if 'it' is a starting number
        if (st.find(it-1) == st.end()) {
            //find consecutive numbers
            int cnt3 = 1;
            int x3 =it;
            while (st.find(x3 + 1) != st.end()) {
                x3 = x3 + 1;
                cnt3 = cnt3 + 1;
            }
            longest3 = max(longest3, cnt3);
        }
    }
    return longest3;

}




int main() {

// Soln 1: Brute Force
    vector<int> ar1 = {100, 200, 1, 2, 3, 4};
    int ans1 = longestConsecutiveElement1(ar1);
    cout<<"The longest consecutive sequence is "<<ans1<<"\n";



// Soln 2: Better(using Sorting)
    vector<int> ar2 = {100, 200, 1, 2, 3, 4};
    int ans2 = longestConsecutiveElements2(ar2);
    cout << "The longest consecutive sequence is " << ans2 << "\n";



// Soln 3: Optimal(using Set DS)
    vector<int> ar3 = {100, 200, 1, 2, 3, 4, 5};
    int ans3 = longestConsecutiveElement3(ar3);
    cout<<"The longest Consecutive sequence is "<<ans3<<"\n";




    return 0;
}

