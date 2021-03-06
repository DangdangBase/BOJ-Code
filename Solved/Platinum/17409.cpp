#include <bits/stdc++.h>
#define INF 987654321
#define DIV 1000000007
#define P pair<int, int>
#define ll long long
using namespace std;

int N, K, tmp;
int base=1;
int ret;

vector<P> v;
vector<int> seg;
int dp[11][100010];


int query(int idx, int s, int e, int cur){
    if(cur < s) return 0;
    else if(e <= cur) return seg[idx];
    else {
        int mid = (s+e)/2;
        return (query(idx*2, s, mid, cur) + query(idx*2+1, mid+1, e, cur)) % DIV;
    }
}

void update(int idx, int val){
    seg[base+idx] = val;
    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = (seg[i*2] + seg[i*2+1]) % DIV;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    while(base < N) base *= 2;
    seg.resize(base*2);

    for(int i=0; i<N; i++){
        cin >> tmp;
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());


    for(int i=0; i<N; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=K; i++){
        fill(seg.begin(), seg.end(), 0);

        for(int j=0; j<N; j++){
            dp[i][j] = query(1, 0, base-1, v[j].second);
            update(v[j].second, dp[i-1][j]);
        }
    }
    
    for(int j=0; j<N; j++){
        ret = (ret + dp[K][j]) % DIV;
    }
    cout << ret;
    return 0;
}