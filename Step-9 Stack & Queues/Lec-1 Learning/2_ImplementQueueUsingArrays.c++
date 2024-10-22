// Implement Queue using Arrays





#include<bits/stdc++.h>
using namespace std;

//
class Queue {
    int *ar;
    int maxSize, currSize, start, end;

    public:
    Queue() {
        ar = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        (* this).maxSize = maxSize;
        ar = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }


//Push function, not return type
void push(int x) {
    if(currSize == maxSize) {
        cout << "Queue is full\nExiting..." << endl;
        exit(1);
    }
    if(end == -1) {
        start = 0;
        end = 0;
    } else 
        end = (end + 1) % maxSize;
    ar[end] = x;
    cout << "The element pushed is " << x << endl;
    currSize++;
}

//Pop function, & this will be return type
int pop() {
    if(start == -1) {
        cout << "Queue Empty\nExiting..." << endl;
    }

    int popped = ar[start];

    if(currSize == 1) {
        start = -1;
        end = -1;
    }
    else
        start = (start + 1) % maxSize;
    currSize--;
    return popped;
}

//Top function, & this will be return type
int top() {
    if(start == -1) {
        cout << "Queue is Empty" << endl;
        exit(1);
    }
    return ar[start];
}

//Size function, & this will be return type
int size() {
    return currSize;
}

};






int main() {


    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;



    return 0;
}

