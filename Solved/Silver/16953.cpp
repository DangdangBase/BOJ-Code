#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

ll A, B;
queue<pair<ll, int>> q;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> A >> B;

    q.push({A, 1});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        
        if(p.first == B){
            cout << p.second;
            return 0;
        }
        else if(p.first > B) continue;

        q.push({p.first*2, p.second+1});
        q.push({p.first*10+1, p.second+1});
    }

    cout << -1;
    return 0;
}