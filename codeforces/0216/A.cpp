#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int t, n, tmp;
int cnt;
vector<int> v;

int arr[10] = {2, 4, 8, 16, 32};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    while(t--){
        v.clear();
        cnt = 0;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
        }

        for(int i=1; i<n; i++){
            int b = max(v[i-1], v[i]), s = min(v[i-1], v[i]);

            while(s*2 < b){
                cnt++;
                s *= 2;
            }
        }
        
        cout << cnt << "\n";
    }

    return 0;
}