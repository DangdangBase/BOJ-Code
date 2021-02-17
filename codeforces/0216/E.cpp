#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int t, n;
ll tmp;
vector<pair<ll, int>> v;
vector<int> v2;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        v.clear();
        v2.clear();

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> tmp;
            v.push_back({tmp, i+1});
        }

        sort(v.begin(), v.end());

        ll cur = v[0].first;
        int idx = 0;
        for(int i=1; i<n; i++){
            if(cur < v[i].first){
                idx = i;
            }
            cur += v[i].first;
        }

        for(int i=idx; i<n; i++){
            v2.push_back(v[i].second);
        }
        sort(v2.begin(), v2.end());

        cout << v2.size() << "\n";
        for(int i: v2){
            cout << i << ' ';
        }
        cout << "\n";
    }

    return 0;
}