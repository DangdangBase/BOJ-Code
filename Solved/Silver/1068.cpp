#include <bits/stdc++.h>
using namespace std;

int N, del, root, cnt, tmp;
vector<int> graph[55];
bool visited[55];

void dfs(int cur){
    if(cur==-1 || visited[cur]){
        return;
    }
    visited[cur] = 1;

    if(graph[cur].size() == 1){
        cnt++;
        return;
    }

    for(int next: graph[cur]){
        dfs(next);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        if(tmp == -1){
            root = i;
            graph[i].push_back(tmp);
        }
        else {
            graph[i].push_back(tmp);
            graph[tmp].push_back(i);
        }
    }
    

    cin >> del;
    for(int v: graph[del]){
        if(v == -1) continue;
        graph[v].erase(find(graph[v].begin(), graph[v].end(), del));
    }
    graph[del].clear();

    dfs(root);
    cout << cnt;

    return 0;
}