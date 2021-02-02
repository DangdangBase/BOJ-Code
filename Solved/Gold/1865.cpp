#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int T, N, M, W;
int s, e, t;

vector<pair<int, int>> graph[510];
long long dist[510];
bool visited[510];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        bool is_cycle = false;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<510; i++){
            graph[i].clear();
        }

        cin >> N >> M >> W;
        for(int i=0; i<M; i++){
            cin >> s >> e >> t;
            graph[s].push_back({e, t});
            graph[e].push_back({s, t});
        }
        for(int i=0; i<W; i++){
            cin >> s >> e >> t;
            graph[s].push_back({e, -t});
        }

        for(int i=1; i<=N; i++){
            if(visited[i]) continue;
            
            fill(dist, dist+510, INF);
            visited[i] = true;
            dist[i] = 0;

            for(int j=0; j<N; j++){
                for(int k=1; k<=N; k++){

                    for(auto cur: graph[k]){
                        if(dist[k]!=INF && dist[cur.first] > dist[k]+cur.second){
                            visited[cur.first] = true;
                            dist[cur.first] = dist[k] + cur.second;

                            if(j == N-1){
                                is_cycle = true;
                            }
                        }
                    }
                }
            }
        }

        if(is_cycle){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }


    }

    return 0;
}