#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

struct city{
    int start, end, depth;
};

int N, C, Q;
int v, w;
int a, b;

vector<int> graph[200010];
bool visited[200010];

city cities[200010];
int last_idx = 1;

vector<int> fwt;

void dfs(int n, int d){
    visited[n] = true;

    cities[n].start = last_idx++;
    cities[n].depth = d;

    for(int next: graph[n]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next, d+1);
        }
    }

    cities[n].end = last_idx-1;
}

ll sum(int i){
    ll ret = 0;

    while (i > 0){
        ret += fwt[i];
        i -= (i & -i);
    }
 
    return ret;
}

void update(int i) {
    while (i < fwt.size()) {
        fwt[i] += 1;
        i += (i & -i);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> C;
    fwt.resize(N+1);

    for(int i=0; i<N-1; i++){
        cin >> v >> w;
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    dfs(C, 1);

    cin >> Q;
    while(Q--){
        cin >> a >> b;

        if(a == 1){
            update(cities[b].start);
        } else {
            ll tmp = sum(cities[b].end) - sum(cities[b].start-1);
            cout << tmp*cities[b].depth << '\n';
        }
    }


    return 0;
}