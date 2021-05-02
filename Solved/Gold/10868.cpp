#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define INF 1987654321
using namespace std;

int N, M, base=1;
int a, b;
vector<int> seg;

int query(int idx, int s, int e){
    if(b < s || e < a){
        return INF;
    } else if(a <= s && e <= b){
        return seg[idx];
    } else {
        int mid = (s+e)/2;
        return min(query(idx*2, s, mid), query(idx*2+1, mid+1, e));
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    while(base < N) base *= 2;
    seg.resize(base*2);

    for(int i=base; i<base+N; i++){
        cin >> seg[i];
    }
    for(int i=base+N; i<base*2; i++){
        seg[i] = INF;
    }

    for(int i=base-1; i>0; i--){
        seg[i] = min(seg[i*2], seg[i*2+1]);
    }

    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << query(1, 1, base) << '\n';
    }

    return 0;
}

