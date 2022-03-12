#include <bits/stdc++.h>
#define ll long long
using namespace std;

int T, N, M;
int a[1010];
int b[1010];
map<int, int> a_ps;
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];
    cin >> M;
    for(int i=0; i<M; i++) cin >> b[i];

    for(int i=0; i<N; i++){
        ll tmp = 0;
        for(int j=i; j<N; j++){
            tmp += a[j];
            a_ps[tmp]++;
        }
    }
    for(int i=0; i<M; i++){
        ll tmp = 0;
        for(int j=i; j<M; j++){
            tmp += b[j];
            ans += a_ps[T - tmp];
        }
    }

    cout << ans;
    return 0;
}