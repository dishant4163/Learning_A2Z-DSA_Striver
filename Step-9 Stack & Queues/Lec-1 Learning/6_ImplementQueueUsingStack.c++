// Implement Queue using Stack



#include <bits/stdc++.h>
using namespace std;



// Check for detailed approach soln-> (https://shorturl.at/Lx0NM)


//Approach-1(Using two Stacks where push operation is O(N))
struct Queue {
    stack<int> stIn, stO;


    //Push elements in queue
    void Push(int x) {
        // Pop out all elements from the stack input
        while(!stIn.empty()) {
            stO.push(stIn.top());
            stIn.pop();
        }

// Insert the desired element in the stack input
        cout << "The element pushed is " << x << endl;
        stIn.push(x);
// Pop out elements from the stack output and push them into the stack input
        while(!stO.empty()) {
            stIn.push(stO.top());
            stO.pop();
        }
    }


    //Pop Function
    int Pop() {
        if(stIn.empty()){
            cout << "Stack is empty";
            exit(0);
        }
        int val = stIn.top();
        stIn.pop();
        return val;
    }


    //Top Function
    int Top() {
        if(stIn.empty()) {
            cout << "Stack is empty";
            exit(0);
        }
        return stIn.top();
    }


    //Size
    int Size() {
        return stIn.size();
    }

};








int main() {

//Approach-1(Using two Stacks where push operation is O(N))
    Queue Q;
    Q.Push(3);
    Q.Push(4);
    cout << "The element poped is " << Q.Pop() << endl;
    Q.Push(6);
    cout << "The top of the queue is " << Q.Top() << endl;
    cout << "The size of the queue is " << Q.Size() << endl;





    return 0;
}
