#include <iostream>
#include <vector>
using namespace std;



vector<int> mergeSort(vector<int> vect){
    if(vect.size() == 1){
        return vect;
    }
    int mid = vect.size()/2;
    vector<int> left = {vect.begin() , vect.begin() + mid};
    vector<int> right= {vect.begin() + mid , vect.end()};
    left = mergeSort(left);
    right = mergeSort(right);

    //merging
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < left.size() && j < right.size()){
        if(left[i] <= right[j]){
            vect[k] = left[i];
            i++;
            k++;
            continue;
        }

        if(right[j] <= left[i]){
            vect[k] = right[j];
            j++;
            k++;
            continue;
        }
    }

    //Last element remaining

    while(i < left.size()){
        vect[k] = left[i];
        i++;
        k++;
    }

    while(j < right.size()){
        vect[k] = right[j];
        j++;
        k++;
    }

    return vect;
}

int main(){
    vector<int> vect = {9 , 6 , 9 , 8 , 9 , 6,5 , 23 , 5, 7 , 89, 5, 4};
    vect = mergeSort(vect);
    for(int i = 0 ; i < vect.size() ; i++){
        cout << vect[i] << " , ";
    }
    return 0;
}