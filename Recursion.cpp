#include <iostream>
#include <string>
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

void rev(string str , int i){
    if(i == str.length()){
        return;
    }
    rev(str , i+1);
    cout << str[i];

}

void reverseString(){
    string str = "hello";
    rev(str , 0);
}

string replace(string str , int i){
    if(i == (str.length() - 1)){
        return str;
    }

    if(str[i] == 'p' && str[i+1] == 'i'){
        str[i] = '3';
        str[i+1] = '.';
        str.insert(i+2 , "14");
    }

    return replace(str , i+1);
}
void replacePi(){
    string str = "pipipipipipipipi";
    cout << replace(str , 0);
}

void hanoi(int n , char src , char dest , char help){
    if(n==1){
        cout << "Moving From "<<src<<" to "<<dest << endl;
        return;
    }
    // Move n-1 from src to helper
    hanoi(n-1 , src , help , dest);
    //move n drom src to dest
    cout <<"Moving From "<<src<<" to "<<dest << endl;
    //Move n-1 back from helper to dest
    hanoi(n-1 , help , dest , src);
}

string rmvDuplicates(string str , char key){
    if(str.length() == 1){
        return str;
    }
    for(int i = 1 ; i < str.length() ; i++){
        if(str[i] == key){
            str.erase(i , 1);
            i--;
        }
    }
    string join = str[0] + rmvDuplicates(str.substr(1 , str.length()-1) , str[1]);
    return join;
}

int main(){
    string output = rmvDuplicates("aaaabccccdefeee" , 'a');
    cout << output;
    return 0;
}