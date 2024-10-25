// Implement Stack using single Queue


/* Implement Stack using Queue  Coding Ninjas-> (  https://tinyurl.com/3e59hawv  )

class Stack {
	// Define the data members.
    queue<int> q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    // *--------- Public Functions of Stack ---------* //

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.size() == 0 ? true : false;
    }

    void push(int element) {
        // Implement the push() function.
        int size = q.size();
        q.push(element);
        for(int i=1; i <= size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()) return -1;
        int element = q.front();
        q.pop();
        return element;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        return q.front();
    }
};

*/



#include<bits/stdc++.h>
using namespace std;


/* Soln (Stack using Queue)
  Intuition: As we know stack follows last in first out, which means we get the most recently inserted element whenever we remove an element from the stack. But queue follows first in first out, it means we get that element which we inserted in the starting at each deletion, it means if we want to use the queue like a stack we have to arrange elements in the queue such that we get the most recent element at each deletion.


   Approach:
 # Take a single queue.
 # push(x): Push the element in the queue.
 # Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
 # pop(): remove the element from the queue.
 # top(): show the element at the top of the queue.
 # size(): size of the current queue.
Repeat step3 at every insertion of the element.


   Complexity Analysis:-
 # Time Complexity: O(N)
 # Space Complexity: O(N)
*/
class Stack {
queue<int> q; //declaring Queue using inBuilt Q lib
    public:

    //PUSH
    void Push(int x) {
        int s = q.size();
        q.push(x); //as Q is declareing we using push & all operation of Q
        for(int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    //POP
    int Pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    //TOP
    int Top() {
        return q.front();
    }

    //Size
    int Size() {
        return q.size();
    }

};




int main() {

    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout << "Top of the stack: " << s.Top() << endl;
    cout << "Size of the stack before removing element: " << s.Size() << endl;
    cout << "The deleted element is: " << s.Pop() << endl;
    cout << "Top of the stack after removing element: " << s.Top() << endl;
    cout << "Size of the stack after removing element: " << s.Size();




    return 0;
}


