#include <bits/stdc++.h>
using namespace std;

int T, I;
int cur_x, cur_y;
int goal_x, goal_y;

int visited[310][310];
struct tile {
    int x, y, cnt;
};
queue<tile> q;
int moves[8][2] = 
{
    {1,2}, {1,-2}, {-1,2}, {-1,-2},
    {2,1}, {2,-1}, {-2,1}, {-2,-1}
};

void bfs(){
    memset(visited, 0, sizeof(visited));
    visited[cur_x][cur_y] = 1;
    q.push({cur_x, cur_y, 0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        if (cur.x==goal_x && cur.y==goal_y) {
            cout << cur.cnt << "\n";
            break;
        } else if (cur.x>=I || cur.x<0 || cur.y>=I || cur.y<0){
            continue;
        }

        for(auto cur_move: moves){
            int next_x=cur.x+cur_move[0], next_y=cur.y+cur_move[1];
            if (next_x>=I || next_x<0 || next_y>=I || next_y<0){
                continue;
            }

            if(!visited[next_x][next_y]){
                visited[next_x][next_y] = 1;
                q.push({next_x, next_y, cur.cnt+1});
            }
        }
    }

    q = queue<tile>();
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    while(T--){
        cin >> I;
        cin >> cur_x >> cur_y;
        cin >> goal_x >> goal_y;
        
        bfs();
    }

    return 0;
}