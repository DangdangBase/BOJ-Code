#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, A, B, C;
int base=1048576;

int seg[2097162];


int query(int idx, int s, int e, int cnt){
    if(s == e) return idx-base;

    int mid = (s+e)/2;
    if(cnt <= seg[idx*2]){
        return query(idx*2, s, mid, cnt);
    } else {
        return query(idx*2+1, mid+1, e, cnt-seg[idx*2]);
    }
}


void update(int idx, int val){
    seg[base+idx] = max(seg[base+idx]+val, 0);

    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    while(N--){
        cin >> A;

        if(A == 1){
            cin >> B;

            int idx = query(1, 1, base, B);
            update(idx, -1);

            cout << idx << "\n";
        } else {
            cin >> B >> C;
            update(B, C);
        }
    }

    return 0;
}