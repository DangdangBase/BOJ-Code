#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int T;
int x, y;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> x >> y;

        ll bound = (ll)floor(sqrt(x));
        ll ret = 0;
        for(int k=1; k<=bound; k++){
            ret += max(min(x/k - 1, y)-k, 0);
        }

        cout << ret << "\n";
    }

    return 0;
}