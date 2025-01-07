// Minimum Number of Platforms Required in a Railway Station


#include<bits/stdc++.h>
using namespace std;

/*//Soln-1  (Brute Force)
// TC:- O(N^2) , SC:- O(1)
int countPlatforms(int N,int arri[],int dep[]) {
    int ans = 0;

    for(int i=0; i < N; i++) {
        int cnt = 1;
        for(int j = i+1; j < N; j++) {
            if( (arri[i] >= arri[j] && arri[i] <= dep[j]) ||
            (arri[j] >= arri[i] && arri[j] <= dep[i]) ) {
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    return ans;
}
*/





//Soln-2 OPtimal (using Sorting)
// TC:- O 2(N logN + n), SC:- O(1)
// If(arr[i]<=dep[j]) means if arrival time is less than or equal to the departure time then- we need one more platform
//  If(arr[i]>dep[j]) means the arrival time is more than the departure time then- we have one extra platform which we can reduce. 
int countMiniPlatforms(int n, int arriv[], int dept[]) {
    int  i = 0, j = 0, cnt = 0, maxCnt = 0;

    sort(arriv, arriv + n);
    sort(dept, dept + n);

    while(i < n && j < n) {
        if(arriv[i] <= dept[j]) { //one more platform needed
            cnt++;
            i++;
        }
        else { //one platform can be reduced
            cnt--;
            j++;
        }

        maxCnt = max(cnt, maxCnt);
    }

    return maxCnt;
}






int main() {

/*//Soln-1 Brute Force
    int arri[]= {900,945,955,1100,1500,1800};
    int dep[]= {920,1200,1130,1150,1900,2000};
    int N = sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(N,arri,dep)<<endl;
*/



//Soln-2 OPtimal Soln
    int arriv[]= {900,945,955,1100,1500,1800};
    int dept[]= {920,1200,1130,1150,1900,2000};
    int n = sizeof(dept)/sizeof(dept[0]);
    cout<<"Minimum number of Platforms required "<< countMiniPlatforms(n,arriv,dept)<<endl;




    return 0;
}

