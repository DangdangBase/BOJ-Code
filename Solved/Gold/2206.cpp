#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, ret;
string tmp;

int board[1010][1010];
int visited[1010][1010][2];
queue<pair<P, int>> q;

int action[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> tmp;
        for(int j=0; j<M; j++){
            board[i][j] = tmp[j] - '0';
        }
    }

    visited[0][0][0] = 1;
    visited[0][0][1] = 1;
    q.push({{0, 0}, 1});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cur_x = cur.first.first, cur_y = cur.first.second;

        if(cur_x==M-1 && cur_y==N-1){
            cout << visited[N-1][M-1][cur.second];
            return 0;
        };

        for(int i=0; i<4; i++){
            int next_x = cur_x+action[i][0], next_y = cur_y+action[i][1];

            if(next_x<0 || next_x>=M || next_y<0 || next_y>=N) continue;
            
            if(board[next_y][next_x] && cur.second){
                visited[next_y][next_x][0] = visited[cur_y][cur_x][1]+1;
                q.push({{next_x, next_y}, 0});
            }
            else if(!visited[next_y][next_x][cur.second] && !board[next_y][next_x]){
                visited[next_y][next_x][cur.second] = visited[cur_y][cur_x][cur.second]+1;
                q.push({{next_x, next_y}, cur.second});
            }
        }
    }

    cout << -1;
    return 0;
}