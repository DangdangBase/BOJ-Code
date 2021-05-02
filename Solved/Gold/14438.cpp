#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, base=1;
int op, a, b;
vector<int> seg;

int query(int i, int s, int e){
    if(b < s || e < a) return INF;
    else if(a <= s && e <= b) return seg[i];
    else {
        int mid = (s+e)/2;
        return min(query(i*2, s, mid), query(i*2+1, mid+1, e));
    }
}

void update(int idx, int val){
    seg[base+idx-1] = val;

    for(int i=(base+idx-1)/2; i>0; i/=2){
        seg[i] = min(seg[i*2], seg[i*2+1]);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    while(base < N) base *= 2;
    seg.resize(base*2);

    for(int i=0; i<N; i++){
        cin >> seg[base+i];
    }
    for(int i=N; i<base; i++){
        seg[base+i] = INF;
    }

    for(int i=base-1; i>0; i--){
        seg[i] = min(seg[i*2], seg[i*2+1]);
    }

    cin >> M;
    while(M--){
        cin >> op >> a >> b;

        if(op == 1){
            update(a, b);
        } else {
            cout << query(1, 1, base) << '\n';
        }
    }


    return 0;
}