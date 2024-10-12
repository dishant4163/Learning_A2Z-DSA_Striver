// Sum of Beauty of All Substrings | Leetcode 1781 | Coding Ninjas



/* Sum of Beauty of All Substrings (Coding Ninjas ->  https://shorturl.at/Z9DSY  )

int getMinCnt(vector<int>& freq) {
    int minCnt = INT_MAX;
    for (int i=0; i <26; i++) {
        if (freq[i] != 0) {
            minCnt = min(minCnt, freq[i]);
        }
    }
    return minCnt;
}

int getMaxCnt(vector<int>& freq) {
    int maxCnt = INT_MIN;
    for (int i=0; i < 26; i++) {
        maxCnt = max(maxCnt, freq[i]);
    }
    return maxCnt;
}


int sumOfBeauty(string s) {
	// Write your code here.
	int sum =0;
	int n = s.size();

	for (int i=0; i<n; i++) {
		vector<int> freqAr(26, 0);
		for (int j=i; j<n; j++) {
			freqAr[s[j] - 'a']++;
			int beauty = getMaxCnt(freqAr) - getMinCnt(freqAr);
			sum += beauty;
		}
	}
	return sum;
}


*/



#include<bits/stdc++.h>
using namespace std;

int getMinCnt(vector<int>& freq) {
    int minCnt = INT_MAX;
    for (int i=0; i <26; i++) {
        if (freq[i] != 0) {
            minCnt = min(minCnt, freq[i]);
        }
    }
    return minCnt;
}

int getMaxCnt(vector<int>& freq) {
    int maxCnt = INT_MIN;
    for (int i=0; i < 26; i++) {
        maxCnt = max(maxCnt, freq[i]);
    }
    return maxCnt;
}


int sumOfBeauty(string s) {
	// Write your code here.
    int sum = 0;
    int n = s.size();
    for (int i=0; i < n; i++) {
        vector<int> freqAr(26, 0); // initialize frequency array to 0
        for (int j=i; j < n; j++) {
            freqAr[s[j] - 'a']++;
            int beauty = getMaxCnt(freqAr) - getMinCnt(freqAr);
            sum += beauty;
        }
    }
    return sum;
}



int main() {

    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = sumOfBeauty(s);
    cout << "Sum of beauty: " << result << endl;



    return 0;
}


