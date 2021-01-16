#include <bits/stdc++.h>
using namespace std;

int N;
int a, b, len;
int max_v, max_len;

int visited[10010];
vector<pair<int, int>> graph[10010];

void dfs(int v, int l){
    if(visited[v]) return;
    if(l > max_len){
        max_v = v;
        max_len = l;
    }

    visited[v] = 1;
    for(auto p: graph[v]){
        dfs(p.first, l+p.second);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<N; i++){
        cin >> a >> b >> len;
        graph[a].push_back({b, len});
        graph[b].push_back({a, len});
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));

    dfs(max_v, 0);
    cout << max_len;

    return 0;
}