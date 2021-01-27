#include <bits/stdc++.h>
using namespace std;

int M, n;
string action;
// set<int> s;
// int s[21];
bitset<21> b;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> M;
    while(M--){
        cin >> action;

        if(action == "empty"){
            b.reset();
            continue;
        } else if(action == "all"){
            b.set();
            continue;
        }

        cin >> n;
        if(action == "add"){
            b.set(n, 1);
        } else if(action == "remove"){
            b.set(n, 0);
        } else if(action == "check"){
            cout << b[n] << "\n";
        } else if(action == "toggle"){
            b.flip(n);
        }
    }


    return 0;
}