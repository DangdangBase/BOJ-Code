#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
#define MAX 987654321
using namespace std;


int N, M;
int u, v, w;
int A, B;

vector<P> graph[1010];
int min_dist[1010];
bool visited[1010];
priority_queue<P, vector<P>, greater<P>> pq;


ll dijkstra(int start, int end){
    pq = priority_queue<P, vector<P>, greater<P>> ();
    memset(visited, 0, sizeof(visited));
    for(int i=1; i<=N; i++){
        min_dist[i] = MAX;
    }
    min_dist[start] = 0;

    pq.push({0, start});
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int cur_node = tmp.second;

        if(visited[cur_node]) continue;

        min_dist[cur_node] = tmp.first;
        visited[cur_node] = true;

        for(auto e: graph[cur_node]){
            if(min_dist[e.second] > e.first+min_dist[cur_node]){
                pq.push({e.first + min_dist[cur_node], e.second});
            }
        }
    }

    return min_dist[end];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    cin >> A >> B;

    ll first = dijkstra(1, A) + dijkstra(A, B) + dijkstra(B, N);
    ll second = dijkstra(1, B) + dijkstra(B, A) + dijkstra(A, N);

    ll ret = min(first, second);
    if(ret >= MAX){
        ret = -1;
    }

    cout << ret;
    return 0;
}