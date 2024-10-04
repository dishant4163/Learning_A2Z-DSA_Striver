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









// Components of Recursion
//1. Printing Counting Using TAIL Recursion(it will print in reverse order)
void print1(int a) {
    //base case
    if (a == 0) return;

    //Processing
    cout << a << endl;

    //Recursive Relation
    print1(a-1);
}



//2. Printing Counting Using HEAD Recursion(it will print in reverse order)
void print2(int b) {
    //base case
    if (b == 0) return;

    //Recursive Relation
    print2(b-1);

    //Processing
    cout << b << endl;
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







// Components of Recursion
//1. Printing Counting Using Tail Recursion(it will print in decending/reverse order)
    int a, b;
    cin >> a >> b;
    cout <<endl;
    print1(a);

//2. Printing Counting Using HEAD Recursion(it will print in incresing order)
    cout<<endl;
    print2(b);






    return 0;
}

