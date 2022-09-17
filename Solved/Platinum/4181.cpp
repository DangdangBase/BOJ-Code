#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

struct Pos {
  ll x, y;
  ll rel_x = 0, rel_y = 0;

  Pos() {
    x = 0;
    y = 0;
  }

  Pos(ll new_x, ll new_y) {
    x = new_x;
    y = new_y;
  }

  bool operator<(const Pos& p) const {
    if (rel_y * p.rel_x != p.rel_y * rel_x)
      return rel_y * p.rel_x < p.rel_y * rel_x;
    else if (x != p.x)
      return x < p.x;
    else
      return y < p.y;
  }
};

int N;
ll x, y;
char ch;

vector<Pos> p;

ll ccw(Pos p1, Pos p2, Pos p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> ch;

    if (ch == 'Y')
      p.push_back({x, y});
  }

  for (int i = 1; i < p.size(); i++) {
    if (p[i].x < p[0].x || (p[i].x == p[0].x && p[i].y < p[0].y)) {
      swap(p[0], p[i]);
    }
  }

  for (int i = 1; i < p.size(); i++) {
    p[i].rel_x = p[i].x - p[0].x;
    p[i].rel_y = p[i].y - p[0].y;
  }
  sort(p.begin() + 1, p.end());

  for (int i = p.size() - 2; i >= 0; i--) {
    if (ccw(p[0], p[p.size() - 1], p[i]) != 0) {
      reverse(p.begin() + i + 1, p.end());
      break;
    }
  }

  cout << p.size() << '\n';
  for (Pos cur : p) {
    cout << cur.x << ' ' << cur.y << '\n';
  }

  return 0;
}
