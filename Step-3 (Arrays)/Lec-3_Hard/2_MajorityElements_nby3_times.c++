/*// (Majority Elements N/3 Times_Coding Ninja)-> https://bit.ly/3vIsCTH  

#include<bits/stdc++.h>

vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int n = v.size();
	int cnt1 = 0, cnt2 = 0;
	int el1 = INT_MIN;
	int el2 = INT_MIN;

	for (int i = 0; i < n; i++) {
		if (cnt1 == 0 && el2 != v[i]) {
			cnt1 = 1;
			el1 = v[i];
		}
	    else if(cnt2 == 0 && el1 != v[i]) {
			cnt2 = 1;
			el2 = v[i];
		}
		else if (v[i] == el1) cnt1++;
		else if (v[i] == el2) cnt2++;
		else {
			cnt1--, cnt2;
		}
	}

	vector<int> ls;
	cnt1 = 0, cnt2 =0;
	for (int i=0; i < n; i++) {
		if (v[i] == el1) cnt1++;
		if (v[i] == el2) cnt2++;
	}

	int mini = (int)(n/3) + 1;
	if (cnt1 >= mini) ls.push_back(el1);
	if (cnt2 >= mini) ls.push_back(el2);


	return ls;
}

*/

// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)
   Observation: How many integers can occur more than floor(N/3) times in the given array:

 If we closely observe, in the given array, there can be a maximum of two integers that can occur more than floor(N/3) times. Let’s understand it using the following scenario:
 Assume there are 8 elements in the given array. Now, if there is any majority element, it should occur more than floor(8/3) = 2 times. So, the majority of elements should occur at least 3 times. Now, if we imagine there are 3 majority elements, then the total occurrence of them will be 3X3 = 9 i.e. greater than the size of the array. But this should not happen. That is why there can be a maximum of 2 majority elements.

   Naive Approach (Brute-force): 
  #  We will run a loop that will select the elements of the array one by one.
  #  Now, for each unique element, we will run another loop and count its occurrence in the given array.
  #  If any element occurs more than the floor of (N/3), we will include it in our answer. 
  #  While traversing if we find any element that is already included in our answer, we will just skip it.

   Complexity Analysis:-
  # Time Complexity:-
*/
vector<int> majorityElement1(vector<int> ar1) {
    int n1 = ar1.size(); // size of the array
    vector<int> ls; // list of answers

    for (int i=0; i < n1; i++) {
        // selected element is arr[i]
        // Checking if arr[i] is not already
        // a part of answer
        if (ls.size() == 0 || ls[0] != ar1[i]) {
            int cnt1 = 0;
            for (int j=0; j < n1; j++) {
                // Counting the frequency of arr[i]
                if (ar1[j] == ar1[i]) {
                    cnt1++;
                }
            }

            // Check if frequency is greater than n/3 times
            if (cnt1 > (n1/3))
            ls.push_back(ar1[i]);
        }

        if (ls.size() == 2) break;
    }

    return ls;
}






/*// Soln 2: Better(using Hashing)
 Intuition:- Use a better data structure to reduce the number of look-up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

   Approach:- The steps are as follows:
  #  Use a hashmap and store the elements as <key, value> pairs. (Can also use frequency array based on the size of nums).
  #  Here the key will be the element of the array and the value will be the number of times it occurs. 
  #  Traverse the whole array and update the occurrence of each element. 
  #  After that, check the map if the value for any element is greater than the floor of N/3. 
>       If yes, include it in the list. 
>       Else iterate forward.
  #  Finally, return the list.

   Complexity Analysis:-
  # Time Complexity:- O(N*logN), where N = size of the given array.
>   Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN).
If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
  # Space Complexity: O(N) as we are using a map data structure. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.
*/
vector<int> majorityElement2(vector<int> ar2) {
    int n2 = ar2.size(); // size of the array
    vector<int> Ls; // list of answers

    //declare a map(either ordered OR unordered)
    map<int, int> mpp; // Here, using Ordered map

    //least occurrence of the majority element
    int mini = (n2/3) + 1;

    // storing the elements with its occurnce
    for (int i=0; i < n2; i++) {
        mpp[ar2[i]]++;

        //checking if arr[i] is the majority element
        if (mpp[ar2[i]] == mini) {
            Ls.push_back(ar2[i]);
        }
        if (Ls.size() == 2) break;
    }

    return Ls;
}






/*// Soln 3: Optimal(Extended Boyer Moore’s Voting Algo)
 Intuition: If the array contains the majority of elements, their occurrence must be greater than the floor(N/3). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the counts of elements and the elements themselves for which we are tracking the counts. 

 > After traversing the whole array, we will check the elements stored in the variables. Then we need to check if the stored elements are the majority elements or not by manually checking their counts.

   Approach: 
  #  Initialize 4 variables:
  #  cnt1 & cnt2 –  for tracking the counts of elements el1 & el2 – for storing the majority of elements.
  #  Traverse through the given array.
>       If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along with increasing the cnt1 value by 1.
>       If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along with increasing the cnt2 value by 1.
>       If the current element and el1 are the same increase the cnt1 by 1.
>       If the current element and el2 are the same increase the cnt2 by 1.
>       Other than all the above cases: decrease cnt1 and cnt2 by 1.
  #  The integers present in el1 & el2 should be the result we are expecting. So, using another loop, we will manually check their counts if they are greater than the floor(N/3).

   Complexity Analysis:-
  # Time Complexity: O(N) + O(N), where N = size of the given array.
 >  Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.
  # Space Complexity: O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.
*/
vector<int> majorityElement3(vector<int> arr) {
    int n3 = arr.size(); //Size of the Array

    int cnt1 = 0, cnt2 = 0; // counts
    int ele1 = INT_MIN; // element 1
    int ele2 = INT_MIN; // element 2

    // Apply the Extended Boyer Moore's Voting Algo
    for (int i=0; i < n3; i++) {
        if (cnt1 == 0 && ele2 != arr[i]) {
            cnt1 = 1;
            ele1 =arr[i];
        }
        else if (cnt2 == 0 && ele1 != arr[i]) {
            cnt2 = 1; 
            ele2 = arr[i];
        }
        else if (arr[i] == ele1) cnt1++;
        else if (arr[i] == ele2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }

    // List of answers
    vector<int> ls3;

    // Manually check if the stored elements in
    // el1 and el2 are the majority elements
    cnt1=0, cnt2 =0;
    for (int i=0; i<n3; i++) {
        if (arr[i] == ele1) cnt1++;
        if (arr[i] == ele2) cnt2++;
    }

    int mini = (n3 / 3) + 1;
    if (cnt1 >= mini) ls3.push_back(ele1);
    if (cnt2 >= mini) ls3.push_back(ele2);

    // Uncomment the following line
    // if it is told to sort the answer array:
    // sort(ls3.begin(), ls3.end()); //TC --> O(2*log2) ~ O(1)
    
    return ls3;
}




int main() {

// Soln 1: Brute Force(Naive)
    vector<int> ar1 = {11, 33, 33, 11, 22, 22, 33, 11};
    vector<int> ans1 = majorityElement1(ar1);
    cout << "The majority elements are ";
    for (auto it: ans1)
        cout << it <<" ";
        cout<<endl;



// Soln 2: Better(using Hashing)
    vector<int> ar2 = {1, 1, 1, 3, 2, 2, 2, 1};
    vector<int> ans2 = majorityElement2(ar2);
    cout << "The majority elements are ";
    for (auto it: ans2)
        cout << it <<" ";
    cout << endl;



// Soln 3: Optimal(Extended Boyer Moore’s Voting Algo)
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> sol = majorityElement3(arr);
    cout << "The majority elements are: ";
    for (auto it : sol)
        cout << it << " ";
    cout << endl;



    return 0;
}

