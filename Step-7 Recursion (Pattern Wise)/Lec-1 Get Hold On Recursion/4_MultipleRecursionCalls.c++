// Multiple Recursion Calls

#include<bits/stdc++.h>
using namespace std;



// Function to calculate Fibonacci number using recursion
int fibonacci(int n) {
    //base conditon
    if (n <= 0) return 0; // base case for n=0
    if (n <= 1) return 1; // base case for n=1

    // Recursive case
    return fibonacci(n-1) + fibonacci(n-2); 
}



// Function to print Fibonacci
void printFibonacciSeries(int n) {
    for (int i=0; i < n; i++) {
        cout << fibonacci(i)<<" ";
    }
    cout << endl;
}

int FibonacciSum(int n) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += fibonacci(i);
    }
    return sum;
}







int main() {

    int n;
    cin >> n;
    cout << "Enter the number to get Fibonacci series: ";
    printFibonacciSeries(n);


    // Calculate and print the sum of the first n Fibonacci numbers
    int sum = FibonacciSum(n);
    cout << "Sum of the first " << n << " terms of fibonacci series: " <<sum <<endl;





    return 0;
}



