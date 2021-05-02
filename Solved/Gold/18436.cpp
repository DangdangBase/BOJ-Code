#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

P operator+(const P &a , const P &b){
    return {a.first+b.first, a.second+b.second};
}

int N, M, base=1;
int op, a, b;

vector<int> arr;
vector<P> seg;


P query(int i, int s, int e){
    if(b < s || e < a) return {0, 0};
    else if(a <= s && e <= b) return seg[i];
    else {
        int mid = (s+e)/2;
        return query(i*2, s, mid) + query(i*2+1, mid+1, e);
    }
}

void update(int idx, int val){
    arr[idx] = val;
    seg[idx+base] = {(arr[idx]+1)%2, (arr[idx]+2)%2};

    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    while(base < N) base *= 2;
    arr.resize(base);
    seg.resize(base*2);

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=N; i<base; i++){
        arr[i] = -1;
    }

    for(int i=0; i<base; i++){
        seg[i+base] = {(arr[i]+1)%2, (arr[i]+2)%2};
    }
    for(int i=base-1; i>0; i--){
        seg[i] = seg[i*2] + seg[i*2+1];
    }

    cin >> M;
    while(M--){
        cin >> op >> a >> b;

        if(op == 1){
            update(a-1, b);
        } else if(op == 2) {
            cout << query(1, 1, base).first << '\n';
        } else {
            cout << query(1, 1, base).second << '\n';
        }
    }

    return 0;
}