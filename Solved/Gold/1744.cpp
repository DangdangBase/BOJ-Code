#include <bits/stdc++.h>
using namespace std;

int N;
int seq[10010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> seq[i];
    }
    sort(seq, seq+N);

    int idx = lower_bound(seq, seq+N, 1) - seq - 1;
    int ret = 0;

    for(int i=0; i<=idx; i++){
        if(i != idx){
            ret += seq[i]*seq[i+1];
            i++;
        } else {
            ret += seq[i];
        }
    }
    for(int i=N-1; i>idx; i--){
        if(i != idx+1 && seq[i]*seq[i-1] > seq[i]+seq[i-1]){
            ret += seq[i]*seq[i-1];
            i--;
        } else {
            ret += seq[i];
        }
    }

    cout << ret;
    return 0;
}