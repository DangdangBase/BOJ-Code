#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int op, A, B;

int ancestor[1000010];



int find(int n){
    if(ancestor[n] == n){
        return n;
    } else {
        return ancestor[n] = find(ancestor[n]);
    }
}


void merge(int a, int b){
    int ancestor_a = find(a);
    int ancestor_b = find(b);

    if(ancestor_a == ancestor_b){
        return;
    } else {
        ancestor[ancestor_b] = ancestor_a;
    }
}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for(int i=0; i<=N; i++){
        ancestor[i] = i;
    }

    while(M--){
        cin >> op >> A >> B;

        if(!op){
            merge(A, B);
        } else {
            if(find(A) == find(B)){
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}