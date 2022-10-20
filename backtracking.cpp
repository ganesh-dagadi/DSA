#include <iostream>
#include <vector>
using namespace std;



//Rat in a maze
int numRows = 5;
int numCols = 5;
int input[5][5] = {{1 , 0 , 1 , 0 , 1},
                   {1 , 1 , 1 , 1 , 1},
                   {0 , 1 , 0 , 1 , 0},
                   {1 , 1 , 0 , 0 , 1},
                   {1 , 1 , 1 , 1 , 1}
                  };
bool movable(int input[5][5] , int row , int col){
    if(input[row][col] == 0 || row > numRows-1 || col > numCols-1){
        return false;
    }else{
        return true;
    }
}

bool move(int input[5][5] ,int row , int col , int targetRow , int targetCol){
    if(row == targetRow && col == targetCol){
        cout << "Hit" << endl;
        return true;
    }
    bool isFound = false;
    if(movable(input, row , col+1)){
        if(move(input, row , col+1 ,targetRow , targetCol)){
            isFound = true;
            cout <<"("<<row<<","<<col+1<<")";
        }
    }
    if(movable(input,row+1 , col)){
        if(move(input , row+1 ,col , targetRow , targetCol)){
            isFound = true;
            cout <<"("<<row+1<<","<<col<<")";
        }
    }
    return isFound;
}

// N queen problem
int n = 4;
bool placeable(int **arr,int row , int col){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(arr[i][j] == 1){
                if(i == row || j == col || (i - j) == (row - col) || (i + j) == (row + col)){
                    return false;
                }
            }
        }
    }
    return true;
}

bool nQueen(int **arr , int row){
    if(row >= n){
        return true;
    }

    for(int i = 0 ; i < n ; i++){
        if(placeable(arr , row , i)){
            arr[row][i] = 1;
            if(nQueen(arr , row+1)){
                return true;
            }
            arr[row][i] = 0;
        }
    }

    return false;
}



int main(){
    int **arr = new int*[n];
    for(int i = 0 ; i < n;i++){
        arr[i] = new int[n];
        for(int j = 0; j < n ; j++){
            arr[i][j] = 0;
        }
    }

    nQueen(arr , 0);

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout <<arr[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}