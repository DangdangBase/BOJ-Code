// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, M, K;
int a, b, c, d;
int dp[310][310]{0,};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<N+1; i++){
        for(int j=1; j<M+1; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> a >> b >> c >> d;
        cout << (dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1]) << "\n";
    }

    return 0;
}