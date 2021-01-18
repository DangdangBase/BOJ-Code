#include <bits/stdc++.h>
using namespace std;

int N, u, v;

vector<int> graph[1000010];
int dp[1000010][2];


int dfs(int prev, int cur, int idx){
    if(dp[cur][idx]) return dp[cur][idx];

    int ret = 0;
    if(idx){
        ret++;
        for(int n: graph[cur]){
            if(n == prev) continue;
            ret += min(dfs(cur, n, 0), dfs(cur, n, 1));
        }
    } else {
        for(int n: graph[cur]){
            if(n == prev) continue;
            ret += dfs(cur, n, 1);
        }
    }

    return dp[cur][idx] = ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<N; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(N == 1){
        cout << 1;
        return 0;
    }

    cout << min(dfs(-1, 1, 0), dfs(-1, 1, 1)) << endl;

    return 0;
}