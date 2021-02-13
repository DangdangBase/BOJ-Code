#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
#define MAX 987654321
using namespace std;

int N, M, X;
int u, v, w;
int A, B;

vector<P> graph[1010];
int from_min_dist[1010];
int to_min_dist[1010];
bool visited[1010];
priority_queue<P, vector<P>, greater<P>> pq;


ll dijkstra(int start, int end){
    pq = priority_queue<P, vector<P>, greater<P>> ();
    memset(visited, 0, sizeof(visited));
    for(int i=1; i<=N; i++){
        to_min_dist[i] = MAX;
    }
    to_min_dist[start] = 0;

    pq.push({0, start});
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int cur_node = tmp.second;

        if(visited[cur_node]) continue;

        to_min_dist[cur_node] = tmp.first;
        visited[cur_node] = true;

        for(auto e: graph[cur_node]){
            if(to_min_dist[e.second] > e.first+to_min_dist[cur_node]){
                pq.push({e.first + to_min_dist[cur_node], e.second});
            }
        }
    }

    return to_min_dist[end];
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    
    for(int i=1; i<=N; i++){
        from_min_dist[i] = MAX;
    }
    from_min_dist[X] = 0;

    pq.push({0, X});
    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int cur_node = tmp.second;

        if(visited[cur_node]) continue;

        from_min_dist[cur_node] = tmp.first;
        visited[cur_node] = true;

        for(auto e: graph[cur_node]){
            if(from_min_dist[e.second] > e.first+from_min_dist[cur_node]){
                pq.push({e.first + from_min_dist[cur_node], e.second});
            }
        }
    }

    ll ret = -1;
    for(int i=1; i<=N; i++){
        ll tmp = dijkstra(i, X) + from_min_dist[i];
        ret = max(ret, tmp);
    }

    cout << ret;
    return 0;
}