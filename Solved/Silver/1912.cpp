#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, cur;
int dp[100010];

int main() {
	scanf("%d %d", &n, &cur);

	dp[0] = cur;

	for (int i = 1; i < n; i++) {
		scanf("%d", &cur);
		dp[i] = max(dp[i-1]+cur, cur);
	}

	int ret = *max_element(dp, dp + n);

	cout << ret;
}