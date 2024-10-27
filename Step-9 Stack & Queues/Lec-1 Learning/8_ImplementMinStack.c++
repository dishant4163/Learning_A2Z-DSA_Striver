// Implement Min Stack

/* Min Stack_Coding Ninjas -> (  https://shorturl.at/2Cc9y  )


#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack {
	// Write your code here.
	stack<int> st;
	int mini;
	
	public:
		
		// Constructor
		minStack() { 
			// Write your code here.
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num) {
			// Write your code here.
			if(st.empty()) {
				st.push(num);
				mini = num;
			} else {
				if(num >= mini) {
					st.push(num);
				} else {
					st.push(2*num - mini);
					mini = num;
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop() {
			// Write your code here.
			if(st.empty()) return -1;
			else {
				int el = st.top();
				st.pop();

				if(el < mini) {
					int val = mini;
					mini = (2* mini - el);
					return val;
				} else {
					return el;
				}
			}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top() {
			// Write your code here.
			if(st.empty()) return -1;
			else if(st.top() >= mini) return st.top();
			else return mini;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin() {
			// Write your code here.
			if(st.empty()) return -1;
			else return mini;
		}
};

*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln-1  Using pairs to store the value and minimum element till now.

  Approach: The first element in the pair will store the value and the second element will store the minimum element till now.

 When the first push operation comes in we will push the value and store it as minimum itself in the pair. 

 In the second push operation, we will check if the top element’s minimum is less than the new value. If it is then we will push the value with minimum as the previous top’s minimum. To get the getMin element to take the top’s second element.


   Complexity Analysis:
 # Time Complexity: O(1)

 # Space Complexity: O(2N)
*/
/*class minStack {
    stack< pair <int, int>> St;

public:

    void Push(int el) {
        int minn;
        if(St.empty()) {
            minn = el;
        } else {
            minn = min(St.top().second, el);
        }
        St.push({el, minn});
    }

    void Pop() {
        St.pop();
    }

    int Top() {
        return St.top().first;
    }

    int getMiN() {
        return St.top().second;
    }

};
*/





/* // Soln-2
  Approach: 

Let’s take a variable that stores the minimum number. So whenever a push operation comes in just take that number put it in the stack and update the variable to the number.


 # Push operation:
Now if there is a push operation just check whether that number is less than the min number. If it is smaller than min we will push a modified value which is a push(2 * Val - min) into the stack and will update min to the value of the original number. If it’s not then we will just push it as it is.

 # getMin() operation:
We will just return the value of min.

 # Top operation:
While returning the top value we know that it is a modified value. We will check if the top value is lesser than min, If it is then we will return the min as the top value.

 # Pop operation:
While making pop we will check if the top value is lesser than min, If it is then we must update our min to its previous value. In order to do that min = (2 * min) - (modified value) and we will pop the element.


   Complexity Analysis:
 # Time Complexity: O(1)

 # Space Complexity: O(N)

*/
class MinStack {
    stack<long long> st;
    long long mini;
public:
// initialize your data structure here
MinStack() {
    while (st.empty() == false) st.pop();
    mini = LLONG_MAX;
}

void push(int value) {
    long long val = value;
    if(st.empty()) {
        mini = val;
        st.push(val);
    } else {
        if (val < mini) {
            st.push(2 * val - mini);
            mini = val;
        } else {
            st.push(val);
        }
    }
}

void pop() {
    if(st.empty()) return;
    long long el = st.top();
    st.pop();

    if(el < mini) {
        mini = 2*mini - el;
    }
}

int top() {
    if(st.empty()) return -1;

    long long el = st.top();
    if(el < mini) {
        return mini;
    }
    return el;
}

int getMin() {
    return mini;
}

};






int main() {


/*// Approach-1
    minStack st;
    vector<string> commands = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> args = { {}, {-2}, {0}, {-3}, {}, {}, {}, {} };
    
    for (size_t i = 1; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.Push(args[i][0]);
            cout << "null" << endl; // Push does not return anything
        } else if (commands[i] == "pop") {
            st.Pop();
            cout << "null" << endl; // Pop does not return anything
        } else if (commands[i] == "top") {
            cout << st.Top() << endl; // Should print top element
        } else if (commands[i] == "getMin") {
            cout << st.getMiN() << endl; // Should print minimum element
        }
    }
*/



//Approach-2
    MinStack minStack;
    
    // Test the MinStack with sample inputs
    vector<string> commands = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> args = { {}, {-2}, {0}, {-3}, {}, {}, {}, {} };
    
    for (size_t i = 1; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            minStack.push(args[i][0]);
            cout << "null" << endl; // Push does not return anything
        } else if (commands[i] == "pop") {
            minStack.pop();
            cout << "null" << endl; // Pop does not return anything
        } else if (commands[i] == "top") {
            cout << minStack.top() << endl; // Should print top element
        } else if (commands[i] == "getMin") {
            cout << minStack.getMin() << endl; // Should print minimum element
        }
    }





    return 0;
}


