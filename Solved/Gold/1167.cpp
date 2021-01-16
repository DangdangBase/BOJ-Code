#include <bits/stdc++.h>
using namespace std;

int V;
int cur_v, next_v, len;
int max_v, max_len;

vector<pair<int, int>> graph[100010];
bool visited[100010];

void dfs(int v, int len){
    if(visited[v]){
        return;
    } else if (max_len < len) {
        max_v = v;
        max_len = len;
	}
    visited[v] = true;

    for(auto p: graph[v]){
        dfs(p.first, len+p.second);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> V;
    for(int i=0; i<V; i++){
        cin >> cur_v;

        while(true){
            cin >> next_v;
            if(next_v == -1){
                break;
            }

            cin >> len;
            graph[cur_v].push_back({next_v, len});
        }
    }

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    
    dfs(max_v, 0);
    cout << max_len;

    return 0;
}