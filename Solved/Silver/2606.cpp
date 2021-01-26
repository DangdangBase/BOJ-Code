#include <bits/stdc++.h>
using namespace std;

int N, M;
int u, v;
vector<int> graph[110];
bool visited[110];

int dfs(int cur){
    visited[cur] = true;

    int ret = 1;
    for(int next: graph[cur]){
        if(!visited[next]){
            ret += dfs(next);
        }
    }
    
    return ret;
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

    cout << dfs(1) - 1;

    return 0;
}