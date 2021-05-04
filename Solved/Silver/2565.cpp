#include <bits/stdc++.h>
#define ll long long
#define P pair<int, int>
using namespace std;

int N, s, e;
P lines[110];
int dp[110];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s >> e;
        lines[i] = {s, e};
    }
    sort(lines, lines+N);

    int len = 0;
    for(int i=0; i<N; i++){
        dp[i] = 1;

        for(int j=0; j<i; j++){
            if(lines[j].second <= lines[i].second){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        len = max(len, dp[i]);
    }

    cout << (N - len);
}