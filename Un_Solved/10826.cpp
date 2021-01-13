#include <bits/stdc++.h>
using namespace std;

int divider = 100000000;
int N, tmp;
int dp[10010][2];
string ret = "";

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    dp[0][0] = 0; dp[0][1] = 0;
    dp[1][0] = 1; dp[1][1] = 0;

    cin >> N;
    for(int i=2; i<=N; i++){
        tmp = dp[i-1][0] + dp[i-2][0];

        dp[i][0] = tmp % divider;
        dp[i][1] = (int)(tmp / divider) + dp[i-1][1] + dp[i-2][1];
    }


    if(dp[N][1]){
        cout << to_string(dp[N][1]) + to_string(100000000 + dp[N][0]).erase(0, 1);
    } else {
        cout << dp[N][0];
    }
    
    return 0;
}