/*(Linear Search_Coding Ninja)-> https://www.naukri.com/code360/problems/linear-search_6922070?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&count=25&page=1&search=&sort_entity=order&sort_order=ASC

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i=0; i<n; i++){
        if(arr[i] == num) {
            return i;
        }
    }
    return -1;
}


*/