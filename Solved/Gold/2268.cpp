#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
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

void update(){
    int i = base+b-1;

    segment_tree[i] = c;
    i /= 2;

    for(i; i>0; i/=2){
        segment_tree[i] = segment_tree[i*2] + segment_tree[i*2+1];
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    while(base < N){
        base *= 2;
    }
    segment_tree.resize(base*2);

    for(int i=0; i<M; i++){
        cin >> a >> b >> c;

        if(a == 0){
            if(b > c) swap(b, c);
            cout << get_sum(1, base, 1) << '\n';
        }
        else {
            update();
        }
    }

    return 0;
}