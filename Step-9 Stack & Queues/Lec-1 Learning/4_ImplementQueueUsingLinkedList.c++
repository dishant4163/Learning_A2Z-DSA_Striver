// Implement Queue Using LinkedList


/* Implement Queue Using LL -> (  https://shorturl.at/KrF6k  )


void Queue::push(int x) {
    // Write Your Code Here
    Node* temp = new Node(x);
    if(front == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::pop() {
    // Write Your Code Here
    if(front == NULL) return -1;

    Node* temp = front;
    front = front->next;
    int popped = temp->data;
    delete(temp);
    return popped;
}

*/


#include<bits/stdc++.h> 
using namespace std;


// SOln -> (  https://shorturl.at/vAJkP  )
class QueueNode {
    public:
    int val;
    QueueNode* next;
    QueueNode(int data) {
        val = data;
        next = nullptr;
    }
};

QueueNode *Front = nullptr, *Rare = nullptr;

class Queue {
    public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};

// Empty/isempty
bool Queue :: Empty() {
    return Front == nullptr;
}

// Peek
int Queue :: Peek() {
    if(Empty()) {
        cout << "Queue is Empty" <<endl; 
    } else {
        return Front->val;
    }
}


// Enqueue / push
void Queue :: Enqueue(int value) {
    QueueNode *Temp = new QueueNode(value);
    if(Temp == nullptr) cout << "Queue is Full" <<endl;
    else {
        if (Front == nullptr) {
            Front = Temp;
            Rare = Temp;
        } else {
            Rare->next = Temp;
            Rare = Temp;
        }
        cout << value << " Inserted into Queue" <<endl;
        size++;
    }
}

// Dequeue /pop
void Queue :: Dequeue() {
    if (Front == nullptr) cout << "Queue is Empty" <<endl;
    else {
        cout << Front->val <<" Removed from Queue"<<endl;
        QueueNode *Temp = Front;
        Front = Front->next;
        delete(Temp);
        size--;
    }
}





int main() {

    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;


    return 0;
}
