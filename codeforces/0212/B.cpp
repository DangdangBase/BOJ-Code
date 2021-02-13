#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int N, Q, K;
int l, r;

int arr[100010];
int dp[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> Q >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=1; i<N-1; i++){
        dp[i] = dp[i-1] + arr[i+1] - arr[i-1] - 2;
    }

    while(Q--){
        cin >> l >> r;
        if(l == r){
            cout << K-1 << "\n";
            continue;
        }

        l--; r--;

        int mid = dp[r-1] - dp[l];
        int left = arr[l+1] - 2;
        int right = K - arr[r-1] - 1;
        
        cout << left+mid+right << "\n";
    }

    return 0;
}