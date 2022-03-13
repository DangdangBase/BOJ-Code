#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, S;
int arr[25];

int backtrack(int idx, int sum){
    int ret = 0;

    if(idx != -1 && sum == S) ret++;

    for(int i=idx+1; i<N; i++){
        ret += backtrack(i, sum+arr[i]);
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> S;
    for(int i=0; i<N; i++) cin >> arr[i];

    cout << backtrack(-1, 0);
    return 0;
}