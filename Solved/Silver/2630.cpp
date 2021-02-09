#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N;
int board[130][130];
int cnt;

P operator + (P a, P b){
    return {a.first+b.first, a.second+b.second};
}

P solve(int x1, int y1, int x2, int y2){
    if(x1==x2 && y1==y2){
        return {board[y1][x1], !board[y1][x1]};
    }

    bool is_same_color = true;
    int cur = board[y1][x1];
    for(int i=y1; i<=y2; i++){
        for(int j=x1; j<=x2; j++){
            if(cur != board[i][j]){
                is_same_color = false;
                break;
            }
        }

        if(!is_same_color){
            break;
        }
    }

    if(!is_same_color){
        int mid_x = (x1+x2)/2, mid_y = (y1+y2)/2;
        return solve(x1, y1, mid_x, mid_y) + solve(mid_x+1, y1, x2, mid_y) + solve(x1, mid_y+1, mid_x, y2) + solve(mid_x+1, mid_y+1, x2, y2);
    } else {
        return {cur, !cur};
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }

    P tmp = solve(1, 1, N, N);
    cout << tmp.second << endl;
    cout << tmp.first << endl;

    return 0;
}