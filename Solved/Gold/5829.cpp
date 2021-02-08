#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, K;
int l, r;
char c;
bool action[510];

P graph[1010];
int visited[1010];
int next_port[1010];

int cruise(int s){
    int cur_port = s;

    for(int i=0; i<M; i++){
        if(action[i]){
            cur_port = graph[cur_port].first;
        } else {
            cur_port = graph[cur_port].second;
        }
    }

    return cur_port;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        cin >> l >> r;
        graph[i] = {l, r};
    }
    for(int i=0; i<M; i++){
        cin >> c;
        action[i] = (c=='L');
    }

    int ret, start = 0, period = -1;

    next_port[0] = 1;
    memset(visited, -1, sizeof(visited));
    visited[0] = 0;

    for(int i=1; i<=K; i++){
        int tmp = cruise(next_port[i-1]);
        next_port[i] = tmp;

        if(visited[tmp] != -1){
            start = visited[tmp];
            period = i - start;
            break;
        } else {
            visited[tmp] = i;
        }
    }

    if(period == -1){
        cout << next_port[K];
    } else {
        int idx = (K-start)%period + start;
        cout << next_port[idx];
    }

    return 0;
}