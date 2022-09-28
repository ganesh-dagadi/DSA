#include <iostream>
using namespace std;


void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Pointer
void swap_with_pointer(){
    int a = 2;
    int b = 4;
    swap(&a , &b);
    cout << a << " " << b;
}

int main(){
    cout << "Hello world" << endl;
    swap_with_pointer();
    return 0;
}
