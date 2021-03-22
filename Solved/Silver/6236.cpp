#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int price[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;

    int max_price=0;
    for(int i=0; i<N; i++){
        cin >> price[i];
        max_price = max(max_price, price[i]);
    }

    int start=max_price-1, end=1000000000;
    while(start+1 < end){
        int mid = (start+end)/2;
        int cnt = 1;

        int cur_sum = 0;
        for(int i=0; i<N; i++){
            cur_sum += price[i];

            if(cur_sum > mid){
                cnt++;
                cur_sum = price[i];
            }
        }

        if(cnt > M) start=mid;
        else end=mid;
    }

    cout << end;
    return 0;
}