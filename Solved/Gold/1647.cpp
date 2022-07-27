#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 100010
using namespace std;

struct edge {
  int a, b;
  int value;

  edge(int A, int B, int VAL) : a(A), b(B), value(VAL) {};
};
struct compare_edge {
    bool operator()(edge const& e1, edge const& e2){
        return e1.value > e2.value;
    }
};

int root[MAX];

int find(int cur){
  if (root[cur] == cur) return cur;
  else return root[cur] = find(root[cur]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  root[a] = b;
}

int N, M;
priority_queue<edge, vector<edge>, compare_edge> pq;
int ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for(int i=1; i<=N; i++){
      root[i] = i;
    }

    for(int i=0; i<M; i++){
      int a, b, c;
      cin >> a >> b >> c;
      pq.push(edge(a, b, c));
    }

    int edge_count = 0;
    while(!pq.empty()){
      edge cur = pq.top();
      pq.pop();

      if(find(cur.a) != find(cur.b)){
        merge(cur.a, cur.b);
        ans += cur.value;
        edge_count++;
      }

      if(edge_count == N-2) break;
    }

    cout << ans << endl;
    return 0;
}