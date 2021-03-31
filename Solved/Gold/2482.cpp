#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000003
using namespace std;

int N, K;
ll dp[1010][1010];

ll solve(int n, int k){
    if(k == 1) return n;
    else if(n <= k) return 0;
    else if(dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = (solve(n-1, k) + solve(n-2, k-1)) % MOD;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> K;
    if(K == 1){
        cout << N;
        return 0;
    }

    cout << ((solve(N-3, K-1)+solve(N-1, K)) % MOD);
    return 0;
}