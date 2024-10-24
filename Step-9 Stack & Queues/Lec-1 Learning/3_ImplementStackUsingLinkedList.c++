// Implement Stack using Linkedlist



/* Implement stack using Linkedlist Coding Ninjas -> (  https://tinyurl.com/578w84v4  )


class Stack {
    //Write your code here
    Node* top = NULL;
    int size = 0;

public:
    Stack()
    {
        //Write your code here
    }

    int getSize() {
        //Write your code here
        return size;
    }

    bool isEmpty() {
        //Write your code here
        return size == 0 ? true : false;
    }

    void push(int data) {
        //Write your code here
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        //Write your code here
        if(size == 0) return;
        Node* temp = top;
        top = top->next;
        delete(temp);
        size--;
    }

    int getTop() {
        //Write your code here
        if(top == NULL) return -1;
        else return top->data;
    }
};

*/





#include<bits/stdc++.h>
using namespace std;

/* //Approach for Implementing Stack using LL

-> https://shorturl.at/DjJVu  

*/

struct stackNode {
    int data;
    stackNode * next;
    int size;
    stackNode(int d) {
    data = d;
    next = NULL;
    }
};

struct Stack {
    stackNode* top;
    int size;
    Stack() {
        top = NULL;
        size = 0;
    }

//Push function (pushing an element at the top of a stack)
void stackPush(int data) {
    stackNode* temp = new stackNode(data);
    temp->next = top;
    top = temp;
    size++;
}

//Pop function (removing element from the top of a stack)
int stackPop() {
    if(top == NULL) return -1;

    int topData = top->data;
    stackNode* temp = top;
    top = top->next;
    delete(temp);
    size--;

    return topData;
}

//Size function (returns the size of the stack)
int stackSize() {
    return size;
}

// isEmpty (check is stack is empty or not)
bool stackIsEmpty() {
    return top == NULL;
}

//Peek function
int stackPeek() {
    if(top == NULL) return -1;
    return top->data;
}


void printStack() {
    stackNode* current = top;
    while (current != NULL) {
        cout << current->data <<" ";
        current = current->next;
    }
}


};









int main() {

    Stack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
    cout << "stack's top element: " << s.stackPeek() << "\n";




    return 0;
}


