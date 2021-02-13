#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int V, E;
int a, b, c;

vector<P> graph[10010];
bool visited[10010];
priority_queue<P, vector<P>, greater<P>> pq;


int ret;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    visited[1] = true;
    for(auto p: graph[1]){
        pq.push(p);
    }

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(visited[cur.second]) continue;
        visited[cur.second] = true;

        ret += cur.first;

        for(auto p: graph[cur.second]){
            pq.push(p);
        }
    }

    cout << ret;
    return 0;
}