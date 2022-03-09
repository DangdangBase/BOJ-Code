#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;


int dp[2510][2510];
string str;

int get_len(int s, int e){
    if(s==e) return 1;
    else if(dp[s][e]) return dp[s][e];

    bool flag = true;
    for(int i=0; i<=(e-s+1)/2; i++){
        if(str[s+i] != str[e-i]){
            flag = false;
            break;
        }
    }

    if(flag){
        dp[s][e] = 1;
    } else {
        
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> str;

    return 0;
}