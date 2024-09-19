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








int main() {


//Parameterised Way
    int n1 = 5;
    func1(n1, 0);


// Functional Way
    




return 0;
}
