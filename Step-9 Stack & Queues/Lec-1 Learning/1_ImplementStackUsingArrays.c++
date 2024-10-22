// Implement Stack using Arrays


/* Stack Implementation Using Array (Coding Ninjas ->  https://shorturl.at/kTXLk )


// Stack class.
class Stack {
    
public:

    int Size;
    int *st;
    int Top;
    
    Stack(int capacity) {
        // Write your code here.
        Size = capacity;
        st = new int[Size];
        Top = -1;
    }

    void push(int num) {
        // Write your code here.
        if(Top < Size - 1) {
            Top++;
            st[Top] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(Top == -1) return -1;
        else {
            int num = st[Top];
            Top--;
            return num;
        }
    }
    
    int top() {
        // Write your code here.
        if(Top < 0) return -1;
        else return st[Top];
    }
    
    int isEmpty() {
        // Write your code here.
        if(Top == -1) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(Top == Size-1) return 1;
        else return 0;
    }
    
};



*/


/*//Stack is a data structure that follows, Last In First Out(LIFO) rule.

   Explanation: 

 #  push(): Insert the element in the stack.

 #  pop(): Remove and return the topmost element of the stack.

 #  top(): Return the topmost element of the stack

 #  size(): Return the number of remaining elements in the stack.

*/



#include<bits/stdc++.h>
using namespace std;


/* Solution

  Intuition: As we know stack works on the principle of last in first out, so we have to put elements in an array such that it keeps track of the most recently inserted element. Hence we can think of using a Top variable which will help in keeping track of recent elements inserted in the array.

  Approach:

 #  Declare an array of particular size.
 #  Define a variable “Top” and initialize it as -1.
 #  push(x): insert element is the array by increasing top by one.
 #  pop(): check whether top is not equal to -1 if it is so, return top and decrease its value by one.
 #  size(): return top+1.


   Complexity Analysis:-

 #  Time Complexity: O(N)

 #  Space Complexity: O(N)

*/
class Stack1{
    int size;
    int *st;
    int top;

    public:
    Stack1() {
        top = -1;
        size = 1000;
        st = new int[size];
    }

//Push function, not return type
    void push(int x) {
        if(top >= size - 1) {
            throw overflow_error("Stack Overflow");
        }
        top++;
        st[top] = x;
    }

//Pop function, & this will be return type
    int pop() {
        if(top < 0) {
            throw underflow_error("Stack UnderFlow");
        }
        int x = st[top];
        top--;
        return x;
    }

//Top function, & this will be return tyoe
    int Top() {
        if(top < 0) {
            throw underflow_error("Stack is Empty");
        }
        return st[top];
    }

//Size function, & this will be return type
    int Size() {
        return top + 1;
    }

};






/*//Soln-1.2 Stack class.
class Stack2 {

public:

    int Size;
    int *st;
    int Top;
    
    Stack2(int capacity) {
        // Write your code here.
        Size = capacity;
        st = new int[Size];
        Top = -1;
    }

    void push(int num) {
        // Write your code here.
        if(Top < Size - 1) {
            Top++;
            st[Top] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(Top == -1) return -1;
        else {
            int num = st[Top];
            Top--;
            return num;
        }
    }
    
    int top() {
        // Write your code here.
        if(Top < 0) return -1;
        else return st[Top];
    }
    
    int isEmpty() {
        // Write your code here.
        if(Top == -1) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(Top == Size-1) return 1;
        else return 0;
    }
    
};
*/





int main() {

// Soln-1
    Stack1 s; 
    s.push(6);
    s.push(3);
    s.push(7);

    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;

cout << endl << endl;




/*// Soln-1.2 

    // Create a stack with a capacity of 5
    Stack2 ss(5);

    // Push elements onto the stack
    ss.push(10);
    ss.push(20);
    ss.push(30);
    cout << "Top element after pushing 3 elements: " << ss.top() << endl;
    cout << "Is stack empty? " << (ss.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (ss.isFull() ? "Yes" : "No") << endl;

    // Push more elements
    ss.push(40);
    ss.push(50);
    ss.push(60); // This should not push since the stack is full

    // Display top element
    cout << "Top element after pushing 5 elements: " << ss.top() << endl;

    // Pop elements from the stack
    cout << "Popped element: " << ss.pop() << endl; // Should pop 50
    cout << "Top element after one pop: " << ss.top() << endl;

    cout << "Popped element: " << ss.pop() << endl; // Should pop 40
    cout << "Top element after two pops: " << ss.top() << endl;

    // Check if the stack is empty
    cout << "Is stack empty? " << (ss.isEmpty() ? "Yes" : "No") << endl;

    // Pop remaining elements
    while (!ss.isEmpty()) {
        cout << "Popped element: " << ss.pop() << endl;
    }

    // Final check on stack state
    cout << "Is stack empty? " << (ss.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element on empty stack: " << ss.top() << endl; // Should return -1

*/



    return 0;
}



