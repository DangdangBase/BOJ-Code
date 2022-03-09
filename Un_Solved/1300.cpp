#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, K;
vector<ll> target;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    ll cur_n;
    ll tmp = 0;
    for(int i=1; i<=N; i++){
        tmp += 4*i-3;

        if(tmp >= K){
            tmp -= 4*i-3;
            cur_n = i;
            break;
        }
    }

    target.push_back(0);
    target.push_back(cur_n*cur_n);

    for(ll i=1; i<=cur_n-1; i++){
        ll lower_right = 2*cur_n-1-i;
        ll upper_right = lower_right+1;

        if(lower_right<=N) {
            target.push_back(i*lower_right);
            target.push_back(i*lower_right);
        }
        if(upper_right<=N){
            target.push_back(i*upper_right);
            target.push_back(i*upper_right);
        }
    }
    sort(target.begin(), target.end());

    cout << target[K-tmp];
    return 0;
}