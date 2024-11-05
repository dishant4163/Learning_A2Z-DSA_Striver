// Area of Largest Rectangle in Histogram






#include<bits/stdc++.h>
using namespace std;

/*//Soln-1 Brute Force
  Intuition: The intuition behind the approach is taking different bars and finding the maximum width possible using the bar.

  Similarly for other bars, we will find the areas possible:-


-> Considering the width of each bar as 1 unit.
-> For first bar, area possible = 2* 1 =2 sq . units
-> For second  bar, area possible = 1 * 6 =6 sq . units
-> For third bar , area possible = 5 *2 = 10 sq . units
-> For fourth bar , area possible = 6 * 1 = 6 sq . units
-> For Fifth bar , area possible = 2 * 4 = 8 sq . units
-> For Sixth bar , area possible = 3 * 1 =3 sq . units
-> So, the maximum area possible = 10 sq units.


   Approach:

The approach is to find the right smaller and left smaller element and find the largest Rectangle area in Histogram.


   Complexity Analysis:-

  # Time Complexity: O(N*N ) 
  # Space Complexity: O(1)
*/
/*int largestrectangleArea(int arr[], int s) {
    int maxiAr = 0;
    for(int i=0; i < s; i++) {
        int miniHt = INT_MAX;
        for(int j = i; j < s; j++) {
            miniHt = min(miniHt, arr[j]);
            maxiAr = max(maxiAr, miniHt * (j - i + 1));
        }
    }
    return maxiAr;
}
*/





/*//Soln-2 OPtimal Soln
   Approach -> (  https://shorturl.at/JsJd7  )

   Complexity Analysis:-

  #Time Complexity: O(N) + O (N)
  # Space Complexity: O(N)
*/
int largestRectangleArea(vector<int>& histo) {
    int n = histo.size();
    int maxArea = 0;
    stack<int> st;

    for(int i=0; i < n; i++) {
        while(!st.empty() && histo[st.top()] > histo[i]) {
            int elgot = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, histo[elgot] * (nse-pse-1));
        }
        st.push(i);
    }

    while(!st.empty()) {
        int nse = n;
        int elgot = st.top(); st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, histo[elgot] * (nse-pse-1));
    }

    return maxArea;
}







int main() {

/*//Soln-1 Brute Force
    int arr[] = {2, 1, 5, 3, 2, 3};
    int size = 6;
    cout << "The largest area in the Histogram is: " << largestrectangleArea(arr, size) << endl;
*/



//Soln-2 OPtimal Soln
    vector<int> histo = {3, 2, 10, 11, 5, 10, 6, 3};
    cout << "The largest area in the histogram is " << largestRectangleArea(histo) << " units" << endl;





    return 0;
}


