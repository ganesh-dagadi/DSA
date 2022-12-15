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

int evalPrefix(string str){
    stack st;
    for(int i = str.length() - 1 ; i >= 0 ; i--){
        if(str[i] >= '0' && str[i] <= '9'){
            st.push(str[i] - '0');
        }else{
            int op1 = st.top_ele();
            st.pop();
            int op2 = st.top_ele();
            st.pop();
            switch (str[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(op1 ^ op2);
                break;
            default:
                break;
            }
        }
    }
     return st.top_ele();
}


int evalPostfix(string str){
    stack st;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            st.push(str[i] - '0');
        }else{
            int op1 = st.top_ele();
            st.pop();
            int op2 = st.top_ele();
            st.pop();

            switch (str[i])
            {
            case '+':
                st.push(op2 + op1);
                break;
            case '-':
                st.push(op2 - op1);
                break;
            case '*':
                st.push(op2 * op1);
                break;
            case '/':
                st.push(op2 / op1);
                break;
            case '^':
                st.push(op2 ^ op1);
                break;
            default:
                break;
            }
        }
    }
    return st.top_ele();
}

class charStack{
    char arr[n];
    int top;

    public : 
    charStack(){
        top = -1;
    }

    void push(char ch){
        if(top == (n-1)){
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = ch;
    }

    void pop(){
        if(top == -1){
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    char top_ele(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return ' ';
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};
int preced(char c){
    if(c == '^'){
        return 3;
    }
    if(c == '*' || c== '/'){
        return 2;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}
string infixToPostfix(string str){
    charStack st;
    string res;

    for(int i =0 ; i < str.length() ; i++){
        if((str[i] >= 'a' && str[i] <= 'z') ||(str[i] >= 'A' && str[i] <= 'Z')){
            res += str[i];
        }else if(str[i] == '('){
            st.push(str[i]);
        }else if(str[i] == ')'){
            while(!st.empty() && st.top_ele() != '('){
                res += st.top_ele();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }else{
            while(!st.empty() && (preced(str[i]) < preced(st.top_ele()))){
                res += st.top_ele();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()){
        res += st.top_ele();
        st.pop();
    }

    return res;
}
int main(){
    cout << infixToPostfix("(a-b/c)*(a/k-l)");
    return 0;
}