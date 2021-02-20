#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define MAX 987654321
using namespace std;

struct pq_item {
    int e, prev, cur;
    bool operator< (const pq_item& a) const{return e > a.e;}
};

int N, M;
int u, v, w;
int s, e;

vector<P> graph[1010];
priority_queue<pq_item> pq;
P min_dist[1010];
bool visited[1010];
vector<int> route;

void dijkstra(int start, int end){
    memset(visited, 0, sizeof(visited));
    for(int i=1; i<=N; i++){
        min_dist[i] = {MAX, -1};
    }

    pq.push({0, -1, start});
    min_dist[start] = {0, -1};

    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int cur_node = tmp.cur;

        if(visited[cur_node]) continue;
        visited[cur_node] = true;
        min_dist[cur_node] = {tmp.e, tmp.prev};

        for(auto e: graph[cur_node]){
            int next_dist=e.first, next_node=e.second;
            if(min_dist[next_node].first > next_dist+min_dist[cur_node].first){
                pq.push({next_dist+min_dist[cur_node].first, cur_node, next_node});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    cin >> s >> e;

    dijkstra(s, e);

    int next = e;
    while(next != -1){
        route.push_back(next);
        next = min_dist[next].second;
    }
    reverse(route.begin(), route.end());
    
    cout << min_dist[e].first << "\n";
    cout << route.size() << "\n";
    for(int cur: route){
        cout << cur << ' ';
    }

    return 0;
}