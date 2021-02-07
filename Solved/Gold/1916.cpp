#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
#define MAX 987654321
using namespace std;


int N, M;
int u, v, w;
int cur_v, end_v;

vector<P> graph[1010];
int min_dist[1010];
bool visited[1010];
priority_queue<P, vector<P>, greater<P>> pq;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    cin >> cur_v >> end_v;


    for(int i=1; i<=N; i++){
        min_dist[i] = MAX;
    }
    min_dist[cur_v] = 0;
    pq.push({0, cur_v});


    while(!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        cur_v = tmp.second;

        if(visited[cur_v]) continue;

        min_dist[cur_v] = tmp.first;
        visited[cur_v] = true;

        for(auto e: graph[cur_v]){
            if(min_dist[e.second] > e.first+min_dist[cur_v]){
                pq.push({e.first + min_dist[cur_v], e.second});
            }
        }
    }

    cout << min_dist[end_v];
    return 0;
}