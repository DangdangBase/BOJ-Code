#include <bits/stdc++.h>
using namespace std;

int board[1034][1034];
int dp[1034][1034];

int N, M;
int x_1, x_2, y_1, y_2;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = board[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    for(int i=0; i<M; i++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        cout << dp[x_2][y_2] - dp[x_1-1][y_2] - dp[x_2][y_1-1] + dp[x_1-1][y_1-1] << "\n";
    }
    
    return 0;
}