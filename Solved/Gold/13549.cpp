#include <bits/stdc++.h>
using namespace std;


struct loc_time { int loc, time; };

int N, K;
deque<loc_time> q;
bool visited[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    q.push_back({N, 0});
    while(!q.empty()){
        auto cur = q.front(); q.pop_front();

        if(cur.loc == K){
            cout << cur.time;
            break;
        } else if(cur.loc < 0 || cur.loc > 100000 || visited[cur.loc]){
            continue;
        }

        visited[cur.loc] = true;

        q.push_front({cur.loc*2, cur.time});
        q.push_back({cur.loc+1, cur.time+1});
        q.push_back({cur.loc-1, cur.time+1});
    }

    return 0;
}