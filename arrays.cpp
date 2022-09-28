#include <iostream>
using namespace std;


void stringPalindrome(){
    int n;
    cin >> n;
    char arr[n+1];
    
    // Input into arr
    cout << "Enter your word" <<endl;
    cin >> arr;
    bool isPalindrome = 1;
    for(int i = 0 ; i < n; i++){
        if(arr[i] != arr[n-1-i]){
            isPalindrome = 0;
        }
    }

    cout << arr[4] << endl;
    if(isPalindrome){
        cout << "Palindrome" << endl;
    }else{
        cout << "Not" << endl;
    }
    return;
}

void longestInSentence(){
    int n;
    cin >> n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr , n);
    cin.ignore();

    int i= 0;
    int curLen = 0;
    int maxLen = 0;
    while(1){
        if(arr[i] == ' ' || arr[i] == '\0'){
            if(curLen > maxLen){
                maxLen = curLen;
            }
            curLen = 0;
        }else{
            curLen++;
        }

        if(arr[i] == '\0'){
            break;
        }
        i++;
    }

    cout << maxLen <<endl;
}

int main(){
    longestInSentence();
    return 0;
}
