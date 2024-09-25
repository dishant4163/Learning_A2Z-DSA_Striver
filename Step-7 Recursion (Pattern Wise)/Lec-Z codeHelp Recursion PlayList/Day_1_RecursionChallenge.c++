//Recusrion Day-1 Challenge | Learning Recursion (intro to Recursion)




#include<bits/stdc++.h>
using namespace std;

// Find Factorial Using Recursion
int factorial(int n) {
    //Base Case
    if (n == 0) return 1;

    // int smallerProblem = factorial(n-1);
    // int biggerProblem = n * smallerProblem;
    // return biggerProblem;


    // Modify the code little

    retrun n * factorial(n-1); // dirctly find the factorial without using extra variables
}





// Power of 2
int powerof2(int m) {
    // Base Case
    if (m == 0) return 1;

    // int smallerProblem = powerof2(m-1);//Recursive Relation
    // int biggerProblem = 2 * smallerProblem;
    // return biggerProblem;


    // Modify the code little
    return 2 * powerof2(m-1); // dirctly find the factorial without using extra variables
}









int main() {


// Find Factorial using Recursion
    int n;
    cin >> n;

    int ans = factorial(n);
    cout << ans << endl;



// Power of 2
    int m;
    cin >> m;

    int soln = powerof2(m);
    cout << soln <<endl;







    return 0;
}

