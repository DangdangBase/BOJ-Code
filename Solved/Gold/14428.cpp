#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, base=1;
int op, a, b;

int arr[131080];
vector<int> seg;

int cmp(int idx1, int idx2){
    if(idx1 == INF) return idx2;
    else if(idx2 == INF) return idx1;

    if(arr[idx1] > arr[idx2]) return idx2;
    else return idx1;
}

int query(int i, int s, int e){
    if(b < s || e < a) return INF;
    else if(a <= s && e <= b) return seg[i];
    else {
        int mid = (s+e)/2;
        return cmp(query(i*2, s, mid), query(i*2+1, mid+1, e));
    }
}

void update(int idx, int val){
    arr[idx] = val;

    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = cmp(seg[i*2], seg[i*2+1]);
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
        cin >> arr[i];
    }
    for(int i=N; i<base; i++){
        arr[i] = INF;
    }

    for(int i=0; i<base; i++){
        seg[i+base] = i;
    }

    for(int i=base-1; i>0; i--){
        seg[i] = cmp(seg[i*2], seg[i*2+1]);
    }

    cin >> M;
    while(M--){
        cin >> op >> a >> b;

        if(op == 1){
            update(a-1, b);
        } else {
            cout << (query(1, 1, base)+1) << '\n';
        }
    }

    return 0;
}