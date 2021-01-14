#include <bits/stdc++.h>
using namespace std;

int H, M;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> H >> M;

    M -= 45;
    if(M < 0){
        H--;
        M += 60;
    }
    if(H < 0){
        H += 24;
    }

    cout << H << ' ' << M;

    return 0;
}