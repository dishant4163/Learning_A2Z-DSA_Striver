//Recusrion Day-2 Challenge | Understanding Recursion




//Leetcode Question 
/*// Find nth term of Fibonacci Series (leetcode-> https://shorturl.at/QB3v8)  

int fib(int n) {
    //Base Case
    if(n == 0) return 0;
    if(n == 1) return 1;

    //Recursive Relation
    int soln = fib(n-1) + fib(n-2);
    return soln;
}
*/






// Coding Ninjas
/* // Count Ways To Reach The N-th Stairs -> https://shorturl.at/mvKhN

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.

    // Base Case
    if (nStairs < 0) return 0;
    if (nStairs == 0) return 1;

    // Recursive Relation
    int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);

    return ans;
}
// in this  queston Recursion + DP both is used to solve 
*/






#include<bits/stdc++.h>
using namespace std;


// Level-0 for understanding
void reachHome(int src, int dest) {
    // just 4 checking recursion
    cout << "source " << src << " destination " <<dest <<endl;

    //base Case
    if (src == dest) {
        cout << "Reached Home" <<endl;
        return;
    }

    // processing - ek step aage badhjao
    src++;

    //Recursuve Relation
    reachHome(src, dest);
}




// Say Digits
// I/p = 412
// O/p = Four One Two
void sayDigit(int m, string arr[]) {
    //Base Case
    if (m == 0) return;

    // processing
    int digit = m % 10;
    m = m / 10;
    

    // recursive relation
    sayDigit(m, arr);
    cout << arr[digit] << " ";
}









int main() {

// Level-0
    int dest = 10, src = 1;
    cout << endl;
    reachHome(src, dest);



// Say Digits
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int m; 
    cin >> m;
    cout << endl;
    sayDigit(m, arr);
    cout << endl;




    return 0;
}




