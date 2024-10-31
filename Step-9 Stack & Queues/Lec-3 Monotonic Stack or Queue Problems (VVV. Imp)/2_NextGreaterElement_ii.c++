// Next Greater Element-ii (in right side in an array)


/* Next Greater ElementII_Coding Ninjas -> (  https://shorturl.at/LBoZQ  )


#include<stack>
vector<int> nextGreaterElementII(vector<int>& a) {
    // Write your code here.
    int n = a.size();
    vector<int> nge2(n, -1);
    stack<int> st;

    for(int i = 2*n-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= a[i % n]) {
            st.pop();
        }

        if(i < n) {
            if(!st.empty()) nge2[i] = st.top();
        }

        st.push(a[i % n]);
    }

    return nge2;
}


*/


#include<bits/stdc++.h>
using namespace std;

//Soln-1 Brute Force
// TC:- O(n^2)  SC:- O(n)
vector<int> nextGreaterElementsii(vector<int>& nums) {
    int s = nums.size();
    vector<int> NGE2(s, -1);

    for(int i=0; i < s; i++) {
        //Check the next elements in a circular manner
        for(int j =i+1; j < i+s-1; j++) { // another way for(int j=1; j < s; j++) & for this loop circular index = j%s; & rest code will be same
            int index = j % s; //Circular index
            if(nums[index] > nums[i]) {
                NGE2[i] = nums[index];
                break; //Found NGE2, break the inner loop
            }
        }
    }

    return NGE2;
}






//Soln-2 OPtimal Soln(using Stack & circular array)
vector<int> nextGreaterElementII(vector<int>& ar) {
    int n = ar.size();
    vector<int> nge2(n, -1);
    stack<int> st;

// traversing from last to start
    for(int i = 2*n-1; i >= 0; i--) {
        while(!st.empty() && st.top() <= ar[i%n]) {
            st.pop();
        }

        if (i < n) {
            if (!st.empty()) nge2[i] = st.top();
            else nge2[i] = -1;
        }

        st.push(ar[i%n]);
    }

    return nge2;
}







int main() {

//Soln-1 Brute Force
    vector<int> nums = {2,10,12,1,11};
    vector<int> result = nextGreaterElementsii(nums);

    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;



//Soln-2 OPtimal Soln
    vector<int> ar = {2, 10, 12, 1, 11};
    vector<int> ans = nextGreaterElementII(ar);

    cout << "Next greater elements: ";
    for (int it : ans) {
        cout << it << " ";
    }
    cout << endl;





    return 0;
}

