/*//(Find the Majority Element that occurs more than N/2 times_Coding Ninja)-> https://bit.ly/3GmPYTH

int majorityElement(vector<int> v) {
	int n = v.size(); //size of the given array
	int cnt = 0; // count
	int el; // Element

    //Applying the algorithm(moore's voting algo)
	for (int i=0; i<n; i++) {
		if (cnt == 0) {
			cnt = 1;
			el = v[i];
		}
		else if(v[i] == el) {
			cnt++;
		}
		else {
			cnt--;
		}
	}

    //checking if the stored element
    // is the majority element
	int cnt2 = 0;
	for(int i=0; i<n; i++) {
		if (v[i] == el) {
			cnt2++;
		}
		if (cnt2 > (n/2) ) {
			return el; // return Element
		}
	}
	return -1;
}

*/

 // Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.


#include<bits/stdc++.h>
using namespace std;


/*//Soln 1: Brute Force(Naive Approach)
   Approach:- The steps are as follows:

  #  We will run a loop that will select the elements of the array one by one.
  #  Now, for each element, we will run another loop and count its occurrence in the given array.
  #  If any element occurs more than the floor of (N/2), we will simply return it.

   Complexity Analysis:-
  # Time Complexity: O(N^2), where N = size of the given array. 
->   Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). 

  # Space Complexity: O(1) as we use no extra space. 
*/
int majorityElement1(vector<int> ar1) {
	int n1 = ar1.size();//Size of the Array
	for(int i=0; i<n1; i++){//iterate & scan entire array
	    //initalize count as 0
		int cnt1 = 0;
		//iterate with another loop, check & scan
		//is there Element more than (N/2) times or not
		for (int j=0; j<n1; j++){
			if (ar1[j] == ar1[i]) {
				cnt1++;
			}
			if (cnt1 > (n1 / 2)) {
				return ar1[i];
			}
		}
	}
	return -1; // if element does not exits
}






/*// Soln 2: Better(Using Hashing)
Here, I have used ORDERED_MAP
   Intuition:- Use a better data structure to reduce the number of look-up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again and again - so we have to reduce that also.

   Approach:-
  #  Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
  #  Here the key will be the element of the array and the value will be the number of times it occurs. 
  #  Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
->     If yes, return the key 
->     Else iterate forward.

   Complexity Analysis:- 
  #  Time Complexity: O(N*logN) + O(N), where N = size of the given array.
->   Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

  #  Space Complexity: O(N) as we are using a map data structure.
*/
int majorityElement2(vector<int> ar2) {
    int n2 = ar2.size(); //Size of the Array
    //Declare the OR_Map
    map<int, int> mp;
    //storing the elements with its occurnce
    for (int i=0; i < n2; i++) {
        mp[ar2[i]]++;
    }
    //Searching for the majority element
    for(auto it: mp) {
        if (it.second > (n2 / 2)) {
            return it.first;
        }
    }
    return -1;//If element does not exits
}






/*// Soln 3: Optimal(Moore’s Voting Algo)
   Intuition:
#   If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

#   After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.


   Approach:- 
  # Initialize 2 variables:
->   Count –  for tracking the count of element
->   Element – for which element we are counting
  # Traverse through the given array.
->       If Count is 0 then store the current element of the array as Element.
->       If the current element and Element are the same increase the Count by 1.
->       If they are different decrease the Count by 1.
  # The integer present in Element should be the result we are expecting 

   Complexity Analysis:-
  # Time Complexity: O(N) + O(N), where N = size of the given array.
->   Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.

*** Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).

  # Space Complexity: O(1) as we are not using any extra space.
*/
int majorityElement3(vector<int> arr3) {
    int N = arr3.size(); //Size of the Array
    int cnt3 = 0; //Count
    int ele; //Element

    // Apply the Moore's Voting Algo
    for (int i=0; i<N; i++) {
        if (cnt3 == 0) {
            cnt3 = 1;
            ele = arr3[i];
        }
        else if(ele == arr3[i]) {
            cnt3++;
        }
        else {
            cnt3--;
        }
    }

    //checking if the stored element
    // is the majority element
    int cnt4 = 0;
    for(int i=0; i<N; i++) {
        if (arr3[i] == ele) {
            cnt4++;
        }
        if (cnt4 > (N/2)) {
            return ele;
        }
    }
    return -1;
}




int main() {

// Soln 1: Brute Force
    vector<int> ar1 = {2, 2, 1, 1, 1, 2, 2};
    int ans1 = majorityElement1(ar1);
    cout<<"THe majority element is: "<<ans1<<endl;



// Soln 2: Better(using Hashing)
    vector<int> ar2 = {2, 2, 1, 1, 1, 2, 1};
    int ans2 = majorityElement2(ar2);
    cout<<"The majority element is: "<<ans2<<endl;



// Soln 3: Optimal(Moore's Voting Algo)
    vector<int> arr3 = {2, 2, 1, 1, 1, 2, 2};
    int soln = majorityElement3(arr3);
    cout << "The majority element is: " << soln <<endl;



    return 0;
}

