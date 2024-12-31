// Implementation of Heap + Insertion in Heap

#include<iostream>
#include<queue> // for using prioity Q
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    //making constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }


// Function to  insert in HEAp
    void insert(int val) {

        // insert at the end
        size = size + 1;
        int index = size;
        arr[index] = val;

        //take it to correct position
        while(index > 1) {
            int parent = index / 2;

            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;

        }
    }




//Function to delete root node from heap
    void delfromHeap() {
        if(size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        //Step-1 put last element into first index
        arr[1] = arr[size];

        //Step-2 Remove last element
        size--;

        //Step-3 Take root node to its correct position
        int i = 1;
        while(i < size) {
            int leftind = 2*i;
            int rightind = 2*i+1;

            if(leftind < size && arr[i] < arr[leftind]) {
                swap(arr[i], arr[leftind]);
                i = leftind;
            }
            else if(rightind < size && arr[i] < arr[rightind]) {
                swap(arr[i], arr[rightind]);
                i = rightind;
            }
            else return;
        }
    }


//Function to print Heap
    void print() {
    // from i=1 bcz at 0th index kuch nhi dala h usme
        for(int i=1; i <= size; i++) {
            cout << arr[i] <<" ";
        }
        cout << endl;
    }

};






//Function to Heapify
    void heapify(int ar[], int n, int ind) { //implementing for Max-Heap
        int largest = ind;
        int left = 2 * ind;
        int right = 2* ind + 1;

        if(left <= n && ar[largest] < ar[left]) {
            largest = left;
        }
        if(right <= n && ar[largest] < ar[right]) {
            largest = right;
        }

        if(largest != ind) {
            swap(ar[largest], ar[ind]);
            heapify(ar, n, largest);
        }

    }






//Function for doing Heap-Sort
    void heapSort(int Ar[], int m) {

        int Size = m;

        while(Size > 1) {
            // step:1 swap
            swap(Ar[1], Ar[Size]);
            Size--;

            //step-2 heapify
            heapify(Ar, Size, 1);
        }
    }






int main() {


    heap H;
    H.insert(50);
    H.insert(55);
    H.insert(53);
    H.insert(52);
    H.insert(54);
    H.print();

    H.delfromHeap();
    H.print();



 cout << endl << endl;



    //calling heapify algo function
    int v[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //heap creation done
    for(int i = n/2; i > 0; i--) {
        heapify(v, n, i);
    }

    cout << "Printing the heapify arr now "<< endl;
    for(int i=1; i <= n; i++) {
        cout << v[i] <<" ";
    }
    cout << endl;



 cout << endl << endl;



    // calling Function for heapSort
    heapSort(v, n);

    cout << "Printing the HeapSort array "<< endl;
    for(int i=1; i <= n; i++) {
        cout << v[i] <<" ";
    }
    cout << endl;


 cout << endl << endl << endl << endl;


cout << "Using Priority Queue here via STL ==> " <<endl;

//maxheap
priority_queue<int> pq;

pq.push(4);
pq.push(2);
pq.push(5);
pq.push(3);

cout << "element at top " << pq.top() <<endl;
pq.pop();
cout << "element at top " << pq.top() <<endl;
cout << "size of priority queue " << pq.size() <<endl;

if(pq.empty()) {
    cout << "PQ is empty" << endl;
} else {
    cout <<"PQ is not empty" <<endl;
}






cout << endl << endl << endl << endl;


cout << "Using Priority Queue for Declaring MIN Heap via STL  " <<endl;
//Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

minHeap.push(4);
minHeap.push(2);
minHeap.push(5);
minHeap.push(3);

cout << "element at top " << minHeap.top() <<endl;
minHeap.pop();
cout << "element at top " << minHeap.top() <<endl;
cout << "size of priority queue " << minHeap.size() <<endl;

if(minHeap.empty()) {
    cout << "PQ is empty" << endl;
} else {
    cout <<"PQ is not empty" <<endl;
}


    return 0;
}
