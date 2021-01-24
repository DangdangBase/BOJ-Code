#include <bits/stdc++.h>
using namespace std;

int N;
int board[20];

int cnt;

bool can_queen(int len, int cur){
    for(int i=0; i<len; i++)
        if(board[i] == cur || board[i] == cur+(len-i) || board[i] == cur-(len-i)) return false;
    return true;
}

int backtrack(int n){
    if(n == N) return 1;

    int ret = 0;
    for(int i=0; i<N; i++){
        if(can_queen(n, i)){
            board[n] = i;
            ret += backtrack(n+1);
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    memset(board, -1, sizeof(board));
    cin >> N;
    cout << backtrack(0);

    return 0;
}