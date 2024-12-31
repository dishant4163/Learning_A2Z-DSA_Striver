// Assign Cookies


/* Assign Cookies-> ( https://shorturl.at/KrPDl )

int assignCookie(vector<int> &greed, vector<int> &size) {
	// Write your code here.
    int L = 0, R = 0;

    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    while(L < greed.size() && R < size.size()) {
        if(size[R] >= greed[L]) {
            L++;
        }
        R++;
    }
    return L;
}


*/



#include<bits/stdc++.h>
using namespace std;


//Soln-> Greedly OPtimal Soln
// TC:- O(NxlogN + MxlogM + N + M)
int findMaxiContentChildren(vector<int>& greed, vector<int>& cookies) {
    int n = greed.size(), m = cookies.size();
    int Lptr = 0, Rptr = 0;

    sort(greed.begin(), greed.end()); // TC:- O(NxlogN)
    sort(cookies.begin(), cookies.end()); // TC:- O(MxlogM)

    while(Lptr < n && Rptr < m) { // O(N+M)
        if( cookies[Rptr] >= greed[Lptr]) {
            Lptr++;
        }
        Rptr++;
    }

    return Lptr;
}



int main() {

    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 2, 1, 2, 1, 3};

    int ans = findMaxiContentChildren(greed, cookies);

    cout << endl << "No. of kids assigned cookies is: "<< ans << endl;



    return 0;
}
