#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;


int N, M, base=1;
int u, v;

vector<int> graph[100010];

struct seg_node {int depth, node;};
vector<seg_node> seg;
int leaf_idx[100010];
int next_idx;


seg_node query(int idx, int s, int e, int lo, int hi){
    if(e < lo || hi < s) return {INF, -1};
    else if(lo <= s && e <= hi) return seg[idx];
    else {
        int mid = (s+e)/2;
        seg_node left = query(idx*2, s, mid, lo, hi);
        seg_node right = query(idx*2+1, mid+1, e, lo, hi);

        if(left.depth < right.depth){
            return left;
        } else {
            return right;
        }
    }
}
void update(int depth, int node){
    seg[base+next_idx] = {depth, node};

    for(int i=(base+next_idx)/2; i>0; i/=2){
        if(seg[i*2].depth > seg[i*2+1].depth){
            seg[i] = seg[i*2+1];
        } else {
            seg[i] = seg[i*2];
        }
    }

    next_idx++;
}
void dfs(int d, int node){
    leaf_idx[node] = next_idx;
    update(d, node);

    for(int next: graph[node]){
        if(leaf_idx[next] != -1) continue;
        dfs(d+1, next);

        update(d, node);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    while(base < 2*N) base *= 2;
    seg.resize(base*2);
    
    for(int i=1; i<N; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(leaf_idx, -1, sizeof(leaf_idx));
    dfs(0, 1);

    while(next_idx != base){
        update(INF, -1);
    }

    cin >> M;
    while(M--){
        cin >> u >> v;

        int lo = leaf_idx[u];
        int hi = leaf_idx[v];
        if(lo > hi) swap(lo, hi);

        seg_node lca = query(1, 0, base-1, lo, hi);
        cout << lca.node << '\n';
    }

    return 0;
}