#include <iostream>
#include <deque>
#include <vector>
using namespace std;
void slidingWindow(){
    int k = 2;
    vector<int> output;
    int arr[4] = {8 , 7 , 6 , 9};
    deque<int> dq;
    int left = 0;
    int right = k-1;
    for(int i = 0 ; i<4 ; i++){
        while(arr[i] > dq.back() && !dq.empty()){
            dq.pop_back();
        }
        dq.push_back(arr[i]);
        if(i == right){
            output.push_back(dq.front());
            if(arr[left] == dq.front()){
                dq.pop_front();
            }
            left++;
            right++;
        }
    }

    for(int i = 0 ; i < output.size() ; i++){
        cout << output[i] << endl;
    }
}
int main(){
    
    slidingWindow();
    return 0;    
}