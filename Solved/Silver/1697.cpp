#include <bits/stdc++.h>
using namespace std;

int N, K;
queue<pair<int, int>> q;
bool visited[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> K;

    q.push({N, 0});
    while(!q.empty()){
        int loc=q.front().first, time=q.front().second; 
        q.pop();

        if(loc == K){
            cout << time;
            break;
        } else if(loc > 100000 || loc < 0 || visited[loc]){
            continue;
        }

        visited[loc] = true;
        q.push({2*loc, time+1});
        q.push({loc+1, time+1});
        q.push({loc-1, time+1});
    }

    return 0;
}