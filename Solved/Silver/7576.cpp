#include <bits/stdc++.h>
using namespace std;

int N, M;
int tomatos[1010][1010];
int ret;

struct tomato_state{int y, x, t;};
queue<tomato_state> q;
int actions[4][2] = 
{
    0, 1,
    0, -1,
    1, 0,
    -1, 0
};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomatos[i][j];

            if(tomatos[i][j] == 1){
                q.push({i, j, 0});
            }
        }
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        ret = cur.t+1;

        for(auto action: actions){
            int next_y = cur.y + action[0], next_x = cur.x + action[1];

            if(next_y>=N || next_y<0 || next_x>=M || next_x<0){
                continue;
            }
            if(tomatos[next_y][next_x] == 0){
                tomatos[next_y][next_x] = 1;
                q.push({next_y, next_x, ret});
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tomatos[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << ret-1;
    return 0;
}