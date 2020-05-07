#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int n;
int dp[1010];

int main() {
	dp[0] = 1;
	dp[1] = 1;

	scanf("%d", &n);

	for (int i = 2; i < n + 1; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	printf("%d", dp[n]);
}