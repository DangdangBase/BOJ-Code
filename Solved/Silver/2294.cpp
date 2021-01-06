#include <bits/stdc++.h>
using namespace std;

int dp[10010];
int coins[110];
int N, K;

// bottom-up
// int main() {
//     cin >> N >> K;

// 	dp[0] = 0;
// 	for (int i = 1; i < K + 1; i++) {
// 		dp[i] = 10001;
// 	}

// 	for (int i = 0; i < N; i++) {
//         cin >> coins[i];
// 	}



// 	for (int cur_coin: coins) {
// 		for (int i = cur_coin; i < K + 1; i++) {
// 			dp[i] = min(dp[i], dp[i - cur_coin] + 1);
// 		}
// 	}


// 	if (dp[K] == 10001) {
// 		dp[K] = -1;
// 	}

// 	cout << dp[K];
// }


// top-down
int get_coin(int a){
	if(a < 0){
		return 10001;
	}
	if(dp[a] || a==0){
		return dp[a];
	}

	int ret = 10001;
	for(int i=0; i<N; i++){
		ret = min(ret, get_coin(a-coins[i])+1);
	}
	
	return dp[a] = ret;
}

int main(){
	cin >> N >> K;

	for(int i=0; i<K+1; i++){
		dp[i] = 0;
	}
	for(int i=0; i<N; i++){
		cin >> coins[i];
	}

	int ret = get_coin(K);
	if(ret == 10001){
		cout << -1;
	} else {
		cout << ret;
	}

	return 0;
}
