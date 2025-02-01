// Maximum XOR of Two Numbers in an Array


/*// Problem-Link-> https://www.naukri.com/code360/problems/maximum-xor_3119012


struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }

};


class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i=31; i >= 0; i--) {
            //get number SET-BIT of the number
            int bit = (num >> i) & 1; // RightShiift
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i = 31; i >= 0; i--) {
            //get the SET-BIT of the number
            int bit = (num >> i) & 1; // RightShift
            // check Node have opposite of Bit i.e for 
            // '0' is '1' and for '1' is '0' present
            if(node->containsKey(1-bit)) {
                // if it contains bit then make its Opposite
                maxNum = (maxNum | (1 << i)); // LeftShift
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }

        return maxNum;
    }

};


int maximumXor(vector<int> A) {
    // Write your code here.
    Trie* obj = new Trie();
    for(auto &it1: A) {
        obj->insert(it1);
    }

    int maxAns = 0;

    for(auto &it2 : A) {
        maxAns = max(maxAns, obj->getMax(it2));
    }

    return maxAns;
}



*/




#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[2];

    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }

};



class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

public:
    void insert(int num) {
        Node* node = root;

        //In traversing Bit we goes from Right to Left
        for(int i = 31; i >= 0; i--) {
            // get Set-Bit
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;

        //In traversing Bit we goes from Left to Right
        for(int i=31; i >= 0; i--) {
            // get Set-Bit
            int bit = (num >> i) & 1;

            // check Node have opposite of Bit i.e for 
            // '0' is '1' and for '1' is '0' present
            if(node->containsKey(1 - bit)) {
                // if it contains bit then make its Opposite
                maxNum = (maxNum | (1 << i));
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};



// Function to find the maximum XOR value between two sets of numbers
int maxXOR(int n, int m, vector<int>& arr1, vector<int>& arr2) {
    //Create a Trie Object
    Trie* obj = new Trie();

    // Insert each number from the first set into the Trie
    for(auto &it1 : arr1) {
        obj->insert(it1);
    }

    int maxXORR = 0;

    // Iterate through each number in the second set
    for(auto &it2 : arr2) {
        // Update the maximum XOR value with the result from the Trie
        maxXORR = max(maxXORR, obj->getMax(it2));
    }

    return maxXORR;// Return the maximum XOR value
}




// Function to print the Input Arrays
void printArr(vector<int> arr){
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
}



int main() {
    vector<int> arr1 = {3, 10, 5, 25, 2};
    vector<int> arr2 = {8, 1, 2, 12, 7};
    int n = arr1.size();
    int m = arr2.size();
    
    cout << "Arr1: ";
    printArr(arr1);
    cout << "Arr2: ";
    printArr(arr2);
    

    int result = maxXOR(n, m, arr1, arr2);
    cout << "Maximum XOR value: " << result << endl;

    return 0;
}
