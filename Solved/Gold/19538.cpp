#include <bits/stdc++.h>
#define ll long long;
#define P pair<int, int>
using namespace std;

int N, M, tmp;
vector<int> graph[1000010];
queue<P> q;
int rumor[200010];


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    memset(rumor, -1, sizeof(rumor));

    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> tmp;
        while(tmp){
            graph[i].push_back(tmp);
            cin >> tmp;
        }
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> tmp;
        q.push({tmp, 0});
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(rumor[cur.first] == -1){
            rumor[cur.first] = cur.second;
        }

        for(int next: graph[cur.first]){
            if(rumor[next] != -1) continue;

            int count = 0;
            for(int t: graph[next]){
                if(rumor[t] != -1){
                    count++;
                }
            }

            if(count >= (graph[next].size()+1)/2){
                q.push({next, cur.second+1});
            }
        }
    }

    for(int i=1; i<=N; i++){
        cout << rumor[i] << ' ';
    }

    return 0;
}