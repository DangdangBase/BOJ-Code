#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
#define PI 3.141592
using namespace std;

struct Pos {
  int x, y;
  int rel_x, rel_y;

  Pos() {
    x = 0;
    y = 0;
    rel_x = 0;
    rel_y = 0;
  }

  bool operator<(const Pos& p) const {
    if (1ll * rel_x * p.rel_y != 1ll * p.rel_x * rel_y)
      return 1ll * rel_x * p.rel_y > 1ll * p.rel_x * rel_y;
    if (y != p.y)
      return y < p.y;
    return x < p.x;
  }
};

int N, L;
float ans;

Pos p[1010];
stack<int> CH;

ll ccw(Pos p1, Pos p2, Pos p3) {
  return 1ll * (p2.x - p1.x) * (p3.y - p1.y) -
         1ll * (p3.x - p1.x) * (p2.y - p1.y);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> L;

  for (int i = 0; i < N; i++) {
    cin >> p[i].x >> p[i].y;
  }
  sort(p, p + N);

  for (int i = 1; i < N; i++) {
    p[i].rel_x = p[i].x - p[0].x;
    p[i].rel_y = p[i].y - p[0].y;
  }
  sort(p + 1, p + N);

  CH.push(0);
  CH.push(1);
  int next = 2;

  while (next < N) {
    while (CH.size() >= 2) {
      int first, second;
      second = CH.top();
      CH.pop();
      first = CH.top();

      if (ccw(p[first], p[second], p[next]) > 0) {
        CH.push(second);
        break;
      }
    }

    CH.push(next++);
  }

  int wall_num = CH.size();
  Pos wall[wall_num];

  for (int i = wall_num - 1; i >= 0; i--) {
    wall[i] = p[CH.top()];
    CH.pop();
  }

  for (int i = 0; i < wall_num; i++) {
    Pos p1 = wall[i];
    Pos p2 = wall[(wall_num + i - 1) % wall_num];
    Pos p3 = wall[(i + 1) % wall_num];

    P v1 = {p2.x - p1.x, p2.y - p1.y};
    P v2 = {p3.x - p1.x, p3.y - p1.y};

    ans += sqrt(pow(v1.first, 2) + pow(v1.second, 2));
  }

  ans += 2 * PI * L;

  cout << round(ans);
  return 0;
}
