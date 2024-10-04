//Recusrion Day-8 Challenge | Phone Keypad Problem Recursion  


/* Possible Words From A Phone Number (Coding Ninja)-> https://shorturl.at/MCfIC    

#include <bits/stdc++.h> 

void solve(string s, string output, int index, vector<string>& ans, string mapping[]) {
	// Base Case
	if(index >= s.length()) {
		ans.push_back(output);
		return;
	}

	int num = s[index] - '0';
	string value = mapping[num];
	for (int i=0; i < value.length(); i++) {
		output.push_back(value[i]);
		solve(s, output, index+1, ans, mapping);
		//Backtrack
		output.pop_back();
	}
}

vector<string> findPossibleWords(string s)
{
	// Write your code here.
	vector<string> ans;
	// if s is empty string
	if(s.length() == 0) return ans;
	string output = "";
	int index = 0;
	string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	solve(s, output, index, ans, mapping);
	return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;


void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
    // BASE CASE
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    // find num acc. to string combo i.e, 2 -> 'abc' etc
    int number = digits[index] - '0'; //convert char to int
    string value = mapping[number];

    for (int i=0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);

        // Now Backtract 
        // & to delete the recent added string value so empty the output
        output.pop_back(); 
    }
}


vector<string> letterCombinations(string digits) {
    vector<string> ans;
    // if digit-string is empty
    if(digits.length() == 0) return ans;
    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);
}


int main() {

    string digits;
    cout << "Enter the digits: ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    cout << "Possible letter combinations are: " << endl;
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;


    return 0;
}

