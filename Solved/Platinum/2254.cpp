#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
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

  Pos(int px, int py) {
    x = px;
    y = py;
  }

  bool operator<(Pos &p) {
    if (1ll * rel_x * p.rel_y != 1ll * p.rel_x * rel_y)
      return 1ll * rel_x * p.rel_y > 1ll * p.rel_x * rel_y;
    if (y != p.y) return y < p.y;
    return x < p.x;
  }
};

int N, px, py;
int wall_num;
stack<int> CH;

ll ccw(Pos p1, Pos p2, Pos p3) {
  return 1ll * (p2.x - p1.x) * (p3.y - p1.y) -
         1ll * (p3.x - p1.x) * (p2.y - p1.y);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> px >> py;
  vector<Pos> p(N);
  Pos prison(px, py);

  for (int i = 0; i < N; i++) {
    cin >> p[i].x >> p[i].y;
  }

  while (p.size() > 2) {
    sort(p.begin(), p.end());

    for (int i = 1; i < p.size(); i++) {
      p[i].rel_x = p[i].x - p[0].x;
      p[i].rel_y = p[i].y - p[0].y;
    }
    sort(p.begin() + 1, p.end());

    CH.push(0);
    CH.push(1);
    int next = 2;

    while (next < p.size()) {
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

    int pillar_num = CH.size();
    int pillar_pos[pillar_num];

    for (int i = 0; i < pillar_num; i++) {
      pillar_pos[i] = CH.top();
      CH.pop();
    }

    bool is_outer_wall = true;
    for (int i = 0; i < pillar_num; i++) {
      Pos p1 = p[pillar_pos[i]];
      Pos p2 = p[pillar_pos[(i + 1) % pillar_num]];
      is_outer_wall &= (ccw(prison, p1, p2) < 0);
    }

    if (!is_outer_wall) break;

    for (int cur_pillar : pillar_pos) {
      p.erase(p.begin() + cur_pillar);
    }
    wall_num++;
  }

  cout << wall_num << endl;
  return 0;
}