#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;

int T, N, M, K;
int X, Y;
int ret;

int board[55][55];
bool visited[55][55];
queue<P> q;

int action[4][2] = {
    1, 0,
    0, 1,
    -1, 0,
    0, -1
};


void bfs(int y, int x){
    ret++;

    q.push({x, y});
    visited[y][x] = true;

    while(!q.empty()){
        P cur = q.front(); q.pop();

        for(auto a: action){
            int next_x = cur.first+a[0], next_y = cur.second+a[1];

            if(!visited[next_y][next_x] && board[next_y][next_x]){
                visited[next_y][next_x] = true;
                q.push({next_x, next_y});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        ret = 0;
        memset(visited, 0, sizeof(visited));
        memset(board, 0, sizeof(board));

        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            cin >> X >> Y;
            board[Y][X] = 1;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(!board[i][j] || visited[i][j]) continue;

                bfs(i, j);
            }
        }

        cout << ret << "\n";

    }



    return 0;
}