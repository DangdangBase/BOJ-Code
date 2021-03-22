#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, C;
int loc[200010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> loc[i];
    }
    sort(loc, loc+N);

    int start=1, end=loc[N-1];
    while(start+1 < end){
        ll mid=(start+end)/2;
        int cnt=0;

        int last_loc = -1000000000;
        for(int i=0; i<N; i++){
            if(loc[i]-last_loc >= mid){
                cnt++;
                last_loc = loc[i];
            }
        }

        if(cnt < C) end=mid;
        else start=mid;
    }

    cout << start;
    return 0;
}