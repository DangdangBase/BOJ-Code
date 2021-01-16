#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
map<int, int> m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    while(N--){
        cin >> tmp;
        m.insert({tmp, 1});
    }

    cin >> M;
    while(M--){
        cin >> tmp;
        cout << m[tmp]  << "\n";
    }

    return 0;
}