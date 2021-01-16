#include <bits/stdc++.h>
using namespace std;

int N;
int a, b;

int parent[100010];
vector<int> graph[100010];

void dfs(int cur){
    for(int next: graph[cur]){
        if(!parent[next]){
            parent[next] = cur;
            dfs(next);
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<N; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);
    for(int i=2; i<=N; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}