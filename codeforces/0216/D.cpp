#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int t, n;
int tree[110];
int ans[110];

void get_tree_depth(int d, int s, int e){
    if(s > e) return;

    P max_val = {0, 0};
    for(int i=s; i<=e; i++){
        if(max_val.first < tree[i]){
            max_val = {tree[i], i};
        }
    }

    int idx = max_val.second;
    ans[idx] = d;
    get_tree_depth(d+1, s, idx-1);
    get_tree_depth(d+1, idx+1, e);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> tree[i];
        }

        get_tree_depth(0, 0, n-1);

        for(int i=0; i<n; i++){
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }

    return 0;
}