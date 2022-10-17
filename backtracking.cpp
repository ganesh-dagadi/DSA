#include <iostream>
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
int main(){
    move(input , 0 , 0 , 4 , 4);
    return 0;
}