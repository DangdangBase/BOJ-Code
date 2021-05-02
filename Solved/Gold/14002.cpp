#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, len;
int arr[1010];
int dp[1010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=0; i<N; i++){
        dp[i] = 1;

        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[i] <= dp[j]){
                dp[i] = dp[j] + 1;
            }
        }

        len = max(len, dp[i]);
    }
    
    cout << len << '\n';

    int last = INF;
    vector<int> ans;

    for(int i=N-1; i>=0; i--){
        if(dp[i] == len && arr[i] < last){
            ans.push_back(arr[i]);
            len--;
        }
    }

    reverse(ans.begin(), ans.end());
    for(int cur: ans){
        cout << cur << ' ';
    }
    return 0;
}