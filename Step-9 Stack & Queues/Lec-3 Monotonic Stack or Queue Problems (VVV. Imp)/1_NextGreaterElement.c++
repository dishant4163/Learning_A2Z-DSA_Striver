// Next Greater Element (in right side in an array)


/* Next Greater Element_Coding Ninjas Problems -> (  https://tinyurl.com/yckahsvc  )

#include<stack>

vector<int> nextGreaterElement(vector<int>& arr, int n) {
	// Write your code here
	vector<int> nge(n, -1);
	stack<int> st;
	for(int i=n-1; i >= 0; i--) {
		while(!st.empty() && st.top() <= arr[i]) {
			st.pop();
		}

		if(st.empty()) nge[i] = -1;
		else nge[i] = st.top();

		st.push(arr[i]);
	}

	return nge;
}

*/



#include<bits/stdc++.h>
using namespace std;


/*//SOln-1 Naive Approach (Using two nested loops)

  The idea is to use two loops , The outer loop picks all the elements one by one. The inner loop looks for the first greater element for the element picked by the outer loop. If a greater element is found then that element is printed as next, otherwise, -1 is printed.   

   Complexity Analysis:-
  # TC:- O(N^2)
  # SC:- O(N)
*/
void printNGE(int ar[], int N) {
    int next;
    for(int i=0; i < N; i++) {
        next = -1;
        for(int j = i+1; j < N; j++) {
            if(ar[i] < ar[j]) {
                next = ar[j];
                break;
            }
        }
        cout << next << endl;
    }
}





/*//Soln-2 OPtimal (Using Stack)

   Approach:- The idea is to store the elements for which we have to find the next greater element in a stack and while traversing the array, if we find a greater element, we will pair it with the elements from the stack till the top element of the stack is less than the current element.

   Follow the steps mentioned below to implement the idea:
 # Push the first element to stack.
 # Pick the rest of the elements one by one and follow the following steps in the loop. 
    Mark the current element as next.
    If the stack is not empty, compare top most element of stack with next.
    If next is greater than the top element, Pop element from the stack. next is the next greater element for the popped element.
    Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
 # Finally, push the next in the stack.
 # After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.           

   Complexity Analysis:-
  Time Complexity: O(2N)
  Space Complexity: O(N)+O(N) => stack + nge
*/
vector<int> nextGreater(vector<int> &arr, int n) {
// NextGreaterElement_Coding ninjas ( https://tinyurl.com/ycx3nwwf )

    vector<int> nge(n);
    stack<int> st;

    for(int i =n-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= ar[i]) {
            st.pop();
        }

        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();

        st.push(ar[i]);
    }

    return nge;
}




int main() {

//Soln-1 Brute Force
    int ar[] = {11, 13, 21, 5};
    int N = sizeof(ar) / sizeof(ar[0]);
    printNGE(ar, N);




//Soln-2 OPtimal Soln
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input elements of the array
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Get the next greater elements
    vector<int> result = nextGreater(arr, n);

    // Output the results
    cout << "Next Greater Elements: ";
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;




    return 0;
}