#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


int n;
long long int dp[100];

int main() {
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < n + 1; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
}