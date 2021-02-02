#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

int N, M;
int a, b, c;

vector<pair<int, int>> graph[510];
long long dist[510];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    fill(dist, dist+510, INF);
    dist[1] = 0;

    for(int i=0; i<N; i++){
        for(int j=1; j<=N; j++){

            for(auto cur: graph[j]){
                if(dist[j] != INF && dist[cur.first] > dist[j]+cur.second){
                    dist[cur.first] = dist[j]+cur.second;

                    if(i == N-1){
                        cout << -1;
                        return 0;
                    }
                }
            }
        }
    }

    for(int i=2; i<=N; i++){
        if(dist[i] == INF){
            cout << -1 << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}