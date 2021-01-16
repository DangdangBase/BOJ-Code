#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
map<int, int> m;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        m[tmp]++;
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> tmp;
        cout << m[tmp] << ' ';
    }


    return 0;
}