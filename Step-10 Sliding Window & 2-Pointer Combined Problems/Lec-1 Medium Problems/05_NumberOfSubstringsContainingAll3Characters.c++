// Number of Substrings Containing All Three Characters    



/*  Count Substring With abc -> ( https://shorturl.at/tk7z7 )


int countSubstring(string s){
    // Write your code here.
    int n = s.size(), cnt = 0;
    vector<int> lastSeen(3, -1);

    for(int i=0; i < n; i++) {
        lastSeen[s[i] - 'a'] = i;

        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            cnt += 1 + min( {lastSeen[0], lastSeen[1], lastSeen[2] } );
            //The correct way to get the minimum of 3 values is to use min({lastSeen[0], lastSeen[1], lastSeen[2]}).
        }
    }

    return cnt;
}

*/




#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
//TC:- O(N^2),   SC:- O(1) -> bcz hasharr have 3 element only
int subStrAll3Chars(string& Str) {
    int size = Str.size(), count = 0;

    for(int i=0; i < size; i++) {
        vector<int> hashArr(3, 0);
        for(int j=i; j < size; j++) {
            hashArr[Str[j] - 'a' ] = 1;

            if(hashArr[0] + hashArr[1] + hashArr[2] == 3) {
                count++;
            }
        }
    }

    return count;
}
*/




/*//Soln-2 Better Soln (slighty optimized brute soln)
// TC:- O(N^2), SC:- O(1)
int substrAll3Chars(string& str) {
    int Len = str.length(), Count = 0;

    for(int i=0; i < Len; i++) {
        vector<int> hashAr(3, 0);
        for(int j = i; j < Len; j++) {
            hashAr[str[j] - 'a'] = 1;

            if(hashAr[0] + hashAr[1] + hashAr[2] == 3) {
                Count = Count + (Len - j); //slight optimization
                break; // for iterating next substr
            }
        }
    }

    return Count;
}
*/




//Soln- 3 (using Sliding Window & 2-Ptr but here we are playing with indexes)
int findsubStrWithAll3Chars(string& s) {
    int n = s.size(), cnt = 0;
    vector<int> lastSeen(3, -1); //store the lastSeen positions of 'a', 'b', 'c'

    for(int i=0; i < n; i++) {
        lastSeen[s[i] - 'a'] = i; //Update the lastSeen position of the character

        //Check if all 3 characters 'a', 'b', 'c' have been seen
        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            // Update the counter with 1 + minimum of the last seen positions
            cnt += 1 + min( {lastSeen[0], lastSeen[1], lastSeen[2]} );
            //The problem is caused by how min is being used. The standard min function only accepts two arguments, 
            //so when you're trying to pass three values (lastSeen[0], lastSeen[1], lastSeen[2]), it leads to a compilation error.
            // so for this problem use this syntax for more than 2 arguments in min as => min( {arg1, arg2, arg3} ), in min( { } ) 
        }
    }

    return cnt;
}






int main() {

/*//SOln-1 Brute Force
    string Str = "abbac";
    cout << "Number of substrings containing all 3 characters : " << subStrAll3Chars(Str) << endl;
*/


/*//Soln-2 Better Soln (slighty optimized brute soln)
    string str = "bbacba";
    cout << "Number of substrings containing all 3 characters : " << substrAll3Chars(str) << endl;
*/


//Soln-3
    string s = "bbacba";
    cout << "Number of substrings containing all 3 characters : " << findsubStrWithAll3Chars(s) << endl;






    return 0;
}

