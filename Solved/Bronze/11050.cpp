#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[11][11];

int bin(int n, int k){
    if(dp[n][k]){
        return dp[n][k];
    }
    if(k==0 || n==k){
        return dp[n][k] = 1;
    }

    return dp[n][k] = bin(n-1, k-1) + bin(n-1, k);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    cout << bin(N, K);
    return 0;
}