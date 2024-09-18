#include <bits/stdc++.h>
using namespace std;


//Recursive funct, to print 1 infinite recursively
void printRe1() {
    cout << 1 << endl;
    printRe1(); // Recursive call
}




//Recursie Function with base condition 
int cnt = 0;
void countPrt() {
    if (cnt == 3) return;
    cout << cnt <<endl;
    cnt++;
    countPrt();
}







int main() {


// Recursive Function to print 1, in infinite recursive 
    printRe1();



// Recursie Function with base condition
    countPrt();








    return 0;
}



