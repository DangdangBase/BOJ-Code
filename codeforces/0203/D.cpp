#include <bits/stdc++.h>
using namespace std;

int t, n;
string str;

bool visited[300010];
int dp[2][300010];

int journey(int cur, int state){
    if(dp[state][cur]){
        return dp[state][cur];
    }

    visited[cur] = true;
    int first=0, second=0;

    // cout << cur << ' ' << state << endl;

    if(cur != 0 && !visited[cur-1] && ((str[cur-1]=='L' && state==0) || (str[cur-1]=='R' && state==1))){
        first = journey(cur-1, !state);
        // cout << "f " << first << endl;
    }
    if(cur != n && !visited[cur+1] && ((str[cur]=='R' && state==0) || (str[cur]=='L' && state==1))){
        second = journey(cur+1, !state);
        // cout << "s " << second << endl;
    }

    return dp[state][cur] = first+second + 1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));

        cin >> n;
        cin >> str;

        // for(int i=0; i<=n; i++){
        //     memset(visited, 0, sizeof(visited));
        //     cout << journey(i, 0) << ' ';
        // }
        // cout << "\n";
        cout << journey(3, 0) << endl;
    }

    return 0;
}