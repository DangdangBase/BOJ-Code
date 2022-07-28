#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int T, N, Q, base=1;
char op;
int a, b;
vector<int> seg;

int query(int i, int s, int e){
  if(b < s || e < a) return 0;
  else if(a <= s && e <= b) return seg[i];
  else {
    int mid = (s+e)/2;
    return query(i*2, s, mid) + query(i*2+1, mid+1, e);
  }
}

void update(int idx, int val){
  seg[base+idx-1] += val;

  for(int i=(base+idx-1)/2; i>0; i/=2){
    seg[i] = seg[i*2] + seg[i*2+1];
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;
  while(T--){
    vector<int> tmp;
    seg.swap(tmp);

    int p, q;
    cin >> N >> p >> q;
    Q = p + q;

    while(base < N) base *= 2;
    seg.resize(base*2);

    while(Q--){
      cin >> op >> a >> b;

      if(op == 'P'){
        update(a, b);
      } else if(op == 'Q'){
        cout << query(1, 1, base) << "\n";
      }
    }
  }

  return 0;
}