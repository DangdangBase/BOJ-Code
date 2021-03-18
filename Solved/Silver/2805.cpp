#include <bits/stdc++.h>
#define INF 987654321
#define P pair<int, int>
#define ll long long
using namespace std;

int N, M;
int tree[1000010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;

    int max_h = 0;
    for(int i=0; i<N; i++){
        cin >> tree[i];
        if(tree[i] > max_h) max_h = tree[i];
    }


    int start=0, end=max_h, mid=(start+end)/2;
    while(start <= end){
        ll cnt=0;
        for(int i=0; i<N; i++){
            if(tree[i]-mid > 0){
                cnt += tree[i]-mid;
            }
        }

        if(cnt < M) end = mid-1; 
        else start = mid+1;

        mid = (start+end)/2;
    }

    cout << start-1;

    return 0;
}