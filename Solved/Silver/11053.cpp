#include <bits/stdc++.h>
using namespace std;

int N, cur;
int seq[1010];
int dp[1010];
int ret;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> seq[i];

        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(seq[i]>seq[j] && dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }

        if(ret < dp[i]){
            ret = dp[i];
        }
    }

    cout << ret;
    return 0;
}