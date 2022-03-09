#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int T, x, y, diff;
vector<int> square;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    square.push_back(0);
    for(int i=1; i<=46340; i++){
        square.push_back(i*i);
    }

    cin >> T;
    while(T--){
        cin >> x >> y;
        diff = y - x;

        int idx = upper_bound(square.begin(), square.end(), diff) - square.begin() - 1;
        int offset = diff - idx*idx;
        int base_val = 2*idx - 1;

        cout << base_val + ceil(float(offset) / float(idx)) << endl;
    }

    return 0;
}