#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define MAX 123456789
using namespace std;

struct num{
    int caller, value, time;
};

int N;
num dp[1000010];
queue<num> q;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<1000010; i++){
        dp[i] = {-1, i, MAX};
    }

    q.push({-1, N, 0});
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        if(cur.time > dp[cur.value].time){
            continue;
        }
        dp[cur.value] = cur;

        if(cur.value == 1) break;


        if(cur.value%3 == 0){
            q.push({cur.value, cur.value/3, cur.time+1});
        } 
        if(cur.value%2 == 0){
            q.push({cur.value, cur.value/2, cur.time+1});
        } 
        q.push({cur.value, cur.value-1, cur.time+1});
        
    }

    cout << dp[1].time << endl;

    vector<int> ret;

    int tmp = 1;
    while(tmp != N){
        ret.push_back(tmp);
        tmp = dp[tmp].caller;
    }
    ret.push_back(N);

    reverse(ret.begin(), ret.end());
    for(int cur: ret){
        cout << cur << ' ';
    }
    return 0;
}