#include <bits/stdc++.h>
using namespace std;

long long N, x, y;
int K, Q;

pair<long long, long long> p_x, p_y;
long long cumulative_sum[55];

pair<long long, long long> to_2dim(long long n){
    if(n==1) return {0, 0};

    for(int i=1; i<55; i++){
        if(cumulative_sum[i] >= n){
            return {i, n - cumulative_sum[i-1] - 1};
        }
    }
}

int dist(int d){
    if(p_x == p_y) return d;

    long long tmp;

    if(p_x.first != p_y.first){
        tmp = (long long)floor((long double)p_y.second / K);
        p_y = {p_y.first-1, tmp};

        return dist(d+1);
    } else {
        tmp = (long long)floor((long double)p_x.second / K);
        p_x = {p_x.first-1, tmp};

        tmp = (long long)floor((long double)p_y.second / K);
        p_y = {p_y.first-1, tmp};

        return dist(d+2);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K >> Q;

    long long tmp, cur_exp = 1;
    cumulative_sum[0] = 1;
    for(int i=1; i<55; i++){
        cur_exp *= K;
        tmp = cur_exp + cumulative_sum[i-1];

        if(tmp < 0){
            cumulative_sum[i] = LLONG_MAX;
            break;
        }

        cumulative_sum[i] = tmp;
    }


    while(Q--){
        cin >> x >> y;
        if(x > y) swap(x, y);

        if(K == 1){
            cout << y-x << "\n";
            continue;
        }
        
        p_x = to_2dim(x);
        p_y = to_2dim(y);

        cout << dist(0) << "\n";
    }

    return 0;
}