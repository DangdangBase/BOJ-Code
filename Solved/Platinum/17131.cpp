#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define MOD 1000000007
using namespace std;

int N;
vector<P> stars;
int fwt[400002];

void update(int i){
    while(i <= 400002){
        fwt[i]++;
        i += (i & -i);
    }
}
int sum(int i){
    int ret = 0;
    while(i > 0){
        ret += fwt[i];
        i -= (i & -i);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    stars.resize(N);

    for(int i=0; i<N; i++){
        cin >> stars[i].first >> stars[i].second;
        stars[i].first += 200001;
    }
    sort(stars.begin(), stars.end(), [](P& a, P& b){ return a.second > b.second; });

    ll ans = 0;
    int start = 0;
    for(int i=0; i<N; i++){
        if(stars[i].second != stars[start].second){
            for(int j=start; j<i; j++){
                update(stars[j].first);
            }
            start = i;
        }

        ans += 1ll * sum(stars[i].first-1) * (sum(400002)-sum(stars[i].first));
        ans %= MOD;
    }

    cout << ans;
    return 0;
}
