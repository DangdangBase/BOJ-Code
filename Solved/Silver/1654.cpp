#include <bits/stdc++.h>
#define ll long long
using namespace std;

int K, N;
int lan[10010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> K >> N;
    for(int i=0; i<K; i++){
        cin >> lan[i];
    }

    ll start=0, end=2147483648;
    while(start+1 < end){
        ll mid = (start+end)/2;
        ll cnt = 0;

        for(int i=0; i<K; i++) cnt += (lan[i]/mid);
        cnt >= N ? start=mid : end=mid;
    }

    cout << start;
    return 0;
}