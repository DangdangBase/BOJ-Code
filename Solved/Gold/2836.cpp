#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int a, b;
vector<P> rev;
ll ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        if(a > b) rev.push_back({b, a});
    }
    sort(rev.begin(), rev.end());

    P cur = {0, 0};
    for(P line: rev){
        if(line.first <= cur.second){
            cur.second = max(cur.second, line.second);
        } else {
            ans += cur.second - cur.first;
            cur = line;
        }
    }
    ans += 2*ans + M + (cur.second-cur.first);

    cout << ans;
    return 0;
}