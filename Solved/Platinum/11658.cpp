#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int base=1;
int w;
int x, y, c;
int x_1, y_1, x_2, y_2;

vector<vector<int>> seg;

int get_col_sum(int r_idx, int c_idx, int c_s, int c_e){
    if(c_e < x_1 || x_2 < c_s) return 0;
    else if(x_1 <= c_s && c_e <= x_2){
        return seg[r_idx][c_idx];
    } else {
        int mid = (c_s+c_e)/2;
        return get_col_sum(r_idx, c_idx*2, c_s, mid) + get_col_sum(r_idx, c_idx*2+1, mid+1, c_e);
    }
}
int get_row_sum(int r_idx, int r_s, int r_e){
    if(r_e < y_1 || y_2 < r_s) return 0;
    else if(y_1 <= r_s && r_e <= y_2){
        return get_col_sum(r_idx, 1, 1, base);
    } else {
        int mid = (r_s+r_e)/2;
        return get_row_sum(r_idx*2, r_s, mid) + get_row_sum(r_idx*2+1, mid+1, r_e);
    }
}

void update(int r_idx, int c_idx, int val){
    int delta = val - seg[base+r_idx][base+c_idx];

    for(int i=base+r_idx; i>0; i/=2){
        seg[i][c_idx+base] += delta;

        for(int j=(c_idx+base)/2; j>0; j/=2){
            seg[i][j] = seg[i][j*2] + seg[i][j*2+1];
        }
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
    seg.resize(base*2);

    for(int i=1; i<base*2; i++){
        seg[i].resize(base*2);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> c;
            update(j, i, c);
        }
    }

    while(M--){
        cin >> w;
        if(!w){
            cin >> x >> y >> c;
            update(y-1, x-1, c);
        } else {
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            if(x_1 > x_2) swap(x_1, x_2);
            if(y_1 > y_2) swap(y_1, y_2);

            cout << get_row_sum(1, 1, base) << '\n';
        }
    }

    return 0;
}