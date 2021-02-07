#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int h[110];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i=0; i<N; i++){
            cin >> h[i];
        }

        while(K){
            int cur = 0;

            for(int i=0; i<N; i++){
                if(i == N-1){
                    K = 0;
                    cout << -1 << "\n";
                    break;
                }

                if(h[i] >= h[i+1]) continue;
                else {
                    h[i]++;
                    K--;

                    if(!K){
                        cout << i+1 << "\n";
                    }

                    break;
                }
            }
        }

    }

    return 0;
}