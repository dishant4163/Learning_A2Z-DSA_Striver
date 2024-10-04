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

/* Find power of a number -> https://shorturl.at/pu1mc   

#include<bits/stdc++.h>
long long Pow(int X, int N)
{
    // Write your code here. 

    if (N == 0) return 1; //base case-1
    if (N == 1) return X; //base case-2

    // Recursive Call
    int ans = Pow(X, N/2);

    if(N%2 == 0) { // if N is Even
        return ans * ans;
    }
    else { // if N is odd
        return X * ans * ans;
    }
}

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




//3. Calculating Power(exponent) using Recursion
int calPower(int X, int N) {
    // Base Case-1
    if (N == 0) return 1;
    // Base Case-2
    if (N == 1) return X;

    // Recursion Call
    int ans = calPower(X, N/2);

    // if N is even
    if (N%2 == 0) {
        return ans * ans;
    }
    else {
    // if N is odd
        return X * ans * ans;
    }
}




//4. Bubble Sort Using Recursion
void buSortArr(int *Ar, int size) {
    //Base case - if already sorted
    if (size ==0 || size == 1) return;

    //1- case solve karliya - largest element ko end me rakh deya
    for (int i=0; i < size-1; i++) {
        if (Ar[i] > Ar[i+1]){
            swap(Ar[i], Ar[i+1]);
        }
    }

    //Recursive Call
    buSortArr(Ar, size-1);

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



// Calculating Power(exponent) using Recursion
    int X, N;
    cin >> X >> N;
    int soln = calPower(X, N);
    cout << "Answer is " << soln << endl;



// Bubble Sort Using Recursion
    int Ar[5] = {9, 7, 1, 3, 5};
    int size = 5;
    buSortArr(Ar, size);
    //print the sorted Array
    for (int i=0; i<size; i++) {
        cout << Ar[i] <<" ";
    }
    cout << endl;






    return 0;
}
