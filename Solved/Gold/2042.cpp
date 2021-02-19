#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, K;
int base = 2;
ll a, b, c;

vector<ll> segment_tree;

ll get_sum(int s, int e, int idx){
    if(c < s || e < b){
        return 0;
    } else if(b <= s && e <= c){
        return segment_tree[idx];
    } else {
        int mid = (s+e)/2;
        return get_sum(s, mid, idx*2) + get_sum(mid+1, e, idx*2+1);
    }
}

void update(int idx, ll n){
    int i = base+idx-1;

    segment_tree[i] = n;
    i /= 2;

    for(i; i>0; i/=2){
        segment_tree[i] = segment_tree[i*2] + segment_tree[i*2+1];
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;

    while(base < N){
        base *= 2;
    }
    segment_tree.resize(base*2);

    for(int i=base; i<base+N; i++){
        cin >> segment_tree[i];
    }
    for(int i=base-1; i>0; i--){
        segment_tree[i] = segment_tree[i*2] + segment_tree[i*2+1];
    }

    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;

        if(a == 1){
            update(b, c);
        }
        else {
            ll tmp = get_sum(1, base, 1);
            cout << tmp << '\n';
        }
    }

    for(int cur: segment_tree){
        cout << cur << ' ';
    }
    cout << endl;

    return 0;
}