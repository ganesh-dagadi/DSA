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

    //elements remaining

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

void quickSort(vector <int> &vect , int start , int end){
    if((end - start) <= 0){
        return;
    }
    int pivot = vect[end];
    int j = start;
    int i = start - 1;
    while(j < end){
        if(vect[j] < pivot){
            i+= 1;
            int temp = vect[i];
            vect[i] = vect[j];
            vect[j] = temp;
        }
        j++;
    }

    vect.insert(vect.begin() + i + 1 , pivot);
    vect.erase(vect.begin() + end+1);
    quickSort(vect , 0 , i);
    quickSort(vect , i+2 , end);
}
int main(){
    vector<int> vect = {1 , 44 , 2 , 2 , 2 , 4 , 6 , 1 , 0 , 77 , 7 , 8 , 8 , 44 };
    vector<int> output = {};
    quickSort(vect,0 , vect.size() - 1);
    for(int i = 0 ; i < vect.size() ; i++){
        cout << vect[i] << " , ";
    }
    return 0;
}