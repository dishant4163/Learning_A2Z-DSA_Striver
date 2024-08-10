/*//(Find the number that appears once, and the other numbers twice_Coding Ninja)-> https://bit.ly/4534Wty
// XOR Soln is getting partially correct
// XOR approach is correct and efficient in O(n), it doesn’t meet the O(log n) requirement. The binary search approach provided will help achieve the required time complexity. If you’re facing TLE with the XOR approach, ensure the implementation details and input handling are correct.
#include<vector>
//
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int xorr = 0;
	for (int i=0; i < arr.size(); i++) {
		xorr = xorr ^ arr[i];
	}
	return xorr;
}


// Soln 2
#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int n = arr.size();	
	for(int i=0; i < n; i++) {
		if(arr[i] != arr[i+1]) {
			return arr[i];
		}
		else {
			i++;
		}
	}
}
*/



#include<bits/stdc++.h>
using namespace std;


//Find the number that appears once, and the other numbers twice

/*// Soln 1. Brute (Naive Approach)
  Intuition:- For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.

  Approach:- The steps are as follows:
  #  First, we will run a loop(say i) to select the elements of the array one by one.
  #  For every element arr[i], we will perform a linear search using another loop and count its occurrence.
  #  If for any element the occurrence is 1, we will return it.

  Complexity Analysis:-
  # Time Complexity: O(N^2), where N = size of the given array.
->    Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).

  # Space Complexity: O(1) as we are not using any extra space.
*/
int getSingleElement1(vector<int> &ar1) {
    // Size of the Array
    int N1 = ar1.size();

    // Run a Loop for Selecting Elements
    for (int i=0; i<N1; i++) {
        int num = ar1[i]; // Select Element
        int cnt1 = 0;

        //Find the Occurrence using Linear Search
        for (int j = 0; j < N1; j++) {
            if (ar1[j] == num) {
                cnt1++;
            }
        }

        // if the occurrence is 1 return Ans
        if (cnt1 == 1) {
            return num;
        }
    }

    // This line will never Execut
    // if the Array contains a single element
    return -1;
}






/*// Soln 2.1: Better(Using Hashing) 
  Intuition:- In the previous approach, we were finding the occurrence of an element using linear search. We can optimize this using hashing technique. We can simply hash the elements along with their occurrences in the form of (key, value) pair. Thus, we can reduce the cost of finding the occurrence and hence the time complexity.

->    Now, hashing can be done in two different ways and they are the following:

  #  Array hashing(not applicable if the array contains negatives or very large numbers)
  #  Hashing using the map data structure

 # Array hashing:- In order to hash using an array, we need to first find the maximum element(say maxElement) to get the range of the hash array. The index of the hash array will represent the elements of the given array and the value stored in that index will be the number of occurrences. Now, the size of the array must be maxElement+1 as we need to hash the maxElement itself.

   Approach:-The steps are as follows:

  #  First, we will find the maximum element(say maxElement) to know the size of the hash array.
  #  Then we will declare a hash array of size maxElement+1.
  #  Now, using another loop we will store the elements of the array along with their frequency in the hash array. (i.e. hash[arr[i]]++)
  #  After that, using another loop we will iterate over the hash array, and try to find the element for which the frequency is 1, and finally, we will return that particular element.

***Note: While searching for the answer finally, we can either use a loop from 0 to n(i.e. Size of the array) or use a loop from 0 to maxElement. So, the time complexity will change accordingly.

Now, using array hashing it is difficult to hash the elements of the array if it contains negative numbers or a very large number. So to avoid these problems, we will be using the map data structure to hash the array elements.

   Complexity Analysis:- 
   # Time Complexity: O(N)+O(N)+O(N), where N = size of the array
Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.

   # Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
*/
int getSingleElement2(vector<int> &ar2) {
    // Size of the Array
    int n = ar2.size();

    //Find the Maximum Element
    int maxi = ar2[0];
    for (int i=0; i<n; i++) {
        maxi = max(maxi, ar2[i]);
    }

    // Declare HashArray of Size maxi+1
    // And Hash the given Array
    vector<int> hash1(maxi + 1, 0);
    for (int i=0; i < n; i++) {
        hash1[ar2[i]]++;
    }

    //Find the Single Element & Return the Answer
    for (int i=0; i < n; i++) {
        if(hash1[ar2[i]] == 1) {
            return ar2[i];
        }
    }

    //This line will never Execute
    // if the array contains a Single Element
    return -1;

//NOTE-:
// Hash Array have Limitation to use, for finding single element in hasharray
//Bcz of Big No (like 10^9) Or Negatives No's
// Therefore, more better soln Is Using Hash Map with Bigger DataType as a longlong

}






/*// Soln 2.2: Better(Hashing using the map DS)
 Intuition:- The intuition will be the same as the array hashing. The only difference here is we will use the map data structure for hashing instead of using another array for hashing.

   Approach:- The steps are as follows:

  #  First, we will declare a map.
  #  Now, using a loop we will store the elements of the array along with their frequency in the map data structure.
  #  Using another loop we will iterate over the map, and try to find the element for which the frequency is 1, and finally, we will return that particular element.

   Complexity Analysis:-
   # Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array. 
->    Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

***Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

   # Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
*/
int getSingleElement3(vector<int> &ar3) {
    //Size of the Array
    int m = ar3.size();

    // Declare the HashMap & hash the given Array
    map<int, int> mpp;
    for(int i=0; i<m; i++) {
        mpp[ar3[i]]++;
    }

    //Find the Single Element & Return the Answer
    for(auto it: mpp) {
        if (it.second == 1) {
            return it.first;
        }
    }

    //This Line will Never Execute
    //if the Array contains a Single Element
    return -1;
}






/*// Soln 3: Optimal(Using XOR)
 Intuition:- Two important properties of XOR are the following:

  # XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
  # XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

->  Here all the numbers except the single number appear twice and so will form a pair. Now, if we perform XOR of all elements of the array, the XOR of each pair will result in 0 according to the XOR property 1. The result will be = 0 ^ (single number) = single number (according to property 2).

->   So, if we perform the XOR of all the numbers of the array elements, we will be left with a single number.

  Approach:-
  #  We will just perform the XOR of all elements of the array using a loop and the final XOR will be the answer.

   Complexity Analysis:-
  # Time Complexity: O(N), where N = size of the array.
Reason: We are iterating the array only once.
  # Space Complexity: O(1) as we are not using any extra space.
*/
int getSingleElement4(vector<int> &ar4) {
    //Size of the Array
    int N2 = ar4.size();

    //XOR all the Elements
    int xorr = 0;
    for (int i=0; i<N2; i++) {
        xorr = xorr ^ ar4[i];
    }
    return xorr;
}





int main() {

// Soln 1: Brute Approach
    vector<int> ar1 = {4, 1, 2, 1, 2};
    int ans1 = getSingleElement1(ar1);
    cout << "Single Element is " << ans1 << endl;



// Soln 2.1: Better Approach(Using Hashing)
    vector<int> ar2 = {4, 4, 0, 1, 2, 1, 2};
    int ans2 = getSingleElement2(ar2);
    cout<<"Single Element is "<<ans2 <<endl;



// Soln 2.2: Better Approach(Using HashMap)
    vector<int> ar3 = {1, 1, 2, 3, 3, 8, 8};
    int ans3 = getSingleElement3(ar3);
    cout<< "Single Element in the Array is " <<ans3<<endl;



// Soln 3: Optimal Approach
    vector<int> ar4 = {1, 1, 2, 2, 3, 3, 4};
    int ans4 = getSingleElement4(ar4);
    cout << "Single Element in the array is "<<ans4<<endl;



    return 0;
}

