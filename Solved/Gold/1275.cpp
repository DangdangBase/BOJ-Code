#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, Q, tmp;
int base = 2;
ll x, y, a, b;

vector<ll> segment_tree;

ll get_sum(int s, int e, int idx){
    if(y < s || e < x){
        return 0;
    } else if(x <= s && e <= y){
        return segment_tree[idx];
    } else {
        int mid = (s+e)/2;
        return get_sum(s, mid, idx*2) + get_sum(mid+1, e, idx*2+1);
    }
}

void update(){
    int i = base+a-1;

    segment_tree[i] = b;
    i /= 2;

    for(i; i>0; i/=2){
        segment_tree[i] = segment_tree[i*2] + segment_tree[i*2+1];
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> Q;

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

    for(int i=0; i<Q; i++){
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);

        cout << get_sum(1, base, 1) << '\n';
        update();
    }

    return 0;
}