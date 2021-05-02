#include <bits/stdc++.h>
#define INF 1987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, K, base, tmp;
char op;
int a, b;

vector<int> seg;


int transform(int val){
    if(val > 0) return 1;
    else if(val == 0) return 0;
    else return -1;
}

int query(int idx, int s, int e){
    if(b < s || e < a) return 1;
    else if(a <= s && e <= b) return seg[idx];
    else {
        int mid = (s+e)/2;
        return query(idx*2, s, mid) * query(idx*2+1, mid+1, e);
    }
}

void update(int idx, int val){
    int tf_val = transform(val);

    if(tf_val == seg[base+idx]) return;

    seg[base+idx] = tf_val;
    for(int i=(base+idx)/2; i>0; i/=2){
        seg[i] = seg[i*2] * seg[i*2+1];
    }
}

void print_seg(){
    int exp = 1;
    int tmp = 0;

    for(int i=1; i < base*2; i++){
        cout << seg[i] << ' ';
        tmp++;

        if(tmp == exp){
            cout << '\n';
            exp *= 2;
            tmp = 0;
        }
    } cout << '\n' << '\n';
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    while(cin >> N >> K){
        base = 1;
        seg.clear();
 
        while(base < N) base *= 2;        
        seg.resize(base*2, 1);

        for(int i=0; i<N; i++){
            cin >> tmp;
            update(i, tmp);
        }

        while(K--){
            cin >> op >> a >> b;

            if(op == 'C'){
                update(a-1, b);
            } else {
                int cur = query(1, 1, base);

                if(cur == 0) cout << 0;
                else if(cur > 0) cout << '+';
                else cout << '-';
            }
        } cout << '\n';
    }

    return 0;
}