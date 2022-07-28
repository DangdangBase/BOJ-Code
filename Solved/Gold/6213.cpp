#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, Q, base=1;
int lo, hi;
vector<P> seg;

P query(int i, int s, int e){
    if(hi < s || e < lo) return {INF, 0};
    else if(lo <= s && e <= hi) return seg[i];
    else {
      int mid = (s+e)/2;
      P left = query(i*2, s, mid);
      P right = query(i*2+1, mid+1, e);
      return {min(left.first, right.first), max(left.second, right.second)};
    }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> Q;
  while(base < N) base *= 2;
  seg.resize(base*2);

  int tmp;
  for(int i=base; i<base+N; i++){
    cin >> tmp;
    seg[i] = {tmp, tmp};
  }
  for(int i=base+N+1; i<base*2; i++){
    seg[i] = {INF, 0};
  }

  for(int i=base-1; i>0; i--){
    P left = seg[i*2];
    P right = seg[i*2+1];
    seg[i] = {min(left.first, right.first), max(left.second, right.second)};
  }

  while(Q--){
    cin >> lo >> hi;

    P data = query(1, 1, base);
    cout << data.second - data.first << "\n";
  }

  return 0;
}