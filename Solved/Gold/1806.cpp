#include <bits/stdc++.h>
#define P pair<int, int>
#define ll long long
#define INF 987654321
using namespace std;

int N, S;
int arr[100010];
int min_len = INF;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int sum = 0, lo = 0, hi = 0;
    
    while(true){
        if(sum >= S) sum -= arr[lo++];
        else if(hi == N) break;
        else sum += arr[hi++];
        if(sum >= S) {
            min_len = min(min_len, hi-lo);
        }
    }
    
    if(min_len == INF) min_len = 0;
    cout << min_len << endl;
    return 0;
}
