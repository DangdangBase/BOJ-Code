#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

struct vert{ 
    int x, y1, y2; 
    bool is_start;

    bool operator < (vert& a){
        return x < a.x;
    }
}; 

int N, prev_x, ans;
vector<vert> verts;
int vert_locs[30001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int x1, x2, y1, y2;

    cin >> N;
    verts.resize(2*N);

    for(int i=0; i<N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        verts[2*i] = {x1, y1, y2, true};
        verts[2*i+1] = {x2, y1, y2, false};
    }
    sort(verts.begin(), verts.end());

    prev_x = verts[0].x;
    for(vert cur: verts){
        int len = 0;
        for(int i=0; i<30000; i++){
            if(vert_locs[i] > 0) len++;
        }

        ans += len * (cur.x - prev_x);

        int val = cur.is_start ? 1 : -1;
        for(int i=cur.y1; i<cur.y2; i++){
            vert_locs[i] += val;
        }

        prev_x = cur.x;
    }

    cout << ans;
    return 0;
}