// Check The Number is Odd Or Even


#include<bits/stdc++.h>
using namespace std;


//Approach-1 (using % operator)
bool checkEvenOdd(int n) {
    // Returns true if n is even, else odd 
    return (n%2 == 0);
}





/* //Approach-2:
A better solution is to use bitwise operators. We need to check whether the last bit is 1 or not. If the last bit is 1 then the number is odd, otherwise always even.
*/
bool checkEvenOdd_2(int x) {
    int oddCheck = (x & 1); //(n&1) is used to find odd num

    return (!oddCheck); //this give even num
}






int main() {

//Approach-1
    int n;
    cout << "Enetr the number: ";
    cin >> n;
    checkEvenOdd(n) ? cout << "Even" : cout << "Odd" <<endl <<endl;





//Approach-2
    int x;
    cout << "Enetr the number: ";
    cin >> x;
    checkEvenOdd_2(x) ? cout << "Even" : cout << "Odd"<<endl <<endl;







/*//Approach-3 (using bitwise left-shift & right-shift)
Another approach is by using bitwise left-shift and right-shift operators. The logic behind this implementation is about regenerating the value after the right shift and left shift. We all know even numbers have zero as the last bit and odd have one as the last bit. When we bitwise right shift any number then the last bit of the number piped out whenever it is even or odd. Next, we did a bitwise left shift, then our bit shifted by one. Now last bit placed is empty which is by default filled by a zero. During all these odd numbers changed their value but even remains the same. That’s how by comparing the initial and final value we decide number is even or odd.
*/

int num;
cout<<"Enter an number: ";
cin >> num ;

//using bitwise left-shift & right-shift
if (num == (num >> 1) << 1) {
    cout << "Number is Even: " << num <<endl;
} else {
    cout << "Number is Odd: " << num << endl;
}







    return 0;
}


