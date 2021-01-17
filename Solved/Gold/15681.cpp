#include <bits/stdc++.h>
using namespace std;

int N, R, Q;
int u, v;

vector<int> graph[100010];
bool visited[100010];
int dp[100010];

int dfs(int cur){
    if(dp[cur]) return dp[cur];

    int ret = 1;
    for(int next: graph[cur]){
        if(!visited[next]){
            visited[next] = true;
            ret += dfs(next);
        }
    }

    return dp[cur] = ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> R >> Q;
    for(int i=0; i<N-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited[R] = true;
    dfs(R);

    int tmp;
    for(int i=0; i<Q; i++){
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }

    return 0;
}