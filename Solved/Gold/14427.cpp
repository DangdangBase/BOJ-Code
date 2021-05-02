#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, base=1;
int op, a, b;

int arr[131080];
vector<int> seg;


void update(int idx, int val){
    arr[idx] = val;

    for(int i=(base+idx)/2; i>0; i/=2){
        if(arr[seg[i*2]] > arr[seg[i*2+1]]) seg[i] = seg[i*2+1];
        else seg[i] = seg[i*2];
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
        if(arr[seg[i*2]] > arr[seg[i*2+1]]) seg[i] = seg[i*2+1];
        else seg[i] = seg[i*2];
    }

    cin >> M;
    while(M--){
        cin >> op;

        if(op == 1){
            cin >> a >> b;
            update(a-1, b);
        } else {
            cout << (seg[1]+1) << '\n';
        }
    }

    return 0;
}