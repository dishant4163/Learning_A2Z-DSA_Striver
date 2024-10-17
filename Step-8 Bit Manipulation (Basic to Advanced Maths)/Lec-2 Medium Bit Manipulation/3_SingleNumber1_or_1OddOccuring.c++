// Single Number-I | One Odd Occurring | Find the number that appears odd number of times




/* //One Odd Occurring (Coding Ninjas ->  https://shorturl.at/UiXaZ  )



*/


#include<bits/stdc++.h>
using namespace std;


/*//Soln-1 Brute Force (2 for-loops on arr & count the appearance)

 Approach:- The approach is very simple where we will run two nested loops, and count the occurrence of every element. If at any moment, we are getting the count as odd, we will just print that element.

  For eg , - arr = {1 , 2 , 3 , 2 , 1}

 # The first iteration -  1 is occurring 2 times
 # The second iteration - 2 is occurring 2 times
 # The third iteration - 3 occurs 1 time (odd number of times).

  This means the answer is ‘3’.


   TC:- O(N^2)
   SC:- O(1)
*/
int find1OddOccurring_1(int ar1[], int n) {
    for(int i=0; i < n; i++) {
        int count=0;
        for(int j=0; j<n; j++) {
            if(ar1[i] == ar1[j])
            count++;
        }
        if(count % 2 != 0){
            return ar1[i];
        }
    }
    return -1;
}






/*//Soln-2 Better Approach (Using hashMap)

 Approach:- It is also simple where we will use hash data structure So here we will be using extra auxiliary space of O(n). Here we will count occurrences of every element. 

  (Note that - hash stores distinct elements and it stores key, value pair )

 For eg , - arr = {1 , 2 , 3 , 2 , 1}

Creating a hash map 

Element       occurrences
1        |        2
2        |        2
3        |        1


  Since occurrences of ‘3’ are 1 . So it is the odd occurring element.


  TC:- O(N), where n is the size of the array
  SC:- O(Map size)
*/
int find1OddOccurring_2(int ar2[], int m) {
    unordered_map<int, int> mp;//map declare
    //iterate in array to add elements in map
    for(int i=0; i < m; i++) {
        mp[ar2[i]]++; //adding arr ele in map with their cnt appears
    }
    //iterate in map
    for(auto it: mp){ 
        if(it.second%2 != 0) //to check for odd occurrences 
            return it.first;
    }

    return -1; //if odd occuring num not found
}





//Soln-3 Using Bit Manipulation
int findOddOccuring(int arr[], int size) {
    int xorAns = 0;
    for(int i=0; i < size; i++) {
        xorAns = xorAns ^ arr[i];
    }
    return xorAns;
}







int main() {

//Soln-1 Brute Force
    int n = 5;
    int ar1[] = {4, 2, 1, 2, 1};
    cout << find1OddOccurring_1(ar1, n)<<" is occurring an odd number of times"<< endl;



//Soln-2 Better Approach
    int m = 5;
    int ar2[] = {1, 2, 3, 2, 1};
    cout<<find1OddOccurring_2(ar2, m)<<" is occurring an odd number of times"<<endl;



//Soln-3 Optimal Approach
    int size = 5;
    int arr[] = {1, 2, 9, 2, 1};
    cout<<findOddOccuring(arr, size)<<" is occurring an odd number of times"<<endl;




    return 0;
}


