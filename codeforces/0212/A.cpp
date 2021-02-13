#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

struct item{
    int a, b, t;
};

int T, A, B;
queue<item> q;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        q = queue<item>();

        cin >> A >> B;
        q.push({A, B, 0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int a = cur.a, b = cur.b;

            if(a == 0){
                cout << cur.t << "\n";
                break;
            }

            q.push({a/b, b, cur.t+1});
            q.push({a, b+1, cur.t+1});
        }
    }
    


    return 0;
}