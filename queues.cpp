#include <iostream>
#define N 10

using namespace std;
class queue{
    int arr[N];
    int front = -1;
    int back = -1;
    public:
    queue(){
        cout << "Initialized queue" << endl;    
    }

    void push(int ele){
        if(back == N-1){
            cout << "Queue is full" << endl;
            return;
        }

        back++;
        arr[back] = ele;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || (front > back)){
            cout << "No element to pop" << endl;
            return;
        }

        front++;
    }

    int peek(){
        if(front == -1 || (front > back)){
            cout << "No element to peek" << endl;
            return - 1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || (front > back)){
            cout << "Is empty" << endl;
            return 1;
        }

        return 0;
    }
};

//LLqueue bez of limitation of arr (takes unnecessary space during initialization)

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class llqueue{
    node* front;
    node* back;
    public:
    llqueue(){
        front = NULL;
        back = NULL;
    }

    void push(int val){
        node* n = new node(val);
        if(front == NULL){
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
        }
        node* toDel = front;
        front = front->next;
        delete toDel;
    }

    int peek(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty(){
        if(front == NULL){
            return 1;
        }
        return 0;
    }
};
int main(){
    llqueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.isEmpty();
    return 0;
}