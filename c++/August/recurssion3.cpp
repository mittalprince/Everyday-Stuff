#include<iostream>

using namespace std;
typedef long long ll;

const ll D = 8;

bool canPlace(ll board[D][D], ll n, ll r, ll c){

    return  r>0 && r<n &&
            c>0 && c<n &&
            board[r][c] == 0;
}

bool solveKnighMove(ll board[D][D], ll n, ll cur_move, ll curRow, ll curCol){

    if(cur_move == (D*D)){
        return true;
    }

    ll rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    ll colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1}

    for(ll curDir=0; curDir<8; curDir++){
        ll nextRow = curRow + rowDir[curDir];
        ll nextCol = curCol + colDir[curDir];
        if(canPlace(board, n, nextRow, nextCol) == true){
            board[nextRow][nextCol] = cur_move+1;
            bool isSuccessful = solveKnightMove(board, n, cur_move, nextRow, nextCol);
            if(isSuccessful == true){
                return true;
            }
            board[nextRow][nextCol] = 0;
        }
    }
}

void printBoard(ll board[D][D], ll n){

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<board[i][j]<<" s";
        }
        cout<<endl;
    }
}
int main(){

    ll board[D][D] = {0};
    int n;
    cin>>n;
    board[0][0]=1;
    bool ans = solveKnighMove(board, n, 2, 0, 0);
    if(ans == true){
        printBoard(board, n);
    }
    else{
        cout<<"Sorry no solution"<<endl;
    }
    return 0;
}