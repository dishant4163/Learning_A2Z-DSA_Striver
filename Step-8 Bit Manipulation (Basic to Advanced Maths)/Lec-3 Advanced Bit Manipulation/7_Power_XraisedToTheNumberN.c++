// Implement Pow(x,n) | X raised to the power N



#include<bits/stdc++.h>
using namespace std;

//Soln-1 Brute Force
double myPow(double x, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        ans = ans * x;
    }
    return ans;
}


int main()
{
    cout<<myPow(2,10)<<endl;
}



