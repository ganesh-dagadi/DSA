#include <iostream>
#include <string.h>
#define n 10
using namespace std;

class stack{
    int* arr;
    int top;

    public : 
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int num){
        if(top == (n-1)){
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

class strStack{
    string arr[n];
    int top;

    public : 
    strStack(){
        top = -1;
    }

    void push(string str){
        if(top == (n-1)){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = str;
    }

    void pop(){
        if(top == -1){
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    string top_ele(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return "";
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};
void reverseSentence(string str){
    strStack st;
    int start = 0 , count = 0;
    int i = 0;
    for(i ; i < str.length() ; i++){
        if(str[i] == ' ' || i == str.length() - 1){
            st.push(str.substr(start , count));
            count = 0;
            start = i+1;
        }
        count++;
    }

    while(!st.empty()){
        cout << st.top_ele() << " ";
        st.pop();
    }
}

void insertAtBottom(stack &st , int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int topEle = st.top_ele();
    st.pop();
    insertAtBottom(st , ele);
    st.push(topEle);
}
void reverse(stack &st){
    if(st.empty()){
        return;
    }
    int topEle = st.top_ele();
    st.pop();
    reverse(st);
    insertAtBottom(st , topEle);
}
int main(){
    stack st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(8);
    // st.printStack();
    cout << endl;
    //cout << st.top_ele() << endl;
    // reverse(st);
    //cout << st.top_ele() << endl;
    // st.printStack();
    string str = "Hello what is your name?";
    reverseSentence(str);
    return 0;
}