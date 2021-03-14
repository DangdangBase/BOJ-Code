#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

struct water{
    int loc, date;
};

int action[4][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1
};

int R, C, prev_date = 0;
vector<int> swan;
string lake[1510];

int parent[2250010];
bool visited[2250010];

deque<water> dq;


int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    parent[b] = a;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            int cur = i*C + j;
            parent[cur] = cur;
        }
    }

    for(int i=0; i<R; i++){
        cin >> lake[i];

        for(int j=0; j<C; j++){
            int cur_loc = i*C + j;

            if(lake[i][j] != 'X'){
                dq.push_back({cur_loc, 0});
                visited[cur_loc] = true;

                if(i>0 && lake[i-1][j] != 'X') merge(cur_loc, cur_loc-C);
                if(j>0 && lake[i][j-1] != 'X') merge(cur_loc, cur_loc-1);

                if(lake[i][j] == 'L'){
                    swan.push_back(cur_loc);
                    lake[i][j] = '.';
                }
            }
        }
    }

    while(!dq.empty()){
        water cur = dq.front(); dq.pop_front();

        if(prev_date != cur.date){
            prev_date = cur.date;
            
            if(find(swan[0]) == find(swan[1])){
                cout << cur.date;
                return 0;
            }
        }

        
        int cur_loc = cur.loc;
        for(int i=0; i<4; i++){
            int next_r = cur_loc/C+action[i][0], next_c = cur_loc%C+action[i][1];
            if(next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;

            int next_loc = next_r*C + next_c;
            merge(cur_loc, next_loc);


            if(lake[next_r][next_c] == 'X'){
                dq.push_back({next_loc, cur.date+1});
                lake[next_r][next_c] = '.';
                visited[next_loc] = true;

                for(int j=0; j<4; j++){
                    int r = next_r+action[i][0], c = next_c+action[i][1];
                    if(r < 0 || r >= R || c < 0 || c >= C) continue;
                    if(lake[r][c] == '.'){
                        merge(next_loc, r*C+c);
                    }
                }

            } else if(lake[next_r][next_c] == '.' && !visited[next_loc]){
                visited[next_loc] = true;
                dq.push_front({next_loc, cur.date});
            }
        }
    }

    return 0;
}