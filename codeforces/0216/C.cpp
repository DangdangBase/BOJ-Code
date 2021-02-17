#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
using namespace std;

int t;
ll x, arr[10010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    arr[0] = 1;
    for(int i=1; i<10010; i++){
        arr[i] = (ll)round(pow(i, 3));
    }

    cin >> t;
    while(t--){
        cin >> x;

        bool flag = false;
        for(int i=1; i<10010; i++){
            if(arr[i] > x) break;

            int idx = lower_bound(arr, arr+10010, x-arr[i]) - arr;
            if(arr[idx]+arr[i] == x){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}