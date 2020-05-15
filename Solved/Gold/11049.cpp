#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int sCalc(int s, int e);

int n, r, c;
int mat[500][2];
int dp[500][500];


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &r, &c);
		mat[i][0] = r;
		mat[i][1] = c;

		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}

	cout << sCalc(0, n - 1);
}

int sCalc(int s, int e) {
	if (s == e) {
		return 0;
	}

	if (dp[s][e] != -1) {
		return dp[s][e];
	}

	int ret = INT_MAX;
	for (int i = 0; i < e-s; i++) {
		ret = min(ret, sCalc(s, s+i) + sCalc(s+i+1, e) + mat[s][0]*mat[s+i][1]*mat[e][1]);
	}

	dp[s][e] = ret;
	return ret;
}