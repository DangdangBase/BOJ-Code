#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M, K, need;
int v, w;

int parent[10010];
int price[10010];


int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b){
        return;
    } else {
        if(price[b] < price[a]) swap(a, b);
        parent[b] = a;
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        cin >> price[i];
        parent[i] = i;
    }

    while(M--){
        cin >> v >> w;
        merge(v, w);
    }

    for(int i=1; i<=N; i++){
        int p = find(i);
        
        if(p){
            need += price[p];
            parent[p] = 0;
        }
    }

    if(need > K){
        cout << "Oh no";
    } else {
        cout << need;
    }

    return 0;
}