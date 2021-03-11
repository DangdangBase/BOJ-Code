#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
string board[1010];
int parent[1000010];

map<char, P> direction = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}},
};
unordered_set<int> result;

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    parent[a] = b;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    for(int i=0; i<N*M; i++){
        parent[i] = i;
    }
    for(int i=0; i<N; i++){
        cin >> board[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            P dir = direction[board[i][j]];
            merge(i*M+j, (i+dir.first)*M+(j+dir.second));
        }
    }

    for(int i=0; i<N*M; i++){
        find(i);
    }
    for(int i=0; i<N*M; i++){
        result.insert(parent[i]);
    }

    cout << result.size();
    return 0;
}