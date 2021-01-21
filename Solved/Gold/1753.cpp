#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321

struct edge{
    int to, value;
};
bool operator < (edge left, edge right){
    return right.value < left.value;
}

vector<edge> graph[20010];
int min_dist[20010];
bool visited[20010];
priority_queue<edge> pq;

int V, E, cur_n;
int u, v, w;


void dijkstra(){
    while(!pq.empty()){
        edge tmp = pq.top(); pq.pop();
        cur_n = tmp.to;

        if(visited[cur_n]) continue;

        min_dist[cur_n] = tmp.value;
        visited[cur_n] = true;

        for(auto e: graph[cur_n]){
            if(min_dist[e.to] > e.value+min_dist[cur_n]){
                pq.push({e.to, e.value + min_dist[cur_n]});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=0; i<20010; i++){
        min_dist[i] = MAX;
    }

    cin >> V >> E >> cur_n;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    min_dist[cur_n] = 0;
    pq.push({cur_n, 0});
    
    dijkstra();


    for(int i=1; i<=V; i++){
        if(min_dist[i] == MAX){
            cout << "INF" << "\n";
        } else {
            cout << min_dist[i] << "\n";
        }
    }

    return 0;
}