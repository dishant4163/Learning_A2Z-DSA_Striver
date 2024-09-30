//Recusrion Day-9 Challenge | Permutations of a String    


/*// Permutations of a String (Coding Ninjas)-> https://shorturl.at/FzzQ8   

#include<bits/stdc++.h>

void solve(string str, vector<string>& ans, int index) {
    //Base Case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index+1);

        //Backtrack, for maintaining consistency of given string
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str)
{
    // write your code here
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end());
    return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;



//1. Permutations of a String
void solveStrPermute(string str, int index, vector<string>& ans) {
    // Base Case
    if (index >= str.length()) {
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++) {
        swap(str[index], str[j]);
        solveStrPermute(str, index+1, ans);

        // Backtrack, for maintaining consistency of given string
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string &str) {
    vector<string> ans;
    int index = 0;
    solveStrPermute(str, index, ans);
    // sort(ans.begin(), ans.end()); //if asked to sort 
    return ans;
}




//2. Permutations of a Array






int main() {


// Permutations of a String
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Generate permutations
    vector<string> permutations = generatePermutations(str);

    // Print the permutations
    cout << "Permutations of the string are:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }


    return 0;
}

