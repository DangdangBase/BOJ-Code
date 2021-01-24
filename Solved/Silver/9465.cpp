#include <bits/stdc++.h>
using namespace std;

int T, N;
int sticker[2][100010];
int dp[2][100010];

// top-down
int get_sticker(int y, int x){
    if(x >= N) return 0;
    else if(dp[y][x]) return dp[y][x];

    return dp[y][x] = sticker[y][x] + max(get_sticker(x+1, !y), get_sticker(x+2, !y));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N;

        for(int i=0; i<2; i++){
            for(int j=1; j<=N; j++){
                cin >> sticker[i][j];
            }
        }


        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for(int i=2; i<=N; i++){
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
        }
        cout << max(dp[0][N], dp[1][N]) << "\n";

        // top-down
        // cout << max(get_sticker(0, 0), get_sticker(1, 0)) << "\n";
        // memset(dp, 0, sizeof(dp));
    }

    return 0;
}