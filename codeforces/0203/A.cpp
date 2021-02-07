#include <bits/stdc++.h>
using namespace std;
 
int T, N, K;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
    cin >> T;
    while(T--){
        cin >> N >> K;
 
        if(K == 1){
            cout << 1 << "\n";
            continue;
        }
 
        // int k = K;
        // while(N > k){
        //     k += K;
        // }
        if(N > K){
            if(N%K){
                K = K * (N/K+1);
            } else {
                K = K * (N/K);
            }
        }
 
        int tmp = K/N;
        if(K%N != 0){
            cout << tmp + 1 << "\n";
        } else {
            cout << tmp << "\n";
        }
    }
 
    return 0;
}