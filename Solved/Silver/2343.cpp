#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int lesson[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_len=0;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> lesson[i];
        max_len = max(max_len, lesson[i]);
    }

    int start=max_len-1, end=1000000000;
    while(start+1 < end){
        int mid = (start+end)/2;
        int cnt=1;

        int cur_len=0;
        for(int i=0; i<N; i++){
            cur_len += lesson[i];

            if(cur_len > mid){
                cnt++;
                cur_len = lesson[i];
            }
        }

        if(cnt > M) start=mid;
        else end=mid;
    }

    cout << end;
    return 0;
}