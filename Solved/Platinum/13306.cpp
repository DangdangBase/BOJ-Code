#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

struct query{
    int action, a, b; 
};

int N, Q;
int tmp, A, B;
vector<query> query_arr;
vector<bool> ans;

int parent[200010];
int parent_target[200010];

int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    parent[b] = a;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> Q;

    for(int i=2; i<=N; i++){
        cin >> parent_target[i];
        parent[i] = i;
    }

    for(int i=0; i<N-1+Q; i++){
        cin >> tmp;

        if(tmp){
            cin >> A >> B;
            query_arr.push_back({1, A, B});
        } else {
            cin >> A;
            query_arr.push_back({0, A});
        }
    }

    reverse(query_arr.begin(), query_arr.end());
    for(query cur: query_arr){
        if(cur.action){
            ans.push_back(find(cur.a) == find(cur.b));
        } else {
            merge(cur.a, parent_target[cur.a]);
        }
    }

    reverse(ans.begin(), ans.end());
    for(bool yn: ans){
        cout << (yn ? "YES" : "NO") << '\n';
    }

    return 0;
}