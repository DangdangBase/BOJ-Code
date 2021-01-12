#include <bits/stdc++.h>
using namespace std;

int T, K;
int files[510];
int dp[510][510];

int file_merge(int s, int e){
    if(s == e){
        return 0;
    }
    else if(dp[s][e] != -1){
        return dp[s][e];
    }

    int ret = INT_MAX;
    for(int i=s; i<e; i++){
        ret = min(ret, file_merge(s,i)+file_merge(i+1,e));
    }

    int tot_sum = 0;
    for(int i=s; i<=e; i++){
        tot_sum += files[i];
    }

    return dp[s][e] = ret + tot_sum;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T>0){
        cin >> K;
        for(int i=0; i<K; i++){
            cin >> files[i];
        }
        memset(dp, -1, sizeof(dp));

        cout << file_merge(0, K-1) << "\n";
        T--;
    }
    
    return 0;
}