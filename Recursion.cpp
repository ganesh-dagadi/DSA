#include <iostream>
using namespace std;

bool sorted(int arr[] , int n){
    if(n == -1){
        return true;
    }

    if(arr[n] < arr[n+1] && sorted(arr , n-1)){
        return true;
    }else{
        return false;
    }
}
void checkSorted(){
    int arr[10] = {0,1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 ,9};
    cout << sorted(arr , 9) << endl;
}

int firstOcc(int arr[] , int n , int i , int key){
    if(i == n){
        return -1; // not found
    }

    if(arr[i] == key){
        return i;
    }

    return firstOcc(arr , n , i+1 , key);
}

int lastOcc(int arr[] , int n , int i , int key){
    if(i == n){
        return -1;
    }
    int restArray = lastOcc(arr , n , i+1 , key);
    if(restArray != -1){
        return restArray;
    }

    if(arr[i] == key){
        return i;
    }

    return -1;
}
void getfirstAndLastOccuranceInArray(){
    int arr[7] = {1 ,3 , 2 , 4 ,5 , 2 , 7};
    cout << lastOcc(arr , 7 , 0 , 2) <<endl;
}

int main(){
    getfirstAndLastOccuranceInArray();
    return 0;
}