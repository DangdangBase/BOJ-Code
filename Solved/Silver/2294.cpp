#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;


int dp[10010];
int coins[110];
int N, K;


int main() {
	dp[0] = 0;

	scanf("%d%d", &N, &K);

	for (int i = 1; i < K + 1; i++) {
		dp[i] = 10001;
	}


	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
	}



	for (int i = 0; i < N; i++) {
		for (int j = coins[i]; j < K + 1; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}


	if (dp[K] == 10001) {
		dp[K] = -1;
	}

	cout << dp[K];
}
