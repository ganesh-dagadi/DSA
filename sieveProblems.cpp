#include <iostream>
using namespace std;
int prime(int n){
    int arr[n - 2];
    for(int i = 0 ; i <= n-2; i++){
        arr[i] = i+2;
    }
    
    for(int i = 2 ; i*i <= n ; i++){
        int currIndex = i*i;
        while(currIndex <= n){
            arr[currIndex - 2] = 0;
            currIndex += i;
        }
    }

    for(int i = 0 ; i <= n - 2 ; i++){
        if(arr[i] != 0){
            cout << arr[i] << endl;
        }
    }
}

int main(){
    prime(100);
    return 0;
}