#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, K, base=65536, mid;
int arr[250010];
int seg[131080];
ll ret;

ll find(int idx, ll l, ll r, int cnt){
    if(l==r) return l;

    ll tmp = (l+r)/2;
    if(cnt <= seg[idx*2]){
        return find(idx*2, l, tmp, cnt);
    } else {
        return find(idx*2+1, tmp+1, r, cnt-seg[idx*2]);
    }
}

void update(int idx, int val){
    seg[base+idx] += val;

    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> K;
    mid = (K+1)/2;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<K-1; i++){
        update(arr[i], 1);
    }

    for(int i=K-1; i<N; i++){
        update(arr[i], 1);
        ret += find(1, 0, base-1, mid);
        update(arr[i-K+1], -1);
    }

    cout << ret;
    return 0;
}