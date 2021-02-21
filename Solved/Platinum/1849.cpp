#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define INF 987654321
using namespace std;


int N, loc;
int base=2;
vector<ll> seg;

int arr[100010];


int find(int idx, int s, int e, int cnt){
    if(s==e) return s;
    
    int mid = (s+e)/2;
    if(cnt < seg[idx*2]){
        return find(idx*2, s, mid, cnt);
    } else {
        return find(idx*2+1, mid+1, e, cnt-seg[idx*2]);
    }
}

void update(int idx, ll num){
    if(!idx) return;

    seg[idx] += num;
    update(idx/2, num);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    while(base < N) base *= 2;
    seg.resize(base*2);
    for(int i=1; i<=N; i++){
        update(base+i-1, 1);
    }
    
    for(int i=1; i<=N; i++){
        cin >> loc;

        int idx = find(1, 1, base, loc)-1;
        arr[idx] = i;
        update(base+idx, -1);
    }
 
    for(int i=0; i<N; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}