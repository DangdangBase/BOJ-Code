#include <bits/stdc++.h>
using namespace std;
#define divider 1000000000;

int N;
long long dp[110][10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    dp[1][0] = 0;
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }

    cin >> N;
    for(int i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                dp[i][0] = dp[i-1][1];
            }
            else if(j==9){
                dp[i][9] = dp[i-1][8];
            }
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % divider;
            }
        }
    }
    
    long long tmp = 0;
    for(int i=0; i<10; i++){
        tmp += dp[N][i];
    }

    cout << tmp % divider;
    return 0;
}