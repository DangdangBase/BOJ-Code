#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int T;
int board[11][11];
bool checkTable[11];

void resetCheckTable(){
    memset(checkTable, 0, 11*sizeof(int));
}

bool isSolvable(){
    for(int i=1; i<=9; i++){
        resetCheckTable();
        for(int j=1; j<=9; j++){
            int curVal = board[i][j];
            if(curVal != 0){
                if(checkTable[curVal]) return false;
                else checkTable[curVal] = true;
            }
        }
    }

    for(int j=1; j<=9; j++){
        resetCheckTable();
        for(int i=1; i<=9; i++){
            int curVal = board[i][j];
            if(curVal != 0){
                if(checkTable[curVal]) return false;
                else checkTable[curVal] = true;
            }
        }
    }

    for(int bi=0; bi<3; bi++){
        for(int bj=0; bj<3; bj++){
            resetCheckTable();
            for(int i=1; i<=3; i++){
                for(int j=1; j<=3; j++){
                    int curVal = board[bi*3+i][bj*3+j];
                    if(curVal != 0){
                        if(checkTable[curVal]) return false;
                        else checkTable[curVal] = true;
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for(int t=1; t<=T; t++){
        for(int i=1; i<=9; i++){
            for(int j=1; j<=9; j++) cin >> board[i][j];
        }

        printf("Case %d: %s\n", t, isSolvable() ? "CORRECT" : "INCORRECT");
    }
    
    return 0;
}