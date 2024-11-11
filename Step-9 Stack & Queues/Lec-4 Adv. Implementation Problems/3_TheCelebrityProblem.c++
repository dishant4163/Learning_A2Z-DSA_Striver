// The Celebrity Problem


/* Celebrity Problem_Coding Ninjas -> (  https://shorturl.at/syS6v  )

#include <bits/stdc++.h>

//	This is signature of helper function 'knows'.
//	You should not implement it, or speculate about its implementation.

//	bool knows(int A, int B); 
//	Function 'knows(A, B)' will returns "true" if the person having
//	id 'A' know the person having id 'B' in the party, "false" otherwise.


int findCelebrity(int n) {
 	// Write your code here.
	stack<int> st;

    // Step 1: Push all people onto the stack
	for(int i=0; i < n; i++) {
		st.push(i);
	}

	// Step 2: Determine the potential celebrity
	while(st.size() > 1) {
		int a = st.top(); st.pop();
		int b = st.top(); st.pop();

		if(knows(a,b)) st.push(b);
		else st.push(a);
	}

    //might be not a celebrity
	int candidate = st.top();

	//everyone should know celebrity
	for(int i=0; i < n; i++) {
		if(knows(candidate, i)) return -1;
	}

	//everyone should know celebrity
	for(int i=0; i < n; i++) {
		if(i != candidate && !knows(i, candidate)) return -1;
	}

	return candidate;
}

*/



#include<bits/stdc++.h>
using namespace std;

/*// Soln-1 Brute Force
// TC:- O(N^2) + O(N),   SC:- O(N)
int celebrity(vector<vector<int>>& M){
    int size = M.size();
    vector<int> knowMe(size, 0);
    vector<int> iKnow(size, 0);

    // Fill knowMe and iKnow arrays
    for(int i=0; i < size; i++) {
        for(int j=0; j < size; j++) {
            if(M[i][j] == 1) {
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }

    // Check for the celebrity
    for(int i=0; i < size; i++) {
        if(knowMe[i] == size-1 && iKnow[i] == 0) {
            return i;
        }
    }

    return -1; // No celebrity found
}
*/




/*//Soln-2.1 OPtimal Soln(using Stack)

   To solve the celebrity problem using a stack, we can follow these steps:

 # Push all the people (indices) onto the stack.
 # While there are at least two people in the stack, pop the top two people and determine who can potentially be the celebrity based on their mutual knowledge.
 # Push the potential celebrity back onto the stack.
 # Finally, verify if the person left in the stack is indeed a celebrity.


  TC:- O(N), SC:- O(N)
*/
int findcelebrity(vector<vector<int>>& m) {
    int s = m.size();
    stack<int> st;

    // Step 1: Push all people onto the stack
    for(int i=0; i < s; i++) {
        st.push(i); //push indcies
    }

    // Step 2: Determine the potential celebrity
    while(st.size() > 1) { //Ensure at least two elements in the stack
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        // If a knows b, then a cannot be a celebrity
        // If a does not know b, then b cannot be a celebrity

        if(m[a][b] == 1) {
            st.push(b); // b could be a celebrity
        }
        else {
            st.push(a); // a could be a celebrity
        }
    }

    //Step 3: single element in stack is potential celebrity, may be or not
    // so Verify the candidate
    int candidate = st.top();

    for(int i=0; i < s; i++) {
        if(i != candidate) {
            if(m[candidate][i] == 1 || m[i][candidate] == 0) {
            //Candidate knows someone or someone does not know candidate
                return -1;
            }
        }
    }

    return candidate; //Return the celebrity index

}







// Soln-2.2 Most OPtimised (using 2-Pointers)
// TC: O(N),   SC:- O(N)
int findCelebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int topPtr = 0, downPtr = n-1;

    while(topPtr < downPtr) {
        //if top knows down then moves top to next
        if(mat[topPtr][downPtr] == 1) topPtr++;
        //if down knows top then moves down to prev
        else if(mat[downPtr][topPtr] == 1) downPtr--;
        //if both of them don't know each other
        //then both cannot be celebrity
        else {
            topPtr--;
            downPtr--;
        }
    }

    if(topPtr > downPtr) return -1;

    for(int i=0; i < n; i++) {
        //if it is diagonal no need to check it
        if(i == topPtr) continue;

        //checking in entire row & column of matrix
        if(mat[topPtr][i] == 0 && mat[i][topPtr] == 1) continue;
        else return -1;
    }

    return topPtr;
}








int main() {


/*//Soln-1 Brute Force
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int celeb = celebrity(M);
    if (celeb == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person: " << celeb << endl;
    }
*/


//Soln-2.1 OPtimal Soln
    vector<vector<int>> m = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int Celeb = findcelebrity(m);
    if (Celeb == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is at index: " << Celeb << endl;
    }


// Soln-2.2 Most OPtimal Soln
vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int celebrity = findCelebrity(mat);
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is at index: " << celebrity << endl;
    }




    return 0;
}

