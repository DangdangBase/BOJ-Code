#include <bits/stdc++.h>
#define ll long long;
using namespace std;

int N, M;
int board[1010][1010];
int dp[1010][1010];
int tmp[2][1010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> board[i][j];
        }
    }

    dp[1][1] = board[1][1];
    for(int j=2; j<=M; j++){
        dp[1][j] = board[1][j] + dp[1][j-1];
    }

    for(int i=2; i<=N; i++){
        tmp[0][1] = board[i][1] + dp[i-1][1];
        tmp[1][M] = board[i][M] + dp[i-1][M];

        for(int j=2; j<=M; j++){
            tmp[0][j] = max(tmp[0][j-1], dp[i-1][j]) + board[i][j];
        }
        for(int j=M-1; j>=1; j--){
            tmp[1][j] = max(tmp[1][j+1], dp[i-1][j]) + board[i][j];
        }


        for(int j=1; j<=M; j++){
            if(i == N){
                dp[i][j] = tmp[0][j];    
            } else {
                dp[i][j] = max(tmp[0][j], tmp[1][j]);
            }
        }
    }


    cout << dp[N][M];
    return 0;
}