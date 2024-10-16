//Power Set: Print all the possible subsequences | Bit Manipulation

/* //Power Set (Coding Ninjas ->  https://shorturl.at/eDx0j  )

#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int> v){
    //Write your code here
    int n = v.size();
    vector<vector<int>> ans;
    int subsets = (1 << n); // no. of subsets = (2^n) = (1 << n) <- for bitwise

    for(int num = 0; num < subsets; num++) {
        vector<int> temp;

        for(int i=0; i < n; i++) {
            //check for ith bit is set or not
            if(num & (1 << i)) {
                temp.push_back(v[i]);
            }
        }

        //Only add non-empty subsets
        if(temp.size() > 0) {
            ans.push_back(temp);
        }
    }

    return ans;
}

*/


#include<bits/stdc++.h>
using namespace std;


//1. For Strings using Bit Manipulation
vector<string> AllPossibleStrings(string s) {
    int n = s.length();
    vector<string> ans;
    int subsets = (1 << n); // subsets = 2^n = (1 << n)

    for(int num = 0; num < subsets; num++) {
        string substring = "";
        for(int i=0; i < n; i++) {
            //check if the ith bit is set or not
            if (num & (1 << i)) {
                //Correctly add characters to substring
                substring += s[i]; // or substring.push_back(s[i]);
            }
        }
        if (substring.length() > 0) { // Check if substring is non-empty
            ans.push_back(substring);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}






//2. For finding power set / print subsets of number
vector<vector<int>> pwset(vector<int> ar) {
    int N = ar.size();
    vector<vector<int>> ans;
    int subSets = (1 << N); // 2^N = subsets = (1 << N)

    for(int num = 0; num < subSets; num++) {
        vector<int> temp;

        for(int i=0; i < N; i++) {
            //check if the ith bit is set or not
            if(num & (1 << i)) {
                temp.push_back(ar[i]);
            }
        }
        if(temp.size() > 0) { //Only add non-empty subsets
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}






int main() {


// For Strings
    string s = "abc";
    vector<string> subsets = AllPossibleStrings(s);

    cout << "All Possible Non-Empty Substrings:\n";
    for (const string& substring : subsets) {
        cout << substring << "\n";
    }





// for Array (on number set)
    vector<int> ar = {1, 2, 3};
    vector<vector<int>> subsets = pwset(ar);

    cout << "Power Set:\n";
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }




    return 0;
}


