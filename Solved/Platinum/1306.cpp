#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, tmp;
int base=1;

vector<int> seg;

int query(int idx, int s, int e, int ad_s, int ad_e){
    if(e < ad_s || ad_e < s) return 0;
    else if(ad_s <= s && e <= ad_e) return seg[idx];
    else {
        int mid = (s+e)/2;
        return max(query(idx*2, s, mid, ad_s, ad_e), query(idx*2+1, mid+1, e, ad_s, ad_e));
    }
}

void update(int idx, int val){
    seg[base+idx] = val;

    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = max(seg[i*2], seg[i*2+1]);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    while(base < N) base *= 2;
    seg.resize(base*2);

    for(int i=0; i<N; i++){
        cin >> tmp;
        update(i, tmp);
    }

    for(int i=M-1; i<=N-M; i++){
        cout << query(1, 0, base-1, i-M+1, i+M-1) << ' ';
    }

    return 0;
}