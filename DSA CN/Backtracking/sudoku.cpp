#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLocation(int grid[N][N], int &row, int &col){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool IsSafeInRow(int grid[N][N], int row, int num){
    for(int i = 0; i < N; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool IsSafeInColumn(int grid[N][N], int col, int num){
    for(int i = 0; i < N; i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool IsSafeInGrid(int grid[N][N], int row, int col, int num){

    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++){
            if(grid[i+rowFactor][j+colFactor] == num){
                return false;
            }
        }
    }
    return true;
}

bool IsSafe(int grid[N][N], int row, int col, int num){
    if(IsSafeInRow(grid, row, num) and IsSafeInColumn(grid, col, num) and IsSafeInGrid(grid, row, col, num)){
        return true;
    }
    return false;
}

bool solveSudoku(int grid[N][N]){
    int row, col;
    if(!findEmptyLocation(grid, row, col)){
        return true;
    }

    for(int i = 0; i < 10; i++){
        if(IsSafe(grid, row, col, i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[N][N];
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            grid[i][j] = s[j] - '0';
        }
    }

    solveSudoku(grid);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << grid[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}