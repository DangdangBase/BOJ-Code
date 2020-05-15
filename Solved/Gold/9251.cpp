#include <iostream>
#include <algorithm>
using namespace std;

int lcs(int n, int m);

int n, m;
string a, b;
int dp[1010][1010];


int main() {
	cin >> a >> b;

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			dp[i][j] = -1;
		}
	}

	cout << lcs(a.length()-1, b.length()-1);
}

int lcs(int n, int m) {
	if (n < 0 || m < 0) {
		return 0;
	}
	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	int ret = 0;

	if (a.at(n) == b.at(m)) {
		ret = 1 + lcs(n - 1, m - 1);
	}
	else {
		ret = max(lcs(n - 1, m), lcs(n, m - 1));
	}

	dp[n][m] = ret;
	return ret;
}