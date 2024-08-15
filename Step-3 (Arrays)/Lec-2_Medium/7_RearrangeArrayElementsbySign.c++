//Rearrange the Array Elements in Alternate Sign +ve & -ve

/*//Variety-1 on LEETCODE -> https://shorturl.at/b8Uvm 
vector<int> rearrangeArray(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);//declare ans of size n
    int posIndex=0, negIndex=1;
    //go across entire array
    for(int i=0; i<n; i++) {
        if (nums[i] < 0) { // if array element is -ve
            ans[negIndex] = nums[i];
            negIndex += 2; //at odd indices
        }
        else {
            ans[posIndex] = nums[i];//if arrayelement is +v
            posIndex += 2;// at even indices
        }
    }
    return ans;
}
*/

/*//Variety-2 on CODING NINJA -> https://bit.ly/3yRrCOT

vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    vector<int> pos, neg;//declare 2 for storing + & - element of array
    int n = a.size();

    for(int i=0; i<n; i++) {
        if (a[i] > 0) {
            pos.push_back(a[i]);
        }
        else {
            neg.push_back(a[i]);
        }
    }

    // If +ve is Greater than -ve
    if(pos.size() > neg.size()) {
    //in for loop, till -VE.size bcz they are limited(lefts once element)    
        for(int i=0; i<neg.size(); i++){ 
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            a[index] = pos[i];
            index++;
        }
    }
    else { // If -ve is Greater than +ve
    //in for loop, till +VE.size bcz they are limited(lefts once element)
        for (int i=0; i<pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            a[index] = neg[i];
            index++;
        }
    }

    return a;
} 

*/

/* Problem Statement:

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

*/


#include<bits/stdc++.h>
using namespace std;


//Variety -: 1

/*// Soln 1: Brute Force(Variant-1)
   Approach:
  #  In this simple approach, since the number of positive and negative elements are the same, we put positives into an array called “pos” and negatives into an array called “neg”.
  #  After segregating each of the positive and negative elements, we start putting them alternatively back into array A.
  #  Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
  #  This approach uses O(N+N/2) of running time due to multiple traversals which we’ll try to optimize in the optimized approach given below.

   Complexity Analysis:-
  # Time Complexity:- Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
  # Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/
vector<int> rearrangebySign1(vector<int> Ar1, int n1) {
// Define 2vectors, 1 for storing +ve array
// other for -ve elements of the array.
vector<int> pos1;
vector<int> neg1;

//Segregate the array into +ve's & -ve's
    for (int i=0; i < n1; i++) {
        if (Ar1[i] > 0) {
            pos1.push_back(Ar1[i]);
        }
        else {
            neg1.push_back(Ar1[i]);
        }
    }

    // +ve's on Even Indices, -ve's on Odd Indices
    for (int i=0; i < n1/2; i++) {
        Ar1[2*i] = pos1[i]; // Even Indices
        Ar1[2*i + 1] = neg1[i]; // Odd Indices
    }

    return Ar1;
}




/*// Soln 2: Optimal(Variant-2)
   Approach:
  #  In this optimal approach, we will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.
  #  We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).
  #  Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.
  #  When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.

   Complexity Analysis:-
  # Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.
  # Space Complexity:  O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.
*/
vector<int> rearrangebySign2(vector<int> Ar2) {

    int n2 = Ar2.size();
    vector<int> ans2(n2, 0);
    int posIndex=0, negIndex=1;//+ve at even, -ve at odd
    for (int i=0; i<n2; i++) {
        if(Ar2[i] < 0) { // if array element is -ve
            ans2[negIndex] = Ar2[i];//put -ve array element
            negIndex += 2;//at the odd indices
        }
        else { // if array element is +ve
            ans2[posIndex] = Ar2[i];//put +ve array element
            posIndex += 2;// at the even indices
        }
    }
    return ans2;
}







//Variety -: 2

/* Problem Statement (variety-2) :

There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.
*/

/*// Soln 1: BRUTE
// Bcz optimal requires equal no's of +ve & -ve's element in Array i.e, BRUTE is best soln for this variety of Problem
   Intuition:- In this variety, the number of positive and negative numbers shall not necessarily be equal to each other in the given array. So, there can be two cases possible: either the positive elements exceed the negatives or the negatives exceed the positives. So, instead of using the optimal solution discussed for the variety-1 above, we’ll fall back to the brute force solution where we create separate arrays for storing positives and negatives and then put them back into the array alternatively. The remaining negative or positive elements are added to the array at last.

   Approach:-
  #  In this problem, first, we create a neg array and a pos array for storing all the negative and positive elements of array A separately.
  #  Now, similar to the Brute force approach for variety-1, we start putting elements of pos and neg array alternatively back into array A.
  #  Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.
  #  After all the elements are added to the index where positives were equal to the negatives, we now put all the remaining elements ( whether positive or negative) at the last of the array by running a single loop from pos.size() to neg.size() {if positives < negatives} or neg.size() to pos.size() {if negatives < positives}.

   Complexity Analysis:-
  #Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array to segregate into neg and pos array and O(N) for adding the elements alternatively to the main array}.

    -> Explanation: The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). There can be two cases: when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N), and when equal no. of positive and negative elements are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0). So, from these two cases, we can say the worst-case time complexity is O(N) for the second part, and by adding the first part we get the total complexity of O(2*N).

  # Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/
vector<int> RearrangebySign(vector<int>Ar, int N){
// Define 2 vectors, one for storing positive 
// and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;

// Segregate the array into +ve's & -ve's
    for(int i=0; i<N; i++){

        if(Ar[i]>0) pos.push_back(Ar[i]);
        else neg.push_back(Ar[i]);
    }

    // If positives are lesser than the negatives.
    if(pos.size() < neg.size()){

    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0; i<pos.size(); i++){
        Ar[2*i] = pos[i];
        Ar[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        Ar[index] = neg[i];
        index++;
    }
    }

    // If negatives are lesser than the positives.
    else{

    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0; i<neg.size(); i++){

    Ar[2*i] = pos[i];
    Ar[2*i+1] = neg[i];
    }

    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size(); i<pos.size(); i++){
        
        Ar[index] = pos[i];
        index++;
    }
    }

    return Ar;
    
}






int main(){
//Variety-1

//Soln 1: Brute Force
// Array Intialisation
    int n1 = 6;
    vector<int> Ar1 {3, 1, -2, -5, 2, -4};

    vector<int> ans1 = rearrangebySign1(Ar1, n1);

    cout << "Solution of Variety-1 by using Brute Force method: ";
    for (int i=0; i < ans1.size(); i++) {
        cout << ans1[i]<<" ";
    }



// Soln 2: Optimal (Variety-1)
// Array Intialisation
    vector<int> Ar2 = {3, 1, -2, -5, 2, -4};

    vector<int> ans2 = rearrangebySign2(Ar2);

    cout << "Solution of Variety-1 by using Optimal method: ";
    for (int i=0; i < ans2.size(); i++) {
        cout << ans2[i] << " ";
    }





//Variety-2
//Soln 1: Brute Force (VARIETY-1)
    int N = 6;
    vector<int> A {1,2,-4,-5,3,4};

    vector<int> soln = RearrangebySign(A, N);

    cout << "Solution of Variety-2 by using Brute Force: ";
    for (int i = 0; i < soln.size(); i++) {
    cout << soln[i]<<" ";
    }





    return 0;
}

