// Implement Queue using Stack

/* Implement Queue using Stack_Coding Ninjas -> (  https://tinyurl.com/mwwcad9x  )


class Queue {
    // Define the data members(if any) here.
    stack<int>s1,s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
         if(s2.empty()) {
           while(!s1.empty()) {
               s2.push(s1.top());
               s1.pop();
           }
       }

       if(!s2.empty()) {
       int temp = s2.top();
       s2.pop();
       return temp;
       }
       return -1;
    }

    int peek() {
        // Implement the peek() function here.
        if(s2.empty()) {
           while(!s1.empty()) {
               s2.push(s1.top());
               s1.pop();
           }
       }
       if(!s2.empty()) {
       return s2.top();
       }
       return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty()&&s2.empty();
    }
};


*/

#include <bits/stdc++.h>
using namespace std;

// Check for detailed approach soln-> (https://shorturl.at/Lx0NM)

// Approach-1(Using two Stacks where push operation is O(N))
struct Queue
{
    stack<int> stIn, stO;

    // Push elements in queue
    void Push(int x)
    {
        // Pop out all elements from the stack input
        while (!stIn.empty())
        {
            stO.push(stIn.top());
            stIn.pop();
        }

        // Insert the desired element in the stack input
        cout << "The element pushed is " << x << endl;
        stIn.push(x);
        // Pop out elements from the stack output and push them into the stack input
        while (!stO.empty())
        {
            stIn.push(stO.top());
            stO.pop();
        }
    }

    // Pop Function
    int Pop()
    {
        if (stIn.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = stIn.top();
        stIn.pop();
        return val;
    }

    // Top Function
    int Top()
    {
        if (stIn.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return stIn.top();
    }

    // Size
    int Size()
    {
        return stIn.size();
    }
};

// Approach-2(Using two Stacks where push operation is O(1))
class MyQueue
{
public:
    stack<int> inS, outS;
    MyQueue()
    {
    }

    // Push Function
    void push(int x)
    {
        cout << "The element pushed is " << x << endl;
        inS.push(x);
    }

    // POP function
    int pop()
    {
        if (outS.empty())
            while (inS.size())
            {
                outS.push(inS.top());
                inS.pop();
            }
        int x = outS.top();
        outS.pop();
        return x;
    }

    // TOP function
    int top()
    {
        if (outS.empty())
            while (inS.size())
            {
                outS.push(inS.top());
                inS.pop();
            }
        return outS.top();
    }

    // Size
    int size()
    {
        return (outS.size() + inS.size());
    }
};

int main()
{

    // Approach-1(Using two Stacks where push operation is O(N))
    Queue Q;
    Q.Push(3);
    Q.Push(4);
    cout << "The element poped is " << Q.Pop() << endl;
    Q.Push(6);
    cout << "The top of the queue is " << Q.Top() << endl;
    cout << "The size of the queue is " << Q.Size() << endl;

    cout << endl;

    // Approach-2(Using two Stacks where push operation is O(1))
    MyQueue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.top() << endl;
    cout << "The size of the queue is " << q.size() << endl;

    return 0;
}
