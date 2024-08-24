/*(Count Reverse Pairs_Coding Ninja)-> https://bit.ly/3Zj9U2L      

void merge(vector<int> &a, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        }
        else {
            temp.push_back(a[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i=low; i<=high; i++) {
        a[i] = temp[i - low];
    }
}

int countPairs(vector<int>&a, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i=low; i <= mid; i++) {
        while(right <= high && a[i] > 2*a[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &a, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = low + (high - low) / 2;

    cnt += mergeSort(a, low, mid);
    cnt += mergeSort(a, mid+1, high);
    cnt += countPairs(a, low, mid, high);
    
    merge(a, low, mid, high);

    return cnt;
}



int team(vector<int> &skill, int n)
{
    // Write your code here.
    return mergeSort(skill, 0, n-1);
}


*/



/* Problem Statement: 
 Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
*/



#include<bits/stdc++.h>
using namespace std;


/*// Soln 1: Brute Force(Naive)  
   Solution:-This question is slightly different from the question count inversion where the condition was a[i] > a[j] but here in this question, the condition is a[i] > 2*a[j]. In both questions, the index i < j.  

   Approach:- The steps are as follows:
  #  First, we will run a loop(say i) from 0 to N-1 to select the a[i].
  #  As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1, and select the element a[j].
  #  Inside this second loop, we will check if a[i] > 2*a[j] i.e. if a[i] and a[j] can be a pair. If they satisfy the condition, we will increase the count by 1.
  #  Finally, we will return the count i.e. the number of such pairs.

   Intuition:- The naive approach is pretty straightforward. We will use nested loops to generate all possible pairs. We know index i must be smaller than index j. So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition a[i] > 2*a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i].

   Complexity Analysis:-
  # Time Complexity: O(N2), where N = size of the given array.
    Reason: We are using nested loops here and those two loops roughly run for N times.
  # Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int countPairs1(vector<int>&ar, int n1) {

    //Count the number of pairs
    int cnt1 = 0;
    for (int i=0; i < n1; i++) {
        for (int j = i + 1; j < n1; j++) {
            if (ar[i] > 2 * ar[j]) cnt1++;
        }
    }

    return cnt1;
}

int TeamORcountReverse_1(vector<int>&skill1, int n1) {
    return countPairs1(skill1, n1);
}





/*// Soln 2: Optimal  
   Approach:- The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:

  #  In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
  #  We will add the numbers returned by the previous mergeSort() calls.
  #  Before the merge step, we will count the number of pairs using a function, named countPairs().
  #  We need to remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.

>>> The steps of the countPairs() function will be as follows:

  #  We will declare a variable, cnt, initialized with 0.
  #  We will run a loop from low to mid, to select an element at a time from the left half.
  #  Inside that loop, we will use another loop to check how many elements from the right half can make a pair.
  #  Lastly, we will add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.

   Complexity Analysis:-
  # Time Complexity: O(2N*logN), where N = size of the given array.
    Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
  # Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order. 
*/
void merge(vector<int>&ar, int low, int mid, int high) {
    vector<int> temp;// temporary array
    int left = low;// starting index of left half of arr
    int right = mid+1;// starting index of right half of arr

    //storing elements in the temporary array in a sorted manner

    while(left <= mid && right <= high) {
        if (ar[left] <= ar[right]) {
            temp.push_back(ar[left]);
            left++;
        }
        else {
            temp.push_back(ar[right]);
            right++;
        }
    }

    // if elements on the left half are still left

    while(left <= mid) {
        temp.push_back(ar[left]);
        left++;
    }

    // if elements on the right half are still left

    while(right <= high) {
        temp.push_back(ar[right]);
        right++;
    }

    // transfering all elements from temporary to arr

    for (int i=low; i<=high; i++) {
        ar[i] = temp[i -low];
    }
}

//Modification: defining count pair function
int countPairs(vector<int>&ar, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i=low; i<=mid; i++) {
        while(right <= high && ar[i] > 2 * ar[right])
        right++;
        cnt += right - (mid + 1);//Modification
    }
    return cnt;
}

int mergeSort(vector<int>&ar, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;

    int mid = low + (high - low) / 2;

    cnt += mergeSort(ar, low, mid);// left half
    cnt += mergeSort(ar, mid+1, high);// right half
    cnt += countPairs(ar, low, mid, high);//Modification

    merge(ar, low, mid, high);

    return cnt;
}

int team(vector<int>&skill, int n) {
    return mergeSort(skill, 0, n-1);
}




int main() {

// Soln 1: Brute Force
    vector<int> ar = {4, 1, 2, 3, 1};
    int n1 = 5;
    int cnt1 = TeamORcountReverse_1(ar, n1);
    cout<<"The number of reverse pair is: "<<cnt1<<endl;



// Soln 2: Optimal
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "<< cnt << endl;



    return 0;
}
