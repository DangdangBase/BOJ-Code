#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define INF 2100000000;
using namespace std;

int N, M, tmp;
int a, b;

int base = 2;

vector<ll> min_v;
vector<ll> max_v;

int get_min(int s, int e, int idx){
    if(b < s || e < a){
        return INF;
    } else if(a <= s && e <= b){
        return min_v[idx];
    } else {
        int mid = (s+e)/2;
        return min(get_min(s, mid, idx*2), get_min(mid+1, e, idx*2+1));
    }
}
int get_max(int s, int e, int idx){
    if(b < s || e < a){
        return 0;
    } else if(a <= s && e <= b){
        return max_v[idx];
    } else {
        int mid = (s+e)/2;
        return max(get_max(s, mid, idx*2), get_max(mid+1, e, idx*2+1));
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
    min_v.resize(base*2);
    max_v.resize(base*2);

    for(int i=base; i<base+N; i++){
        cin >> tmp;
        min_v[i] = tmp;
        max_v[i] = tmp;
    }
    for(int i=base+N; i<base*2; i++){
        min_v[i] = INF;
        max_v[i] = 0;
    }

    for(int i=base-1; i>0; i--){
        min_v[i] = min(min_v[i*2], min_v[i*2+1]);
        max_v[i] = max(max_v[i*2], max_v[i*2+1]);
    }


    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << get_min(1, base, 1) << ' ' << get_max(1, base, 1) << '\n';
    }

    return 0;
}