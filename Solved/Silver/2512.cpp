#include <bits/stdc++.h>
using namespace std;

int N, M;
int request[10010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int sum=0, max_req=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> request[i];
        max_req = max(max_req, request[i]);
        sum += request[i];
    }
    cin >> M;


    if(M >= sum){
        cout << max_req;
        return 0;
    }

    int start=0, end=max_req;
    while(start+1 < end){
        int mid = (start+end)/2;
        int cnt=0;

        for(int i=0; i<N; i++){
            cnt += min(request[i], mid);
        }

        if(cnt > M) end=mid;
        else start=mid;
    }

    cout << start;

    return 0;
}