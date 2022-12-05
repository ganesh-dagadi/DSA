#include <iostream>
using namespace std;
//count number of ones in a number
int numOnes(int n){
    int count = 0;
    int pos = 0;
    while(n){
        if(n&(1 << pos)){
            count++;
            //set pos to 0
            n = n & ~(1 << pos);
        }
        pos++;
    }
    return count;
}

int findUnique(int arr[] , int n){
   int xorSum = 0;
   for(int i = 0 ; i < n ; i++){
    xorSum = xorSum^arr[i];
   }
   return xorSum; 
}
int main(){
    int arr[5] = {2 , 4 , 3 , 4, 2};
    cout << findUnique(arr , 5) << endl;
    return 0;
}