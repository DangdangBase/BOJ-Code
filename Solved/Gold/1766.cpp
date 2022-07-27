#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define MAX 32010
using namespace std;

int N, M;

int in_degree[MAX];
int result[MAX];
vector<int> graph[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<M; i++){
      int a, b;
      cin >> a >> b;

      in_degree[b]++;
      graph[a].push_back(b);
    }

    for(int i=1; i<=N; i++){
      if(!in_degree[i]) pq.push(i);
    }

    for(int i=1; i<=N; i++){
      if(pq.empty()) return 0;

      int cur = pq.top();
      pq.pop();

      result[i] = cur;

      for(int next: graph[cur]){
        if(!--in_degree[next]) pq.push(next);
      }
    }

    for(int i=1; i<=N; i++){
      cout << result[i] << ' ';
    }

    return 0;
}