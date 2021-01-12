#include <bits/stdc++.h>
using namespace std;

int N, K, W, V;
int dp[100010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	for(int i=0; i<N; i++){
        cin >> W >> V;
        for(int j=K; j>=W; j--){
            if(dp[j] < dp[j-W]+V){
                dp[j] = dp[j-W]+V;
            }
        }
	}

    printf("%d", dp[K]);
	return 0;
}