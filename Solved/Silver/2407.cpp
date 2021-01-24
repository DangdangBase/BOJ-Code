#include <bits/stdc++.h>
using namespace std;

int N, M;
string dp[110][60];

string addBigNum(string a, string b){
    int tmp = 0;
    string ret;

    while(!a.empty() || !b.empty()){
        if(!a.empty()){
            tmp += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty()){
            tmp += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((tmp%10) + '0');
        tmp /= 10;
    }

    if(tmp){
        ret.push_back(tmp + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string comb(int n, int m){
    if(n == m || m == 0) return "1";
    else if(dp[n][m] != "0") return dp[n][m];

    return dp[n][m] = addBigNum(comb(n-1, m-1), comb(n-1, m));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=0; i<110; i++){
        for(int j=0; j<60; j++){
            dp[i][j] = "0";
        }
    }
    cin >> N >> M;
    cout << comb(N, min(M, N-M)) << endl;

    return 0;
}