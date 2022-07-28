#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 100010
using namespace std;

struct vertex {
  int x, y, z;
};

struct edge {
  int a, b, length;
};
struct compare_edge {
    bool operator()(edge const& e1, edge const& e2){
        return e1.length > e2.length;
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

int N;
int x, y, z;
vertex planet[MAX];
vector<P> x_arr;
vector<P> y_arr;
vector<P> z_arr;
priority_queue<edge, vector<edge>, compare_edge> pq;

int ans;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for(int i=1; i<=N; i++){
    root[i] = i;

    cin >> x >> y >> z;
    x_arr.push_back({x, i});
    y_arr.push_back({y, i});
    z_arr.push_back({z, i});
  }

  sort(x_arr.begin(), x_arr.end(), less<>());
  sort(y_arr.begin(), y_arr.end(), less<>());
  sort(z_arr.begin(), z_arr.end(), less<>());

  for(int i=0; i<N-1; i++){
    pq.push({x_arr[i].second, x_arr[i+1].second, x_arr[i+1].first - x_arr[i].first});
    pq.push({y_arr[i].second, y_arr[i+1].second, y_arr[i+1].first - y_arr[i].first});
    pq.push({z_arr[i].second, z_arr[i+1].second, z_arr[i+1].first - z_arr[i].first});
  }

  int edge_count = 0;
  while(!pq.empty()){
    edge cur = pq.top();
    pq.pop();

    if(find(cur.a) != find(cur.b)){
      merge(cur.a, cur.b);
      ans += cur.length;
      edge_count++;
    }

    if(edge_count == N-1) break;
  }

  cout << ans << endl;
  return 0;
}