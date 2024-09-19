//Intro to Parametrised & Functional way in Recursion

#include<bits/stdc++.h>
using namespace std;

//1. Sum of First N numbers
/*//a). By Parametrised Way
  # Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

  # Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/
void func1(int i, int sum) {
    //Base Condition
    if (i < 1) {
        cout << sum << endl;
        return;
    }
    func1(i-1, sum + i);
}



/*// Functional way
  # Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }

  # Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
*/
int sumOfN(int n2) {
    if (n2 == 0 ) return 0;
    return (n2 + sumOfN(n2 - 1));
}







//2. Factorial of a Number
/*//a). By Iterative Way
  # Time Complexity: O(n)

  # Space Complexity: O(1)
*/
int factorial1(int m) {
    int fact = 1;
    for (int i=1; i <= m; i++) {
        fact = fact * i;
    }
    return fact;
}



//b). By Functional Way
int factorial2(int m) {
    if (m == 0) return 1;
    return (m * factorial2(m - 1));
} 








int main() {


//1. Sum of First N numbers
//Parameterised Way
    int n1 = 5;
    func1(n1, 0);


// Functional Way
    int n2 = 3;
    cout << sumOfN(n2) <<endl;






//2. Factorial of a Number
//By Parametrised Way
    int m1 = 3;
    cout << factorial1(m1)<<endl;


//By Functional Way
    int m = 4;
    cout << factorial2(m)<<endl;







return 0;
}
