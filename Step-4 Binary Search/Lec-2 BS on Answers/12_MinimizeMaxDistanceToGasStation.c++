/*(Minimise Max Distance between Gas Stations_Coding Ninja)-> https://bit.ly/452QhyM    

int numOfgasStationReq(long double dist, vector<int>&ar) {
	int n = ar.size();
	int cnt = 0;
	for (int i=1; i<n; i++) {
		int numInBetween = ((ar[i] - ar[i-1]) / dist);
		if((ar[i] - ar[i-1]) == (dist * numInBetween)) {
			numInBetween--;
		}
		cnt += numInBetween;
	}
	return cnt;
}


long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	long double low = 0;
	long double high = 0;

	for (int i=0; i<n-1; i++) {
		high = max(high, (long double)(arr[i+1] - arr[i]));
	}

	long double diff = 1e-6;
	while((high-low) > diff) {
		long double mid = low + (high - low) / 2.0;
		int cntgasSt = numOfgasStationReq(mid , arr);
		if (cntgasSt > k) {
			low = mid;
		}
		else {
			high = mid;
		}
	}
	return high;
}




*/


/* Problem Statement: 
 You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’. You have to place 'k' new gas stations on the X-axis. You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions. Let 'dist' be the maximum value of the distance between adjacent gas stations after adding k new gas stations.
 Find the minimum value of ‘dist’.

   ote: Answers within 10^-6 of the actual answer will be accepted. For example, if the actual answer is 0.65421678124, it is okay to return 0.654216. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place.
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force   
 Intuition:-
 We are given n gas stations. Between them, there are n-1 sections where we may insert the new stations to reduce the distance. So, we will create an array of size n-1 and each of its indexes will represent the respective sections between the given gas stations. 
 In each iteration, we will identify the index 'i' where the distance (arr[i+1] - arr[i]) is the maximum. Then, we will insert new stations into that section to reduce that maximum distance. The number of stations inserted in each section will be tracked using the previously declared array of size n-1.
 Finally, after placing all the stations we will find the maximum distance between two consecutive stations. To calculate the distance using the previously discussed formula, we will just do as follows for each section:
distance = section_length / (number_of_stations_ inserted+1)
 Among all the values of ‘distance’, the maximum one will be our answer.

   Algorithm:-
  #  First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations.
  #  Next, using a loop we will pick k gas stations one at a time.
  #  Then, using another loop, we will find the index 'i' where the distance (arr[i+1] - arr[i]) is the maximum and insert the current gas station between arr[i] and arr[i+1] (i.e. howMany[i]++).
  #  Finally, after placing all the new stations, we will find the distance between two consecutive gas stations. For a particular section,
    distance = section_length / (number_of_stations_ inserted+1)
        = (arr[i+1]-arr[i]) / (howMany[i]+1)
  #  Among all the distances, the maximum one will be the answer.


   Complexity Analysis:-
  # Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
    Reason: O(k*n) to insert k gas stations between the existing stations with maximum distance. Another O(n) for finding the answer i.e. the maximum distance.
  # Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations.
*/
double minimiseMaxDistance1(vector<int> &a1, int k1){
	// Write your code here. 
  int n1 = a1.size();
//size (n-1) (1 less than the no). Initialize all elements to 0:
  vector<int> howMany1(n1 - 1, 0); // how many to place in the array:

//Pick and place k gas stations:
  for (int gasSt = 1; gasSt <= k1; gasSt++) {
  //Find the maximum section
  //and insert the gas station:
    long double maxSection1 = -1;
    long double maxInd1 = -1;
    for (int i=0; i < n1 - 1; i++) {
      long double diff1 = a1[i+1] - a1[i];
      long double sectionLength1 = diff1 / (long double)(howMany1[i] + 1);

      if (sectionLength1 > maxSection1) {
        maxSection1 = sectionLength1;
        maxInd1 = i;
      }
    }
  //insert the current gas station:
    howMany1[maxInd1]++;
  }

//Find the maximum distance i.e. the answer:
  long double maxAns1 = -1;
  for (int i=0; i < n1 - 1; i++) {
    long double diff1 = a1[i+1] - a1[i];
    long double sectionLength1 = diff1 / (long double)(howMany1[i] + 1);
    maxAns1 = max(maxAns1, sectionLength1);
  }
  return maxAns1;
}






/*// Soln 2: Better(using Heap i.e., PQ)   
 Intuition- In the previous approach, for every gas station, we were finding the index i for which the distance between arr[i+1] and arr[i] is maximum. After that, our job was to place the gas station. Instead of using a loop to find the maximum distance, we can simply use the heap data structure i.e. the priority queue.
 Priority Queue: Priority queue internally uses the heap data structure. In the max heap implementation, the first element is always the greatest of the elements it contains and the rest elements are in decreasing order.

   Note: Please refer to the article: priority_queue in C++ STL to know more about the data structure.

 Thus using a priority queue, we can optimize the search for the maximum distance. We will use the max heap implementation and the elements will be in the form of pairs i.e. <distance, index> as we want the indices sorted based on the distance. As we are using max heap the maximum distance will always be the first element.

   Algorithm:-
  #  First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations and a priority queue that uses max heap.
  #  We will insert the first n-1 indices with the respective distance value, arrr[i+1]-arr[i] for every index.
  #  Next, using a loop we will pick k gas stations one at a time.
  #  Then we will pick the first element of the priority queue as this is the element with the maximum distance. Let’s call the index ‘secInd’.
  #  Now we will place the current gas station at ‘secInd’(howMany[secInd]++) and calculate the new section length,
    new_section_length = initial_section_length / (number_of_stations_ inserted+1)
                = (arr[secInd+1] - arr[secInd]) / (howMany[i] + 1)
  #  After that, we will again insert the pair <new_section_length, secInd> into the priority queue for further consideration.
  #  After performing all the steps for k gas stations, the distance at the top of the priority queue will be the answer as we want the maximum distance.


   Complexity Analysis:-
  # Time Complexity: O(nlogn + klogn),  n = size of the given array, k = no. of gas stations to be placed.
    Reason: Insert operation of priority queue takes logn time complexity. O(nlogn) for inserting all the indices with distance values and O(klogn) for placing the gas stations.
  # Space Complexity: O(n-1)+O(n-1)
    Reason: The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue.
*/
long double minimiseMaxDistance2(vector<int>&a2, int k2) {
  int n2 = a2.size();
  //size (n-1) (1 less than the no). Initialize all elements to 0:
  vector<int> howMany2(n2 - 1, 0);
  //declare Priority Queue:
  priority_queue<pair<long double, int>> pq;
  for (int i=0; i < n2-1; i++) {
  //insert first n-1 elements into pq with resp. dist values:
    pq.push({a2[i + 1] - a2[i], i});
  }

  //pick and placed gas stations:
  for (int gasSt = 1; gasSt <= k2; gasSt++) {
    // find max. section & insert gas stations
    auto topp = pq.top(); //get top element in pq
    pq.pop(); //Remove max. distance from the pq.
    //declare sectionIndex
    int sectionInd = topp.second;

    //insert the current gas station which is at secInd:
    howMany2[sectionInd]++;

    // initial difference
    long double inidiff1 = a2[sectionInd +1] - a2[sectionInd];
    // new section Length
    long double newSecLen = inidiff1 / (long double)(howMany2[sectionInd] + 1);
    pq.push({newSecLen, sectionInd});
  }

// return the top element which now min(max dist) as answer
  return pq.top().first;  
}





/*// Soln 3: Optimal(BS)  
    Changes in the binary search algorithm to apply it to the decimal answer space:
 The traditional binary search algorithm used for integer answer space won't be effective in this case. As our answer space consists of decimal numbers, we need to adjust some conditions to tailor the algorithm to this specific context. The changes are the following:

  #  while(low <= high): The condition 'while(low <= high)' inside the 'while' loop won't work for decimal answers, and using it might lead to a TLE error. To avoid this, we can modify the condition to 'while(high - low > 10^(-6))'. This means we will only check numbers up to the 6th decimal place. Any differences beyond this decimal precision won't be considered, as the question explicitly accepts answers within 10^-6 of the actual answer.
  #  low = mid+1: We have used this operation to eliminate the left half. But if we apply the same here, we might ignore several decimal numbers and possibly our actual answer. So, we will use this: low = mid.
  #  high = mid-1: Similarly, We have used this operation to eliminate the right half. But if we apply the same here, we might ignore several decimal numbers and possibly the actual answer. So, we will use this: high = mid.

    We are applying binary search on the answer i.e. the possible values of distances. So, we have to figure out a way to check the number of gas stations we can place for a particular value of distance.


   How to check the number of gas stations we can place with a particular distance ‘dist’: 
 In order to find out the number of gas stations we will use the following function:
    numberOfGasStationsRequired(dist, arr[]): 
  #  We will use a loop(say i) that will run from 1 to n.
  #  For each section between i and i-1, we will do the following:
    No. of stations = (arr[i]-arr[i-1]) / dist
  #  Let's keep in mind a crucial edge case: if the section_length (arr[i] - arr[i-1]) is completely divisible by 'dist', the actual number of stations required will be one less than what we calculate.
    if (arr[i]-arr[i-1] == (No. of stations*dist): No. of stations -= 1.
  #  Now, we will add the no. of stations regarding all the sections and the total will be the answer.


   Algorithm:-
  #  First, we will find the maximum distance between two consecutive gas stations i.e. max(dist).
  #  Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 0 and the high will point to max(dist).
  #  Now, we will use the ‘while’ loop like this: while(high - low > 10^(-6)).
  #  Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
    mid = (low+high) / 2.0
  #  Eliminate the halves based on the number of stations returned by numberOfGasStationsRequired():
  #  We will pass the potential value of ‘dist’, represented by the variable 'mid', to the ‘numberOfGasStationsRequired()' function. This function will return the number of gas stations we can place.
        If result > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid).
        Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid).
  #  Finally, outside the loop, we can return either low or high as their difference is beyond 10^(-6). They both can be the possible answer. Here, we have returned the ‘high’.
 The steps from 4-5 will be inside a loop and the loop will continue until (low-high <= 10^(-6)).


   Complexity Analysis:-
  # Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
    Reason: We are applying binary search on the answer space. For every possible answer, we are calling the function numberOfGasStationsRequired() that takes O(n) time complexity. And another O(n) for finding the maximum distance initially.

  # Space Complexity: O(1) as we are using no extra space to solve this problem.
*/
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}


long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}







int main() {

// Soln 1: Brute Force
    vector<int> a1 = {1, 2, 3, 4, 5};
    int k1 = 4;
    long double ans1 = minimiseMaxDistance1(a1, k1);
    cout << "The answer is: " << ans1 << endl;



// Soln 2: Better
    vector<int> a2 = {1,  13, 17, 23};
    int k2 = 5;
    long double ans2 = minimiseMaxDistance2(a2, k2);
    cout << "The answer is: " << ans2 << endl;



// Soln 3: Optimal
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans <<endl;




    return 0;
}
