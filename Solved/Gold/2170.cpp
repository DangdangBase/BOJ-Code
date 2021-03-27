#include <bits/stdc++.h>
#define P pair<int, int>
using namespace std;

int N, ans;
vector<P> lines;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    lines.resize(N);
    for(int i=0; i<N; i++){
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(), lines.end());

    P cur = {-1000000001, -1000000001};
    for(P line: lines){
        if(line.first <= cur.second){
            cur.second = max(cur.second, line.second);
        } else {
            ans += cur.second - cur.first;
            cur = line;
        }
    }
    ans += cur.second - cur.first;

    cout << ans;
    return 0;
}