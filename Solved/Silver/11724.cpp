#include <bits/stdc++.h>
using namespace std;

int N, M;
int u, v, cnt;

vector<int> graph[1010];
bool visited[1010];



void dfs(int cur){
    visited[cur] = true;

    for(int next: graph[cur]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}