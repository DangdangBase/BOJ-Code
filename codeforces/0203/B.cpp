#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, N, K;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        ll cur, tmp;
        ll sum, ret = 0;

        cin >> N >> K;
        cin >> sum;
        for(int i=1; i<N; i++){
            cin >> cur;

            tmp = 100*cur - sum*K;
            if(ret < tmp){
                ret = tmp;
            }
            sum += cur;
        }
        cout << (ret + K - 1) / K << "\n";
    }

    return 0;
}