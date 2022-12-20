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

//stack for queue
class stack{
    int* arr;
    int top;

    public : 
    stack(){
        arr = new int[N];
        top = -1;
    }

    void push(int num){
        if(top == (N-1)){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = num;
    }

    void pop(){
        if(top == -1){
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int top_ele(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }

    void printStack(){
        int i = 0;
        while(i <= top){
            cout << arr[i] << endl;
            i++;
        }
    }
};

class stackQueue{
    stack s1 ; 
    stack s2;

    public:
        void push(int val){
            s1.push(val);
        }

        void pop(){
            if(s1.empty() && s2.empty()){
                cout << "Queue is empty" << endl;
                return;
            }

            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top_ele());
                    s1.pop();
                }
            }
            s2.pop();            
        }

        int peek(){
            if(s1.empty() && s2.empty()){
                cout << "Queue is empty" << endl;
                return -1;
            }

            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top_ele());
                    s1.pop();
                }
            }

            return s2.top_ele();
        }
};
int main(){
    stackQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    // cout << q.isEmpty();
    return 0;
}