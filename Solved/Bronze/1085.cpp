#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> x >> y >> w >> h;
    cout << min(min(min(x, y), w-x), h-y);

    return 0;
}