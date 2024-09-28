//Recusrion Day-4 Challenge | Recursion with Strings 


/* Reverse the String -> https://shorturl.at/QdWpv  

void reverseStr(string &str, int i, int j) {
	// Base Case
	if(i > j) return;

	//Processing
	swap(str[i++], str[j--]);

	//Recursive Relation
	reverseStr(str, i, j);
}

string reverseString(string str)
{
	// Write your code here.
	reverseStr(str, 0, str.length()-1);
	return str;
}

*/

/* Check If Binary Representation of a Number is Palindrome -> https://shorturl.at/NFWbc       



*/


#include<bits/stdc++.h>
using namespace std;

//1. Reverse String Using Recursion
void reverseStr(string &str, int i, int j) {//"&" i.e pass by reference, so that main-Func se same copy return naho

    //Base Case
    if(i > j) return;

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive Call
    reverseStr(str, i, j);
}




//2. Check Palindrome or Not
bool checkPalindrome(string s, int ptr1, int ptr2) {
    //Base Case 
    if (ptr1 > ptr2) return true;

    if (s[ptr1] != s[ptr2]) {
        return false;
    } else {
        return checkPalindrome(s, ptr1 + 1, ptr2 - 1);
    }
}






int main() {

//Reverse String using Recursion
    string name = "abcde";
    reverseStr(name, 0, name.length()-1 );
    cout << name << endl;



// Check Palindrome or Not
    string s = "NITIN";
    cout<< endl;

    bool isPalindrome = checkPalindrome(s, 0, s.length()-1 );

    if(isPalindrome) {
        cout << "Its a Palindrome " << endl;
    } else {
        cout << "Its not a Palindrome " << endl;
    }








    return 0;
}
