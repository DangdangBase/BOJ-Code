#include <bits/stdc++.h>
using namespace std;

int N;
int prev_w, cur_w;
int dp[10010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=1; i<N+1; i++){
        cin >> cur_w;

        dp[i] = cur_w + max(prev_w+dp[i-3], dp[i-2]);
        dp[i] = max(dp[i-1], dp[i]);

        prev_w = cur_w;
    }

    cout << dp[N];
    return 0;
}