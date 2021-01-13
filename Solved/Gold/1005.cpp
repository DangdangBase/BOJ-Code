#include <bits/stdc++.h>
using namespace std;

int T;
int N, K;
int x, y, W;

int times[1010];
int dp[1010];
vector<int> graph[1010];


int dfs(int n){
    if(dp[n] >= 0){
        return dp[n];
    }

    int ret = 0;
    for(int next: graph[n]){
        ret = max(ret, dfs(next));
    }

    return dp[n] = ret + times[n];
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<1010; i++){
            graph[i].clear();
        }

        cin >> N >> K;
        for(int i=1; i<=N; i++){
            cin >> times[i];
        }
        for(int i=0; i<K; i++){
            cin >> x >> y;
            graph[y].push_back(x);
        }
        cin >> W;

        cout << dfs(W) << "\n";
    }
    
    return 0;
}