#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 1010
using namespace std;

struct edge {
  int a, b, val;
};
struct compare_edge {
    bool operator()(edge const& e1, edge const& e2){
        return e1.val > e2.val;
    }
};

int N, M;
vector<edge> graph[MAX];
bool selected[MAX];
priority_queue<edge, vector<edge>, compare_edge> pq;

int ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for(int i=0; i<M; i++){
      int a, b, c;
      cin >> a >> b >> c;

      graph[a].push_back({a, b, c});
      graph[b].push_back({b, a, c});
    }

    selected[1] = true;
    for(edge cur: graph[1]){
      pq.emplace(cur);
    }

    while(!pq.empty()){
      edge cur = pq.top();
      pq.pop();

      if(cur.a == cur.b || selected[cur.b]) continue;

      ans += cur.val;

      selected[cur.b] = true;
      for(edge next: graph[cur.b]){
        pq.emplace(next);
      }
    }

    cout << ans << endl;
    return 0;
}