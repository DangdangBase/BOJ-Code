#include <bits/stdc++.h>
using namespace std;

int N, prev_f, cur_f;
int dp[310];

int main()
{
    cin.tie(0),
    ios_base::sync_with_stdio;
    
    cin >> N;
    for(int i=1; i<N+1; i++){
        cin >> cur_f;

        if (i==1) {
            dp[i] = cur_f;
        } else if (i==2) {
            dp[i] = cur_f + dp[1];
        } else {
            dp[i] = cur_f + max(dp[i-3]+prev_f, dp[i-2]);
        }

        prev_f = cur_f;
    }

    cout << dp[N];
    return 0;
}