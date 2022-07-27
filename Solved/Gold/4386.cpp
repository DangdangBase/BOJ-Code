#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 110
using namespace std;

struct vertex {
  float x, y;
};

struct edge {
  int a, b;
  float length;

  edge(int A, int B, float LEN) : a(A), b(B), length(LEN) {};
};
struct compare_edge {
    bool operator()(edge const& e1, edge const& e2){
        return e1.length > e2.length;
    }
};

int root[MAX];

int find(int cur){
  if (root[cur] == cur) return cur;
  else return find(root[cur]);
}

void merge(int a, int b){
  a = find(a);
  b = find(b);

  root[a] = b;
}

int N;
vertex star[MAX];
priority_queue<edge, vector<edge>, compare_edge> pq;
float ans;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<=N; i++){
      root[i] = i;
      cin >> star[i].x >> star[i].y;
    }

    for(int i=1; i<=N; i++){
      for(int j=i+1; j<=N; j++){
        float x_diff = star[i].x - star[j].x;
        float y_diff = star[i].y - star[j].y;
        float distance = sqrt(x_diff*x_diff + y_diff*y_diff);

        pq.emplace(edge(i, j, distance));
      }
    }

    while(!pq.empty()){
      edge cur = pq.top();
      pq.pop();

      if(find(cur.a) != find(cur.b)){
        merge(cur.a, cur.b);
        ans += cur.length;
      }
    }

    cout << ans << endl;
    return 0;
}