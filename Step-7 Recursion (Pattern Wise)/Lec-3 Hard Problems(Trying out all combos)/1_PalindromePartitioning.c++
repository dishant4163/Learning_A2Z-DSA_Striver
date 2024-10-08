//  Palindrome Partitioning | Recursion 

/*  Palindrome Partitioning (Coding Ninjas) -> https://shorturl.at/wsGJL     


bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}

void solve(int index, string s, vector<string>& path, vector<vector<string>>& ans) {
    //BASE CASE
    if (index == s.length()) {
        ans.push_back(path);
        return;
    }

    for(int i = index; i < s.size(); i++) {
        if(isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i-index+1)); //calculate no. of characters->(i-ind+1)
            solve(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) {
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> path;
    solve(0, s, path, ans);
    return ans;
}


*/



#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string str, int start, int end) {
    while(start <= end) {
        if(str[start++] != str[end--]) return false;
    }
    return true;
}

void solve(int ind, string s, vector<string>& output, vector<vector<string>>& ans) {
    //Base case
    if(ind == s.length()) {
        ans.push_back(output);
        return;
    }

    for(int i = ind; i < s.length(); i++) {
        if(isPalindrome(s, ind, i)) {
            output.push_back(s.substr(ind, i-ind+1));
            // (i-ind+1): This calculates the number of characters from ind to i, inclusive.
            solve(i+1, s, output, ans);
            output.pop_back();
        }
    }
}


vector<vector<string>> partition(string& s) {
    vector<vector<string>> ans;
    vector<string> output;
    solve(0, s, output, ans);
    return ans;
}


int main() {

    string s;
    cout << "Enter a string: ";
    cin >> s;  // Take user input for the string

    // Get all palindrome partitions
    vector<vector<string>> result = partition(s);

    // Print the results
    cout << "All possible palindrome partitions:" << endl;
    for (const auto& partition : result) {
        cout << "[ ";
        for (const auto& substring : partition) {
            cout << substring << ", ";
        }
        cout << "]" << endl;
    }



    return 0;
}

