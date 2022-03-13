#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

string ip;
int board[11][11];
vector<P> blank;

bool rowTable[10][10];
bool colTable[10][10];
bool blkTable[10][10];

int getBlkIdx(int i, int j){
    return 3*((i-1)/3) + (j-1)/3 + 1;
}

void updateCheckTable(int i, int j, int val, bool flag){
    rowTable[i][val] = flag;
    colTable[j][val] = flag;
    blkTable[getBlkIdx(i, j)][val] = flag;
}

bool isViolated(int i, int j, int val){
    return rowTable[i][val] || colTable[j][val] || blkTable[getBlkIdx(i, j)][val];
}

bool backtrack(int idx){
    if(idx == blank.size()) return true;

    for(int i=1; i<=9; i++){
        int row = blank[idx].first, col = blank[idx].second;
        if(isViolated(row, col, i)) continue;

        board[row][col] = i;
        updateCheckTable(row, col, i, true);

        if(backtrack(idx+1)) return true;

        board[row][col] = 0;
        updateCheckTable(row, col, i, false);
    }

    return false;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=1; i<=9; i++){
        cin >> ip;
        for(int j=1; j<=9; j++){
            board[i][j] = ip[j-1] - '0';
        }
    }

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(board[i][j] == 0){
                blank.push_back({i, j});
            } else {
                updateCheckTable(i, j, board[i][j], true);
            }
        }
    }

    backtrack(0);

    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cout << board[i][j];
        } cout << endl;
    }
    return 0;
}